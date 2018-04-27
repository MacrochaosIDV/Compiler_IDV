// Compiler_code_logic_thing.h

#pragma once
#include <string>
#include <vector>
#include "Lex_analizer.h"
#include "Error_Module.h"
#include "Syntax_analizer.h"
#include "Token.h"
#include "SymbolTable.h"
#include "Semantic_analizer.h"

//.h
//lexic
//syntax
//semantic

//#include <winsock2.h>
using namespace System;

namespace Compiler_code_logic_thing {

	

	public ref class Manager {
	private :

		Lex_analizer* lex;
		Error_Module ^ err;
		Syntax_analizer * syntx;
		SymbolTable * symtbl;
		Semantic_analizer * sem;

		// TODO: Add your methods for this class here.
	public:

		Manager() {
			err = gcnew Error_Module();
			lex = new Lex_analizer(err);
			sem = new Semantic_analizer();
			syntx = new Syntax_analizer(err, lex, sem);
			symtbl = new SymbolTable();
			
		}
		~Manager() {
			delete err;
			delete lex;
			delete syntx;
		}

		cli::array<String^>^ GetCompilationDetails();
		cli::array<String^>^ compile(String ^ src_txt);
		cli::array<String^>^ getAllTokens();
		//void lexAnalysis(String ^ src_txt);
		//^ reference to pointer

	};

	

}
