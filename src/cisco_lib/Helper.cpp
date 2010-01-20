/* 

                          Firewall Builder

                 Copyright (C) 2002 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@vk.crocodile.org

  $Id$

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/


#include "Helper.h"

#include <fwbuilder/Interface.h>
#include <fwbuilder/ObjectGroup.h>
#include <fwbuilder/InetAddr.h>
#include <fwbuilder/FWObjectDatabase.h>
#include <fwbuilder/RuleElement.h>
#include <fwbuilder/Rule.h>
#include "fwbuilder/Resources.h"
#include <fwbuilder/IPv6.h>

#include <assert.h>
#include <limits.h>
#include <iostream>

using namespace libfwbuilder;
using namespace fwcompiler;
using namespace std;

static unsigned long calculateDimension(FWObject* obj)
{
    if (Group::cast(obj)!=NULL)
    {
        unsigned long res=0;
	for (FWObject::iterator i1=obj->begin(); i1!=obj->end(); ++i1) 
        {
            unsigned long n=calculateDimension( *i1 );
            if (n==LONG_MAX)    return n;
            if (LONG_MAX-res<n) return LONG_MAX; // prevent overflow
	    res+=n;
	}
        return res;
    } else
    {
        Address *a=Address::cast(obj);
        if (a!=NULL) 
        {
            if (a->isAny()) return LONG_MAX;
            return a->dimension();
        }
    }
    return 0;
}

void Helper::expand_group_recursive(FWObject *o,list<FWObject*> &ol)
{
    if (Group::cast( o )!=NULL)
    {
        for (FWObject::iterator i2=o->begin(); i2!=o->end(); ++i2) 
        {
            FWObject *o1= *i2;
            if (FWReference::cast(o1)!=NULL) o1=FWReference::cast(o1)->getPointer();
            assert(o1);

            expand_group_recursive(o1,ol);
        }
    } else {
        ol.push_back( o );
    }
}

int  Helper::findInterfaceByAddress(Address *obj)
{
    return findInterfaceByAddress( obj->getAddressPtr() );
}

int  Helper::findInterfaceByAddress(const InetAddr *addr)
{
    if (addr==NULL) return -1;

    Firewall *fw=compiler->fw;
    list<FWObject*> l2=fw->getByType(Interface::TYPENAME);
    for (list<FWObject*>::iterator i=l2.begin(); i!=l2.end(); ++i)
    {
	Interface *iface=Interface::cast(*i);
        FWObjectTypedChildIterator j =
            iface->findByType((addr->isV4())?IPv4::TYPENAME:IPv6::TYPENAME);
        for (; j!=j.end(); ++j)
        {
            const Address *i_addr = Address::constcast(*j);
            if ( i_addr->belongs(*addr) ) return iface->getId();
        }
    }
    return -1;
}

int  Helper::findInterfaceByNetzone(Address *obj)
{
    return findInterfaceByNetzone(obj->getAddressPtr());
}

int  Helper::findInterfaceByNetzone(const InetAddr *addr) throw(string)
{
    Firewall *fw = compiler->fw;
    map<int,FWObject*> zones;
    list<FWObject*> l2 = fw->getByTypeDeep(Interface::TYPENAME);
    for (list<FWObject*>::iterator i=l2.begin(); i!=l2.end(); ++i)
    {
        Interface *iface = Interface::cast(*i);
        if (iface->isDedicatedFailover()) continue;
        if (iface->isUnprotected()) continue;

        // NOTE: "network_zone" is globally unique string ID
        int netzone_id =
            FWObjectDatabase::getIntId(iface->getStr("network_zone"));

#if 0
        FWObject *netzone = fw->getRoot()->findInIndex(netzone_id);
        cerr << "netzone_id=" << netzone_id
             << "  " << iface->getStr("network_zone")
             << "  " << netzone->getName()
             << endl;
#endif
        if (netzone_id != -1)
        {
            FWObject *netzone = fw->getRoot()->findInIndex(netzone_id);
            list<FWObject*> nz;
            expand_group_recursive(netzone, nz);

            for (list<FWObject*>::iterator j=nz.begin(); j!=nz.end(); ++j)
            {
                if (Address::cast(*j) == NULL) continue;

                // if addr==NULL, return id of the interfacce that has
                // net_zone=="any"
                if (addr==NULL)
                {
                    if ((*j)->getId()==FWObjectDatabase::ANY_ADDRESS_ID)
                        return iface->getId(); // id of the interface
                } else
                {
                    if (Address::cast(*j)->belongs(*addr))
                        zones[iface->getId()] = netzone;
                }
            }
        }
    }

/*
 * now compare dimensions of all netzones that contain address obj and
 * pick the one with smallest dimension
 */    
    int  res_id = -1;
    unsigned long res_dim=LONG_MAX;
    for (map<int,FWObject*>::iterator i=zones.begin(); i!=zones.end(); ++i) 
    {
        int iface_id = (*i).first;
        FWObject *netzone = (*i).second;
        unsigned long dim = calculateDimension(netzone);

        if (dim<=res_dim) 
        {
            res_id=iface_id;
            res_dim=dim;
        }
    }

