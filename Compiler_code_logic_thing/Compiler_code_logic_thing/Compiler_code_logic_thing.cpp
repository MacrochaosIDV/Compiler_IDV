// This is the main DLL file.

#include "stdafx.h"
#include "Compiler_code_logic_thing.h"


using namespace System;

cli::array<String^>^ Compiler_code_logic_thing::Manager::GetCompilationDetails() {
	int numErrorLines = 0;
	cli::array<String^>^ CompilationDetails;
	if (lex->succeeded()) {
		CompilationDetails = gcnew cli::array<String^>(1);
		CompilationDetails[0] = gcnew String("====== Compile succeded ======");
		return CompilationDetails;
	}
	else {
		numErrorLines = err->NumErrors + 3;
		CompilationDetails = gcnew cli::array<String^>(numErrorLines);
		for (int i = 0; i < numErrorLines; ++i) {
			CompilationDetails[i] = gcnew String("");
		}
		CompilationDetails[0] = String::Format("Compilation phase \tLine number \tDescription \t\t\tLine");
		CompilationDetails[1] = String::Format("---------------------------------------------------------");
		cli::array<String^>^ allErrors = err->Errors;
		for (int i = 2; i < numErrorLines - 1; ++i) {
			CompilationDetails[i] = allErrors[i - 2];
		}
		CompilationDetails[numErrorLines - 1] = String::Format("====== Compile: failed, {0} errors ======", err->Errors);
		return CompilationDetails;
	}
}

cli::array<String^>^ Compiler_code_logic_thing::Manager::compile(String ^ src_txt)
{
	//throw gcnew System::NotImplementedException();
	// TODO: insert return statement here

	cli::array<String^>^ compilation_details;

	//Clear state
	if (err && lex != NULL) {
		err->clearErrors();
	}
	else {
		if (!err) {
			compilation_details = gcnew cli::array<String^>(1);
			compilation_details[0] = gcnew String("====== Compiler: fatal internal error on error module ======");
			return compilation_details;
		}
		else if (lex == NULL) {
			compilation_details = gcnew cli::array<String^>(1);
			compilation_details[0] = gcnew String("====== Compiler: fatal internal error on Lexic analizer module ======");
			return compilation_details;
		}
	}
	//======== Lexic analysis ========//
	lex->parse_Code((const char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(src_txt).ToPointer());
	//======== Syntax analysis ========//
	syntx->syntaxizeCode();

	//======== Semantic analysis ========//
	//TO DO

	//compilation_details = gcnew cli::array<String^>(1);
	//compilation_details[0] = gcnew String("Compiler start");
	
	

	
	
	compilation_details = GetCompilationDetails();

	return compilation_details;
	
}
cli::array<String^>^ Compiler_code_logic_thing::Manager::getAllTokens() {
	cli::array<String ^ > ^ allTokens;
	if (lex->GetNumTokens() > 0) {

		allTokens = gcnew cli::array<String ^ >(lex->GetNumTokens());
		std::vector<Token *> allTokensVec;
		lex->GetTokens(&allTokensVec);

		for (int i = 0; i < allTokensVec.size(); ++i) {
			String ^ lex_ = gcnew String(allTokensVec[i]->GetLex().c_str());
			String ^ typ_ = gcnew String(allTokensVec[i]->GetTypeStr().c_str());
			allTokens[i] = gcnew String("");
			allTokens[i] = String::Format("{0}\t\t{1}", lex_, typ_);
		}
	}
	else {
		allTokens = gcnew cli::array<String^>(1);
		allTokens[0] = gcnew String("NO TOKENS FOUND");
	}
	return allTokens;
}
