#include "stdafx.h"
#include "Token.h"


Compiler_code_logic_thing::Token::Token(std::string lex, TOKEN_TYPE t, int lineNum)
{
	m_Lex = lex;
	m_Type = t;
	m_LineNumber = lineNum;
}

Compiler_code_logic_thing::Token::~Token()
{
}

std::string Compiler_code_logic_thing::Token::GetTypeStr()
{
	std::string TypeStr = "";
	static const char* EnumStrings[] = {
		"UNDEFINED",
		"ID",
		"INT",
		"FLOAT",
		"STRING",
		"LOGICAL_CONSTANT",
		"KEYWORD",
		"SEPARATOR",
		"RELATIONAL_OPE",
		"ARITHMETIC_OPE",
		"LOGICAL_OPE",
		"LOGICAL_UNARY_OPE",
		"ASSIGN_OPE",
		"GROUPING_OPE",
		"DIMENSION_OPE"
	};
	TypeStr = EnumStrings[m_Type];
	return TypeStr;
}
