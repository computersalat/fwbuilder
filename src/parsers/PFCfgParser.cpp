/* $ANTLR 2.7.7 (20100319): "pf.g" -> "PFCfgParser.cpp"$ */
#line 43 "pf.g"

    // gets inserted before the antlr generated includes in the cpp
    // file

#line 8 "PFCfgParser.cpp"
#include "PFCfgParser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
#line 49 "pf.g"

    // gets inserted after the antlr generated includes in the cpp
    // file
#include <antlr/Token.hpp>
#include <antlr/TokenBuffer.hpp>

#line 20 "PFCfgParser.cpp"
#line 1 "pf.g"
#line 22 "PFCfgParser.cpp"
PFCfgParser::PFCfgParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,k)
{
}

PFCfgParser::PFCfgParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,2)
{
}

PFCfgParser::PFCfgParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,k)
{
}

PFCfgParser::PFCfgParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,2)
{
}

PFCfgParser::PFCfgParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(state,2)
{
}

void PFCfgParser::cfgfile() {
	Tracer traceInOut(this, "cfgfile");
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case COMMENT_START:
			{
				comment();
				break;
			}
			case INCLUDE_COMMAND:
			{
				include_command();
				break;
			}
			case WORD:
			{
				macro_definition();
				break;
			}
			case ALTQ:
			{
				altq_rule();
				break;
			}
			case ANTISPOOF:
			{
				antispoof_rule();
				break;
			}
			case QUEUE:
			{
				queue_rule();
				break;
			}
			case SET:
			{
				set_rule();
				break;
			}
			case SCRUB:
			{
				scrub_rule();
				break;
			}
			case MATCH:
			{
				match_rule();
				break;
			}
			case TABLE:
			{
				table_rule();
				break;
			}
			case NO:
			{
				no_nat_rule();
				break;
			}
			case NAT:
			{
				nat_rule();
				break;
			}
			case RDR:
			{
				rdr_rule();
				break;
			}
			case BINAT:
			{
				binat_rule();
				break;
			}
			case PASS:
			{
				pass_rule();
				break;
			}
			case BLOCK:
			{
				block_rule();
				break;
			}
			case NEWLINE:
			{
				match(NEWLINE);
				break;
			}
			default:
			{
				goto _loop3;
			}
			}
		}
		_loop3:;
		} // ( ... )*
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
}

