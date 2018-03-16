#include "stdafx.h"
#include "SyntaxStateM.h"
#include "Syntax_analizer.h"

////////////////////////////// Syntx State //////////////////////////////
Compiler_code_logic_thing::SyntaxStateM::SyntaxStateM(Lex_analizer * lexx, Syntax_analizer * syntt) {
	indexToExpToken = 0;
	lex = lexx;
	synt = syntt;
}
Compiler_code_logic_thing::SyntaxStateM::~SyntaxStateM() {

}
////////////////////////////// Syntx Program //////////////////////////////
////////////////////// v Generic check syntax v //////////////////////
/*
int i = 0;
while (indexToExpToken < m_ExpectedTokens.size()) {
while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
{
//Here check compare tokens//
//if the lex of next token
if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
if (S != nullptr) {
S->CheckSyntax();
}
}
else if(m_ExpectedTokens[indexToExpToken].b_Required){
if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
--i;
}
else {

}
}
else {
if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
--i;
}
else {

}
}
++i;
}
++indexToExpToken;
}
*/
////////////////////// ^ Generic check syntax ^ //////////////////////
Compiler_code_logic_thing::SyntxProg::SyntxProg(Lex_analizer * lexx, Syntax_analizer * syntt):
	SyntaxStateM(lexx, syntt) {
	/*std::vector<TOKEN_TYPE>v_Token_Type;
	std::vector<std::string>str_Token_lex;
	bool b_Required;
	bool b_Repeated;*/
	S_TOKEN_EXPECTED exp_token;

	exp_token.str_Token_lex.push_back("var");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 0;
	exp_token.b_Repeated = 1;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("procedure");
	exp_token.str_Token_lex.push_back("function");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 0;
	exp_token.b_Repeated = 1;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("main");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}

void Compiler_code_logic_thing::SyntxProg::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token 
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
														m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if(m_ExpectedTokens[indexToExpToken].b_Required){
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}

////////////////////////////// Syntx Var //////////////////////////////
Compiler_code_logic_thing::SyntxVar::SyntxVar(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("");
	exp_token.v_Token_Type.push_back(ID);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(",");
	exp_token.v_Token_Type.push_back(SEPARATOR);
	exp_token.b_Required = 0;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 1;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(":");
	exp_token.v_Token_Type.push_back(SEPARATOR);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("int");
	exp_token.str_Token_lex.push_back("float");
	exp_token.str_Token_lex.push_back("string");
	exp_token.str_Token_lex.push_back("bool");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(";");
	exp_token.v_Token_Type.push_back(SEPARATOR);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}

void Compiler_code_logic_thing::SyntxVar::CheckSyntax() {
	vector<std::string> v_IDs;
	vector<std::string> v_Dimens;
	int i = 0;
	int index = 0;
	bool found = false;
	std::string tokenLex;
	lex->getNextToken();

	while (indexToExpToken < m_ExpectedTokens.size()) {
		found = false;
		i = 0;
		tokenLex = lex->peekToken(0)->GetLex();
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size()) {
			//Here check compare tokens//
			//if the lex of next token
			if (m_ExpectedTokens[indexToExpToken].str_Token_lex[i] == "") {
				if (m_ExpectedTokens[indexToExpToken].v_Token_Type[i] == lex->peekToken(0)->GetType()) {
					//insert or 
					v_IDs.push_back(lex->peekToken(0)->GetLex());
					//dimensions
					found = true;
				}
				else {
					//adderror
				}

				break;
			}
			else if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
														m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				found = true;
				if (S != nullptr) {
					S->CheckSyntax();
				}
				else {
					if (m_ExpectedTokens[indexToExpToken].b_Conditional ) {
						index = m_ExpectedTokens[indexToExpToken].goToIndex;
					}
				}
				break;
			}
			++i;
		}

		if (found)
		{
			if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
				--indexToExpToken;
				
			}
			else {
				
			}

			lex->getNextToken();
		}
		else {	// if not found
			if (m_ExpectedTokens[indexToExpToken].b_Required) {
				//add error
				lex->getNextToken();
			}
			else {

			}
		}
		if (!m_ExpectedTokens[indexToExpToken].b_Conditional) {
			++indexToExpToken;
		}
		else {
			if (found) {
				indexToExpToken = index;
			}
			else {
				++indexToExpToken;
			}
		}
		//if (!m_ExpectedTokens[indexToExpToken].b_Repeated) {
		//	lex->getNextToken();
		//}
	}
}
////////////////////////////// Syntx Main //////////////////////////////
Compiler_code_logic_thing::SyntxMain::SyntxMain(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("main");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("(");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(")");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	exp_token.b_Conditional = 0;
	exp_token.goToIndex = 0;
	m_ExpectedTokens.push_back(exp_token);

}

