#pragma once
#include <string>

//using namespace System;

namespace Compiler_code_logic_thing {

	public enum class ERROR_PHASE
	{
		GLOBAL,
		LEX_ANALYZER,
		SYN_ANALYZER,
		SEM_ANALYZER,
		CODE_GENERATION
	};

#define MAX_UAD_COMPILER_ERRORS 100

	public ref class Error_Module
	{
	private:
		int numErrors;
		cli::array<System::String ^> ^ errorsArray;

	public:
		//cli::array<String^>^ Errors;
		//int numErrors = 0;
		Error_Module();
		~Error_Module();

		bool addError(ERROR_PHASE errorPhase, int lineNumber, System::String ^ errorDesc, System::String ^ errorLine);
		void clearErrors();

		property int NumErrors
		{
			int get()
			{
				return numErrors;
			}
		}

		property int MaxErrors
		{
			int get()
			{
				return MAX_UAD_COMPILER_ERRORS;
			}
		}

		property cli::array<System::String ^> ^ Errors
		{
			cli::array<System::String ^> ^ get()
			{
				return errorsArray;
			}
		}
	};

}