/*
 * Subnets defined by addresses of interfaces are automatically part
 * of the corresponding network zones
 */
    if (res_id == -1) res_id = findInterfaceByAddress( addr );

    if (res_id == -1)
        throw(string("Can not find interface with network zone that includes "
                     "address ") + string((addr)?addr->toString():"NULL"));
    return res_id;
}

list<int> Helper::getAllInterfaceIDs()
{
    Firewall *fw = compiler->fw;
    list<int> intf_id_list;
    FWObjectTypedChildIterator i=fw->findByType(Interface::TYPENAME);
    for ( ; i!=i.end(); ++i)
    {
        Interface *ifs = Interface::cast(*i);
        assert(ifs);
        if (ifs->isUnprotected()) continue;   // skip!
        intf_id_list.push_back( (*i)->getId() );
    }
    return intf_id_list;
}

list<int> Helper::findInterfaceByNetzoneOrAll(RuleElement *re)
{
    Firewall *fw = compiler->fw;
    list<int> intf_id_list;
    if (re->isAny())
    {
        return getAllInterfaceIDs();
    } else
    {
        FWObject *fo = re->front();
        if (FWReference::cast(fo)!=NULL) fo=FWReference::cast(fo)->getPointer();
        Address  *a = Address::cast(fo);
        if (a==NULL)
        {
            Rule *rule = Rule::cast(re->getParent());
            compiler->abort(
                re->getParent(), 
                string("findInterfaceByNetzoneOrAll failed to retrieve first "
                       "object from the rule element; is argument not of "
                       "the type RuleElementSrc or RuleElementDst ?"));
            return intf_id_list;
        }

        try
        {
            intf_id_list.push_back( findInterfaceByNetzone( a ) );
        } catch(string err)
        {
            // could not find interface with netzone to match address 'a'
            // will assign rule to all interfaces. Act as if all interfaces
            // had network zone 'any' and each matches this address.

            // issue warning only if platform uses netwrk zones.

            bool supports_network_zones =
                Resources::getTargetCapabilityBool(
                    compiler->fw->getStr("platform"), "network_zones");

            if (supports_network_zones)
                compiler->warning(err);

            FWObjectTypedChildIterator i = compiler->fw->findByType(
                Interface::TYPENAME);
            for ( ; i!=i.end(); ++i)
            {
                Interface  *ifs = Interface::cast(*i);
                intf_id_list.push_back( ifs->getId() );
            }
        }
    }
    return intf_id_list;
}

string triplet::hash()
{
    ostringstream ostr;
    string dst_str;
    string src_str;

    Interface *intf = Interface::cast(src);
    if (intf && intf->isDyn()) src_str = intf->getId();
    else src_str = src->getAddressPtr()->toString();

    intf = Interface::cast(dst);
    if (intf && intf->isDyn()) dst_str = intf->getId();
    else dst_str = dst->getAddressPtr()->toString();

    ostr << src_str << "." << dst_str <<"." << srv->getId();
    return ostr.str();
}
