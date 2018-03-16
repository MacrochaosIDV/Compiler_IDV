#include "stdafx.h"
#include "Lex_analizer.h"
#include <iterator>

using namespace Compiler_code_logic_thing;

Lex_analizer::Lex_analizer(Error_Module ^err) {
	//err
	managedRef_errMod = err;

	m_Keywords.insert(std::make_pair("var", ""));
	m_Keywords.insert(std::make_pair("int", ""));
	m_Keywords.insert(std::make_pair("float", ""));
	m_Keywords.insert(std::make_pair("string", ""));
	m_Keywords.insert(std::make_pair("bool", ""));
	m_Keywords.insert(std::make_pair("function", ""));
	m_Keywords.insert(std::make_pair("procedure", ""));
	m_Keywords.insert(std::make_pair("main", ""));
	m_Keywords.insert(std::make_pair("for", ""));
	m_Keywords.insert(std::make_pair("while", ""));
	m_Keywords.insert(std::make_pair("if", ""));
	m_Keywords.insert(std::make_pair("else", ""));
	m_Keywords.insert(std::make_pair("switch", ""));
	m_Keywords.insert(std::make_pair("default", ""));
	m_Keywords.insert(std::make_pair("print", ""));
	m_Keywords.insert(std::make_pair("read", ""));
	m_Keywords.insert(std::make_pair("return", ""));
}

Compiler_code_logic_thing::Lex_analizer::~Lex_analizer() {

}

