#include "stdafx.h"
#include "Error_Module.h"

using namespace Compiler_code_logic_thing;

Compiler_code_logic_thing::Error_Module::Error_Module() {
	numErrors = 0;

	errorsArray = gcnew cli::array<System::String ^>(MAX_UAD_COMPILER_ERRORS);

	for (int i = 0; i < MAX_UAD_COMPILER_ERRORS; i++)
	{
		errorsArray[i] = gcnew System::String("");
	}
}

Compiler_code_logic_thing::Error_Module::~Error_Module()
{
	throw gcnew System::NotImplementedException();
}

bool Compiler_code_logic_thing::Error_Module::addError(ERROR_PHASE errorPhase, int lineNumber, System::String ^ errorDesc, System::String ^ errorLine)
{
	if (numErrors < MAX_UAD_COMPILER_ERRORS)
	{
		System::String ^ errLine = gcnew System::String("");
		if (errorLine->Length > 20)
		{
			errLine = errorLine->Substring(0, 20);
		}
		else
		{
			errLine = errorLine;
		}

		errorsArray->SetValue(System::String::Format("<{0}>: \t{1} \t\t{2} \t\t{3}", errorPhase.ToString(), lineNumber, errorDesc, errLine), numErrors);
		++numErrors;
		if (errorPhase == ERROR_PHASE::LEX_ANALYZER) {
			++numErr_Lex;
		}
		else if (errorPhase == ERROR_PHASE::SYNTX_ANALYZER) {
			++numErr_Syntx;
		}
		else if (errorPhase == ERROR_PHASE::SEM_ANALYZER) {
			++numErr_Sem;
		}
		return true;
	}

	return false;
}

void Compiler_code_logic_thing::Error_Module::clearErrors()
{
	//throw gcnew System::NotImplementedException();
	// Clear num errors
	numErrors = 0;
}
