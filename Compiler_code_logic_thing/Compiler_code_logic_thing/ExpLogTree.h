#pragma once
#include <string>
#include <vector>
#include "Token.h"
#include "ExpLogNode.h"
using namespace Compiler_code_logic_thing;
using std::string;
using std::vector;

class ExpLogTree {
public:
	ExpLogNode * root;
	vector<const Token*> PostFixExpr;
	ExpLogTree(vector<const Token*> logExp);
	bool evaluate();//
};