bool Lex_analizer::parse_Code(const char * src) {
	int currentLineNum = 1;
	int numCharsInLine = 0;
	int floatDigitCount = 0;
	const char * currentChar = src;
	const char * currentLine = src;
	std::string tokenBuffer;
	std::string lineBufferString;
	std::string firstCommentLine;
	char lexSrcEof = '\0'; //end of file
	bool stringNotClosed = 0;
	TOKEN_TYPE tokenType = TOKEN_TYPE::UNDEFINED;
	m_Succeeded = true;
	m_State = S_START; // Compiler starts
	clearTokens();

	while (*currentChar != lexSrcEof) {
		switch (m_State)
		{				///////////////////////////////////////////////////////
		case S_START:	//////////////////// Parsing Start ////////////////////
						///////////////////////////////////////////////////////
			if (is_Space(currentChar)) { ////////// Space and newLine handling //////////
				if (is_NewLine(currentChar)) {
					++currentLineNum;
					//Move line pointer to next line
					currentLine = currentChar + 1;
				}
				++currentChar;
			}
			else if (*currentChar=='.') {
				//tokenBuffer.clear();
				addError(currentLineNum, LEX_ERROR_INVALID_FLOAT, currentLine, currentChar, lineBufferString);
				//tokenBuffer.clear();
				++currentChar;
			}
			else if (is_Alpha(currentChar) || *currentChar == '_') {
				tokenBuffer.clear();
				tokenBuffer.append(currentChar, 1);
				m_State = S_PARSING_ID;	////////// Go to Parsing ID //////////
				++currentChar;
			}
			else if (is_Digit(currentChar)) {
				tokenBuffer.clear();
				tokenBuffer.append(currentChar, 1);
				m_State = S_PARSING_INT;	////////// Go to Parsing int //////////
				++currentChar;
			}
			else if (is_StringLiteral(currentChar)) {
				//tokenBuffer.clear();
				//tokenBuffer.append(currentChar, 1);
				m_State = S_PARSING_STRING;	////////// Go to Parsing String //////////
				++currentChar;
			}
			else if (is_ArithmeticOpe(currentChar)) {
				if (*currentChar == '/') {
					if ((*currentChar + 1 != lexSrcEof) && (*currentChar + 1 == '*')) {
						m_State = S_PARSING_COMMENT_START;	////////// Go to Parsing start of comment //////////
						++currentChar;
						++currentChar;
					}
				}
				tokenBuffer.clear();
				tokenBuffer.append(currentChar, 1);
				m_State = S_PARSING_ARITHMETICOP;////////// Go to Parsing Aritmetic operator //////////
				++currentChar;
			}
			else if (is_RelationalOpe(currentChar)) {
				//tokenBuffer.clear();
				if (*currentChar == '<') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_LESSTHAN;	////////// Go to Parsing < //////////
					++currentChar;
				}
				else if (*currentChar == '>') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_GREATERTHAN;	////////// Go to Parsing > //////////
					++currentChar;
				}
				else if (*currentChar == '=') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_ASSIGN;	////////// Go to Parsing = //////////
					++currentChar;
				}
			}
			else if (is_LogicalOpe(currentChar)) {
				if (*currentChar == '!') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_LOGICAL_OP_NOT;	////////// Go to Parsing ! //////////
					++currentChar;
				}
				if (*currentChar == '|') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_LOGICAL_OP_OR;	////////// Go to Parsing | //////////
					++currentChar;
				}
				if (*currentChar == '&') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_LOGICAL_OP_AND;	////////// Go to Parsing & //////////
					++currentChar;
				}
			}
			else if (is_GroupingChar(currentChar)) {
				if (*currentChar == '(') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_OPENPARENTHESIS;	////////// Go to Parsing ( //////////
					++currentChar;
				}
				else if (*currentChar == ')') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_CLOSEPARENTHESIS;	////////// Go to Parsing ) //////////
					++currentChar;
				}
			}
			else if (is_DimensionChar(currentChar)) {
				if (*currentChar == '[') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_OPENBRACKET;	////////// Go to Parsing [ //////////
					++currentChar;
				}
				else if (*currentChar == ']') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_CLOSEBRACKET;	////////// Go to Parsing ] //////////
					++currentChar;
				}
			}
			else if (is_BlockChar(currentChar)) {
				if (*currentChar == '{') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_OPENCURLYBRACKET;	////////// Go to Parsing { //////////
					++currentChar;
				}
				else if (*currentChar == '}') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_CLOSECURLYBRACKET;	////////// Go to Parsing } //////////
					++currentChar;
				}
			}
			else if (is_Separator(currentChar)) {
				if (*currentChar == ',') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_COMMA;	////////// Go to Parsing , //////////
					++currentChar;
				}
				else if (*currentChar == ';') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_SEMICOLON;	////////// Go to Parsing ; //////////
					++currentChar;
				}
				else if (*currentChar == ':') {
					tokenBuffer.clear();
					tokenBuffer.append(currentChar, 1);
					m_State = S_PARSING_COLON;	////////// Go to Parsing : //////////
					++currentChar;
				}
			}
			break;			////////////////////////////////////////////////////
		case S_PARSING_ID:	//////////////////// Parsing ID ////////////////////
							////////////////////////////////////////////////////
				if(is_ValidChar(currentChar)) {

					tokenBuffer.append(currentChar, 1);
					++currentChar;
					if (*currentChar == lexSrcEof || is_Space(currentChar) || is_Separator(currentChar)) {
						//add token
						if (m_Keywords.find(tokenBuffer) != m_Keywords.end()) {
							//if is reading keyqord
							addToken(tokenBuffer.c_str(), TOKEN_TYPE::KEYWORD, currentLineNum);
						}
						else if (tokenBuffer.compare("true") == 0 || tokenBuffer.compare("false") == 0) {
							//if is reading true/false
							addToken(tokenBuffer.c_str(), TOKEN_TYPE::LOGICAL_CONSTANT, currentLineNum);
						}
						else {
							//if is reading other ID
							addToken(tokenBuffer.c_str(), TOKEN_TYPE::ID, currentLineNum);
						}
						m_State = S_START;
					}
				}
				else {
					//no append -> add token -> go to Start
					if (m_Keywords.find(tokenBuffer) != m_Keywords.end()) {
						addToken(tokenBuffer.c_str(), TOKEN_TYPE::KEYWORD, currentLineNum);
					}
					else if (tokenBuffer.compare("true") == 0 || tokenBuffer.compare("false") == 0) {
						addToken(tokenBuffer.c_str(), TOKEN_TYPE::LOGICAL_CONSTANT, currentLineNum);
					}
					else {
						addToken(tokenBuffer.c_str(), TOKEN_TYPE::ID, currentLineNum);
					}
					//addError(currentLineNum, LEX_ERROR_INVALID_CHARACTER, currentLine);
					m_State = S_START;
				}
				break;		/////////////////////////////////////////////////////
		case S_PARSING_INT:	//////////////////// Parsing int ////////////////////
							/////////////////////////////////////////////////////
			if (is_Digit(currentChar)) {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				if (*currentChar == lexSrcEof || is_Space(currentChar) || is_Separator(currentChar)) {
					addToken(tokenBuffer.c_str(), TOKEN_TYPE::INT, currentLineNum);
					m_State = S_START;
				}
			}
			else if (*currentChar == '.') {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				m_State = S_PARSING_FLOAT;
			}
			else {
				tokenBuffer.clear();
				addError(currentLineNum, LEX_ERROR_INVALID_CHARACTER, currentLine, currentChar, lineBufferString);
				m_State = S_START;
			}
			break;				///////////////////////////////////////////////////////
		case S_PARSING_FLOAT:	//////////////////// Parsing float ////////////////////
								///////////////////////////////////////////////////////
			//must check that first char after . is digit
			if (floatDigitCount == 0) {
				if (!is_Digit(currentChar)) {
					addError(currentLineNum, LEX_ERROR_INVALID_FLOAT, currentLine, currentChar, lineBufferString);
					m_State = S_START;
				}
			}
			//////////////
			else if (is_Digit(currentChar)) {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				++floatDigitCount;
				if (*currentChar == lexSrcEof || *currentChar == ' ' || *currentChar == '\t' || is_Separator(currentChar)) {
					addToken(tokenBuffer.c_str(), TOKEN_TYPE::FLOAT, currentLineNum);
					floatDigitCount = 0;
					m_State = S_START;
				}
			}
			else {
				tokenBuffer.clear();
				addError(currentLineNum, LEX_ERROR_INVALID_FLOAT, currentLine, currentChar, lineBufferString);
				floatDigitCount = 0; 
				m_State = S_START;
			}
			break;				////////////////////////////////////////////////////////
		case S_PARSING_STRING:	//////////////////// Parsing string ////////////////////
								////////////////////////////////////////////////////////
			if (*currentChar == lexSrcEof || is_NewLine(currentChar)) {
				addError(currentLineNum, LEX_ERROR_STRING_NOT_CLOSED, currentLine, currentChar, lineBufferString);
				//tokenBuffer.clear();
				++currentChar;
				m_State = S_START;
			}
			else if (is_StringLiteral(currentChar)) {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::STRING, currentLineNum);
				++currentChar;
				tokenBuffer.clear();
				m_State = S_START;
			}
			else {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
			}
			/*if (is_StringLiteral(currentChar)) {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::STRING, currentLineNum);
				m_State = S_START;
			}
			else if (*currentChar != lexSrcEof || !is_NewLine(currentChar)) {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
			}
			else {
				addError(currentLineNum, LEX_ERROR_STRING_NOT_CLOSED, currentLine, currentChar, lineBufferString);
				m_State = S_START;
			}*/
			break;					///////////////////////////////////////////////////
		case S_PARSING_LESSTHAN:	//////////////////// Parsing < ////////////////////
									///////////////////////////////////////////////////
			if (*currentChar == '=') {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				m_State = S_PARSING_LESSTHANOREQUAL;
			}
			/*else if (*currentChar == lexSrcEof || is_Space(currentChar) || is_Separator(currentChar)) {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
				m_State = S_START;
			}*/
			else {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
				m_State = S_START;
			}
			break;						////////////////////////////////////////////////////
		case S_PARSING_LESSTHANOREQUAL:	//////////////////// Parsing <= ////////////////////
										////////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;					///////////////////////////////////////////////////
		case S_PARSING_GREATERTHAN:	//////////////////// Parsing > ////////////////////
									///////////////////////////////////////////////////
			if (*currentChar == '=') {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				m_State = S_PARSING_GREATERTHANOREQUAL;
			}
			/*else if (*currentChar == lexSrcEof || is_Space(currentChar) || is_Separator(currentChar)) {
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
			m_State = S_START;
			}*/
			else {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
				m_State = S_START;
			}
			break;							////////////////////////////////////////////////////
		case S_PARSING_GREATERTHANOREQUAL:	//////////////////// Parsing >= ////////////////////
											////////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;				///////////////////////////////////////////////////
		case S_PARSING_ASSIGN :	//////////////////// Parsing = ////////////////////
								///////////////////////////////////////////////////
			if (*currentChar == '=') {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				m_State = S_PARSING_EQUAL;
			}
				/*else if (*currentChar == lexSrcEof || is_Space(currentChar) || is_Separator(currentChar)) {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
				m_State = S_START;
				}*/
			else {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::ASSIGN_OPE, currentLineNum);
				m_State = S_START;
			}
			break;				////////////////////////////////////////////////////
		case S_PARSING_EQUAL:	//////////////////// Parsing == ////////////////////
								////////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;					////////////////////////////////////////////////////
		case S_PARSING_NOTEQUAL:	//////////////////// Parsing != ////////////////////
									////////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::LOGICAL_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;						///////////////////////////////////////////////////
		case S_PARSING_OPENPARENTHESIS:	//////////////////// Parsing ( ////////////////////
										///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::GROUPING_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;							///////////////////////////////////////////////////
		case S_PARSING_CLOSEPARENTHESIS:	//////////////////// Parsing ) ////////////////////
											///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::GROUPING_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;						//////////////////////////////////////////////////////////
		case S_PARSING_ARITHMETICOP:	//////////////////// Parsing arit ope ////////////////////
										//////////////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::ARITHMETIC_OPE, currentLineNum);
			m_State = S_START;
			break;						////////////////////////////////////////////////////
		case S_PARSING_LOGICAL_OP_AND:	//////////////////// Parsing && ////////////////////
										////////////////////////////////////////////////////
			if (*currentChar == '&') {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::LOGICAL_OPE, currentLineNum);
				m_State = S_START;
			}
			else {
				tokenBuffer.clear();
				addError(currentLineNum, LEX_ERROR_INVALID_LOGICAL_OP_AND, currentLine, currentChar, lineBufferString);
				m_State = S_START;
			}
			break;						////////////////////////////////////////////////////
		case S_PARSING_LOGICAL_OP_OR:	//////////////////// Parsing || ////////////////////
										////////////////////////////////////////////////////
			if (*currentChar == '|') {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::LOGICAL_OPE, currentLineNum);
			}
			else {
				tokenBuffer.clear();
				addError(currentLineNum, LEX_ERROR_INVALID_LOGICAL_OP_OR, currentLine, currentChar, lineBufferString);
				m_State = S_START;
			}
			break;						///////////////////////////////////////////////////
		case S_PARSING_LOGICAL_OP_NOT:	//////////////////// Parsing ! ////////////////////
										///////////////////////////////////////////////////
			if (*currentChar == '=') {
				tokenBuffer.append(currentChar, 1);
				++currentChar;
				m_State = S_PARSING_NOTEQUAL;
			}
			/*else if (*currentChar == lexSrcEof || is_Space(currentChar) || is_Separator(currentChar)) {
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::RELATIONAL_OPE, currentLineNum);
			m_State = S_START;
			}*/
			else {
				addToken(tokenBuffer.c_str(), TOKEN_TYPE::LOGICAL_UNARY_OPE, currentLineNum);
				m_State = S_START;
			}
			break;					///////////////////////////////////////////////////
		case S_PARSING_OPENBRACKET:	//////////////////// Parsing [ ////////////////////
									///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::GROUPING_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;						///////////////////////////////////////////////////
		case S_PARSING_CLOSEBRACKET:	//////////////////// Parsing ] ////////////////////
										///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::GROUPING_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;							///////////////////////////////////////////////////
		case S_PARSING_OPENCURLYBRACKET:	//////////////////// Parsing { ////////////////////
											///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::GROUPING_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;							///////////////////////////////////////////////////
		case S_PARSING_CLOSECURLYBRACKET:	//////////////////// Parsing } ////////////////////
											///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::GROUPING_OPE, currentLineNum);
			m_State = S_START;
			//++currentChar;
			break;					///////////////////////////////////////////////////
		case S_PARSING_SEMICOLON:	//////////////////// Parsing ; ////////////////////
									///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::SEPARATOR, currentLineNum);
			m_State = S_START;
			break;				///////////////////////////////////////////////////
		case S_PARSING_COMMA:	//////////////////// Parsing , ////////////////////
								///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::SEPARATOR, currentLineNum);
			m_State = S_START;
			break;				///////////////////////////////////////////////////
		case S_PARSING_COLON:	//////////////////// Parsing : ////////////////////
								///////////////////////////////////////////////////
			addToken(tokenBuffer.c_str(), TOKEN_TYPE::SEPARATOR, currentLineNum);
			m_State = S_START;
			break;						////////////////////////////////////////////////////
		case S_PARSING_COMMENT_START:	//////////////////// Parsing /* ////////////////////
										////////////////////////////////////////////////////
			m_State = S_PARSING_COMMENT_MIDDLE;
			break;						/////////////////////////////////////////////////////////
		case S_PARSING_COMMENT_MIDDLE:	//////////////////// Parsing comment ////////////////////
										/////////////////////////////////////////////////////////
			if (*currentChar != lexSrcEof || *currentChar != '*') {
				++currentChar;
			}
			else if (*currentChar == '*') {
				if (*currentChar != lexSrcEof || *currentChar == '/') {
					m_State = S_START;
				}
			}
			else {
				tokenBuffer.clear();
				addError(currentLineNum, LEX_ERROR_COMMENT_NOT_CLOSED, currentLine, currentChar, lineBufferString);
				m_State = S_START;
			}
			break;
		default:
			tokenBuffer.clear();
			addError(currentLineNum, LEX_ERROR_INVALID_STATE, currentLine, currentChar, lineBufferString);
			break;
		}
	}
	return m_Succeeded;
}

