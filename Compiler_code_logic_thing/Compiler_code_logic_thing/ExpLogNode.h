#pragma once
#include "Token.h"
#include "SymbolTable.h"

using namespace Compiler_code_logic_thing;

enum RES_EXPLOGNODE
{
	RES_ARIT,
	RES_BOOL,
	RES_INVALID
};
enum OP_EXPLOGNODE
{
	OP_ARIT,
	OP_REL,
	OP_LOG
};
class ExpLogNode {
public:
	SymbolTable * symbtbl;
	Token* operand;
	Token* nodeOperator;
	ExpLogNode * node1;
	ExpLogNode * node2;

	RES_EXPLOGNODE expectedResNode1;
	RES_EXPLOGNODE expectedResNode2;
	RES_EXPLOGNODE currNodeRes;

	OP_EXPLOGNODE nodeOperatorType;

	ExpLogNode();
	bool evaluate();
	RES_EXPLOGNODE getResult();
};

