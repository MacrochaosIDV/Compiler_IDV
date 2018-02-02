#pragma once
#include<string>


namespace Compiler_code_logic_thing {
	enum TOKEN_TYPE
	{
		UNDEFINED = 0,
		ID,
		INT,
		FLOAT,
		STRING,
		LOGICAL_CONSTANT,
		KEYWORD,
		SEPARATOR,
		RELATIONAL_OPE,
		ARITHMETIC_OPE,
		LOGICAL_OPE,
		LOGICAL_UNARY_OPE,
		ASSIGN_OPE,
		GROUPING_OPE,
		DIMENSION_OPE
	};
	class Token
	{
	private:
		std::string m_Lex;
		TOKEN_TYPE m_Type;
		int m_LineNumber = 0;
	public:

		Token(std::string lex, TOKEN_TYPE, int lineNum);
		~Token();

		std::string GetLex() const { return m_Lex; }
		std::string GetTypeStr();
		TOKEN_TYPE GetType() const { return m_Type; }
		int GetLineNumber() const { return m_LineNumber; }

	};
}