int Compiler_code_logic_thing::Lex_analizer::GetNumTokens() const {
	return m_Tokens.size();
}

void Compiler_code_logic_thing::Lex_analizer::GetTokens(std::vector<Token*>* allTokensVec) const {
	std::copy(m_Tokens.begin(), m_Tokens.end(), std::back_inserter(*allTokensVec));
}

const Token * Compiler_code_logic_thing::Lex_analizer::getNextToken() {
	if (currToken < m_Tokens.size()) {
		return m_Tokens[currToken++];
	}
	else if (currToken == 0) {
		return m_Tokens[0];
	}
	else {
		return nullptr;
	}
}

const Token * Compiler_code_logic_thing::Lex_analizer::peekToken(int offset) {
	if ((currToken + offset) < m_Tokens.size() && (currToken + offset >= 0)) {
		return m_Tokens[currToken + offset];
	}
	else
		return nullptr;
}

void Compiler_code_logic_thing::Lex_analizer::addError(int lineNum, const char * desc, const char * line) {
	String ^ strDesc = gcnew String(desc);
	String ^ strLine = gcnew String(line);
	managedRef_errMod->addError(Compiler_code_logic_thing::ERROR_PHASE::LEX_ANALYZER, lineNum, strDesc, strLine);
	m_Succeeded = false;
}

