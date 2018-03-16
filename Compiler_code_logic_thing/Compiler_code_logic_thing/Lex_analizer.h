#pragma once
#include <string>
#include<vector>
#include<map>
#include"Token.h"
#include"Error_Module.h"
#include<Windows.h>
#include<vcclr.h>

using namespace System;
using namespace std;

enum LEX_STATE {
	S_START = 0,
	S_PARSING_ID,				  //							 // ----- Stg 3 done ----- //
	S_PARSING_INT,				  //							 // ----- Stg 3 done ----- //
	S_PARSING_FLOAT,			  //							 // ----- Stg 3 done ----- //
	S_PARSING_STRING,			  //							 // ----- Stg 3 done ----- // bugged
	S_PARSING_LESSTHAN,			  // Relational ope				 // ----- Stg 3 done ----- //
	S_PARSING_LESSTHANOREQUAL,	  // Relational ope -> <=		 // ----- Stg 3 done ----- //
	S_PARSING_GREATERTHAN,		  // Relational ope				 // ----- Stg 3 done ----- //
	S_PARSING_GREATERTHANOREQUAL, // Relational ope -> >=		 // ----- Stg 3 done ----- //
	S_PARSING_ASSIGN,			  // assing						 // ----- Stg 3 done ----- //
	S_PARSING_EQUAL,			  // assing -> ==				 // ----- Stg 3 done ----- //
	S_PARSING_NOTEQUAL,			  //  Logic ope -> !=			 // ----- Stg 3 done ----- //
	S_PARSING_OPENPARENTHESIS,	  //							 // ----- Stg 3 done ----- //
	S_PARSING_CLOSEPARENTHESIS,	  //							 // ----- Stg 3 done ----- //
	S_PARSING_ARITHMETICOP,		  // Aritmetic ope				 // ----- Stg 3 done ----- //
	S_PARSING_LOGICAL_OP_AND,	  // Logic ope					 // ----- Stg 3 done ----- //
	S_PARSING_LOGICAL_OP_OR,	  // Logic ope					 // ----- Stg 3 done ----- //
	S_PARSING_LOGICAL_OP_NOT,	  // Logic ope					 // ----- Stg 3 done ----- //
	S_PARSING_OPENBRACKET,		  //							 // ----- Stg 3 done ----- //
	S_PARSING_CLOSEBRACKET,		  //							 // ----- Stg 3 done ----- //
	S_PARSING_OPENCURLYBRACKET,   //							 // ----- Stg 3 done ----- //
	S_PARSING_CLOSECURLYBRACKET,  //							 // ----- Stg 3 done ----- //
	S_PARSING_SEMICOLON,		  // ; is semiclon				 // ----- Stg 3 done ----- //
	S_PARSING_COMMA,			  //							 // ----- Stg 3 done ----- //
	S_PARSING_COLON,			  // : is colon					 // ----- Stg 3 done ----- //
	S_PARSING_COMMENT_START,	  // Aritmetic ope -> comment    // ----- Stg 3 done ----- //
	S_PARSING_COMMENT_MIDDLE	  //							 // ----- Stg 3 done ----- //

};

#define LEX_ERROR_INVALID_CHARACTER			"Invalid character"
#define LEX_ERROR_STRING_NOT_CLOSED			"Literal constant not closed"
#define LEX_ERROR_COMMENT_NOT_CLOSED		"Comment not closed"
#define LEX_ERROR_INVALID_FLOAT				"Invalid floating point number. Digit expected"
#define LEX_ERROR_INVALID_LOGICAL_OP_AND	"Invalid logical 'AND' operator. "
#define LEX_ERROR_INVALID_LOGICAL_OP_OR		"Invalid logical 'OR' operator."
#define LEX_ERROR_INVALID_STATE				"Internal error. Invalid state."

namespace Compiler_code_logic_thing {

	public class Lex_analizer
	{
	private:
		int currToken;
		
		bool m_Succeeded;											// PARSING SUCCEEDED?
		LEX_STATE m_State;												// CURRENT STATE

		msclr::gcroot<Error_Module ^> managedRef_errMod;				// REFERENCE TO MANAGED ERRORS MODULE

		std::map<std::string, std::string> m_Keywords;					// KEYWORDS
		std::vector<Token *> m_Tokens;									// TOKENS

		void addError(int lineNum, const char *desc, const char *line);	// ADD ERROR TO ERRORS MODULE
		void addError(int lineNum, const char *desc, const char *line, const char *curr_char, std::string & lineBuffer);
		void addToken(const char *lex, TOKEN_TYPE type, int lineNum);	// ADD TOKEN TO SYMBOLS TABLE AND TOKENS VECTOR
		void clearTokens();												// FREE MEMORY AND CLEAR TOKENS VECTOR

		//////////////////////////////////////// v Parsing Flags v ////////////////////////////////////////
		bool is_Alpha(const char * cur_char) const;
		bool is_Alpha_v2(const char * cur_char) const;
		bool is_Digit(const char * cur_char) const;
		bool is_Digit_v2(const char * cur_char) const;
		bool is_ValidChar(const char * cur_char) const;
		bool is_Space(const char * cur_char) const;
		bool is_NewLine(const char * cur_char) const;
		bool is_ArithmeticOpe(const char *cur_char) const;
		bool is_AssingOpe(const char * cur_char) const;
		bool is_RelationalOpe(const char *cur_char) const;
		bool is_RelationalOpe_v2(const char * cur_char) const;
		bool is_LogicalOpe(const char *cur_char) const;
		bool is_LogicalOpe_v2(const char * cur_char) const;
		bool is_Separator(const char *cur_char) const;
		bool is_GroupingChar(const char *cur_char) const;
		bool is_BlockChar(const char *cur_char) const;
		bool is_DimensionChar(const char *cur_char) const;
		bool is_StringLiteral(const char *cur_char) const;
		//////////////////////////////////////// ^ Parsing Flags ^ ////////////////////////////////////////

	public:
		Lex_analizer(Error_Module ^err);
		~Lex_analizer();
		bool parse_Code(const char * src);
		int GetNumTokens() const;
		void GetTokens(std::vector<Token *> *allTokensVec) const;

		const Token * getNextToken();
		const Token * peekToken(int offset);
		bool succeeded() const
		{
			return m_Succeeded;
		}
	};

}