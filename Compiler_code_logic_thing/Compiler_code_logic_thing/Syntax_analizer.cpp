#include "stdafx.h"
#include "Syntax_analizer.h"

Compiler_code_logic_thing::Syntax_analizer::~Syntax_analizer() {
	
}

Compiler_code_logic_thing::Syntax_analizer::Syntax_analizer(Error_Module ^errr, Lex_analizer * lexx) {
	err =  errr;
	lex = lexx;
	m_Syntx_State_Map.insert(std::make_pair("program", new SyntxProg(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("main", new SyntxMain(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("var", new SyntxVar(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("procedure", new SyntxProc(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("funtion", new SyntxFunc(lex, this)));

	m_Syntx_State_Map.insert(std::make_pair("int", new SyntxType(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("float", new SyntxType(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("string", new SyntxType(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("bool", new SyntxType(lex, this)));

	m_Syntx_State_Map.insert(std::make_pair("inc", new SyntxIncDec(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("dec", new SyntxIncDec(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("=", new SyntxAssing(lex, this)));

	m_Syntx_State_Map.insert(std::make_pair("[", new SyntxDimension(lex, this)));

	m_Syntx_State_Map.insert(std::make_pair("switch", new SyntxSwitch(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("while", new SyntxWhile(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("for", new SyntxFor(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("if", new SyntxIf(lex, this)));

	m_Syntx_State_Map.insert(std::make_pair("return", new SyntxReturn(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("read", new SyntxRead(lex, this)));
	m_Syntx_State_Map.insert(std::make_pair("print", new SyntxPrint(lex, this)));

	//m_Syntx_State_Map.insert(std::make_pair("", new SyntxParam(lex, this)));	//first value is wat?
	//m_Syntx_State_Map.insert(std::make_pair("", new SyntxExp_L(lex, this)));	//how do I expresion?
	//m_Syntx_State_Map.insert(std::make_pair("", new SyntxProcFunc_call(lex, this)));	//
	m_Syntx_State_Map.insert(std::make_pair("{", new SyntxBlock_or_BlockSwitch(lex, this)));	//
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// v Non-Terminal Syntax Checking funtions v ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//void Compiler_code_logic_thing::Syntax_analizer::syntx_Program() {
//	//////////////////////////////// Processing Flags ////////////////////////////////
//	bool VarsProcessed = 0; 
//	bool FuncProcProcessed = 0;
//	bool MainProcessed = 0;
//	//////////////////////////////// Processing Flags ////////////////////////////////
//
//	const Token* t = lex->getNextToken();
//	while (t != NULL) {
//		if ((t->GetLex()).compare("var")) {
//			syntx_Vars();
//			VarsProcessed = 1;
//			if (MainProcessed || FuncProcProcessed) {
//				//addError();
//			}
//		}
//		if ((t->GetLex()).compare("function") || (t->GetLex()).compare("procedure")) {
//			syntx_FuncProc();
//			FuncProcProcessed = 1;
//			if(MainProcessed) {
//				//addError();
//			}
//				
//
//		}
//		if ((t->GetLex()).compare("main")) {
//			syntx_Main();
//			MainProcessed = 1;
//		}
//	}
//}
////void Compiler_code_logic_thing::Syntax_analizer::syntx_Prog_FTM() {
//
//void Compiler_code_logic_thing::Syntax_analizer::syntx_Main() {
//
//}
//
//void Compiler_code_logic_thing::Syntax_analizer::syntx_FuncProc() {
//
//}
//
//void Compiler_code_logic_thing::Syntax_analizer::syntx_Vars() {
//	const Token * t = lex->peekToken(0);
//	while (!t->GetLex().compare("var")) {
//		do {
//			t = lex->getNextToken();	////////////////////////////////
//			if (t->GetType() == ID) {
//				//add_to_Symbols(t);
//			}
//			else {
//				//addError();
//				//recoverFromError();
//			}
//			t = lex->getNextToken();	////////////////////////////////
//			if (!t->GetLex().compare("[")) {
//				//syntx_Dimension();
//			}
//		} while (!t->GetLex().compare(","));
//		if (t->GetLex().compare(":")) {
//			//addError();
//			//RecoverFromError();
//		}
//		t = lex->getNextToken();	////////////////////////////////
//		//syntx_Type();
//		t = lex->getNextToken();	////////////////////////////////
//		if (t->GetLex().compare(";")) {
//			//addError();
//			//RecoverFromError();
//		}
//		t = lex->getNextToken();	////////////////////////////////
//	}
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// ^ Non-Terminal Syntax Checking funtions ^ ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Compiler_code_logic_thing::Syntax_analizer::addError(int linenumber, const char *desc) {
	/*
	Error :: Varible cant have same ID as function or prodecure
	Error :: Param already defined
	Error :: Local var cant have same ID as param
	Error :: Expecting X, found Y
	Error :: Global var alredy defined
	Error :: Function or procedure already defined
	Error :: Local var already defined
	*/

	String ^ strDesc = gcnew String(desc);
	String ^ strLine = gcnew String("");
	err->addError(Compiler_code_logic_thing::ERROR_PHASE::SYNTX_ANALYZER, linenumber, strDesc, strLine);
}
void Compiler_code_logic_thing::Syntax_analizer::addErrorExpexted(int n, char * e, char * f) {
	string was_expecting = "Was expecting ";
	string expected(e);
	string was_found = "instead found ";
	string found(f);
	string line = was_expecting + e + was_found + f;
	addError(n, line.c_str());
}
bool Compiler_code_logic_thing::Syntax_analizer::syntaxizeCode() {
	reset();
	SyntaxStateM * S = getSyntxState("program");
	if (S != nullptr) {
		S->CheckSyntax();
	}
	else {
		delete S;
		S = nullptr;
	}
	//syntx_Program();
	//syntx_Prog_FTM();
	if (err->SYNTX_NumErrors == 0)
		return true;
	else
		return false;
}
void Compiler_code_logic_thing::Syntax_analizer::reset() {

}

Compiler_code_logic_thing::SyntaxStateM * Compiler_code_logic_thing::Syntax_analizer::getSyntxState(std::string str)
{
	SyntaxStateM * Psyntx = NULL;
	auto mapSyntx = m_Syntx_State_Map.find(str);
	if (mapSyntx != m_Syntx_State_Map.end()) {
		Psyntx = mapSyntx->second->clone();
	}
	return Psyntx;
}


