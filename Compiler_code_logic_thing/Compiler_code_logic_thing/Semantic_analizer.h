#pragma once
#include "Syntax_analizer.h"
#include "Token.h"
#include "Error_Module.h"
#include "ExpLogTree.h"
using std::map;
using msclr::gcroot;
namespace Compiler_code_logic_thing {

	class Semantic_analizer {
	private:
		Syntax_analizer * synt;
		gcroot<Error_Module ^> managedRef_errMod;
		map<int, ExpLogTree*> if_for_while_Expr;
		map<string, ExpLogTree*> return_Expr;
		map<string, ExpLogTree*> assing_Expr;
		map<string, vector<const Token*>> m_logExpMap;

	public:
		//Notacion postfija
		void evalExprns(); //main func
		void addExpLog(string , vector<const Token*>);//converts infix 2 postfix & adds to map
		vector<const Token*> infix2Postfix(vector<const Token*> logExp);
		Semantic_analizer();
	};
}