void Compiler_code_logic_thing::Lex_analizer::addError(int lineNum, const char *desc, const char *line, const char *curr_char, std::string & lineBuffer) {
	int nCharsInLine = (curr_char - line) + 1;
	lineBuffer.clear();
	lineBuffer.append(line, nCharsInLine);
	lineBuffer.append("<-<-<-<");
	String ^ strDesc = gcnew String(desc);
	String ^ strLine = gcnew String(lineBuffer.c_str());
	managedRef_errMod->addError(Compiler_code_logic_thing::ERROR_PHASE::LEX_ANALYZER, lineNum, strDesc, strLine);
	m_Succeeded = false;
}

void Compiler_code_logic_thing::Lex_analizer::addToken(const char * lex, TOKEN_TYPE type, int lineNum) {
	m_Tokens.push_back(new Token(std::string(lex), type, lineNum));
}

void Compiler_code_logic_thing::Lex_analizer::clearTokens() {
	currToken = 0;
	if (m_Tokens.size() > 0) {
		for (int i = 0; i < (int)m_Tokens.size(); i++) {
			if (m_Tokens[i] != NULL) {
				delete m_Tokens[i];
				m_Tokens[i] = NULL;
			}
		}
		m_Tokens.clear();
	}
}

bool Lex_analizer::is_Alpha(const char * cur_char) const {
	if ((*cur_char >= 'a' && *cur_char <= 'z') || (*cur_char >= 'A' && *cur_char <= 'Z'))
		return true;
	else 
		return false;
}