void Compiler_code_logic_thing::SyntxMain::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size()) {
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Inc & Dec //////////////////////////////
Compiler_code_logic_thing::SyntxIncDec::SyntxIncDec(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("inc");
	exp_token.str_Token_lex.push_back("dec");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(";");
	exp_token.v_Token_Type.push_back(SEPARATOR);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}
void Compiler_code_logic_thing::SyntxIncDec::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Dimension //////////////////////////////
Compiler_code_logic_thing::SyntxDimension::SyntxDimension(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("[");
	exp_token.v_Token_Type.push_back(DIMENSION_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("");
	exp_token.v_Token_Type.push_back(INT);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("]");
	exp_token.v_Token_Type.push_back(DIMENSION_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

}

void Compiler_code_logic_thing::SyntxDimension::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Switch //////////////////////////////
Compiler_code_logic_thing::SyntxSwitch::SyntxSwitch(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;

	exp_token.str_Token_lex.push_back("switch");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}

void Compiler_code_logic_thing::SyntxSwitch::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx While //////////////////////////////
Compiler_code_logic_thing::SyntxWhile::SyntxWhile(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {

}

void Compiler_code_logic_thing::SyntxWhile::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx For //////////////////////////////
Compiler_code_logic_thing::SyntxFor::SyntxFor(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {

}

void Compiler_code_logic_thing::SyntxFor::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Read //////////////////////////////
Compiler_code_logic_thing::SyntxRead::SyntxRead(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("read");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("(");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("");
	exp_token.v_Token_Type.push_back(ID);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	//check for dimension
	//

	exp_token.str_Token_lex.push_back(")");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(";");
	exp_token.v_Token_Type.push_back(SEPARATOR);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}

void Compiler_code_logic_thing::SyntxRead::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Print //////////////////////////////
Compiler_code_logic_thing::SyntxPrint::SyntxPrint(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("print");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back("(");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	// exp
	//

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(")");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	exp_token.str_Token_lex.push_back(";");
	exp_token.v_Token_Type.push_back(SEPARATOR);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}

void Compiler_code_logic_thing::SyntxPrint::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx If //////////////////////////////
Compiler_code_logic_thing::SyntxIf::SyntxIf(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {

}

void Compiler_code_logic_thing::SyntxIf::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Param //////////////////////////////
Compiler_code_logic_thing::SyntxParam::SyntxParam(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("(");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	// check for vars
	//

	exp_token.str_Token_lex.push_back(")");
	exp_token.v_Token_Type.push_back(GROUPING_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}

void Compiler_code_logic_thing::SyntxParam::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Assing //////////////////////////////
Compiler_code_logic_thing::SyntxAssing::SyntxAssing(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;

	//
	//check for ID
	//

	exp_token.str_Token_lex.push_back("=");
	exp_token.v_Token_Type.push_back(ASSIGN_OPE);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	//check for exp
	//
}

void Compiler_code_logic_thing::SyntxAssing::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Procedure //////////////////////////////
Compiler_code_logic_thing::SyntxProc::SyntxProc(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("procedure");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	//check id
	//

	//
	//check params
	//

	//
	//exp/block/procs/funcs
	//
}

void Compiler_code_logic_thing::SyntxProc::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Function //////////////////////////////
Compiler_code_logic_thing::SyntxFunc::SyntxFunc(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("function");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	//id
	//

	//
	//params
	//

	exp_token.str_Token_lex.push_back(":");
	exp_token.v_Token_Type.push_back(SEPARATOR);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	//exp/block/procs/funcs
	//
	
}

void Compiler_code_logic_thing::SyntxFunc::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Expresion List //////////////////////////////
Compiler_code_logic_thing::SyntxExp_L::SyntxExp_L(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	// magias negras plz send help
}

void Compiler_code_logic_thing::SyntxExp_L::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Function | Procedure call //////////////////////////////
Compiler_code_logic_thing::SyntxProcFunc_call::SyntxProcFunc_call(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;

	//
	//id
	//

	exp_token.str_Token_lex.push_back("(");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();

	//
	//exp list
	//

	exp_token.str_Token_lex.push_back(")");
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();
}

void Compiler_code_logic_thing::SyntxProcFunc_call::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Return //////////////////////////////
Compiler_code_logic_thing::SyntxReturn::SyntxReturn(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {

}

void Compiler_code_logic_thing::SyntxReturn::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Type //////////////////////////////
Compiler_code_logic_thing::SyntxType::SyntxType(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {
	S_TOKEN_EXPECTED exp_token;
	exp_token.str_Token_lex.push_back("int");
	exp_token.str_Token_lex.push_back("float");
	exp_token.str_Token_lex.push_back("string");
	exp_token.str_Token_lex.push_back("bool");
	exp_token.v_Token_Type.push_back(INT);
	exp_token.v_Token_Type.push_back(FLOAT);
	exp_token.v_Token_Type.push_back(STRING);
	exp_token.v_Token_Type.push_back(KEYWORD);
	exp_token.b_Required = 1;
	exp_token.b_Repeated = 0;
	m_ExpectedTokens.push_back(exp_token);

	exp_token.str_Token_lex.clear();
	exp_token.v_Token_Type.clear();


}

void Compiler_code_logic_thing::SyntxType::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
////////////////////////////// Syntx Block or BlockSwitch //////////////////////////////
Compiler_code_logic_thing::SyntxBlock_or_BlockSwitch::SyntxBlock_or_BlockSwitch(Lex_analizer * lexx, Syntax_analizer * syntt) :SyntaxStateM(lexx, syntt) {

}

void Compiler_code_logic_thing::SyntxBlock_or_BlockSwitch::CheckSyntax() {
	int i = 0;
	while (indexToExpToken < m_ExpectedTokens.size()) {
		while (i < m_ExpectedTokens[indexToExpToken].str_Token_lex.size())
		{
			//Here check compare tokens//
			//if the lex of next token
			if (lex->peekToken(0)->GetLex() == m_ExpectedTokens[indexToExpToken].str_Token_lex[i]) {
				SyntaxStateM * S = synt->getSyntxState(	// vector of exp tokens @ xxxx's token type in str
					m_ExpectedTokens[indexToExpToken].str_Token_lex[i]);
				if (S != nullptr) {
					S->CheckSyntax();
				}
			}
			else if (m_ExpectedTokens[indexToExpToken].b_Required) {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			else {
				if (m_ExpectedTokens[indexToExpToken].b_Repeated) {
					--i;
				}
				else {

				}
			}
			++i;
		}
		++indexToExpToken;
	}
}
