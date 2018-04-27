#include "stdafx.h"
#include "ExpLogTree.h"
#include <stack>

using std::stack;
ExpLogTree::ExpLogTree(vector<const Token*> logExp) {
	int logExpCount = 0;
	int logExpSize = logExp.size();
	int nestedExpr = 0;

	Token** IdR;
	Token** IdL;
	Token* *ope;

	vector<const Token*> logExpCopy = logExp;
	//PostFixExpr;

	stack<const Token*> TokenStack;

	for (auto& it : logExpCopy) {
		TOKEN_TYPE TT = it->GetType();
		if (TT == GROUPING_OPE) {
			if (it->GetLex == '(') {
				++nestedExpr;
			}
			while (!TokenStack.empty() && TokenStack.top()->GetLex() != "(")
			{
				PostFixExpr.push_back(TokenStack.top());
				TokenStack.pop();
			}

		}
		if (TT != OP_ARIT || TT != OP_LOG || TT != OP_REL) {
			if (it->GetLex == '/' || it->GetLex == '*') {

			}
		}
	}
	//For ends
	while (!TokenStack.empty()) {
		PostFixExpr.push_back(TokenStack.top());
		TokenStack.pop();
	}
	if (nestedExpr != 0) {
		//addError
	}
}
bool ExpLogTree::evaluate() {
	if (root != nullptr) {
		return root->evaluate();
	}
	else
		return false;
}
