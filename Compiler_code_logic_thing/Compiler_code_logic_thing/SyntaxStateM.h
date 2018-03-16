#pragma once
#include "Token.h"
#include <vector>
#include "Syntax_analizer.h"
#include "Lex_analizer.h"
// SyntaxStateM * S = new SyntxProg();
//S->CheckSyntax();
namespace Compiler_code_logic_thing {
	struct S_TOKEN_EXPECTED {
		std::vector<TOKEN_TYPE>v_Token_Type;
		std::vector<std::string>str_Token_lex;
		bool b_Required;
		bool b_Repeated;
		bool b_Conditional;
		int goToIndex = 0;
	};

	class Syntax_analizer;

	////////////////////////////// Syntx State //////////////////////////////
	class SyntaxStateM {
	public:
		SyntaxStateM(Lex_analizer * lexx, Syntax_analizer * syntt);
		~SyntaxStateM();
		virtual void CheckSyntax() = 0;
		virtual SyntaxStateM* clone() = 0;
	protected:
		Syntax_analizer * synt;
		Lex_analizer * lex;
		std::vector<S_TOKEN_EXPECTED> m_ExpectedTokens;
		int indexToExpToken;
	};
	////////////////////////////// Syntx Program //////////////////////////////
	class SyntxProg : public SyntaxStateM {
	public:
		SyntxProg(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxProg(lex, synt); }
	};
	////////////////////////////// Syntx Var //////////////////////////////
	class SyntxVar : public SyntaxStateM {
	public:
		SyntxVar(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxVar(lex, synt); }
	};
	////////////////////////////// Syntx Main //////////////////////////////
	class SyntxMain : public SyntaxStateM {
	public:
		SyntxMain(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxMain(lex, synt); }
	};
	////////////////////////////// Syntx Inc & Dec //////////////////////////////
	class SyntxIncDec : public SyntaxStateM {
	public:
		SyntxIncDec(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxIncDec(lex, synt); }
	};
	////////////////////////////// Syntx Dimension //////////////////////////////
	class SyntxDimension : public SyntaxStateM {
	public:
		SyntxDimension(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxDimension(lex, synt); }
	};
	////////////////////////////// Syntx Switch //////////////////////////////
	class SyntxSwitch : public SyntaxStateM {
	public:
		SyntxSwitch(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxSwitch(lex, synt); }
	};
	////////////////////////////// Syntx While //////////////////////////////
	class SyntxWhile : public SyntaxStateM {
	public:
		SyntxWhile(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxWhile(lex, synt); }
	};
	////////////////////////////// Syntx For //////////////////////////////
	class SyntxFor : public SyntaxStateM {
	public:
		SyntxFor(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxFor(lex, synt); }
	};
	////////////////////////////// Syntx Read //////////////////////////////
	class SyntxRead : public SyntaxStateM {
	public:
		SyntxRead(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxRead(lex, synt); }
	};
	////////////////////////////// Syntx Print //////////////////////////////
	class SyntxPrint : public SyntaxStateM {
	public:
		SyntxPrint(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxPrint(lex, synt); }
	};
	////////////////////////////// Syntx If //////////////////////////////
	class SyntxIf : public SyntaxStateM {
	public:
		SyntxIf(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxIf(lex, synt); }
	};
	////////////////////////////// Syntx Param //////////////////////////////
	class SyntxParam : public SyntaxStateM {
	public:
		SyntxParam(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxParam(lex, synt); }
	};
	////////////////////////////// Syntx Assing //////////////////////////////
	class SyntxAssing : public SyntaxStateM {
	public:
		SyntxAssing(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxAssing(lex, synt); }
	};
	////////////////////////////// Syntx Procedure //////////////////////////////
	class SyntxProc : public SyntaxStateM {
	public:
		SyntxProc(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxProc(lex, synt); }
	};
	////////////////////////////// Syntx Function //////////////////////////////
	class SyntxFunc : public SyntaxStateM {
	public:
		SyntxFunc(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxFunc(lex, synt); }
	};
	////////////////////////////// Syntx Expresion List //////////////////////////////
	class SyntxExp_L : public SyntaxStateM {
	public:
		SyntxExp_L(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxExp_L(lex, synt); }
	};
	////////////////////////////// Syntx Proc/Func call //////////////////////////////
	class SyntxProcFunc_call : public SyntaxStateM {
	public:
		SyntxProcFunc_call(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxProcFunc_call(lex, synt); }
	};
	////////////////////////////// Syntx Return //////////////////////////////
	class SyntxReturn : public SyntaxStateM {
	public:
		SyntxReturn(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxReturn(lex, synt); }
	};
	////////////////////////////// Syntx Type //////////////////////////////
	class SyntxType : public SyntaxStateM {
	public:
		SyntxType(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxType(lex, synt); }
	};
	////////////////////////////// Syntx Block/Block switch //////////////////////////////
	class SyntxBlock_or_BlockSwitch : public SyntaxStateM {
	public:
		SyntxBlock_or_BlockSwitch(Lex_analizer * lexx, Syntax_analizer * syntt);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxBlock_or_BlockSwitch(lex, synt); }
	};
}

