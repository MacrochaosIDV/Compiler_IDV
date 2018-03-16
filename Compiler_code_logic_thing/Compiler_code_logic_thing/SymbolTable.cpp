#include "stdafx.h"
#include "SymbolTable.h"

//////////////////////////////////  v Symbol Table v //////////////////////////////////
Compiler_code_logic_thing::SymbolTable::SymbolTable() {

}

Compiler_code_logic_thing::SymbolTable::~SymbolTable() {
	for (auto it = m_Nodes.begin(); it != m_Nodes.end(); ++it) {
		delete it->second;
	}
}

bool Compiler_code_logic_thing::SymbolTable::symbolExists(std::string symbol, Enum_Node_Class nodeClass, std::string n_ProcFunc) {
	if (nodeClass == GLOBAL_VAR || nodeClass == PROC || nodeClass == FUNC) {
		if (m_Nodes.find(symbol) != m_Nodes.end()) {
			return true;
		}
	}
	else if (nodeClass == PARAM || nodeClass == LOCAL_VAR) {
		auto it = m_Nodes.find(symbol);
		if (it != m_Nodes.end()) {
			Global_Node * g_node = it->second;
			if (g_node != nullptr) {
				Local_Node * l_node = g_node->getLocalNode();
				while (l_node != nullptr) {
					if (l_node->getNodeClass() == nodeClass && l_node->getVarContext().compare(n_ProcFunc) == 0) {
						return true;
					}
					l_node->getNextNode();
				}
			}
		}
	}

	return false;
}

bool Compiler_code_logic_thing::SymbolTable::addSymbol(std::string symbol, Enum_Node_Class nodeClass, int dimen, std::string type, std::string n_ProcFunc) {
	if (!symbolExists(symbol, nodeClass, n_ProcFunc)) {

		if (nodeClass == GLOBAL_VAR || nodeClass == LOCAL_VAR || nodeClass == PARAM) {
			if (symbolExists(symbol, PROC, n_ProcFunc)) {
				//add error
			}
			if (symbolExists(symbol, FUNC, n_ProcFunc)) {
				//add error
			}
		}
		if (nodeClass == FUNC) {
			if (symbolExists(symbol, PROC, n_ProcFunc)) {
				//add error
			}
		}
		if (nodeClass == PROC) {
			if (symbolExists(symbol, FUNC, n_ProcFunc)) {
				//add error
			}
		}
		if (nodeClass == GLOBAL_VAR || nodeClass == PROC || nodeClass == FUNC) {
			m_Nodes.insert(std::make_pair(symbol, new Global_Node(symbol, nodeClass, dimen, type)));
		}
		else if (nodeClass == PARAM || nodeClass == LOCAL_VAR) {
			Local_Node * l_node = new Local_Node(n_ProcFunc, nodeClass, dimen, type, NULL);
			auto it = m_Nodes.find(symbol);
			if (it != m_Nodes.end()) {
				Global_Node * g_node = it->second;
				g_node->setLocalNode(l_node);
			}
			else {
				Global_Node * g_node = new Global_Node(n_ProcFunc, UNDEF, dimen, type);
				g_node->setLocalNode(l_node);
			}
		}

		return 1;
	}

	return 0;
}
//////////////////////////////////  ^ Symbol Table ^ //////////////////////////////////
//------------------------------------------------------------------------------------------------------------------
//////////////////////////////////  v Local Node v //////////////////////////////////
Compiler_code_logic_thing::Local_Node::Local_Node(std::string n_ProcFunc, Enum_Node_Class nodeClass, int dimen, std::string type, Local_Node * nextNode) {
	m_N_Val = NULL;
	m_nextNode = NULL;
	m_nodeClass = nodeClass;
	m_dimen = dimen;
	m_type = type;
	m_n_ProcFunc = n_ProcFunc;
}

Compiler_code_logic_thing::Local_Node::~Local_Node() {
	if (m_N_Val) {
		delete m_N_Val;
	}
	if (m_nextNode) {
		Local_Node * tmp = m_nextNode;
		Local_Node * aux;
		while (tmp != nullptr) {
			aux = tmp->getNextNode();
			delete tmp;
			tmp = aux;
		}
	}
}
void Compiler_code_logic_thing::Local_Node::setNextNode(Local_Node * n_next) {
	m_nextNode = n_next;
}
//////////////////////////////////  ^ Local Node ^ //////////////////////////////////
//------------------------------------------------------------------------------------------------------------------
//////////////////////////////////  v Global Node v //////////////////////////////////
Compiler_code_logic_thing::Global_Node::Global_Node(std::string symbol, Enum_Node_Class nodeClass, int dimen, std::string type) {
	m_N_Val = NULL;
	m_n_local = NULL;
	m_symbol = symbol;
	m_nodeClass = nodeClass;
	m_dimen = dimen;
	m_type = type;
}

Compiler_code_logic_thing::Global_Node::~Global_Node() {
	if (m_N_Val) {
		delete m_N_Val;
	}
	if (m_n_local) {
		delete m_n_local;
	}
}
void Compiler_code_logic_thing::Global_Node::setLocalNode(Local_Node * n_local) {
	if (m_n_local == nullptr) {
		m_n_local = n_local;
	}
	else {
		Local_Node* tmp = m_n_local;
		m_n_local = n_local;
		n_local->setNextNode(tmp);
	}
}
//////////////////////////////////  ^ Global Node ^ //////////////////////////////////