void PFCfgParser::comment() {
	Tracer traceInOut(this, "comment");
	
	try {      // for error handling
		match(COMMENT_START);
#line 156 "pf.g"
		
		QStringList str;
		while (LA(1) != ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE && LA(1) != NEWLINE)
		{
		str << QString::fromUtf8(LT(1)->getText().c_str());
		consume();
		}
		importer->last_comment << str.join(" ");
		
#line 170 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::include_command() {
	Tracer traceInOut(this, "include_command");
	
	try {      // for error handling
		match(INCLUDE_COMMAND);
#line 169 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'include' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 191 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::macro_definition() {
	Tracer traceInOut(this, "macro_definition");
	
	try {      // for error handling
		match(WORD);
		match(EQUAL);
#line 180 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		consumeUntil(NEWLINE);
		
#line 211 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::altq_rule() {
	Tracer traceInOut(this, "altq_rule");
	
	try {      // for error handling
		match(ALTQ);
#line 200 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->error_tracker->registerError(
		QString("import of 'altq' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 232 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::antispoof_rule() {
	Tracer traceInOut(this, "antispoof_rule");
	
	try {      // for error handling
		match(ANTISPOOF);
#line 189 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Warning: import of 'antispoof' commands has not been implemented yet."));
		consumeUntil(NEWLINE);
		
#line 253 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::queue_rule() {
	Tracer traceInOut(this, "queue_rule");
	
	try {      // for error handling
		match(QUEUE);
#line 211 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->error_tracker->registerError(
		QString("import of 'queue' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 274 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_rule() {
	Tracer traceInOut(this, "set_rule");
	
	try {      // for error handling
		match(SET);
#line 222 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		
#line 292 "PFCfgParser.cpp"
		{
		switch ( LA(1)) {
		case TIMEOUT:
		{
			set_timeout();
			break;
		}
		case 14:
		{
			set_ruleset_optimization();
			break;
		}
		case LITERAL_optimization:
		{
			set_optimization();
			break;
		}
		case LITERAL_limit:
		{
			set_limit();
			break;
		}
		case LITERAL_loginterface:
		{
			set_loginterface();
			break;
		}
		case 23:
		{
			set_block_policy();
			break;
		}
		case 26:
		{
			set_state_policy();
			break;
		}
		case 29:
		{
			set_state_defaults();
			break;
		}
		case 30:
		{
			set_require_order();
			break;
		}
		case LITERAL_fingerprints:
		{
			set_fingerprints();
			break;
		}
		case LITERAL_skip:
		{
			set_skip();
			break;
		}
		case LITERAL_debug:
		{
			set_debug();
			break;
		}
		case LITERAL_reassemble:
		{
			set_reassemble();
			break;
		}
		case LITERAL_hostid:
		{
			set_hostid();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::scrub_rule() {
	Tracer traceInOut(this, "scrub_rule");
	
	try {      // for error handling
		match(SCRUB);
#line 521 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->newPolicyRule();
		importer->action = "scrub";
		*dbg << LT(1)->getLine() << ":" << " scrub ";
		
#line 391 "PFCfgParser.cpp"
		rule_extended();
		match(NEWLINE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::match_rule() {
	Tracer traceInOut(this, "match_rule");
	
	try {      // for error handling
		match(MATCH);
#line 536 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->newPolicyRule();
		importer->action = "match";
		*dbg << LT(1)->getLine() << ":" << " match ";
		
#line 414 "PFCfgParser.cpp"
		rule_extended();
#line 544 "pf.g"
		
		if ( ! importer->scrub_rule) importer->pushRule();
		
#line 420 "PFCfgParser.cpp"
		match(NEWLINE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::table_rule() {
	Tracer traceInOut(this, "table_rule");
	ANTLR_USE_NAMESPACE(antlr)RefToken  name = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefToken  file = ANTLR_USE_NAMESPACE(antlr)nullToken;
	
	try {      // for error handling
		match(TABLE);
#line 553 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		
#line 441 "PFCfgParser.cpp"
		match(LESS_THAN);
		name = LT(1);
		match(WORD);
		match(GREATER_THAN);
		{
		switch ( LA(1)) {
		case PERSIST:
		{
			match(PERSIST);
			break;
		}
		case NEWLINE:
		case OPENING_BRACE:
		case CONST_WORD:
		case COUNTERS:
		case FILE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case CONST_WORD:
		{
			match(CONST_WORD);
#line 565 "pf.g"
			
			importer->addMessageToLog(
			QString("Warning: attribute \"const\" will be dropped from table configuration since this attribute is not supported at this time"));
			
#line 477 "PFCfgParser.cpp"
			break;
		}
		case NEWLINE:
		case OPENING_BRACE:
		case COUNTERS:
		case FILE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case COUNTERS:
		{
			match(COUNTERS);
#line 572 "pf.g"
			
			importer->addMessageToLog(
			QString("Warning: attribute \"counters\" will be dropped from table configuration since this attribute is not supported at this time"));
			
#line 503 "PFCfgParser.cpp"
			break;
		}
		case NEWLINE:
		case OPENING_BRACE:
		case FILE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case FILE:
		{
			match(FILE);
			file = LT(1);
			match(STRING);
#line 579 "pf.g"
			
			importer->newAddressTableObject(
			name->getText(), file->getText());
			
#line 530 "PFCfgParser.cpp"
			break;
		}
		case OPENING_BRACE:
		{
			match(OPENING_BRACE);
			tableaddr_spec();
			{ // ( ... )*
			for (;;) {
				if ((_tokenSet_2.member(LA(1)))) {
					{
					switch ( LA(1)) {
					case COMMA:
					{
						match(COMMA);
						break;
					}
					case WORD:
					case INT_CONST:
					case EXLAMATION:
					case SELF:
					case IPV4:
					case NUMBER:
					{
						break;
					}
					default:
					{
						throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
					}
					}
					}
					tableaddr_spec();
				}
				else {
					goto _loop58;
				}
				
			}
			_loop58:;
			} // ( ... )*
			match(CLOSING_BRACE);
#line 591 "pf.g"
			
			importer->newAddressTableObject(
			name->getText(), importer->tmp_group);
			
#line 577 "PFCfgParser.cpp"
			break;
		}
		case NEWLINE:
		{
			match(NEWLINE);
#line 597 "pf.g"
			
			// Special case: table definition without file name or list of addresses.
			// Create run-time AddressTable object with name but no file spec.
			importer->newAddressTableObject(name->getText(), "");
			
#line 589 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::no_nat_rule() {
	Tracer traceInOut(this, "no_nat_rule");
	
	try {      // for error handling
		match(NO);
#line 672 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->newNATRule();
		importer->action = "nonat";
		*dbg << LT(1)->getLine() << ":" << " nonat ";
		
#line 618 "PFCfgParser.cpp"
		{
		switch ( LA(1)) {
		case NAT:
		{
			nat_rule();
			break;
		}
		case RDR:
		{
			rdr_rule();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::nat_rule() {
	Tracer traceInOut(this, "nat_rule");
	
	try {      // for error handling
		match(NAT);
#line 689 "pf.g"
		
		if ( importer->action != "nonat" )
		{
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->newNATRule();
		importer->action = "nat";
		*dbg << LT(1)->getLine() << ":" << " nat ";
		}
		
#line 660 "PFCfgParser.cpp"
		{
		switch ( LA(1)) {
		case PASS:
		{
			match(PASS);
#line 701 "pf.g"
			
			importer->error_tracker->registerError(
			QString("import of 'nat pass' commands is not supported."));
			
#line 671 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case LOG:
			{
				logging();
				break;
			}
			case NEWLINE:
			case ON:
			case EXLAMATION:
			case MINUS:
			case ALL:
			case TO:
			case INET:
			case INET6:
			case PROTO:
			case FROM:
			case TAGGED:
			case TAG:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case NEWLINE:
		case ON:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case ON:
		{
			intrface();
			break;
		}
		case NEWLINE:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case INET:
		case INET6:
		{
			address_family();
			break;
		}
		case NEWLINE:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case PROTO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case PROTO:
		{
			protospec();
			break;
		}
		case NEWLINE:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		hosts();
		{
		switch ( LA(1)) {
		case EXLAMATION:
		case TAGGED:
		{
			tagged();
			break;
		}
		case NEWLINE:
		case MINUS:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case TAG:
		{
			tag_clause();
#line 714 "pf.g"
			
			importer->error_tracker->registerError(
			QString("import of 'nat ... tag' commands is not supported."));
			
#line 831 "PFCfgParser.cpp"
			break;
		}
		case NEWLINE:
		case MINUS:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case MINUS:
		{
			match(MINUS);
			match(GREATER_THAN);
			{
			switch ( LA(1)) {
			case WORD:
			case IPV4:
			case OPENING_PAREN:
			{
				redirhost();
				break;
			}
			case OPENING_BRACE:
			{
				redirhost_list();
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
#line 722 "pf.g"
			
			importer->nat_group = importer->tmp_group;
			
#line 875 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case PORT:
			{
				portspec();
#line 727 "pf.g"
				
				importer->nat_port_group = importer->tmp_port_group;
				
#line 885 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case STATIC_PORT:
			case BITMASK:
			case RANDOM:
			case SOURCE_HASH:
			case ROUND_ROBIN:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case BITMASK:
			case RANDOM:
			case SOURCE_HASH:
			case ROUND_ROBIN:
			{
				pooltype();
				break;
			}
			case NEWLINE:
			case STATIC_PORT:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case STATIC_PORT:
			{
				match(STATIC_PORT);
#line 733 "pf.g"
				importer->nat_rule_opt_2 = "static-port";
#line 931 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case NEWLINE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 736 "pf.g"
		
		importer->pushRule();
		
#line 960 "PFCfgParser.cpp"
		match(NEWLINE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::rdr_rule() {
	Tracer traceInOut(this, "rdr_rule");
	
	try {      // for error handling
		match(RDR);
#line 745 "pf.g"
		
		if ( importer->action != "nonat" )
		{
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->newNATRule();
		importer->action = "rdr";
		*dbg << LT(1)->getLine() << ":" << " rdr ";
		}
		
#line 985 "PFCfgParser.cpp"
		{
		switch ( LA(1)) {
		case PASS:
		{
			match(PASS);
#line 757 "pf.g"
			
			importer->error_tracker->registerError(
			QString("import of 'nat pass' commands is not supported."));
			
#line 996 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case LOG:
			{
				logging();
				break;
			}
			case NEWLINE:
			case ON:
			case EXLAMATION:
			case MINUS:
			case ALL:
			case TO:
			case INET:
			case INET6:
			case PROTO:
			case FROM:
			case TAGGED:
			case TAG:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case NEWLINE:
		case ON:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case ON:
		{
			intrface();
			break;
		}
		case NEWLINE:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case INET:
		case INET6:
		{
			address_family();
			break;
		}
		case NEWLINE:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case PROTO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case PROTO:
		{
			protospec();
			break;
		}
		case NEWLINE:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		hosts();
		{
		switch ( LA(1)) {
		case EXLAMATION:
		case TAGGED:
		{
			tagged();
			break;
		}
		case NEWLINE:
		case MINUS:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case TAG:
		{
			tag_clause();
#line 770 "pf.g"
			
			importer->error_tracker->registerError(
			QString("import of 'nat ... tag' commands is not supported."));
			
#line 1156 "PFCfgParser.cpp"
			break;
		}
		case NEWLINE:
		case MINUS:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case MINUS:
		{
			match(MINUS);
			match(GREATER_THAN);
			{
			switch ( LA(1)) {
			case WORD:
			case IPV4:
			case OPENING_PAREN:
			{
				redirhost();
				break;
			}
			case OPENING_BRACE:
			{
				redirhost_list();
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
#line 778 "pf.g"
			
			importer->nat_group = importer->tmp_group;
			
#line 1200 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case PORT:
			{
				portspec();
#line 783 "pf.g"
				
				importer->nat_port_group = importer->tmp_port_group;
				
#line 1210 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case BITMASK:
			case RANDOM:
			case SOURCE_HASH:
			case ROUND_ROBIN:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case BITMASK:
			case RANDOM:
			case SOURCE_HASH:
			case ROUND_ROBIN:
			{
				pooltype();
				break;
			}
			case NEWLINE:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case NEWLINE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 789 "pf.g"
		
		importer->pushRule();
		
#line 1263 "PFCfgParser.cpp"
		match(NEWLINE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::binat_rule() {
	Tracer traceInOut(this, "binat_rule");
	
	try {      // for error handling
		match(BINAT);
#line 921 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->error_tracker->registerError(
		QString("import of 'binat' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1285 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::pass_rule() {
	Tracer traceInOut(this, "pass_rule");
	
	try {      // for error handling
		match(PASS);
#line 944 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->newPolicyRule();
		importer->action = "pass";
		*dbg << LT(1)->getLine() << ":" << " pass ";
		
#line 1306 "PFCfgParser.cpp"
		rule_extended();
#line 952 "pf.g"
		
		importer->pushRule();
		
#line 1312 "PFCfgParser.cpp"
		match(NEWLINE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::block_rule() {
	Tracer traceInOut(this, "block_rule");
	
	try {      // for error handling
		match(BLOCK);
#line 959 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->newPolicyRule();
		importer->action = "block";
		*dbg << LT(1)->getLine() << ":" << " block   ";
		
#line 1334 "PFCfgParser.cpp"
		{
		switch ( LA(1)) {
		case DROP:
		case RETURN:
		case RETURN_RST:
		case RETURN_ICMP:
		case RETURN_ICMP6:
		{
			block_return();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case ON:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case IN_WORD:
		case OUT_WORD:
		case LOG:
		case QUICK:
		case ALL:
		case USER:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case ROUTE_TO:
		case REPLY_TO:
		case DUP_TO:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		rule_extended();
#line 968 "pf.g"
		
		importer->pushRule();
		
#line 1397 "PFCfgParser.cpp"
		match(NEWLINE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_timeout() {
	Tracer traceInOut(this, "set_timeout");
	
	try {      // for error handling
		match(TIMEOUT);
		{
		switch ( LA(1)) {
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
		case 46:
		case 47:
		case 48:
		case 49:
		case 50:
		case 51:
		case 52:
		case 53:
		case LITERAL_frag:
		case LITERAL_interval:
		case 56:
		case 57:
		case 58:
		{
			timeout_def();
			break;
		}
		case OPENING_BRACE:
		{
			timeout_def_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_ruleset_optimization() {
	Tracer traceInOut(this, "set_ruleset_optimization");
	
	try {      // for error handling
		match(14);
#line 265 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'set ruleset-optimization' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1467 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_optimization() {
	Tracer traceInOut(this, "set_optimization");
	
	try {      // for error handling
		match(LITERAL_optimization);
		{
		switch ( LA(1)) {
		case LITERAL_aggressive:
		{
			match(LITERAL_aggressive);
			break;
		}
		case LITERAL_conservative:
		{
			match(LITERAL_conservative);
			break;
		}
		case 18:
		{
			match(18);
			break;
		}
		case LITERAL_normal:
		{
			match(LITERAL_normal);
			break;
		}
		case LITERAL_satellite:
		{
			match(LITERAL_satellite);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 287 "pf.g"
		importer->set_optimization = LT(0)->getText();
#line 1515 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_limit() {
	Tracer traceInOut(this, "set_limit");
	
	try {      // for error handling
		match(LITERAL_limit);
		{
		switch ( LA(1)) {
		case LITERAL_frags:
		case LITERAL_states:
		case 62:
		case LITERAL_tables:
		case 64:
		{
			limit_def();
			break;
		}
		case OPENING_BRACE:
		{
			limit_def_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_loginterface() {
	Tracer traceInOut(this, "set_loginterface");
	
	try {      // for error handling
		match(LITERAL_loginterface);
#line 298 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'set loginterface' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1570 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_block_policy() {
	Tracer traceInOut(this, "set_block_policy");
	
	try {      // for error handling
		match(23);
		{
		switch ( LA(1)) {
		case DROP:
		{
			match(DROP);
			break;
		}
		case RETURN:
		{
			match(RETURN);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 310 "pf.g"
		importer->set_block_policy = LT(0)->getText();
#line 1603 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_state_policy() {
	Tracer traceInOut(this, "set_state_policy");
	
	try {      // for error handling
		match(26);
		{
		switch ( LA(1)) {
		case 27:
		{
			match(27);
			break;
		}
		case LITERAL_floating:
		{
			match(LITERAL_floating);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 316 "pf.g"
		importer->set_state_policy = LT(0)->getText();
#line 1636 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_state_defaults() {
	Tracer traceInOut(this, "set_state_defaults");
	
	try {      // for error handling
		match(29);
#line 322 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'set state-defaults' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1657 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_require_order() {
	Tracer traceInOut(this, "set_require_order");
	
	try {      // for error handling
		match(30);
#line 334 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'set require-order' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1678 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_fingerprints() {
	Tracer traceInOut(this, "set_fingerprints");
	
	try {      // for error handling
		match(LITERAL_fingerprints);
#line 346 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'set fingerprints' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1699 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_skip() {
	Tracer traceInOut(this, "set_skip");
	
	try {      // for error handling
		match(LITERAL_skip);
		match(ON);
		skip_def();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_debug() {
	Tracer traceInOut(this, "set_debug");
	
	try {      // for error handling
		match(LITERAL_debug);
		match(WORD);
#line 382 "pf.g"
		
		importer->set_debug = LT(0)->getText();
		
#line 1731 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_reassemble() {
	Tracer traceInOut(this, "set_reassemble");
	
	try {      // for error handling
		match(LITERAL_reassemble);
#line 390 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'set reassemble' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1752 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::set_hostid() {
	Tracer traceInOut(this, "set_hostid");
	
	try {      // for error handling
		match(LITERAL_hostid);
#line 402 "pf.g"
		
		importer->clear();
		importer->setCurrentLineNumber(LT(0)->getLine());
		importer->addMessageToLog(
		QString("Error: import of 'set hostid' commands is not supported."));
		consumeUntil(NEWLINE);
		
#line 1773 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::timeout_def() {
	Tracer traceInOut(this, "timeout_def");
#line 420 "pf.g"
	std::string timeout_name, timeout_value;
#line 1785 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case 40:
		{
			match(40);
			break;
		}
		case 41:
		{
			match(41);
			break;
		}
		case 42:
		{
			match(42);
			break;
		}
		case 43:
		{
			match(43);
			break;
		}
		case 44:
		{
			match(44);
			break;
		}
		case 45:
		{
			match(45);
			break;
		}
		case 46:
		{
			match(46);
			break;
		}
		case 47:
		{
			match(47);
			break;
		}
		case 48:
		{
			match(48);
			break;
		}
		case 49:
		{
			match(49);
			break;
		}
		case 50:
		{
			match(50);
			break;
		}
		case 51:
		{
			match(51);
			break;
		}
		case 52:
		{
			match(52);
			break;
		}
		case 53:
		{
			match(53);
			break;
		}
		case LITERAL_frag:
		{
			match(LITERAL_frag);
			break;
		}
		case LITERAL_interval:
		{
			match(LITERAL_interval);
			break;
		}
		case 56:
		{
			match(56);
			break;
		}
		case 57:
		{
			match(57);
			break;
		}
		case 58:
		{
			match(58);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 461 "pf.g"
		
		timeout_name = LT(0)->getText();
		
#line 1895 "PFCfgParser.cpp"
		match(INT_CONST);
#line 465 "pf.g"
		
		timeout_value = LT(0)->getText();
		importer->timeouts.push_back(
		std::pair<std::string, std::string>(timeout_name, timeout_value));
		
#line 1903 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_3);
	}
}

void PFCfgParser::timeout_def_list() {
	Tracer traceInOut(this, "timeout_def_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		timeout_def();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_4.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case 40:
				case 41:
				case 42:
				case 43:
				case 44:
				case 45:
				case 46:
				case 47:
				case 48:
				case 49:
				case 50:
				case 51:
				case 52:
				case 53:
				case LITERAL_frag:
				case LITERAL_interval:
				case 56:
				case 57:
				case 58:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				timeout_def();
			}
			else {
				goto _loop42;
			}
			
		}
		_loop42:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::limit_def() {
	Tracer traceInOut(this, "limit_def");
#line 483 "pf.g"
	std::string limit_name, limit_value;
#line 1976 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_frags:
		{
			match(LITERAL_frags);
			break;
		}
		case LITERAL_states:
		{
			match(LITERAL_states);
			break;
		}
		case 62:
		{
			match(62);
			break;
		}
		case LITERAL_tables:
		{
			match(LITERAL_tables);
			break;
		}
		case 64:
		{
			match(64);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 496 "pf.g"
		
		limit_name = LT(0)->getText();
		
#line 2016 "PFCfgParser.cpp"
		match(INT_CONST);
#line 500 "pf.g"
		
		limit_value = LT(0)->getText();
		importer->limits.push_back(
		std::pair<std::string, std::string>(limit_name, limit_value));
		
#line 2024 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_5);
	}
}

void PFCfgParser::limit_def_list() {
	Tracer traceInOut(this, "limit_def_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		limit_def();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_6.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case LITERAL_frags:
				case LITERAL_states:
				case 62:
				case LITERAL_tables:
				case 64:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				limit_def();
			}
			else {
				goto _loop48;
			}
			
		}
		_loop48:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::skip_def() {
	Tracer traceInOut(this, "skip_def");
	
	try {      // for error handling
		switch ( LA(1)) {
		case WORD:
		{
			match(WORD);
#line 362 "pf.g"
			importer->set_skip_on.push_back(LT(0)->getText());
#line 2089 "PFCfgParser.cpp"
			break;
		}
		case OPENING_BRACE:
		{
			skip_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::skip_list() {
	Tracer traceInOut(this, "skip_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		match(WORD);
#line 371 "pf.g"
		importer->set_skip_on.push_back(LT(0)->getText());
#line 2117 "PFCfgParser.cpp"
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == WORD || LA(1) == COMMA)) {
				{ // ( ... )*
				for (;;) {
					if ((LA(1) == COMMA)) {
						match(COMMA);
					}
					else {
						goto _loop32;
					}
					
				}
				_loop32:;
				} // ( ... )*
				match(WORD);
#line 374 "pf.g"
				importer->set_skip_on.push_back(LT(0)->getText());
#line 2136 "PFCfgParser.cpp"
			}
			else {
				goto _loop33;
			}
			
		}
		_loop33:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

void PFCfgParser::rule_extended() {
	Tracer traceInOut(this, "rule_extended");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IN_WORD:
		case OUT_WORD:
		{
			direction();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case ON:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case LOG:
		case QUICK:
		case ALL:
		case USER:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case ROUTE_TO:
		case REPLY_TO:
		case DUP_TO:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case LOG:
		case QUICK:
		{
			quick_or_log();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case ON:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case ALL:
		case USER:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case ROUTE_TO:
		case REPLY_TO:
		case DUP_TO:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case ON:
		{
			intrface();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case ALL:
		case USER:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case ROUTE_TO:
		case REPLY_TO:
		case DUP_TO:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case ROUTE_TO:
		case REPLY_TO:
		case DUP_TO:
		{
			route();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case ALL:
		case USER:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case INET:
		case INET6:
		{
			address_family();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case ALL:
		case USER:
		case TO:
		case PROTO:
		case FROM:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case PROTO:
		{
			protospec();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case ALL:
		case USER:
		case TO:
		case FROM:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		if ((_tokenSet_7.member(LA(1))) && (_tokenSet_8.member(LA(2)))) {
			hosts();
		}
		else if ((_tokenSet_9.member(LA(1))) && (_tokenSet_10.member(LA(2)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		{
		switch ( LA(1)) {
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case USER:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			filteropts();
			break;
		}
		case NEWLINE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
}

void PFCfgParser::tableaddr_spec() {
	Tracer traceInOut(this, "tableaddr_spec");
#line 605 "pf.g"
	AddressSpec as;
#line 2500 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case EXLAMATION:
		{
			match(EXLAMATION);
#line 606 "pf.g"
			as.neg = true;
#line 2510 "PFCfgParser.cpp"
			break;
		}
		case WORD:
		case INT_CONST:
		case SELF:
		case IPV4:
		case NUMBER:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case WORD:
		{
			match(WORD);
#line 609 "pf.g"
			
			// interface name or domain/host name
			as.at = AddressSpec::INTERFACE_OR_HOST_NAME;
			as.address = LT(0)->getText();
			
#line 2538 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case COLON:
			{
				match(COLON);
				{
				switch ( LA(1)) {
				case NETWORK:
				{
					match(NETWORK);
#line 618 "pf.g"
					
					as.at = AddressSpec::INTERFACE_NETWORK;
					
#line 2553 "PFCfgParser.cpp"
					break;
				}
				case BROADCAST:
				{
					match(BROADCAST);
#line 623 "pf.g"
					
					as.at = AddressSpec::INTERFACE_BROADCAST;
					
#line 2563 "PFCfgParser.cpp"
					break;
				}
				case PEER:
				{
					match(PEER);
#line 628 "pf.g"
					
					importer->error_tracker->registerError(
					QString("import of 'interface:peer' is not supported."));
					
#line 2574 "PFCfgParser.cpp"
					break;
				}
				case INT_CONST:
				{
					match(INT_CONST);
#line 634 "pf.g"
					
					importer->error_tracker->registerError(
					QString("import of 'interface:0' is not supported."));
					
#line 2585 "PFCfgParser.cpp"
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				break;
			}
			case WORD:
			case COMMA:
			case CLOSING_BRACE:
			case INT_CONST:
			case EXLAMATION:
			case SELF:
			case IPV4:
			case NUMBER:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case SELF:
		{
			match(SELF);
#line 642 "pf.g"
			
			as.at = AddressSpec::SPECIAL_ADDRESS;
			as.address = "self";
			
#line 2623 "PFCfgParser.cpp"
			break;
		}
		case INT_CONST:
		case IPV4:
		case NUMBER:
		{
			{
			switch ( LA(1)) {
			case IPV4:
			{
				match(IPV4);
				break;
			}
			case NUMBER:
			{
				match(NUMBER);
				break;
			}
			case INT_CONST:
			{
				match(INT_CONST);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
#line 649 "pf.g"
			
			as.at = AddressSpec::HOST_ADDRESS;
			as.address = LT(0)->getText();
			
#line 2658 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case SLASH:
			{
				match(SLASH);
#line 655 "pf.g"
				
				as.at = AddressSpec::NETWORK_ADDRESS;
				
#line 2668 "PFCfgParser.cpp"
				{
				switch ( LA(1)) {
				case IPV4:
				{
					match(IPV4);
					break;
				}
				case INT_CONST:
				{
					match(INT_CONST);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
#line 659 "pf.g"
				
				as.netmask = LT(0)->getText(); 
				
#line 2691 "PFCfgParser.cpp"
				break;
			}
			case WORD:
			case COMMA:
			case CLOSING_BRACE:
			case INT_CONST:
			case EXLAMATION:
			case SELF:
			case IPV4:
			case NUMBER:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 664 "pf.g"
		
		importer->tmp_group.push_back(as);
		
#line 2723 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_12);
	}
}

void PFCfgParser::logging() {
	Tracer traceInOut(this, "logging");
	
	try {      // for error handling
		match(LOG);
		{
		switch ( LA(1)) {
		case OPENING_PAREN:
		{
			logopts();
			break;
		}
		case NEWLINE:
		case ON:
		case EXLAMATION:
		case MINUS:
		case ALL:
		case TO:
		case INET:
		case INET6:
		case PROTO:
		case FROM:
		case TAGGED:
		case TAG:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1043 "pf.g"
		importer->logging = true;
#line 2766 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_13);
	}
}

void PFCfgParser::intrface() {
	Tracer traceInOut(this, "intrface");
	
	try {      // for error handling
		match(ON);
		{
		switch ( LA(1)) {
		case WORD:
		case EXLAMATION:
		{
			ifspec();
			break;
		}
		case OPENING_BRACE:
		{
			interface_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_14);
	}
}

void PFCfgParser::address_family() {
	Tracer traceInOut(this, "address_family");
	
	try {      // for error handling
		switch ( LA(1)) {
		case INET:
		{
			match(INET);
			break;
		}
		case INET6:
		{
			match(INET6);
#line 1087 "pf.g"
			
			importer->address_family = LT(0)->getText();
			
#line 2822 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_15);
	}
}

void PFCfgParser::protospec() {
	Tracer traceInOut(this, "protospec");
	
	try {      // for error handling
		match(PROTO);
		proto_def();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_16);
	}
}

void PFCfgParser::hosts() {
	Tracer traceInOut(this, "hosts");
	
	try {      // for error handling
		switch ( LA(1)) {
		case ALL:
		{
			match(ALL);
#line 1130 "pf.g"
			
			importer->src_group.push_back(
			AddressSpec(AddressSpec::ANY, false, "0.0.0.0", "0.0.0.0"));
			importer->dst_group.push_back(
			AddressSpec(AddressSpec::ANY, false, "0.0.0.0", "0.0.0.0"));
			
#line 2865 "PFCfgParser.cpp"
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case MINUS:
		case OPENING_PAREN:
		case USER:
		case TO:
		case FROM:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			{
			switch ( LA(1)) {
			case FROM:
			{
				hosts_from();
				break;
			}
			case NEWLINE:
			case QUEUE:
			case LITERAL_reassemble:
			case SCRUB:
			case EXLAMATION:
			case NO:
			case MINUS:
			case OPENING_PAREN:
			case USER:
			case TO:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case TO:
			{
				hosts_to();
				break;
			}
			case NEWLINE:
			case QUEUE:
			case LITERAL_reassemble:
			case SCRUB:
			case EXLAMATION:
			case NO:
			case MINUS:
			case OPENING_PAREN:
			case USER:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_17);
	}
}

void PFCfgParser::tagged() {
	Tracer traceInOut(this, "tagged");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case EXLAMATION:
		{
			match(EXLAMATION);
#line 1689 "pf.g"
			importer->tagged_neg = true;
#line 3001 "PFCfgParser.cpp"
			break;
		}
		case TAGGED:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(TAGGED);
		match(WORD);
#line 1691 "pf.g"
		
		importer->tagged = LT(0)->getText();
		
#line 3020 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_18);
	}
}

void PFCfgParser::tag_clause() {
	Tracer traceInOut(this, "tag_clause");
	
	try {      // for error handling
		match(TAG);
		match(WORD);
#line 1698 "pf.g"
		
		importer->tag = LT(0)->getText();
		
#line 3038 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_18);
	}
}

void PFCfgParser::redirhost() {
	Tracer traceInOut(this, "redirhost");
#line 800 "pf.g"
	AddressSpec as;
#line 3050 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IPV4:
		{
			match(IPV4);
#line 803 "pf.g"
			
			as.at = AddressSpec::HOST_ADDRESS;
			as.address = LT(0)->getText();
			
#line 3063 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case SLASH:
			{
				match(SLASH);
#line 809 "pf.g"
				
				as.at = AddressSpec::NETWORK_ADDRESS;
				
#line 3073 "PFCfgParser.cpp"
				{
				switch ( LA(1)) {
				case IPV4:
				{
					match(IPV4);
					break;
				}
				case INT_CONST:
				{
					match(INT_CONST);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
#line 813 "pf.g"
				
				as.netmask = LT(0)->getText(); 
				
#line 3096 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case WORD:
			case COMMA:
			case CLOSING_BRACE:
			case IPV4:
			case STATIC_PORT:
			case OPENING_PAREN:
			case PORT:
			case BITMASK:
			case RANDOM:
			case SOURCE_HASH:
			case ROUND_ROBIN:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case OPENING_PAREN:
		{
			match(OPENING_PAREN);
			match(WORD);
#line 820 "pf.g"
			
			// interface name or domain/host name
			as.at = AddressSpec::INTERFACE_OR_HOST_NAME;
			as.address = LT(0)->getText();
			
#line 3132 "PFCfgParser.cpp"
			match(CLOSING_PAREN);
			break;
		}
		case WORD:
		{
			match(WORD);
#line 828 "pf.g"
			
			// interface name or domain/host name
			as.at = AddressSpec::INTERFACE_OR_HOST_NAME;
			as.address = LT(0)->getText();
			
#line 3145 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 834 "pf.g"
		
		importer->tmp_group.push_back(as);
		
#line 3158 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_19);
	}
}

void PFCfgParser::redirhost_list() {
	Tracer traceInOut(this, "redirhost_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		redirhost();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_20.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case WORD:
				case IPV4:
				case OPENING_PAREN:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				redirhost();
			}
			else {
				goto _loop101;
			}
			
		}
		_loop101:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_21);
	}
}

void PFCfgParser::portspec() {
	Tracer traceInOut(this, "portspec");
#line 859 "pf.g"
	PortSpec ps;
#line 3215 "PFCfgParser.cpp"
	
	try {      // for error handling
		match(PORT);
		{
		switch ( LA(1)) {
		case WORD:
		case INT_CONST:
		{
			port_def();
#line 863 "pf.g"
			
			ps.port1 = importer->tmp_port_def;
			ps.port2 = ps.port1;
			ps.port_op = "=";
			
#line 3231 "PFCfgParser.cpp"
			break;
		}
		case IPV6:
		{
			match(IPV6);
#line 872 "pf.g"
			
			ps.setFromPortRange(LT(0)->getText());
			
#line 3241 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case STAR:
			{
				match(STAR);
#line 876 "pf.g"
				ps.port2 = "65535";
#line 3249 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case STATIC_PORT:
			case BITMASK:
			case RANDOM:
			case SOURCE_HASH:
			case ROUND_ROBIN:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 879 "pf.g"
		
		importer->tmp_port_group.push_back(ps);
		
#line 3279 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_22);
	}
}

void PFCfgParser::pooltype() {
	Tracer traceInOut(this, "pooltype");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case BITMASK:
		{
			match(BITMASK);
#line 893 "pf.g"
			importer->nat_rule_opt_1 = "bitmask";
#line 3298 "PFCfgParser.cpp"
			break;
		}
		case RANDOM:
		{
			match(RANDOM);
#line 895 "pf.g"
			importer->nat_rule_opt_1 = "random";
#line 3306 "PFCfgParser.cpp"
			break;
		}
		case SOURCE_HASH:
		{
			match(SOURCE_HASH);
#line 897 "pf.g"
			importer->nat_rule_opt_1 = "source-hash";
#line 3314 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case HEX_KEY:
			{
				match(HEX_KEY);
#line 900 "pf.g"
				
				importer->error_tracker->registerError(
				QString("import of 'nat' commands with 'source-hash hex-key' "
				"option is not supported"));
				
#line 3326 "PFCfgParser.cpp"
				break;
			}
			case STRING_KEY:
			{
				match(STRING_KEY);
#line 907 "pf.g"
				
				importer->error_tracker->registerError(
				QString("import of 'nat' commands with 'source-hash string-key' "
				"option is not supported"));
				
#line 3338 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case STATIC_PORT:
			case STICKY_ADDRESS:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case ROUND_ROBIN:
		{
			match(ROUND_ROBIN);
#line 914 "pf.g"
			importer->nat_rule_opt_1 = "round-robin";
#line 3360 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case STICKY_ADDRESS:
		{
			match(STICKY_ADDRESS);
			break;
		}
		case NEWLINE:
		case STATIC_PORT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_23);
	}
}

void PFCfgParser::port_def() {
	Tracer traceInOut(this, "port_def");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case WORD:
		{
			match(WORD);
			break;
		}
		case INT_CONST:
		{
			match(INT_CONST);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1826 "pf.g"
		
		importer->tmp_port_def = LT(0)->getText();
		
#line 3420 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_24);
	}
}

void PFCfgParser::block_return() {
	Tracer traceInOut(this, "block_return");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case DROP:
		{
			match(DROP);
#line 976 "pf.g"
			importer->block_action_params.push_back("drop");
#line 3439 "PFCfgParser.cpp"
			break;
		}
		case RETURN:
		{
			match(RETURN);
#line 978 "pf.g"
			importer->block_action_params.push_back("return");
#line 3447 "PFCfgParser.cpp"
			break;
		}
		case RETURN_RST:
		{
			match(RETURN_RST);
#line 980 "pf.g"
			importer->block_action_params.push_back("return-rst");
#line 3455 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case TTL:
			{
				match(TTL);
				match(INT_CONST);
#line 983 "pf.g"
				
				importer->error_tracker->registerError(
				QString("Import of \"block return-rst ttl number\" is not supported. "));
				
#line 3467 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case QUEUE:
			case ON:
			case LITERAL_reassemble:
			case SCRUB:
			case EXLAMATION:
			case NO:
			case OPENING_PAREN:
			case IN_WORD:
			case OUT_WORD:
			case LOG:
			case QUICK:
			case ALL:
			case USER:
			case TO:
			case INET:
			case INET6:
			case PROTO:
			case FROM:
			case ROUTE_TO:
			case REPLY_TO:
			case DUP_TO:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case RETURN_ICMP:
		{
			match(RETURN_ICMP);
#line 989 "pf.g"
			importer->block_action_params.push_back("return-icmp");
#line 3523 "PFCfgParser.cpp"
			{
			if ((LA(1) == OPENING_PAREN) && (_tokenSet_25.member(LA(2)))) {
				match(OPENING_PAREN);
				{
				switch ( LA(1)) {
				case 176:
				case 177:
				case 178:
				case 179:
				case LITERAL_needfrag:
				case LITERAL_srcfail:
				case 182:
				case 183:
				case LITERAL_isolate:
				case 185:
				case 186:
				case 187:
				case 188:
				case 189:
				case 190:
				case 191:
				case 192:
				case 193:
				case 194:
				case 195:
				case 196:
				case 197:
				case LITERAL_transit:
				case LITERAL_reassemb:
				case LITERAL_badhead:
				case LITERAL_optmiss:
				case LITERAL_badlen:
				case 203:
				case 204:
				case 205:
				{
					icmp_code_by_name();
					break;
				}
				case INT_CONST:
				{
					match(INT_CONST);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
#line 993 "pf.g"
				importer->block_action_params.push_back(LT(0)->getText());
#line 3576 "PFCfgParser.cpp"
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					{
					switch ( LA(1)) {
					case 176:
					case 177:
					case 178:
					case 179:
					case LITERAL_needfrag:
					case LITERAL_srcfail:
					case 182:
					case 183:
					case LITERAL_isolate:
					case 185:
					case 186:
					case 187:
					case 188:
					case 189:
					case 190:
					case 191:
					case 192:
					case 193:
					case 194:
					case 195:
					case 196:
					case 197:
					case LITERAL_transit:
					case LITERAL_reassemb:
					case LITERAL_badhead:
					case LITERAL_optmiss:
					case LITERAL_badlen:
					case 203:
					case 204:
					case 205:
					{
						icmp_code_by_name();
						break;
					}
					case INT_CONST:
					{
						match(INT_CONST);
						break;
					}
					default:
					{
						throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
					}
					}
					}
#line 997 "pf.g"
					
					importer->error_tracker->registerError(
					QString("Import of \"block return-icmp (icmp_code, icmp6_code)\" is not supported"));
					
#line 3634 "PFCfgParser.cpp"
					break;
				}
				case CLOSING_PAREN:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				match(CLOSING_PAREN);
			}
			else if ((_tokenSet_26.member(LA(1))) && (_tokenSet_27.member(LA(2)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			break;
		}
		case RETURN_ICMP6:
		{
			match(RETURN_ICMP6);
#line 1006 "pf.g"
			
			importer->error_tracker->registerError(
			QString("Import of \"block return-icmp6\" is not supported"));
			importer->block_action_params.push_back("return-icmp");
			
#line 3667 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_26);
	}
}

void PFCfgParser::icmp_code_by_name() {
	Tracer traceInOut(this, "icmp_code_by_name");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case 176:
		{
			match(176);
			break;
		}
		case 177:
		{
			match(177);
			break;
		}
		case 178:
		{
			match(178);
			break;
		}
		case 179:
		{
			match(179);
			break;
		}
		case LITERAL_needfrag:
		{
			match(LITERAL_needfrag);
			break;
		}
		case LITERAL_srcfail:
		{
			match(LITERAL_srcfail);
			break;
		}
		case 182:
		{
			match(182);
			break;
		}
		case 183:
		{
			match(183);
			break;
		}
		case LITERAL_isolate:
		{
			match(LITERAL_isolate);
			break;
		}
		case 185:
		{
			match(185);
			break;
		}
		case 186:
		{
			match(186);
			break;
		}
		case 187:
		{
			match(187);
			break;
		}
		case 188:
		{
			match(188);
			break;
		}
		case 189:
		{
			match(189);
			break;
		}
		case 190:
		{
			match(190);
			break;
		}
		case 191:
		{
			match(191);
			break;
		}
		case 192:
		{
			match(192);
			break;
		}
		case 193:
		{
			match(193);
			break;
		}
		case 194:
		{
			match(194);
			break;
		}
		case 195:
		{
			match(195);
			break;
		}
		case 196:
		{
			match(196);
			break;
		}
		case 197:
		{
			match(197);
			break;
		}
		case LITERAL_transit:
		{
			match(LITERAL_transit);
			break;
		}
		case LITERAL_reassemb:
		{
			match(LITERAL_reassemb);
			break;
		}
		case LITERAL_badhead:
		{
			match(LITERAL_badhead);
			break;
		}
		case LITERAL_optmiss:
		{
			match(LITERAL_optmiss);
			break;
		}
		case LITERAL_badlen:
		{
			match(LITERAL_badlen);
			break;
		}
		case 203:
		{
			match(203);
			break;
		}
		case 204:
		{
			match(204);
			break;
		}
		case 205:
		{
			match(205);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_28);
	}
}

void PFCfgParser::direction() {
	Tracer traceInOut(this, "direction");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IN_WORD:
		{
			match(IN_WORD);
			break;
		}
		case OUT_WORD:
		{
			match(OUT_WORD);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1026 "pf.g"
		
		importer->direction = LT(0)->getText();
		
#line 3878 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_29);
	}
}

void PFCfgParser::quick_or_log() {
	Tracer traceInOut(this, "quick_or_log");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LOG:
		{
			match(LOG);
			{
			if ((LA(1) == OPENING_PAREN) && ((LA(2) >= ALL && LA(2) <= TO))) {
				logopts();
			}
			else if ((_tokenSet_30.member(LA(1))) && (_tokenSet_31.member(LA(2)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
#line 1034 "pf.g"
			importer->logging = true;
#line 3908 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case QUICK:
			{
				match(QUICK);
#line 1035 "pf.g"
				importer->quick = true;
#line 3916 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case QUEUE:
			case ON:
			case LITERAL_reassemble:
			case SCRUB:
			case EXLAMATION:
			case NO:
			case OPENING_PAREN:
			case ALL:
			case USER:
			case TO:
			case INET:
			case INET6:
			case PROTO:
			case FROM:
			case ROUTE_TO:
			case REPLY_TO:
			case DUP_TO:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case QUICK:
		{
			match(QUICK);
#line 1037 "pf.g"
			importer->quick = true;
#line 3968 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case LOG:
			{
				match(LOG);
				{
				if ((LA(1) == OPENING_PAREN) && ((LA(2) >= ALL && LA(2) <= TO))) {
					logopts();
				}
				else if ((_tokenSet_32.member(LA(1))) && (_tokenSet_33.member(LA(2)))) {
				}
				else {
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				
				}
#line 1038 "pf.g"
				importer->logging = true;
#line 3987 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case QUEUE:
			case ON:
			case LITERAL_reassemble:
			case SCRUB:
			case EXLAMATION:
			case NO:
			case OPENING_PAREN:
			case ALL:
			case USER:
			case TO:
			case INET:
			case INET6:
			case PROTO:
			case FROM:
			case ROUTE_TO:
			case REPLY_TO:
			case DUP_TO:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_32);
	}
}

void PFCfgParser::route() {
	Tracer traceInOut(this, "route");
	
	try {      // for error handling
		switch ( LA(1)) {
		case ROUTE_TO:
		{
			route_to();
			break;
		}
		case REPLY_TO:
		{
			reply_to();
			break;
		}
		case DUP_TO:
		{
			dup_to();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
}

void PFCfgParser::filteropts() {
	Tracer traceInOut(this, "filteropts");
	
	try {      // for error handling
		filteropt();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_35.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case QUEUE:
				case LITERAL_reassemble:
				case SCRUB:
				case EXLAMATION:
				case NO:
				case OPENING_PAREN:
				case USER:
				case GROUP:
				case LITERAL_fragment:
				case 145:
				case 146:
				case 147:
				case 148:
				case FLAGS:
				case ICMP_TYPE:
				case ICMP6_TYPE:
				case TAGGED:
				case TAG:
				case KEEP:
				case MODULATE:
				case SYNPROXY:
				case LABEL:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				filteropt();
			}
			else {
				goto _loop202;
			}
			
		}
		_loop202:;
		} // ( ... )*
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
}

void PFCfgParser::logopts() {
	Tracer traceInOut(this, "logopts");
	
	try {      // for error handling
		match(OPENING_PAREN);
		logopt();
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == COMMA)) {
				match(COMMA);
#line 1050 "pf.g"
				importer->logopts += ",";
#line 4153 "PFCfgParser.cpp"
				logopt();
			}
			else {
				goto _loop141;
			}
			
		}
		_loop141:;
		} // ( ... )*
		match(CLOSING_PAREN);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_36);
	}
}

void PFCfgParser::logopt() {
	Tracer traceInOut(this, "logopt");
	
	try {      // for error handling
		switch ( LA(1)) {
		case ALL:
		{
			match(ALL);
			break;
		}
		case USER:
		{
			match(USER);
			break;
		}
		case TO:
		{
			match(TO);
			match(WORD);
#line 1057 "pf.g"
			
			importer->logopts += LT(0)->getText();
			
#line 4194 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_37);
	}
}

void PFCfgParser::ifspec() {
	Tracer traceInOut(this, "ifspec");
#line 1065 "pf.g"
	InterfaceSpec is;
#line 4213 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case EXLAMATION:
		{
			match(EXLAMATION);
#line 1066 "pf.g"
			is.neg = true;
#line 4223 "PFCfgParser.cpp"
			break;
		}
		case WORD:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(WORD);
#line 1068 "pf.g"
		
		is.name = LT(0)->getText();
		importer->iface_group.push_back(is);
		importer->newInterface(is.name);
		
#line 4243 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_38);
	}
}

void PFCfgParser::interface_list() {
	Tracer traceInOut(this, "interface_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		ifspec();
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == WORD || LA(1) == COMMA || LA(1) == EXLAMATION)) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case WORD:
				case EXLAMATION:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				ifspec();
			}
			else {
				goto _loop150;
			}
			
		}
		_loop150:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_14);
	}
}

void PFCfgParser::proto_def() {
	Tracer traceInOut(this, "proto_def");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IP:
		case ICMP:
		case IGMP:
		case TCP:
		case UDP:
		case RDP:
		case RSVP:
		case GRE:
		case ESP:
		case AH:
		case EIGRP:
		case OSPF:
		case IPIP:
		case VRRP:
		case L2TP:
		case ISIS:
		{
			proto_name();
			break;
		}
		case INT_CONST:
		{
			proto_number();
			break;
		}
		case OPENING_BRACE:
		{
			proto_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_39);
	}
}

void PFCfgParser::proto_name() {
	Tracer traceInOut(this, "proto_name");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case IP:
		{
			match(IP);
			break;
		}
		case ICMP:
		{
			match(ICMP);
			break;
		}
		case IGMP:
		{
			match(IGMP);
			break;
		}
		case TCP:
		{
			match(TCP);
			break;
		}
		case UDP:
		{
			match(UDP);
			break;
		}
		case RDP:
		{
			match(RDP);
			break;
		}
		case RSVP:
		{
			match(RSVP);
			break;
		}
		case GRE:
		{
			match(GRE);
			break;
		}
		case ESP:
		{
			match(ESP);
			break;
		}
		case AH:
		{
			match(AH);
			break;
		}
		case EIGRP:
		{
			match(EIGRP);
			break;
		}
		case OSPF:
		{
			match(OSPF);
			break;
		}
		case IPIP:
		{
			match(IPIP);
			break;
		}
		case VRRP:
		{
			match(VRRP);
			break;
		}
		case L2TP:
		{
			match(L2TP);
			break;
		}
		case ISIS:
		{
			match(ISIS);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1107 "pf.g"
		
		importer->proto_list.push_back(LT(0)->getText());
		
#line 4440 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_39);
	}
}

void PFCfgParser::proto_number() {
	Tracer traceInOut(this, "proto_number");
	
	try {      // for error handling
		match(INT_CONST);
#line 1113 "pf.g"
		
		importer->proto_list.push_back(LT(0)->getText());
		
#line 4457 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_39);
	}
}

void PFCfgParser::proto_list() {
	Tracer traceInOut(this, "proto_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		proto_def();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_40.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case OPENING_BRACE:
				case INT_CONST:
				case IP:
				case ICMP:
				case IGMP:
				case TCP:
				case UDP:
				case RDP:
				case RSVP:
				case GRE:
				case ESP:
				case AH:
				case EIGRP:
				case OSPF:
				case IPIP:
				case VRRP:
				case L2TP:
				case ISIS:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				proto_def();
			}
			else {
				goto _loop161;
			}
			
		}
		_loop161:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_39);
	}
}

void PFCfgParser::hosts_from() {
	Tracer traceInOut(this, "hosts_from");
	
	try {      // for error handling
		match(FROM);
		src_hosts_part();
		{
		switch ( LA(1)) {
		case PORT:
		{
			src_port_part();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case MINUS:
		case OPENING_PAREN:
		case USER:
		case TO:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_41);
	}
}

void PFCfgParser::hosts_to() {
	Tracer traceInOut(this, "hosts_to");
	
	try {      // for error handling
		match(TO);
		dst_hosts_part();
		{
		switch ( LA(1)) {
		case PORT:
		{
			dst_port_part();
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_reassemble:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case MINUS:
		case OPENING_PAREN:
		case USER:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_17);
	}
}

void PFCfgParser::src_hosts_part() {
	Tracer traceInOut(this, "src_hosts_part");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case WORD:
		case OPENING_BRACE:
		case LESS_THAN:
		case EXLAMATION:
		case SELF:
		case IPV4:
		case OPENING_PAREN:
		case IPV6:
		case ANY:
		case NO_ROUTE:
		{
			common_hosts_part();
			break;
		}
		case URPF_FAILED:
		{
			match(URPF_FAILED);
#line 1153 "pf.g"
			
			importer->tmp_group.push_back(
			AddressSpec(AddressSpec::SPECIAL_ADDRESS, false,
			"urpf-failed", ""));
			
#line 4661 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1159 "pf.g"
		
		importer->src_neg = importer->tmp_neg;
		importer->src_group.splice(importer->src_group.begin(),
		importer->tmp_group);
		
#line 4676 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_42);
	}
}

void PFCfgParser::src_port_part() {
	Tracer traceInOut(this, "src_port_part");
	
	try {      // for error handling
		match(PORT);
		{
		switch ( LA(1)) {
		case WORD:
		case EQUAL:
		case INT_CONST:
		case LESS_THAN:
		case GREATER_THAN:
		case EXLAMATION:
		case IPV6:
		{
			port_op();
			break;
		}
		case OPENING_BRACE:
		{
			port_op_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1747 "pf.g"
		
		importer->src_port_group.splice(importer->src_port_group.begin(),
		importer->tmp_port_group);
		
#line 4718 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_41);
	}
}

void PFCfgParser::dst_hosts_part() {
	Tracer traceInOut(this, "dst_hosts_part");
	
	try {      // for error handling
		common_hosts_part();
#line 1168 "pf.g"
		
		importer->dst_neg = importer->tmp_neg;
		importer->dst_group.splice(importer->dst_group.begin(),
		importer->tmp_group);
		
#line 4737 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_43);
	}
}

void PFCfgParser::dst_port_part() {
	Tracer traceInOut(this, "dst_port_part");
	
	try {      // for error handling
		match(PORT);
		{
		switch ( LA(1)) {
		case WORD:
		case EQUAL:
		case INT_CONST:
		case LESS_THAN:
		case GREATER_THAN:
		case EXLAMATION:
		case IPV6:
		{
			port_op();
			break;
		}
		case OPENING_BRACE:
		{
			port_op_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1760 "pf.g"
		
		importer->dst_port_group.splice(importer->dst_port_group.begin(),
		importer->tmp_port_group);
		
#line 4779 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_17);
	}
}

void PFCfgParser::common_hosts_part() {
	Tracer traceInOut(this, "common_hosts_part");
	
	try {      // for error handling
		switch ( LA(1)) {
		case ANY:
		{
			match(ANY);
#line 1177 "pf.g"
			
			importer->tmp_group.push_back(
			AddressSpec(AddressSpec::ANY, false, "0.0.0.0", "0.0.0.0"));
			
#line 4800 "PFCfgParser.cpp"
			break;
		}
		case NO_ROUTE:
		{
			match(NO_ROUTE);
#line 1183 "pf.g"
			
			importer->tmp_group.push_back(
			AddressSpec(AddressSpec::SPECIAL_ADDRESS, false, "no-route", ""));
			
#line 4811 "PFCfgParser.cpp"
			break;
		}
		case WORD:
		case LESS_THAN:
		case EXLAMATION:
		case SELF:
		case IPV4:
		case OPENING_PAREN:
		case IPV6:
		{
			host();
			break;
		}
		case OPENING_BRACE:
		{
			host_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_42);
	}
}

void PFCfgParser::host() {
	Tracer traceInOut(this, "host");
	ANTLR_USE_NAMESPACE(antlr)RefToken  tn = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefToken  in = ANTLR_USE_NAMESPACE(antlr)nullToken;
#line 1193 "pf.g"
	AddressSpec as;
#line 4848 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case EXLAMATION:
		{
			match(EXLAMATION);
#line 1194 "pf.g"
			as.neg = true;
#line 4858 "PFCfgParser.cpp"
			break;
		}
		case WORD:
		case LESS_THAN:
		case SELF:
		case IPV4:
		case OPENING_PAREN:
		case IPV6:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case WORD:
		{
			match(WORD);
#line 1197 "pf.g"
			
			// interface name or domain/host name
			as.at = AddressSpec::INTERFACE_OR_HOST_NAME;
			as.address = LT(0)->getText();
			
#line 4887 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case COLON:
			{
				match(COLON);
				{
				switch ( LA(1)) {
				case NETWORK:
				{
					match(NETWORK);
#line 1206 "pf.g"
					
					as.at = AddressSpec::INTERFACE_NETWORK;
					
#line 4902 "PFCfgParser.cpp"
					break;
				}
				case BROADCAST:
				{
					match(BROADCAST);
#line 1211 "pf.g"
					
					as.at = AddressSpec::INTERFACE_BROADCAST;
					
#line 4912 "PFCfgParser.cpp"
					break;
				}
				case PEER:
				{
					match(PEER);
#line 1216 "pf.g"
					
					importer->error_tracker->registerError(
					QString("import of 'interface:peer' is not supported."));
					
#line 4923 "PFCfgParser.cpp"
					break;
				}
				case INT_CONST:
				{
					match(INT_CONST);
#line 1222 "pf.g"
					
					importer->error_tracker->registerError(
					QString("import of 'interface:0' is not supported."));
					
#line 4934 "PFCfgParser.cpp"
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				break;
			}
			case NEWLINE:
			case WORD:
			case QUEUE:
			case COMMA:
			case CLOSING_BRACE:
			case LITERAL_reassemble:
			case SCRUB:
			case LESS_THAN:
			case EXLAMATION:
			case SELF:
			case IPV4:
			case NO:
			case MINUS:
			case OPENING_PAREN:
			case PORT:
			case IPV6:
			case USER:
			case TO:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case SELF:
		{
			match(SELF);
#line 1230 "pf.g"
			
			as.at = AddressSpec::SPECIAL_ADDRESS;
			as.address = "self";
			
#line 4997 "PFCfgParser.cpp"
			break;
		}
		case IPV6:
		{
			match(IPV6);
#line 1236 "pf.g"
			
			importer->error_tracker->registerError(
			QString("IPv6 import is not supported. "));
			consumeUntil(NEWLINE);
			
#line 5009 "PFCfgParser.cpp"
			break;
		}
		case IPV4:
		{
			match(IPV4);
#line 1243 "pf.g"
			
			as.at = AddressSpec::HOST_ADDRESS;
			as.address = LT(0)->getText();
			
#line 5020 "PFCfgParser.cpp"
			{
			switch ( LA(1)) {
			case SLASH:
			{
				match(SLASH);
#line 1249 "pf.g"
				
				as.at = AddressSpec::NETWORK_ADDRESS;
				
#line 5030 "PFCfgParser.cpp"
				{
				switch ( LA(1)) {
				case IPV4:
				{
					match(IPV4);
					break;
				}
				case INT_CONST:
				{
					match(INT_CONST);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
#line 1253 "pf.g"
				
				as.netmask = LT(0)->getText(); 
				
#line 5053 "PFCfgParser.cpp"
				break;
			}
			case NEWLINE:
			case WORD:
			case QUEUE:
			case COMMA:
			case CLOSING_BRACE:
			case LITERAL_reassemble:
			case SCRUB:
			case LESS_THAN:
			case EXLAMATION:
			case SELF:
			case IPV4:
			case NO:
			case MINUS:
			case OPENING_PAREN:
			case PORT:
			case IPV6:
			case USER:
			case TO:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case LESS_THAN:
		{
			match(LESS_THAN);
			tn = LT(1);
			match(WORD);
			match(GREATER_THAN);
#line 1259 "pf.g"
			
			as.at = AddressSpec::TABLE;
			as.address = tn->getText();
			
#line 5111 "PFCfgParser.cpp"
			break;
		}
		case OPENING_PAREN:
		{
			match(OPENING_PAREN);
			in = LT(1);
			match(WORD);
			match(CLOSING_PAREN);
#line 1265 "pf.g"
			
			// interface name or domain/host name
			as.at = AddressSpec::INTERFACE_OR_HOST_NAME;
			as.address = in->getText();
			
#line 5126 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1271 "pf.g"
		
		importer->tmp_group.push_back(as);
		
#line 5139 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_44);
	}
}

void PFCfgParser::host_list() {
	Tracer traceInOut(this, "host_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		host();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_45.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case WORD:
				case LESS_THAN:
				case EXLAMATION:
				case SELF:
				case IPV4:
				case OPENING_PAREN:
				case IPV6:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				host();
			}
			else {
				goto _loop183;
			}
			
		}
		_loop183:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_42);
	}
}

void PFCfgParser::route_to() {
	Tracer traceInOut(this, "route_to");
	
	try {      // for error handling
		match(ROUTE_TO);
		{
		switch ( LA(1)) {
		case OPENING_PAREN:
		{
			routehost();
			break;
		}
		case OPENING_BRACE:
		{
			routehost_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1293 "pf.g"
		
		importer->route_type = PFImporter::ROUTE_TO;
		
#line 5223 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
}

void PFCfgParser::reply_to() {
	Tracer traceInOut(this, "reply_to");
	
	try {      // for error handling
		match(REPLY_TO);
		{
		switch ( LA(1)) {
		case OPENING_PAREN:
		{
			routehost();
			break;
		}
		case OPENING_BRACE:
		{
			routehost_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1300 "pf.g"
		
		importer->route_type = PFImporter::REPLY_TO;
		
#line 5258 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
}

void PFCfgParser::dup_to() {
	Tracer traceInOut(this, "dup_to");
	
	try {      // for error handling
		match(DUP_TO);
		{
		switch ( LA(1)) {
		case OPENING_PAREN:
		{
			routehost();
			break;
		}
		case OPENING_BRACE:
		{
			routehost_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1307 "pf.g"
		
		importer->route_type = PFImporter::DUP_TO;
		
#line 5293 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
}

void PFCfgParser::routehost() {
	Tracer traceInOut(this, "routehost");
	ANTLR_USE_NAMESPACE(antlr)RefToken  h = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefToken  v6 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefToken  nm = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefToken  nm6 = ANTLR_USE_NAMESPACE(antlr)nullToken;
#line 1312 "pf.g"
	RouteSpec rs;
#line 5309 "PFCfgParser.cpp"
	
	try {      // for error handling
		match(OPENING_PAREN);
		match(WORD);
#line 1314 "pf.g"
		rs.iface = LT(0)->getText();
#line 5316 "PFCfgParser.cpp"
		{
		switch ( LA(1)) {
		case IPV4:
		{
			h = LT(1);
			match(IPV4);
			break;
		}
		case IPV6:
		{
			v6 = LT(1);
			match(IPV6);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case SLASH:
		{
			match(SLASH);
			{
			switch ( LA(1)) {
			case IPV4:
			{
				nm = LT(1);
				match(IPV4);
				break;
			}
			case INT_CONST:
			{
				nm6 = LT(1);
				match(INT_CONST);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case CLOSING_PAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1316 "pf.g"
		
		if (v6)
		{
		importer->error_tracker->registerError(
		QString("IPv6 import is not supported. "));
		consumeUntil(NEWLINE);
		} else
		{
		if (h) rs.address = h->getText();
		if (nm) rs.netmask = nm->getText();
		importer->route_group.push_back(rs);
		}
		
#line 5388 "PFCfgParser.cpp"
		match(CLOSING_PAREN);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_46);
	}
}

void PFCfgParser::routehost_list() {
	Tracer traceInOut(this, "routehost_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		routehost();
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == COMMA || LA(1) == OPENING_PAREN)) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case OPENING_PAREN:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				routehost();
			}
			else {
				goto _loop198;
			}
			
		}
		_loop198:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_34);
	}
}

void PFCfgParser::filteropt() {
	Tracer traceInOut(this, "filteropt");
	
	try {      // for error handling
		switch ( LA(1)) {
		case USER:
		{
			user_match();
			break;
		}
		case GROUP:
		{
			group_match();
			break;
		}
		case FLAGS:
		{
			tcp_flags();
			break;
		}
		case ICMP_TYPE:
		{
			icmp_type();
			break;
		}
		case ICMP6_TYPE:
		{
			icmp6_type();
			break;
		}
		case EXLAMATION:
		case TAGGED:
		{
			tagged();
			break;
		}
		case TAG:
		{
			tag_clause();
			break;
		}
		case NO:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		{
			state();
			break;
		}
		case QUEUE:
		{
			queue();
			break;
		}
		case LABEL:
		{
			label();
			break;
		}
		case SCRUB:
		{
			match_rule_scrub_options();
			break;
		}
		case LITERAL_reassemble:
		case OPENING_PAREN:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		{
			scrub_options();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::user_match() {
	Tracer traceInOut(this, "user_match");
	
	try {      // for error handling
		match(USER);
		{
		switch ( LA(1)) {
		case WORD:
		case EQUAL:
		case INT_CONST:
		case LESS_THAN:
		case GREATER_THAN:
		case EXLAMATION:
		{
			user_group_op();
			break;
		}
		case OPENING_BRACE:
		{
			user_group_op_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1381 "pf.g"
		
		importer->addMessageToLog(
		QString("Error: import of 'user' match is not supported."));
		
#line 5560 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::group_match() {
	Tracer traceInOut(this, "group_match");
	
	try {      // for error handling
		match(GROUP);
		{
		switch ( LA(1)) {
		case WORD:
		case EQUAL:
		case INT_CONST:
		case LESS_THAN:
		case GREATER_THAN:
		case EXLAMATION:
		{
			user_group_op();
			break;
		}
		case OPENING_BRACE:
		{
			user_group_op_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1390 "pf.g"
		
		importer->addMessageToLog(
		QString("Error: import of 'group' match is not supported."));
		
#line 5601 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::tcp_flags() {
	Tracer traceInOut(this, "tcp_flags");
	ANTLR_USE_NAMESPACE(antlr)RefToken  check = ANTLR_USE_NAMESPACE(antlr)nullToken;
	ANTLR_USE_NAMESPACE(antlr)RefToken  mask = ANTLR_USE_NAMESPACE(antlr)nullToken;
	
	try {      // for error handling
		match(FLAGS);
		{
		switch ( LA(1)) {
		case ANY:
		{
			match(ANY);
#line 1500 "pf.g"
			
			importer->flags_check = "none";
			importer->flags_mask = "none";
			
#line 5626 "PFCfgParser.cpp"
			break;
		}
		case WORD:
		case SLASH:
		{
			{
			switch ( LA(1)) {
			case WORD:
			{
				check = LT(1);
				match(WORD);
				break;
			}
			case SLASH:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(SLASH);
			{
			switch ( LA(1)) {
			case WORD:
			{
				mask = LT(1);
				match(WORD);
				break;
			}
			case NEWLINE:
			case QUEUE:
			case COMMA:
			case LITERAL_reassemble:
			case SCRUB:
			case EXLAMATION:
			case NO:
			case OPENING_PAREN:
			case USER:
			case GROUP:
			case LITERAL_fragment:
			case 145:
			case 146:
			case 147:
			case 148:
			case FLAGS:
			case ICMP_TYPE:
			case ICMP6_TYPE:
			case TAGGED:
			case TAG:
			case KEEP:
			case MODULATE:
			case SYNPROXY:
			case LABEL:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
#line 1506 "pf.g"
			
			if (check)
			importer->flags_check = check->getText();
			else
			importer->flags_check = "any";
			if (mask)
			importer->flags_mask = mask->getText();
			else
			importer->flags_mask = "all";
			
#line 5703 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::icmp_type() {
	Tracer traceInOut(this, "icmp_type");
	
	try {      // for error handling
		match(ICMP_TYPE);
		{
		switch ( LA(1)) {
		case LITERAL_skip:
		case INT_CONST:
		case LITERAL_echorep:
		case LITERAL_unreach:
		case LITERAL_squench:
		case LITERAL_redir:
		case LITERAL_althost:
		case LITERAL_echoreq:
		case LITERAL_routeradv:
		case LITERAL_routersol:
		case LITERAL_timex:
		case LITERAL_paramprob:
		case LITERAL_timereq:
		case LITERAL_timerep:
		case LITERAL_inforeq:
		case LITERAL_inforep:
		case LITERAL_maskreq:
		case LITERAL_maskrep:
		case LITERAL_trace:
		case LITERAL_dataconv:
		case LITERAL_mobredir:
		case 171:
		case 172:
		case LITERAL_mobregreq:
		case LITERAL_mobregrep:
		case LITERAL_photuris:
		{
			icmp_type_code();
			break;
		}
		case OPENING_BRACE:
		{
			icmp_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::icmp6_type() {
	Tracer traceInOut(this, "icmp6_type");
	
	try {      // for error handling
		match(ICMP6_TYPE);
#line 1681 "pf.g"
		
		importer->error_tracker->registerError(
		QString("ICMP6 import is not supported. "));
		consumeUntil(NEWLINE);
		
#line 5785 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::state() {
	Tracer traceInOut(this, "state");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case NO:
		{
			match(NO);
			break;
		}
		case KEEP:
		{
			match(KEEP);
			break;
		}
		case MODULATE:
		{
			match(MODULATE);
			break;
		}
		case SYNPROXY:
		{
			match(SYNPROXY);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1713 "pf.g"
		
		importer->state_op = LT(0)->getText();
		
#line 5829 "PFCfgParser.cpp"
		match(STATE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::queue() {
	Tracer traceInOut(this, "queue");
	
	try {      // for error handling
		match(QUEUE);
		{
		switch ( LA(1)) {
		case WORD:
		{
			match(WORD);
#line 1722 "pf.g"
			importer->queue += LT(0)->getText();
#line 5850 "PFCfgParser.cpp"
			break;
		}
		case OPENING_PAREN:
		{
			match(OPENING_PAREN);
			match(WORD);
#line 1725 "pf.g"
			importer->queue += LT(0)->getText();
#line 5859 "PFCfgParser.cpp"
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == COMMA)) {
					match(COMMA);
#line 1727 "pf.g"
					importer->queue += ",";
#line 5866 "PFCfgParser.cpp"
					match(WORD);
#line 1728 "pf.g"
					importer->queue += LT(0)->getText();
#line 5870 "PFCfgParser.cpp"
				}
				else {
					goto _loop255;
				}
				
			}
			_loop255:;
			} // ( ... )*
			match(CLOSING_PAREN);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::label() {
	Tracer traceInOut(this, "label");
	
	try {      // for error handling
		match(LABEL);
		match(STRING);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::match_rule_scrub_options() {
	Tracer traceInOut(this, "match_rule_scrub_options");
	
	try {      // for error handling
		match(SCRUB);
		scrub_options();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::scrub_options() {
	Tracer traceInOut(this, "scrub_options");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_reassemble:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		{
			scrub_option();
			break;
		}
		case OPENING_PAREN:
		{
			scrub_option_list();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::user_group_op() {
	Tracer traceInOut(this, "user_group_op");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case EQUAL:
		case LESS_THAN:
		case GREATER_THAN:
		case EXLAMATION:
		{
			unary_op();
			{
			switch ( LA(1)) {
			case WORD:
			{
				match(WORD);
				break;
			}
			case INT_CONST:
			{
				match(INT_CONST);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case WORD:
		case INT_CONST:
		{
			{
			switch ( LA(1)) {
			case WORD:
			{
				match(WORD);
				break;
			}
			case INT_CONST:
			{
				match(INT_CONST);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			if ((LA(1) == LESS_THAN || LA(1) == GREATER_THAN || LA(1) == COLON) && (_tokenSet_48.member(LA(2)))) {
				binary_op();
				{
				switch ( LA(1)) {
				case WORD:
				{
					match(WORD);
					break;
				}
				case INT_CONST:
				{
					match(INT_CONST);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
			}
			else if ((_tokenSet_49.member(LA(1))) && (_tokenSet_50.member(LA(2)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_49);
	}
}

void PFCfgParser::user_group_op_list() {
	Tracer traceInOut(this, "user_group_op_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		user_group_op();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_51.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case WORD:
				case EQUAL:
				case INT_CONST:
				case LESS_THAN:
				case GREATER_THAN:
				case EXLAMATION:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				user_group_op();
			}
			else {
				goto _loop217;
			}
			
		}
		_loop217:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::unary_op() {
	Tracer traceInOut(this, "unary_op");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case EQUAL:
		{
			match(EQUAL);
#line 1768 "pf.g"
			importer->tmp_port_op = "=";
#line 6111 "PFCfgParser.cpp"
			break;
		}
		case EXLAMATION:
		{
			match(EXLAMATION);
			match(EQUAL);
#line 1770 "pf.g"
			importer->tmp_port_op = "!=";
#line 6120 "PFCfgParser.cpp"
			break;
		}
		default:
			if ((LA(1) == LESS_THAN) && (LA(2) == WORD || LA(2) == INT_CONST)) {
				match(LESS_THAN);
#line 1772 "pf.g"
				importer->tmp_port_op = "<";
#line 6128 "PFCfgParser.cpp"
			}
			else if ((LA(1) == LESS_THAN) && (LA(2) == EQUAL)) {
				match(LESS_THAN);
				match(EQUAL);
#line 1774 "pf.g"
				importer->tmp_port_op = "<=";
#line 6135 "PFCfgParser.cpp"
			}
			else if ((LA(1) == GREATER_THAN) && (LA(2) == WORD || LA(2) == INT_CONST)) {
				match(GREATER_THAN);
#line 1776 "pf.g"
				importer->tmp_port_op = ">";
#line 6141 "PFCfgParser.cpp"
			}
			else if ((LA(1) == GREATER_THAN) && (LA(2) == EQUAL)) {
				match(GREATER_THAN);
				match(EQUAL);
#line 1778 "pf.g"
				importer->tmp_port_op = ">=";
#line 6148 "PFCfgParser.cpp"
			}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_52);
	}
}

void PFCfgParser::binary_op() {
	Tracer traceInOut(this, "binary_op");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LESS_THAN:
		{
			match(LESS_THAN);
			match(GREATER_THAN);
#line 1784 "pf.g"
			importer->tmp_port_op = "<>";
#line 6174 "PFCfgParser.cpp"
			break;
		}
		case GREATER_THAN:
		{
			match(GREATER_THAN);
			match(LESS_THAN);
#line 1786 "pf.g"
			importer->tmp_port_op = "><";
#line 6183 "PFCfgParser.cpp"
			break;
		}
		case COLON:
		{
			match(COLON);
#line 1788 "pf.g"
			importer->tmp_port_op = ":";
#line 6191 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_52);
	}
}

void PFCfgParser::scrub_option() {
	Tracer traceInOut(this, "scrub_option");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_fragment:
		{
			match(LITERAL_fragment);
			{
			switch ( LA(1)) {
			case LITERAL_reassemble:
			{
				match(LITERAL_reassemble);
				break;
			}
			case LITERAL_crop:
			{
				match(LITERAL_crop);
				break;
			}
			case 144:
			{
				match(144);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
#line 1452 "pf.g"
			
			importer->scrub_options.push_back(
			str_tuple("fragment", LT(0)->getText()));
			importer->scrub_rule = true;
			
#line 6245 "PFCfgParser.cpp"
			break;
		}
		case LITERAL_reassemble:
		{
			match(LITERAL_reassemble);
			match(TCP);
#line 1459 "pf.g"
			
			importer->scrub_options.push_back(
			str_tuple("reassemble", "tcp"));
			importer->scrub_rule = true;
			
#line 6258 "PFCfgParser.cpp"
			break;
		}
		case 145:
		{
			match(145);
#line 1466 "pf.g"
			
			importer->scrub_options.push_back(
			str_tuple(LT(0)->getText(), ""));
			importer->scrub_rule = true;
			
#line 6270 "PFCfgParser.cpp"
			break;
		}
		case 146:
		{
			match(146);
			match(INT_CONST);
#line 1473 "pf.g"
			
			importer->scrub_options.push_back(
			str_tuple("min-ttl", LT(0)->getText()));
			importer->scrub_rule = true;
			
#line 6283 "PFCfgParser.cpp"
			break;
		}
		case 147:
		{
			match(147);
			match(INT_CONST);
#line 1480 "pf.g"
			
			importer->scrub_options.push_back(
			str_tuple("max-mss", LT(0)->getText()));
			importer->scrub_rule = true;
			
#line 6296 "PFCfgParser.cpp"
			break;
		}
		case 148:
		{
			match(148);
#line 1487 "pf.g"
			
			importer->scrub_options.push_back(
			str_tuple(LT(0)->getText(), ""));
			importer->scrub_rule = true;
			
#line 6308 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_53);
	}
}

void PFCfgParser::scrub_option_list() {
	Tracer traceInOut(this, "scrub_option_list");
	
	try {      // for error handling
		match(OPENING_PAREN);
		scrub_option();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_54.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case LITERAL_reassemble:
				case LITERAL_fragment:
				case 145:
				case 146:
				case 147:
				case 148:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				scrub_option();
			}
			else {
				goto _loop224;
			}
			
		}
		_loop224:;
		} // ( ... )*
		match(CLOSING_PAREN);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::icmp_type_code() {
	Tracer traceInOut(this, "icmp_type_code");
#line 1528 "pf.g"
	IcmpSpec is;
#line 6376 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_skip:
		case LITERAL_echorep:
		case LITERAL_unreach:
		case LITERAL_squench:
		case LITERAL_redir:
		case LITERAL_althost:
		case LITERAL_echoreq:
		case LITERAL_routeradv:
		case LITERAL_routersol:
		case LITERAL_timex:
		case LITERAL_paramprob:
		case LITERAL_timereq:
		case LITERAL_timerep:
		case LITERAL_inforeq:
		case LITERAL_inforep:
		case LITERAL_maskreq:
		case LITERAL_maskrep:
		case LITERAL_trace:
		case LITERAL_dataconv:
		case LITERAL_mobredir:
		case 171:
		case 172:
		case LITERAL_mobregreq:
		case LITERAL_mobregrep:
		case LITERAL_photuris:
		{
			icmp_type_by_name();
#line 1530 "pf.g"
			is.icmp_type_name = LT(0)->getText();
#line 6410 "PFCfgParser.cpp"
			break;
		}
		case INT_CONST:
		{
			match(INT_CONST);
#line 1532 "pf.g"
			is.icmp_type_int = LT(0)->getText();
#line 6418 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case ICMP_CODE:
		{
			match(ICMP_CODE);
			{
			switch ( LA(1)) {
			case 176:
			case 177:
			case 178:
			case 179:
			case LITERAL_needfrag:
			case LITERAL_srcfail:
			case 182:
			case 183:
			case LITERAL_isolate:
			case 185:
			case 186:
			case 187:
			case 188:
			case 189:
			case 190:
			case 191:
			case 192:
			case 193:
			case 194:
			case 195:
			case 196:
			case 197:
			case LITERAL_transit:
			case LITERAL_reassemb:
			case LITERAL_badhead:
			case LITERAL_optmiss:
			case LITERAL_badlen:
			case 203:
			case 204:
			case 205:
			{
				icmp_code_by_name();
#line 1538 "pf.g"
				is.icmp_code_name = LT(0)->getText();
#line 6468 "PFCfgParser.cpp"
				break;
			}
			case INT_CONST:
			{
				match(INT_CONST);
#line 1540 "pf.g"
				is.icmp_code_int = LT(0)->getText();
#line 6476 "PFCfgParser.cpp"
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case NEWLINE:
		case QUEUE:
		case LITERAL_skip:
		case COMMA:
		case CLOSING_BRACE:
		case LITERAL_reassemble:
		case INT_CONST:
		case SCRUB:
		case EXLAMATION:
		case NO:
		case OPENING_PAREN:
		case USER:
		case GROUP:
		case LITERAL_fragment:
		case 145:
		case 146:
		case 147:
		case 148:
		case FLAGS:
		case ICMP_TYPE:
		case LITERAL_echorep:
		case LITERAL_unreach:
		case LITERAL_squench:
		case LITERAL_redir:
		case LITERAL_althost:
		case LITERAL_echoreq:
		case LITERAL_routeradv:
		case LITERAL_routersol:
		case LITERAL_timex:
		case LITERAL_paramprob:
		case LITERAL_timereq:
		case LITERAL_timerep:
		case LITERAL_inforeq:
		case LITERAL_inforep:
		case LITERAL_maskreq:
		case LITERAL_maskrep:
		case LITERAL_trace:
		case LITERAL_dataconv:
		case LITERAL_mobredir:
		case 171:
		case 172:
		case LITERAL_mobregreq:
		case LITERAL_mobregrep:
		case LITERAL_photuris:
		case ICMP6_TYPE:
		case TAGGED:
		case TAG:
		case KEEP:
		case MODULATE:
		case SYNPROXY:
		case LABEL:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1543 "pf.g"
		
		importer->icmp_type_code_group.push_back(is);
		
#line 6551 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_55);
	}
}

void PFCfgParser::icmp_list() {
	Tracer traceInOut(this, "icmp_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		icmp_type_code();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_56.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case LITERAL_skip:
				case INT_CONST:
				case LITERAL_echorep:
				case LITERAL_unreach:
				case LITERAL_squench:
				case LITERAL_redir:
				case LITERAL_althost:
				case LITERAL_echoreq:
				case LITERAL_routeradv:
				case LITERAL_routersol:
				case LITERAL_timex:
				case LITERAL_paramprob:
				case LITERAL_timereq:
				case LITERAL_timerep:
				case LITERAL_inforeq:
				case LITERAL_inforep:
				case LITERAL_maskreq:
				case LITERAL_maskrep:
				case LITERAL_trace:
				case LITERAL_dataconv:
				case LITERAL_mobredir:
				case 171:
				case 172:
				case LITERAL_mobregreq:
				case LITERAL_mobregrep:
				case LITERAL_photuris:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				icmp_type_code();
			}
			else {
				goto _loop245;
			}
			
		}
		_loop245:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_47);
	}
}

void PFCfgParser::icmp_type_by_name() {
	Tracer traceInOut(this, "icmp_type_by_name");
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_echorep:
		{
			match(LITERAL_echorep);
			break;
		}
		case LITERAL_unreach:
		{
			match(LITERAL_unreach);
			break;
		}
		case LITERAL_squench:
		{
			match(LITERAL_squench);
			break;
		}
		case LITERAL_redir:
		{
			match(LITERAL_redir);
			break;
		}
		case LITERAL_althost:
		{
			match(LITERAL_althost);
			break;
		}
		case LITERAL_echoreq:
		{
			match(LITERAL_echoreq);
			break;
		}
		case LITERAL_routeradv:
		{
			match(LITERAL_routeradv);
			break;
		}
		case LITERAL_routersol:
		{
			match(LITERAL_routersol);
			break;
		}
		case LITERAL_timex:
		{
			match(LITERAL_timex);
			break;
		}
		case LITERAL_paramprob:
		{
			match(LITERAL_paramprob);
			break;
		}
		case LITERAL_timereq:
		{
			match(LITERAL_timereq);
			break;
		}
		case LITERAL_timerep:
		{
			match(LITERAL_timerep);
			break;
		}
		case LITERAL_inforeq:
		{
			match(LITERAL_inforeq);
			break;
		}
		case LITERAL_inforep:
		{
			match(LITERAL_inforep);
			break;
		}
		case LITERAL_maskreq:
		{
			match(LITERAL_maskreq);
			break;
		}
		case LITERAL_maskrep:
		{
			match(LITERAL_maskrep);
			break;
		}
		case LITERAL_trace:
		{
			match(LITERAL_trace);
			break;
		}
		case LITERAL_dataconv:
		{
			match(LITERAL_dataconv);
			break;
		}
		case LITERAL_mobredir:
		{
			match(LITERAL_mobredir);
			break;
		}
		case 171:
		{
			match(171);
			break;
		}
		case 172:
		{
			match(172);
			break;
		}
		case LITERAL_mobregreq:
		{
			match(LITERAL_mobregreq);
			break;
		}
		case LITERAL_mobregrep:
		{
			match(LITERAL_mobregrep);
			break;
		}
		case LITERAL_skip:
		{
			match(LITERAL_skip);
			break;
		}
		case LITERAL_photuris:
		{
			match(LITERAL_photuris);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_57);
	}
}

void PFCfgParser::port_op() {
	Tracer traceInOut(this, "port_op");
#line 1794 "pf.g"
	PortSpec ps;
#line 6775 "PFCfgParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case EQUAL:
		case LESS_THAN:
		case GREATER_THAN:
		case EXLAMATION:
		{
			unary_op();
#line 1796 "pf.g"
			ps.port_op = importer->tmp_port_op;
#line 6788 "PFCfgParser.cpp"
			port_def();
#line 1798 "pf.g"
			
			ps.port1 = importer->tmp_port_def;
			ps.port2 = importer->tmp_port_def;
			
#line 6795 "PFCfgParser.cpp"
			break;
		}
		case WORD:
		case INT_CONST:
		{
			port_def();
#line 1804 "pf.g"
			
			ps.port1 = importer->tmp_port_def;
			ps.port2 = ps.port1;
			ps.port_op = "=";
			
#line 6808 "PFCfgParser.cpp"
			{
			if ((LA(1) == LESS_THAN || LA(1) == GREATER_THAN || LA(1) == COLON) && (_tokenSet_48.member(LA(2)))) {
				binary_op();
#line 1810 "pf.g"
				ps.port_op = importer->tmp_port_op;
#line 6814 "PFCfgParser.cpp"
				port_def();
#line 1811 "pf.g"
				ps.port2 = LT(0)->getText();
#line 6818 "PFCfgParser.cpp"
			}
			else if ((_tokenSet_58.member(LA(1))) && (_tokenSet_59.member(LA(2)))) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			
			}
			break;
		}
		case IPV6:
		{
			match(IPV6);
#line 1815 "pf.g"
			
			ps.setFromPortRange(LT(0)->getText());
			
#line 6836 "PFCfgParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 1819 "pf.g"
		
		importer->tmp_port_group.push_back(ps);
		
#line 6849 "PFCfgParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_58);
	}
}

void PFCfgParser::port_op_list() {
	Tracer traceInOut(this, "port_op_list");
	
	try {      // for error handling
		match(OPENING_BRACE);
		port_op();
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_60.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case COMMA:
				{
					match(COMMA);
					break;
				}
				case WORD:
				case EQUAL:
				case INT_CONST:
				case LESS_THAN:
				case GREATER_THAN:
				case EXLAMATION:
				case IPV6:
				{
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				port_op();
			}
			else {
				goto _loop273;
			}
			
		}
		_loop273:;
		} // ( ... )*
		match(CLOSING_BRACE);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_41);
	}
}

void PFCfgParser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& )
{
}
const char* PFCfgParser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"NEWLINE",
	"COMMENT_START",
	"\"include\"",
	"WORD",
	"EQUAL",
	"\"antispoof\"",
	"\"altq\"",
	"\"queue\"",
	"\"set\"",
	"\"timeout\"",
	"\"ruleset-optimization\"",
	"\"optimization\"",
	"\"aggressive\"",
	"\"conservative\"",
	"\"high-latency\"",
	"\"normal\"",
	"\"satellite\"",
	"\"limit\"",
	"\"loginterface\"",
	"\"block-policy\"",
	"\"drop\"",
	"\"return\"",
	"\"state-policy\"",
	"\"if-bound\"",
	"\"floating\"",
	"\"state-defaults\"",
	"\"require-order\"",
	"\"fingerprints\"",
	"\"skip\"",
	"\"on\"",
	"OPENING_BRACE",
	"COMMA",
	"CLOSING_BRACE",
	"\"debug\"",
	"\"reassemble\"",
	"\"hostid\"",
	"\"tcp.first\"",
	"\"tcp.opening\"",
	"\"tcp.established\"",
	"\"tcp.closing\"",
	"\"tcp.finwait\"",
	"\"tcp.closed\"",
	"\"udp.first\"",
	"\"udp.single\"",
	"\"udp.multiple\"",
	"\"icmp.first\"",
	"\"icmp.error\"",
	"\"other.first\"",
	"\"other.single\"",
	"\"other.multiple\"",
	"\"frag\"",
	"\"interval\"",
	"\"src.track\"",
	"\"adaptive.start\"",
	"\"adaptive.end\"",
	"INT_CONST",
	"\"frags\"",
	"\"states\"",
	"\"src-nodes\"",
	"\"tables\"",
	"\"tables-entries\"",
	"\"scrub\"",
	"\"match\"",
	"\"table\"",
	"LESS_THAN",
	"GREATER_THAN",
	"\"persist\"",
	"\"const\"",
	"\"counters\"",
	"\"file\"",
	"STRING",
	"EXLAMATION",
	"COLON",
	"\"network\"",
	"\"broadcast\"",
	"\"peer\"",
	"\"self\"",
	"IPV4",
	"NUMBER",
	"SLASH",
	"\"no\"",
	"\"nat\"",
	"\"pass\"",
	"MINUS",
	"\"static-port\"",
	"\"rdr\"",
	"OPENING_PAREN",
	"CLOSING_PAREN",
	"\"port\"",
	"IPV6",
	"STAR",
	"\"bitmask\"",
	"\"random\"",
	"\"source-hash\"",
	"\"hex-key\"",
	"\"string-key\"",
	"\"round-robin\"",
	"\"sticky-address\"",
	"\"binat\"",
	"\"block\"",
	"\"return-rst\"",
	"TTL",
	"\"return-icmp\"",
	"RETURN_ICMP6",
	"\"in\"",
	"\"out\"",
	"\"log\"",
	"\"quick\"",
	"\"all\"",
	"\"user\"",
	"\"to\"",
	"\"inet\"",
	"\"inet6\"",
	"\"proto\"",
	"\"ip\"",
	"\"icmp\"",
	"\"igmp\"",
	"\"tcp\"",
	"\"udp\"",
	"\"rdp\"",
	"\"rsvp\"",
	"\"gre\"",
	"\"esp\"",
	"\"ah\"",
	"\"eigrp\"",
	"\"ospf\"",
	"\"ipip\"",
	"\"vrrp\"",
	"\"l2tp\"",
	"\"isis\"",
	"\"from\"",
	"\"urpf-failed\"",
	"\"any\"",
	"\"no-route\"",
	"\"route-to\"",
	"\"reply-to\"",
	"\"dup-to\"",
	"\"group\"",
	"\"fragment\"",
	"\"crop\"",
	"\"drop-ovl\"",
	"\"no-df\"",
	"\"min-ttl\"",
	"\"max-mss\"",
	"\"random-id\"",
	"\"flags\"",
	"\"icmp-type\"",
	"\"code\"",
	"\"echorep\"",
	"\"unreach\"",
	"\"squench\"",
	"\"redir\"",
	"\"althost\"",
	"\"echoreq\"",
	"\"routeradv\"",
	"\"routersol\"",
	"\"timex\"",
	"\"paramprob\"",
	"\"timereq\"",
	"\"timerep\"",
	"\"inforeq\"",
	"\"inforep\"",
	"\"maskreq\"",
	"\"maskrep\"",
	"\"trace\"",
	"\"dataconv\"",
	"\"mobredir\"",
	"\"ipv6-where\"",
	"\"ipv6-here\"",
	"\"mobregreq\"",
	"\"mobregrep\"",
	"\"photuris\"",
	"\"net-unr\"",
	"\"host-unr\"",
	"\"proto-unr\"",
	"\"port-unr\"",
	"\"needfrag\"",
	"\"srcfail\"",
	"\"net-unk\"",
	"\"host-unk\"",
	"\"isolate\"",
	"\"net-prohib\"",
	"\"host-prohib\"",
	"\"net-tos\"",
	"\"host-tos\"",
	"\"filter-prohib\"",
	"\"host-preced\"",
	"\"cutoff-preced\"",
	"\"redir-net\"",
	"\"redir-host\"",
	"\"redir-tos-net\"",
	"\"redir-tos-host\"",
	"\"normal-adv\"",
	"\"common-adv\"",
	"\"transit\"",
	"\"reassemb\"",
	"\"badhead\"",
	"\"optmiss\"",
	"\"badlen\"",
	"\"unknown-ind\"",
	"\"auth-fail\"",
	"\"decrypt-fail\"",
	"\"icmp6-type\"",
	"\"tagged\"",
	"\"tag\"",
	"\"keep\"",
	"\"modulate\"",
	"\"synproxy\"",
	"\"state\"",
	"\"label\"",
	"\"exit\"",
	"\"quit\"",
	"\"interface\"",
	"\"icmp6\"",
	"\"igrp\"",
	"\"ipsec\"",
	"\"nos\"",
	"\"pcp\"",
	"\"pim\"",
	"\"pptp\"",
	"\"rip\"",
	"\"snp\"",
	"\"host\"",
	"\"range\"",
	"\"alerts\"",
	"\"critical\"",
	"\"debugging\"",
	"\"emergencies\"",
	"\"errors\"",
	"\"informational\"",
	"\"notifications\"",
	"\"warnings\"",
	"\"disable\"",
	"\"inactive\"",
	"Whitespace",
	"HEX_CONST",
	"NEG_INT_CONST",
	"HEX_DIGIT",
	"DIGIT",
	"NUM_3DIGIT",
	"NUM_HEX_4DIGIT",
	"NUMBER_ADDRESS_OR_WORD",
	"PIPE_CHAR",
	"PERCENT",
	"AMPERSAND",
	"APOSTROPHE",
	"PLUS",
	"DOT",
	"SEMICOLON",
	"QUESTION",
	"COMMERCIAL_AT",
	"OPENING_SQUARE",
	"CLOSING_SQUARE",
	"CARET",
	"UNDERLINE",
	"TILDE",
	"DOUBLE_QUOTE",
	0
};

const unsigned long PFCfgParser::_tokenSet_0_data_[] = { 2UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_0(_tokenSet_0_data_,10);
const unsigned long PFCfgParser::_tokenSet_1_data_[] = { 7922UL, 0UL, 40894478UL, 192UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD "antispoof" "altq" "queue" 
// "set" "scrub" "match" "table" "no" "nat" "pass" "rdr" "binat" "block" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_1(_tokenSet_1_data_,10);
const unsigned long PFCfgParser::_tokenSet_2_data_[] = { 128UL, 134217736UL, 460800UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD COMMA INT_CONST EXLAMATION "self" IPV4 NUMBER 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_2(_tokenSet_2_data_,10);
const unsigned long PFCfgParser::_tokenSet_3_data_[] = { 7922UL, 134217496UL, 40894478UL, 192UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD "antispoof" "altq" "queue" 
// "set" COMMA CLOSING_BRACE "tcp.first" "tcp.opening" "tcp.established" 
// "tcp.closing" "tcp.finwait" "tcp.closed" "udp.first" "udp.single" "udp.multiple" 
// "icmp.first" "icmp.error" "other.first" "other.single" "other.multiple" 
// "frag" "interval" "src.track" "adaptive.start" "adaptive.end" "scrub" 
// "match" "table" "no" "nat" "pass" "rdr" "binat" "block" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_3(_tokenSet_3_data_,10);
const unsigned long PFCfgParser::_tokenSet_4_data_[] = { 0UL, 134217480UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// COMMA "tcp.first" "tcp.opening" "tcp.established" "tcp.closing" "tcp.finwait" 
// "tcp.closed" "udp.first" "udp.single" "udp.multiple" "icmp.first" "icmp.error" 
// "other.first" "other.single" "other.multiple" "frag" "interval" "src.track" 
// "adaptive.start" "adaptive.end" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_4(_tokenSet_4_data_,10);
const unsigned long PFCfgParser::_tokenSet_5_data_[] = { 7922UL, 4026531864UL, 40894479UL, 192UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD "antispoof" "altq" "queue" 
// "set" COMMA CLOSING_BRACE "frags" "states" "src-nodes" "tables" "tables-entries" 
// "scrub" "match" "table" "no" "nat" "pass" "rdr" "binat" "block" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_5(_tokenSet_5_data_,10);
const unsigned long PFCfgParser::_tokenSet_6_data_[] = { 0UL, 4026531848UL, 1UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// COMMA "frags" "states" "src-nodes" "tables" "tables-entries" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_6(_tokenSet_6_data_,10);
const unsigned long PFCfgParser::_tokenSet_7_data_[] = { 2064UL, 64UL, 68159490UL, 458752UL, 8282176UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN "all" 
// "user" "to" "from" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_7(_tokenSet_7_data_,16);
const unsigned long PFCfgParser::_tokenSet_8_data_[] = { 8178UL, 134217805UL, 645598270UL, 33685696UL, 4286571392UL, 65535UL, 4177920UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD EQUAL "antispoof" "altq" "queue" 
// "set" "skip" OPENING_BRACE COMMA "reassemble" INT_CONST "scrub" "match" 
// "table" LESS_THAN GREATER_THAN STRING EXLAMATION "self" IPV4 SLASH "no" 
// "nat" "pass" "rdr" OPENING_PAREN IPV6 "binat" "block" "user" "tcp" "urpf-failed" 
// "any" "no-route" "group" "fragment" "crop" "drop-ovl" "no-df" "min-ttl" 
// "max-mss" "random-id" "flags" "icmp-type" "echorep" "unreach" "squench" 
// "redir" "althost" "echoreq" "routeradv" "routersol" "timex" "paramprob" 
// "timereq" "timerep" "inforeq" "inforep" "maskreq" "maskrep" "trace" 
// "dataconv" "mobredir" "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" 
// "photuris" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "state" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_8(_tokenSet_8_data_,16);
const unsigned long PFCfgParser::_tokenSet_9_data_[] = { 2064UL, 64UL, 68159490UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN "user" 
// "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_9(_tokenSet_9_data_,16);
const unsigned long PFCfgParser::_tokenSet_10_data_[] = { 8178UL, 134217805UL, 108530750UL, 33685696UL, 4286570752UL, 65535UL, 4177920UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD EQUAL "antispoof" "altq" "queue" 
// "set" "skip" OPENING_BRACE COMMA "reassemble" INT_CONST "scrub" "match" 
// "table" LESS_THAN GREATER_THAN STRING EXLAMATION SLASH "no" "nat" "pass" 
// "rdr" OPENING_PAREN "binat" "block" "user" "tcp" "any" "group" "fragment" 
// "crop" "drop-ovl" "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" 
// "echorep" "unreach" "squench" "redir" "althost" "echoreq" "routeradv" 
// "routersol" "timex" "paramprob" "timereq" "timerep" "inforeq" "inforep" 
// "maskreq" "maskrep" "trace" "dataconv" "mobredir" "ipv6-where" "ipv6-here" 
// "mobregreq" "mobregrep" "photuris" "icmp6-type" "tagged" "tag" "keep" 
// "modulate" "synproxy" "state" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_10(_tokenSet_10_data_,16);
const unsigned long PFCfgParser::_tokenSet_11_data_[] = { 16UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_11(_tokenSet_11_data_,10);
const unsigned long PFCfgParser::_tokenSet_12_data_[] = { 128UL, 134217752UL, 460800UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD COMMA CLOSING_BRACE INT_CONST EXLAMATION "self" IPV4 NUMBER 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_12(_tokenSet_12_data_,10);
const unsigned long PFCfgParser::_tokenSet_13_data_[] = { 16UL, 2UL, 8390656UL, 3997696UL, 64UL, 0UL, 98304UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "on" EXLAMATION MINUS "all" "to" "inet" "inet6" "proto" "from" 
// "tagged" "tag" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_13(_tokenSet_13_data_,16);
const unsigned long PFCfgParser::_tokenSet_14_data_[] = { 2064UL, 64UL, 76548098UL, 4128768UL, 8289344UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "all" "user" "to" "inet" "inet6" "proto" "from" "route-to" "reply-to" 
// "dup-to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_14(_tokenSet_14_data_,16);
const unsigned long PFCfgParser::_tokenSet_15_data_[] = { 2064UL, 64UL, 76548098UL, 2555904UL, 8282176UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "all" "user" "to" "proto" "from" "group" "fragment" "no-df" "min-ttl" 
// "max-mss" "random-id" "flags" "icmp-type" "icmp6-type" "tagged" "tag" 
// "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_15(_tokenSet_15_data_,16);
const unsigned long PFCfgParser::_tokenSet_16_data_[] = { 2064UL, 64UL, 76548098UL, 458752UL, 8282176UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "all" "user" "to" "from" "group" "fragment" "no-df" "min-ttl" "max-mss" 
// "random-id" "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" 
// "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_16(_tokenSet_16_data_,16);
const unsigned long PFCfgParser::_tokenSet_17_data_[] = { 2064UL, 64UL, 76548098UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "user" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" 
// "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_17(_tokenSet_17_data_,16);
const unsigned long PFCfgParser::_tokenSet_18_data_[] = { 2064UL, 72UL, 76548098UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" COMMA "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "user" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" 
// "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_18(_tokenSet_18_data_,16);
const unsigned long PFCfgParser::_tokenSet_19_data_[] = { 144UL, 24UL, 2499936256UL, 19UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE WORD COMMA CLOSING_BRACE IPV4 "static-port" OPENING_PAREN "port" 
// "bitmask" "random" "source-hash" "round-robin" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_19(_tokenSet_19_data_,10);
const unsigned long PFCfgParser::_tokenSet_20_data_[] = { 128UL, 8UL, 67239936UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD COMMA IPV4 OPENING_PAREN 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_20(_tokenSet_20_data_,10);
const unsigned long PFCfgParser::_tokenSet_21_data_[] = { 16UL, 0UL, 2432696320UL, 19UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "static-port" "port" "bitmask" "random" "source-hash" "round-robin" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_21(_tokenSet_21_data_,10);
const unsigned long PFCfgParser::_tokenSet_22_data_[] = { 16UL, 0UL, 2164260864UL, 19UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "static-port" "bitmask" "random" "source-hash" "round-robin" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_22(_tokenSet_22_data_,10);
const unsigned long PFCfgParser::_tokenSet_23_data_[] = { 16UL, 0UL, 16777216UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "static-port" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_23(_tokenSet_23_data_,10);
const unsigned long PFCfgParser::_tokenSet_24_data_[] = { 2448UL, 134217816UL, 2777684018UL, 393235UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE WORD EQUAL "queue" COMMA CLOSING_BRACE "reassemble" INT_CONST 
// "scrub" LESS_THAN GREATER_THAN EXLAMATION COLON "no" MINUS "static-port" 
// OPENING_PAREN IPV6 "bitmask" "random" "source-hash" "round-robin" "user" 
// "to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" 
// "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_24(_tokenSet_24_data_,16);
const unsigned long PFCfgParser::_tokenSet_25_data_[] = { 0UL, 134217728UL, 0UL, 0UL, 0UL, 4294901760UL, 16383UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// INT_CONST "net-unr" "host-unr" "proto-unr" "port-unr" "needfrag" "srcfail" 
// "net-unk" "host-unk" "isolate" "net-prohib" "host-prohib" "net-tos" 
// "host-tos" "filter-prohib" "host-preced" "cutoff-preced" "redir-net" 
// "redir-host" "redir-tos-net" "redir-tos-host" "normal-adv" "common-adv" 
// "transit" "reassemb" "badhead" "optmiss" "badlen" "unknown-ind" "auth-fail" 
// "decrypt-fail" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_25(_tokenSet_25_data_,16);
const unsigned long PFCfgParser::_tokenSet_26_data_[] = { 2064UL, 66UL, 68159490UL, 4190208UL, 8289344UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "on" "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN 
// "in" "out" "log" "quick" "all" "user" "to" "inet" "inet6" "proto" "from" 
// "route-to" "reply-to" "dup-to" "group" "fragment" "no-df" "min-ttl" 
// "max-mss" "random-id" "flags" "icmp-type" "icmp6-type" "tagged" "tag" 
// "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_26(_tokenSet_26_data_,16);
const unsigned long PFCfgParser::_tokenSet_27_data_[] = { 8178UL, 134217807UL, 645598270UL, 4294951104UL, 4286578687UL, 65535UL, 4177920UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD EQUAL "antispoof" "altq" "queue" 
// "set" "skip" "on" OPENING_BRACE COMMA "reassemble" INT_CONST "scrub" 
// "match" "table" LESS_THAN GREATER_THAN STRING EXLAMATION "self" IPV4 
// SLASH "no" "nat" "pass" "rdr" OPENING_PAREN IPV6 "binat" "block" "log" 
// "quick" "all" "user" "to" "inet" "inet6" "proto" "ip" "icmp" "igmp" 
// "tcp" "udp" "rdp" "rsvp" "gre" "esp" "ah" "eigrp" "ospf" "ipip" "vrrp" 
// "l2tp" "isis" "from" "urpf-failed" "any" "no-route" "route-to" "reply-to" 
// "dup-to" "group" "fragment" "crop" "drop-ovl" "no-df" "min-ttl" "max-mss" 
// "random-id" "flags" "icmp-type" "echorep" "unreach" "squench" "redir" 
// "althost" "echoreq" "routeradv" "routersol" "timex" "paramprob" "timereq" 
// "timerep" "inforeq" "inforep" "maskreq" "maskrep" "trace" "dataconv" 
// "mobredir" "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" "photuris" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "state" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_27(_tokenSet_27_data_,16);
const unsigned long PFCfgParser::_tokenSet_28_data_[] = { 2064UL, 134217817UL, 202377218UL, 131072UL, 4286472192UL, 65535UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "skip" COMMA CLOSING_BRACE "reassemble" INT_CONST "scrub" 
// EXLAMATION "no" OPENING_PAREN CLOSING_PAREN "user" "group" "fragment" 
// "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" "echorep" 
// "unreach" "squench" "redir" "althost" "echoreq" "routeradv" "routersol" 
// "timex" "paramprob" "timereq" "timerep" "inforeq" "inforep" "maskreq" 
// "maskrep" "trace" "dataconv" "mobredir" "ipv6-where" "ipv6-here" "mobregreq" 
// "mobregrep" "photuris" "icmp6-type" "tagged" "tag" "keep" "modulate" 
// "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_28(_tokenSet_28_data_,16);
const unsigned long PFCfgParser::_tokenSet_29_data_[] = { 2064UL, 66UL, 68159490UL, 4177920UL, 8289344UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "on" "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN 
// "log" "quick" "all" "user" "to" "inet" "inet6" "proto" "from" "route-to" 
// "reply-to" "dup-to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_29(_tokenSet_29_data_,16);
const unsigned long PFCfgParser::_tokenSet_30_data_[] = { 2064UL, 66UL, 68159490UL, 4161536UL, 8289344UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "on" "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN 
// "quick" "all" "user" "to" "inet" "inet6" "proto" "from" "route-to" "reply-to" 
// "dup-to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_30(_tokenSet_30_data_,16);
const unsigned long PFCfgParser::_tokenSet_31_data_[] = { 8178UL, 134217807UL, 645598270UL, 4294901952UL, 4286578687UL, 65535UL, 4177920UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD EQUAL "antispoof" "altq" "queue" 
// "set" "skip" "on" OPENING_BRACE COMMA "reassemble" INT_CONST "scrub" 
// "match" "table" LESS_THAN GREATER_THAN STRING EXLAMATION "self" IPV4 
// SLASH "no" "nat" "pass" "rdr" OPENING_PAREN IPV6 "binat" "block" "all" 
// "user" "to" "inet" "inet6" "proto" "ip" "icmp" "igmp" "tcp" "udp" "rdp" 
// "rsvp" "gre" "esp" "ah" "eigrp" "ospf" "ipip" "vrrp" "l2tp" "isis" "from" 
// "urpf-failed" "any" "no-route" "route-to" "reply-to" "dup-to" "group" 
// "fragment" "crop" "drop-ovl" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "echorep" "unreach" "squench" "redir" "althost" 
// "echoreq" "routeradv" "routersol" "timex" "paramprob" "timereq" "timerep" 
// "inforeq" "inforep" "maskreq" "maskrep" "trace" "dataconv" "mobredir" 
// "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" "photuris" "icmp6-type" 
// "tagged" "tag" "keep" "modulate" "synproxy" "state" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_31(_tokenSet_31_data_,16);
const unsigned long PFCfgParser::_tokenSet_32_data_[] = { 2064UL, 66UL, 68159490UL, 4128768UL, 8289344UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "on" "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN 
// "all" "user" "to" "inet" "inet6" "proto" "from" "route-to" "reply-to" 
// "dup-to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_32(_tokenSet_32_data_,16);
const unsigned long PFCfgParser::_tokenSet_33_data_[] = { 8178UL, 134217805UL, 645598270UL, 4293329088UL, 4286571519UL, 65535UL, 4177920UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD EQUAL "antispoof" "altq" "queue" 
// "set" "skip" OPENING_BRACE COMMA "reassemble" INT_CONST "scrub" "match" 
// "table" LESS_THAN GREATER_THAN STRING EXLAMATION "self" IPV4 SLASH "no" 
// "nat" "pass" "rdr" OPENING_PAREN IPV6 "binat" "block" "all" "user" "to" 
// "proto" "ip" "icmp" "igmp" "tcp" "udp" "rdp" "rsvp" "gre" "esp" "ah" 
// "eigrp" "ospf" "ipip" "vrrp" "l2tp" "isis" "from" "urpf-failed" "any" 
// "no-route" "group" "fragment" "crop" "drop-ovl" "no-df" "min-ttl" "max-mss" 
// "random-id" "flags" "icmp-type" "echorep" "unreach" "squench" "redir" 
// "althost" "echoreq" "routeradv" "routersol" "timex" "paramprob" "timereq" 
// "timerep" "inforeq" "inforep" "maskreq" "maskrep" "trace" "dataconv" 
// "mobredir" "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" "photuris" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "state" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_33(_tokenSet_33_data_,16);
const unsigned long PFCfgParser::_tokenSet_34_data_[] = { 2064UL, 64UL, 68159490UL, 4128768UL, 8282176UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN "all" 
// "user" "to" "inet" "inet6" "proto" "from" "group" "fragment" "no-df" 
// "min-ttl" "max-mss" "random-id" "flags" "icmp-type" "icmp6-type" "tagged" 
// "tag" "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_34(_tokenSet_34_data_,16);
const unsigned long PFCfgParser::_tokenSet_35_data_[] = { 2048UL, 72UL, 68159490UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// "queue" COMMA "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN "user" 
// "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_35(_tokenSet_35_data_,16);
const unsigned long PFCfgParser::_tokenSet_36_data_[] = { 2064UL, 66UL, 76548098UL, 4161536UL, 8289344UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "on" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "quick" "all" "user" "to" "inet" "inet6" "proto" "from" "route-to" "reply-to" 
// "dup-to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_36(_tokenSet_36_data_,16);
const unsigned long PFCfgParser::_tokenSet_37_data_[] = { 0UL, 8UL, 134217728UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// COMMA CLOSING_PAREN 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_37(_tokenSet_37_data_,10);
const unsigned long PFCfgParser::_tokenSet_38_data_[] = { 2192UL, 88UL, 76548098UL, 4128768UL, 8289344UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE WORD "queue" COMMA CLOSING_BRACE "reassemble" "scrub" EXLAMATION 
// "no" MINUS OPENING_PAREN "all" "user" "to" "inet" "inet6" "proto" "from" 
// "route-to" "reply-to" "dup-to" "group" "fragment" "no-df" "min-ttl" 
// "max-mss" "random-id" "flags" "icmp-type" "icmp6-type" "tagged" "tag" 
// "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_38(_tokenSet_38_data_,16);
const unsigned long PFCfgParser::_tokenSet_39_data_[] = { 2064UL, 134217820UL, 76548098UL, 4291231744UL, 8282239UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" OPENING_BRACE COMMA CLOSING_BRACE "reassemble" INT_CONST 
// "scrub" EXLAMATION "no" MINUS OPENING_PAREN "all" "user" "to" "ip" "icmp" 
// "igmp" "tcp" "udp" "rdp" "rsvp" "gre" "esp" "ah" "eigrp" "ospf" "ipip" 
// "vrrp" "l2tp" "isis" "from" "group" "fragment" "no-df" "min-ttl" "max-mss" 
// "random-id" "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" 
// "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_39(_tokenSet_39_data_,16);
const unsigned long PFCfgParser::_tokenSet_40_data_[] = { 0UL, 134217740UL, 0UL, 4290772992UL, 63UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OPENING_BRACE COMMA INT_CONST "ip" "icmp" "igmp" "tcp" "udp" "rdp" "rsvp" 
// "gre" "esp" "ah" "eigrp" "ospf" "ipip" "vrrp" "l2tp" "isis" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_40(_tokenSet_40_data_,12);
const unsigned long PFCfgParser::_tokenSet_41_data_[] = { 2064UL, 64UL, 76548098UL, 393216UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "user" "to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_41(_tokenSet_41_data_,16);
const unsigned long PFCfgParser::_tokenSet_42_data_[] = { 2064UL, 64UL, 344983554UL, 393216UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "port" "user" "to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_42(_tokenSet_42_data_,16);
const unsigned long PFCfgParser::_tokenSet_43_data_[] = { 2064UL, 64UL, 344983554UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "reassemble" "scrub" EXLAMATION "no" MINUS OPENING_PAREN 
// "port" "user" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_43(_tokenSet_43_data_,16);
const unsigned long PFCfgParser::_tokenSet_44_data_[] = { 2192UL, 88UL, 882051090UL, 393216UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE WORD "queue" COMMA CLOSING_BRACE "reassemble" "scrub" LESS_THAN 
// EXLAMATION "self" IPV4 "no" MINUS OPENING_PAREN "port" IPV6 "user" "to" 
// "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_44(_tokenSet_44_data_,16);
const unsigned long PFCfgParser::_tokenSet_45_data_[] = { 128UL, 8UL, 604178448UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD COMMA LESS_THAN EXLAMATION "self" IPV4 OPENING_PAREN IPV6 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_45(_tokenSet_45_data_,10);
const unsigned long PFCfgParser::_tokenSet_46_data_[] = { 2064UL, 88UL, 68159490UL, 4128768UL, 8282176UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" COMMA CLOSING_BRACE "reassemble" "scrub" EXLAMATION 
// "no" OPENING_PAREN "all" "user" "to" "inet" "inet6" "proto" "from" "group" 
// "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_46(_tokenSet_46_data_,16);
const unsigned long PFCfgParser::_tokenSet_47_data_[] = { 2064UL, 72UL, 68159490UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" COMMA "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN 
// "user" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" 
// "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_47(_tokenSet_47_data_,16);
const unsigned long PFCfgParser::_tokenSet_48_data_[] = { 128UL, 134217728UL, 48UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD INT_CONST LESS_THAN GREATER_THAN 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_48(_tokenSet_48_data_,10);
const unsigned long PFCfgParser::_tokenSet_49_data_[] = { 2448UL, 134217816UL, 68159538UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE WORD EQUAL "queue" COMMA CLOSING_BRACE "reassemble" INT_CONST 
// "scrub" LESS_THAN GREATER_THAN EXLAMATION "no" OPENING_PAREN "user" 
// "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_49(_tokenSet_49_data_,16);
const unsigned long PFCfgParser::_tokenSet_50_data_[] = { 8178UL, 134217821UL, 108534846UL, 33685696UL, 4286570752UL, 65535UL, 4177920UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD EQUAL "antispoof" "altq" "queue" 
// "set" "skip" OPENING_BRACE COMMA CLOSING_BRACE "reassemble" INT_CONST 
// "scrub" "match" "table" LESS_THAN GREATER_THAN STRING EXLAMATION COLON 
// SLASH "no" "nat" "pass" "rdr" OPENING_PAREN "binat" "block" "user" "tcp" 
// "any" "group" "fragment" "crop" "drop-ovl" "no-df" "min-ttl" "max-mss" 
// "random-id" "flags" "icmp-type" "echorep" "unreach" "squench" "redir" 
// "althost" "echoreq" "routeradv" "routersol" "timex" "paramprob" "timereq" 
// "timerep" "inforeq" "inforep" "maskreq" "maskrep" "trace" "dataconv" 
// "mobredir" "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" "photuris" 
// "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" "state" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_50(_tokenSet_50_data_,16);
const unsigned long PFCfgParser::_tokenSet_51_data_[] = { 384UL, 134217736UL, 2096UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD EQUAL COMMA INT_CONST LESS_THAN GREATER_THAN EXLAMATION 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_51(_tokenSet_51_data_,10);
const unsigned long PFCfgParser::_tokenSet_52_data_[] = { 128UL, 134217728UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD INT_CONST 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_52(_tokenSet_52_data_,10);
const unsigned long PFCfgParser::_tokenSet_53_data_[] = { 2064UL, 72UL, 202377218UL, 131072UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" COMMA "reassemble" "scrub" EXLAMATION "no" OPENING_PAREN 
// CLOSING_PAREN "user" "group" "fragment" "no-df" "min-ttl" "max-mss" 
// "random-id" "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" 
// "synproxy" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_53(_tokenSet_53_data_,16);
const unsigned long PFCfgParser::_tokenSet_54_data_[] = { 0UL, 72UL, 0UL, 0UL, 1982464UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// COMMA "reassemble" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_54(_tokenSet_54_data_,12);
const unsigned long PFCfgParser::_tokenSet_55_data_[] = { 2064UL, 134217817UL, 68159490UL, 131072UL, 4286472192UL, 65535UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "skip" COMMA CLOSING_BRACE "reassemble" INT_CONST "scrub" 
// EXLAMATION "no" OPENING_PAREN "user" "group" "fragment" "no-df" "min-ttl" 
// "max-mss" "random-id" "flags" "icmp-type" "echorep" "unreach" "squench" 
// "redir" "althost" "echoreq" "routeradv" "routersol" "timex" "paramprob" 
// "timereq" "timerep" "inforeq" "inforep" "maskreq" "maskrep" "trace" 
// "dataconv" "mobredir" "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" 
// "photuris" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_55(_tokenSet_55_data_,16);
const unsigned long PFCfgParser::_tokenSet_56_data_[] = { 0UL, 134217737UL, 0UL, 0UL, 4278190080UL, 65535UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// "skip" COMMA INT_CONST "echorep" "unreach" "squench" "redir" "althost" 
// "echoreq" "routeradv" "routersol" "timex" "paramprob" "timereq" "timerep" 
// "inforeq" "inforep" "maskreq" "maskrep" "trace" "dataconv" "mobredir" 
// "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" "photuris" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_56(_tokenSet_56_data_,12);
const unsigned long PFCfgParser::_tokenSet_57_data_[] = { 2064UL, 134217817UL, 68159490UL, 131072UL, 4294860800UL, 65535UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE "queue" "skip" COMMA CLOSING_BRACE "reassemble" INT_CONST "scrub" 
// EXLAMATION "no" OPENING_PAREN "user" "group" "fragment" "no-df" "min-ttl" 
// "max-mss" "random-id" "flags" "icmp-type" "code" "echorep" "unreach" 
// "squench" "redir" "althost" "echoreq" "routeradv" "routersol" "timex" 
// "paramprob" "timereq" "timerep" "inforeq" "inforep" "maskreq" "maskrep" 
// "trace" "dataconv" "mobredir" "ipv6-where" "ipv6-here" "mobregreq" "mobregrep" 
// "photuris" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_57(_tokenSet_57_data_,16);
const unsigned long PFCfgParser::_tokenSet_58_data_[] = { 2448UL, 134217816UL, 613419058UL, 393216UL, 8282112UL, 0UL, 3129344UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NEWLINE WORD EQUAL "queue" COMMA CLOSING_BRACE "reassemble" INT_CONST 
// "scrub" LESS_THAN GREATER_THAN EXLAMATION "no" MINUS OPENING_PAREN IPV6 
// "user" "to" "group" "fragment" "no-df" "min-ttl" "max-mss" "random-id" 
// "flags" "icmp-type" "icmp6-type" "tagged" "tag" "keep" "modulate" "synproxy" 
// "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_58(_tokenSet_58_data_,16);
const unsigned long PFCfgParser::_tokenSet_59_data_[] = { 8178UL, 134217821UL, 653990974UL, 33947840UL, 4286571264UL, 65535UL, 4177920UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NEWLINE COMMENT_START "include" WORD EQUAL "antispoof" "altq" "queue" 
// "set" "skip" OPENING_BRACE COMMA CLOSING_BRACE "reassemble" INT_CONST 
// "scrub" "match" "table" LESS_THAN GREATER_THAN STRING EXLAMATION COLON 
// "self" IPV4 SLASH "no" "nat" "pass" MINUS "rdr" OPENING_PAREN IPV6 "binat" 
// "block" "user" "to" "tcp" "any" "no-route" "group" "fragment" "crop" 
// "drop-ovl" "no-df" "min-ttl" "max-mss" "random-id" "flags" "icmp-type" 
// "echorep" "unreach" "squench" "redir" "althost" "echoreq" "routeradv" 
// "routersol" "timex" "paramprob" "timereq" "timerep" "inforeq" "inforep" 
// "maskreq" "maskrep" "trace" "dataconv" "mobredir" "ipv6-where" "ipv6-here" 
// "mobregreq" "mobregrep" "photuris" "icmp6-type" "tagged" "tag" "keep" 
// "modulate" "synproxy" "state" "label" 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_59(_tokenSet_59_data_,16);
const unsigned long PFCfgParser::_tokenSet_60_data_[] = { 384UL, 134217736UL, 536873008UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// WORD EQUAL COMMA INT_CONST LESS_THAN GREATER_THAN EXLAMATION IPV6 
const ANTLR_USE_NAMESPACE(antlr)BitSet PFCfgParser::_tokenSet_60(_tokenSet_60_data_,10);


