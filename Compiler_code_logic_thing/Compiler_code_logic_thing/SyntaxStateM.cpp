#include "stdafx.h"
#include "SyntaxStateM.h"
#include "Syntax_analizer.h"
#include "Semantic_analizer.h"

////////////////////////////// Syntx State //////////////////////////////
Compiler_code_logic_thing::SyntaxStateM::SyntaxStateM(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) {
	indexToExpToken = 0;
	lex = lexx;
	synt = syntt;
	symbl_tbl = symbl_tbll;
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
Compiler_code_logic_thing::SyntxProg::SyntxProg(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll):
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxVar::SyntxVar(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxMain::SyntxMain(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxIncDec::SyntxIncDec(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxDimension::SyntxDimension(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxSwitch::SyntxSwitch(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxWhile::SyntxWhile(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {

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
Compiler_code_logic_thing::SyntxFor::SyntxFor(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {

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
Compiler_code_logic_thing::SyntxRead::SyntxRead(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxPrint::SyntxPrint(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxIf::SyntxIf(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxParam::SyntxParam(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxAssing::SyntxAssing(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxProc::SyntxProc(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxFunc::SyntxFunc(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxExp_L::SyntxExp_L(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
bool Compiler_code_logic_thing::SyntxExp_L::ProcessExpresion() {
	vector<SNESTED_LVL> vNestedLvls;
	vector<const Token*> vExpr_tokens;
	int currNestedLvl = 0;
	int nErrors = 0;
	SNESTED_LVL Lvl_0;
	vNestedLvls.push_back(Lvl_0);
	Eval_Expr(&vExpr_tokens, &vNestedLvls, &currNestedLvl, &nErrors);
	synt->getSem()->addExpLog("hellow" , vExpr_tokens);
	return false;
}

bool Compiler_code_logic_thing::SyntxExp_L::Process_ProcFunc_Call() {

	return false;
}

void Compiler_code_logic_thing::SyntxExp_L::Eval_Expr(vector<const Token*> * vExpr_tokens, vector<SNESTED_LVL> * vNestedLVL, int * currNestedLVL, int * nErrors) {
	Eval_Term(vExpr_tokens, vNestedLVL, currNestedLVL, nErrors);
	const Token * t = lex->getNextToken();
	if (t == nullptr) {
		return;
	}
	vExpr_tokens->push_back(t);
	if (isOperator(t->GetLex())) {
		vNestedLVL->at(*currNestedLVL).nOperators++;
		t = lex->getNextToken();
		if (t == nullptr) {
			return;
		}
		vExpr_tokens->push_back(t);
		Eval_Expr(vExpr_tokens, vNestedLVL, currNestedLVL, nErrors);
	}
}

void Compiler_code_logic_thing::SyntxExp_L::Eval_Term(vector<const Token*> * vExpr_tokens, vector<SNESTED_LVL> *  vNestedLVL, int * currNestedLVL, int * nErrors) {
	bool negatedTerm = CheckForNot();
	const Token * t = lex->peekToken(0);
	
	if (!t->GetLex().compare("(")) {
		////////////// If case 1 start ////////////// 111111111111111111111111111111111111111111111
		vNestedLVL->at(*currNestedLVL).nOperands++;
		SNESTED_LVL nextLVL;
		vNestedLVL->push_back(nextLVL);
		t = lex->getNextToken();
		if (t == nullptr) {
			return;
		}
		vExpr_tokens->push_back(t);
		Eval_Expr(vExpr_tokens, vNestedLVL, currNestedLVL, nErrors);
		if (!t->GetLex().compare(")")) {
			// Chech Errors
			if (vNestedLVL->at(*currNestedLVL).nOperands < 1) {
				//addError();
				//++nErrors;
			}
			if (vNestedLVL->at(*currNestedLVL).nOperands > 0 && vNestedLVL->at(*currNestedLVL).nOperands != (vNestedLVL->at(*currNestedLVL).nOperators + 1)) {
				//addError();
				//++nErrors;
			}
			(*currNestedLVL)--;
		}
		if (*currNestedLVL > 0) {
			//addError();
			//++nErrors;
		}
	}
	////////////// If case 1 end ////////////// 111111111111111111111111111111111111111111111
	
	else if (isConst(t->GetLex())) {
		////////////// If case 2 start ////////////// 22222222222222222222222222222222222222222222
		if (negatedTerm && t->GetType() != LOGICAL_CONSTANT) {
			//addError();
			//++nErrors;
		}
		vNestedLVL->at(*currNestedLVL).nOperands++;
	}
	////////////// If case 2 end ////////////// 22222222222222222222222222222222222222222222
	else if (isOperand(t->GetLex())) {
		////////////// If case 3 start ////////////// 33333333333333333333333333333333333333333333
		if (t->GetType() == FUNC) {
			Process_ProcFunc_Call();
		}
		else if (t->GetType() == PROC) {
			//addError();
			//++nErrors;
		}
		if (negatedTerm) {
			bool typeIsBoolable = symbl_tbl->getSymbolTypeBoolable(t/*->GetType()*/);
				if (!typeIsBoolable) {
					//addError();
					//++nErrors;
			}
		}
	}
	////////////// If case 3 end ////////////// 33333333333333333333333333333333333333333333
}
/*int Compiler_code_logic_thing::SyntxExp_L::CheckErrors_Expr(vector<SNESTED_LVL> & vNestedLVL, int & currNestedLVL, int * nErrors) {
	// Chech Errors
	if (vNestedLVL.at(currNestedLVL).nOperands < 1) {
		//addError();
		//++nErrors;
	}
	if (vNestedLVL.at(currNestedLVL).nOperands > 0 && vNestedLVL.at(currNestedLVL).nOperands != (vNestedLVL.at(currNestedLVL).nOperators + 1)) {
		//addError();
		//++nErrors;
	}
	if (currNestedLVL > 0) {
		//addError();
		//++nErrors;
	}
	return *nErrors;
}*/

/////////////////// Assist funcs ///////////////////

bool Compiler_code_logic_thing::SyntxExp_L::isOperator(string ope) {
	if (ope == "+" || ope == "-" || ope == "*" || ope == "/" || ope == "^") {
		return true;
	}
	else {
		return false;
	}
}
bool Compiler_code_logic_thing::SyntxExp_L::isOperand(string operand) {

	return false;
}
bool Compiler_code_logic_thing::SyntxExp_L::isConst(string const_maybe) {

	return false;
}
bool Compiler_code_logic_thing::SyntxExp_L::CheckForNot() {
	const Token * t = lex->getNextToken();
	if (t->GetType() == LOGICAL_UNARY_OPE) {
		t = lex->getNextToken();
		return true;
	}
	return false;
}
////////////////////////////// Syntx Function | Procedure call //////////////////////////////
Compiler_code_logic_thing::SyntxProcFunc_call::SyntxProcFunc_call(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
Compiler_code_logic_thing::SyntxReturn::SyntxReturn(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {

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
Compiler_code_logic_thing::SyntxType::SyntxType(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {
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
					S->CheckSyntax();//inf loop plz fix
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
Compiler_code_logic_thing::SyntxBlock_or_BlockSwitch::SyntxBlock_or_BlockSwitch(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll) :
	SyntaxStateM(lexx, syntt, symbl_tbll) {

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
