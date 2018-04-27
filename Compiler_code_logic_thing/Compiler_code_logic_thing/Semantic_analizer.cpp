#include "stdafx.h"
#include "Semantic_analizer.h"
Compiler_code_logic_thing::Semantic_analizer::Semantic_analizer() {

}
void Compiler_code_logic_thing::Semantic_analizer::addExpLog(string str, vector<const Token*> vT) {
	vector<const Token*> postF = infix2Postfix(vT);
	m_logExpMap.insert(std::make_pair(str,postF));

}
void Compiler_code_logic_thing::Semantic_analizer::evalExprns() {
	for (auto it = m_logExpMap.begin(); it != m_logExpMap.end(); ++it) {
		ExpLogTree * t = new ExpLogTree(it->second);
		if (!t->evaluate()) {
			//addError();
		}
		else {

		}
	}
}
vector<const Token*> Compiler_code_logic_thing::Semantic_analizer::infix2Postfix(vector<const Token*> logExp) {
	
	return logExp;
}
