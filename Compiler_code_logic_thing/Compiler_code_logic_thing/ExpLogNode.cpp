#include "stdafx.h"
#include "ExpLogNode.h"
ExpLogNode::ExpLogNode() {

}
bool ExpLogNode::evaluate() {
	if (node1 != nullptr) {
		node1->evaluate();
	}
	if (node2 != nullptr) {
		node2->evaluate();
	}
	if (node1 == nullptr && node2 == nullptr) {
		//currNodeRes=
	}
	else {
		RES_EXPLOGNODE expectedResNode1 = node1->getResult();
		RES_EXPLOGNODE expectedResNode2 = node2->getResult();
		if (nodeOperatorType == OP_ARIT) {

		}
		if (nodeOperatorType == OP_LOG) {

		}
		if (nodeOperatorType == OP_REL) {

		}
	}

	return false;
}
RES_EXPLOGNODE ExpLogNode::getResult() {
	return currNodeRes;
}
