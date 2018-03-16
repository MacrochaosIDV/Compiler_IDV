#pragma once
#include "Token.h"
#include "Error_Module.h"
#include "Lex_analizer.h"
#include <vcclr.h>
#include "SyntaxStateM.h"
#include <map>
#include "SymbolTable.h"

/*
<variables>::= 'var' <grupo_var_id> ';' [<variables>]
<grupo_var_id>::= <grupo_id>':'<tipo>
<grupo_id>::= <id>[','<grupo_id>]

<id>::= <letra> [<valid_id_char>]
<valid_id_char>::= <letras>|<numeros>|<guiones>|<valid_id_char>
<letras>::= <letra>[<letras>]
<letra>::= 'A'|'B'|'C'......

<tipo>::= 'int'|'float'|'bool'|'string'

<func_proceds>::= <func>|<proceds>|<func_proceds>

<func>::= 'function' <id> <params>':'<tipo> <block_func_proceds>
|
(return type)
<proceds>::= 'procedure' <id> <params> <block_func_proceds>
<block_func_proceds>::= '{' [<variables>][<statements>] '}'

<param>::= '(' [<grupo_params>] ')'
<grupo_params>::= <grupo_var_id> [';'<grupo_params>]


<main>::= 'main' '(' ')' <block_func_proceds>


<statements>::= <statement> ';' [<statements>]
<statement>::= <if>|<while>|<switch>|<assing>|<read>|<print>|<return>|<proceds_call>

<if>::= 'if(' <expresion> ')' <block_statement> [<else_elseif>]
<else_elseif>::= 'else if(' <expresion ')' <block_statement> [<else_elseif>]|<else>
<else>::= 'else' <block_statement>
<while>::= 'while(' <expresion> ')' <block_statement>
<for>::= 'for(' <assing> ';' <expresion> ';' <incr_decr><numero> ')' <block_statement>

<switch>::= 'switch(' <id> ')' '{' <block_switch> '}'
<block_switch>::= 'case' <const> ':' <block_statement> [<block_switch>]|<default:>
<default>::= 'default:' <block_statement>

<inc_dec>::= 'inc'|'dec'

<block_statement>::= [<variables>][<statements>]

<assing>::= <id>[<dimen>] '=' <expresion>

<read>::= 'read(' <id>[<dimen>] ')'
<print>::= 'print' [ '(' <lista_expresiones> ')' ]

<lista_expresiones>::= <expresion> [, <lista_expresiones>]
<proc_call>::= <id> '(' <lista_expresiones> ')'
<return>::= 'return' <expresion>

<dimen>::= <numero>

<numero>:: = ['-'] <seq_dig>['.' <seq_dig>]
<seq_dig>:: = <dig>[<seq_dig>]
<dig>:: = '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

<expresion>:: = <term> <operator> <expresion> | [!] <term>
<term>:: = '(' <expresion> ')' | <const> | <id> | <proc_call>

<operator>:: = <op_arit> | <op_log> | <op_rel>
<op_arit>:: = '+' | '-' | '*' | '/' | '^' | '%'
<op_log>:: = '&&' | '||'
<op_rel>:: = '<' | '>' | '<=' | '>=' | '==' | '!='
*/


namespace Compiler_code_logic_thing {
	/*
	Error :: Varible cant have same ID as function or prodecure
	Error :: Param already defined
	Error :: Local var cant have same ID as param
	Error :: Expecting X, found Y
	Error :: Global var alredy defined
	Error :: Function or procedure already defined
	Error :: Local var already defined ////////
	*/

	//////////////////// v Errors defines v ////////////////////
#define SYNTX_err_GlobalVar_isdef "Global var alredy defined"
#define SYNTX_err_Local_isdef "Local var already defined"
#define SYNTX_err_Param_isdef "Param already defined"
#define SYNTX_err_ProcFunc_isdef "Function or procedure already defined"

#define SYNTX_err_LocalVar_CantHasSameID_as_Param "Local var cant have same ID as param"
#define SYNTX_err_VarCantHasSameID_as_ProcFunc "Varible cant have same ID as function or prodecure"


	//////////////////// ^ Errors defines ^ ////////////////////

	class SyntaxStateM;
	class Syntax_analizer {
	private:
		
		std::map<std::string, SyntaxStateM*> m_Syntx_State_Map;

		Token * currToken;
		bool m_Succeeded;											// CURRENT STATE ?

		Lex_analizer * lex;
		msclr::gcroot<Error_Module ^> err;
		SymbolTable * m_p_SymTbl;
		SyntaxStateM * m_p_SyntxState;
		
		void addError(int linenumber, const char *desc);
		void addErrorExpexted(int n, char * e, char * f);
	
		/*void RecoverFromError();
		void add_to_Symbols();*/

	public:
		void reset();
		SyntaxStateM * getSyntxState(std::string str);
		Syntax_analizer(Error_Module ^err, Lex_analizer * lexx);
		~Syntax_analizer();
		bool syntaxizeCode();

	};
}