bool Lex_analizer::is_Alpha_v2(const char * cur_char) const {
	if (*cur_char == 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z') {
		return true;
	}
	else
		return false;
}

bool Lex_analizer::is_Digit(const char * cur_char) const {
	if (*cur_char >= '0' && *cur_char <= '9')
		return true;
	else
		return false;
}

bool Lex_analizer::is_Digit_v2(const char * cur_char) const {
	if (*cur_char == '1', '2', '3', '4', '5', '6', '7', '8', '9', '0') {
		return true;
	}
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_ValidChar(const char * cur_char) const {
	if (*cur_char == '_' || is_Digit(cur_char) || is_Alpha(cur_char))
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_Space(const char * cur_char) const {
	if (*cur_char == ' ' || *cur_char == '\t' || is_NewLine(cur_char))
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_NewLine(const char * cur_char) const {
	if (*cur_char == '\n' || *cur_char == '\r')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_ArithmeticOpe(const char * cur_char) const {
	if (*cur_char == '+' || *cur_char == '*' || *cur_char == '-' || *cur_char == '/' || *cur_char == '%' || *cur_char == '^')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_AssingOpe(const char * cur_char) const {
	if (*cur_char == '=') {
		//if (is_Space(cur_char + 1)) 
		return true;
	}
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_RelationalOpe(const char * cur_char) const {
	if (*cur_char == '<' || *cur_char == '>' || *cur_char == '=')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_RelationalOpe_v2(const char * cur_char) const {
	if (*cur_char == '<', '>', (*cur_char == '<' && *cur_char + 1 == '='), (*cur_char == '>' && *cur_char + 1 == '='),
		(*cur_char == '=' && *cur_char + 1 == '='), (*cur_char == '!' && *cur_char + 1 == '='))
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_LogicalOpe(const char * cur_char) const {
	if (*cur_char == '&' || *cur_char == '|' || *cur_char == '!')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_LogicalOpe_v2(const char * cur_char) const {
	if ((*cur_char == '&'&& *cur_char + 1 == '&'), (*cur_char == '|'&& *cur_char + 1 == '|'), '!')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_Separator(const char * cur_char) const {
	if (*cur_char == ',' || *cur_char == ':' || *cur_char == ';')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_GroupingChar(const char * cur_char) const {
	if (*cur_char == '(' || *cur_char == ')')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_BlockChar(const char * cur_char) const {
	if (*cur_char == '{' || *cur_char == '}')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_DimensionChar(const char * cur_char) const {
	if (*cur_char == '[' || *cur_char == ']')
		return true;
	else
		return false;
}

bool Compiler_code_logic_thing::Lex_analizer::is_StringLiteral(const char * cur_char) const {
	if (*cur_char == '\"')
		return true;
	else
		return false;
}
