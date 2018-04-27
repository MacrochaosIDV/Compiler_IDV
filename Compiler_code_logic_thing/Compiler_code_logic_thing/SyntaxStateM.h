#pragma once
#include "Token.h"
#include <vector>
#include "Syntax_analizer.h"
#include "Lex_analizer.h"
#include "SymbolTable.h"
//#include "Semantic_analizer.h"
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
	struct SNESTED_LVL {
		int nOperands = 0;
		int nOperators = 0;
	};

	class Syntax_analizer;

	////////////////////////////// Syntx State //////////////////////////////
	class SyntaxStateM {
	public:
		SyntaxStateM(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		~SyntaxStateM();
		virtual void CheckSyntax() = 0;
		virtual SyntaxStateM* clone() = 0;
	protected:
		Syntax_analizer * synt;
		Lex_analizer * lex;
		SymbolTable * symbl_tbl;
		std::vector<S_TOKEN_EXPECTED> m_ExpectedTokens;
		int indexToExpToken;
	};
	////////////////////////////// Syntx Program //////////////////////////////
	class SyntxProg : public SyntaxStateM {
	public:
		SyntxProg(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxProg(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Var //////////////////////////////
	class SyntxVar : public SyntaxStateM {
	public:
		SyntxVar(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxVar(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Main //////////////////////////////
	class SyntxMain : public SyntaxStateM {
	public:
		SyntxMain(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxMain(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Inc & Dec //////////////////////////////
	class SyntxIncDec : public SyntaxStateM {
	public:
		SyntxIncDec(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxIncDec(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Dimension //////////////////////////////
	class SyntxDimension : public SyntaxStateM {
	public:
		SyntxDimension(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxDimension(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Switch //////////////////////////////
	class SyntxSwitch : public SyntaxStateM {
	public:
		SyntxSwitch(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxSwitch(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx While //////////////////////////////
	class SyntxWhile : public SyntaxStateM {
	public:
		SyntxWhile(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxWhile(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx For //////////////////////////////
	class SyntxFor : public SyntaxStateM {
	public:
		SyntxFor(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxFor(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Read //////////////////////////////
	class SyntxRead : public SyntaxStateM {
	public:
		SyntxRead(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxRead(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Print //////////////////////////////
	class SyntxPrint : public SyntaxStateM {
	public:
		SyntxPrint(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxPrint(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx If //////////////////////////////
	class SyntxIf : public SyntaxStateM {
	public:
		SyntxIf(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxIf(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Param //////////////////////////////
	class SyntxParam : public SyntaxStateM {
	public:
		SyntxParam(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxParam(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Assing //////////////////////////////
	class SyntxAssing : public SyntaxStateM {
	public:
		SyntxAssing(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxAssing(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Procedure //////////////////////////////
	class SyntxProc : public SyntaxStateM {
	public:
		SyntxProc(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxProc(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Function //////////////////////////////
	class SyntxFunc : public SyntaxStateM {
	public:
		SyntxFunc(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxFunc(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Expresion List //////////////////////////////
	class SyntxExp_L : public SyntaxStateM {
	public:
		SyntxExp_L(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxExp_L(lex, synt, symbl_tbl); }
		bool ProcessExpresion();
		bool Process_ProcFunc_Call();
		void Eval_Expr(vector<const Token*> * vExpr_tokens, vector<SNESTED_LVL> * vNestedLVL, int * currNestedLVL, int * nErrors);
		void Eval_Term(vector<const Token*> * vExpr_tokens, vector<SNESTED_LVL> * vNestedLVL, int * currNestedLVL, int * nErrors);
		//int CheckErrors_Expr(vector<SNESTED_LVL> & vNestedLVL, int & currNestedLVL, int * nErrors);
		bool isOperator(string ope);
		bool isOperand(string operand);
		bool isConst(string const_maybe);
		bool CheckForNot();
	};
	////////////////////////////// Syntx Proc/Func call //////////////////////////////
	class SyntxProcFunc_call : public SyntaxStateM {
	public:
		SyntxProcFunc_call(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxProcFunc_call(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Return //////////////////////////////
	class SyntxReturn : public SyntaxStateM {
	public:
		SyntxReturn(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxReturn(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Type //////////////////////////////
	class SyntxType : public SyntaxStateM {
	public:
		SyntxType(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxType(lex, synt, symbl_tbl); }
	};
	////////////////////////////// Syntx Block/Block switch //////////////////////////////
	class SyntxBlock_or_BlockSwitch : public SyntaxStateM {
	public:
		SyntxBlock_or_BlockSwitch(Lex_analizer * lexx, Syntax_analizer * syntt, SymbolTable * symbl_tbll);
		void CheckSyntax();
		SyntaxStateM* clone() { return new SyntxBlock_or_BlockSwitch(lex, synt, symbl_tbl); }
	};
}

