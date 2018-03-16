#pragma once
#include <map>
#include <string>
#include "Error_Module.h"
namespace Compiler_code_logic_thing {
	enum Enum_Node_Class {
		UNDEF = 0,
		GLOBAL_VAR,
		PROC,
		FUNC,
		PARAM,
		LOCAL_VAR,
	};
	
	//------------------------------------------------------------------------------------------------------------------
	//////////////////////////////////  ^ Node Val ^ //////////////////////////////////
	class Node_Val {
	public:
		Node_Val() {}
		~Node_Val() {}
	};
	//////////////////////////////////  ^ Node Val ^ //////////////////////////////////
	//------------------------------------------------------------------------------------------------------------------
	//////////////////////////////////  v Local Node v //////////////////////////////////
	class Local_Node {
	public:
		Local_Node(std::string n_ProcFunc, Enum_Node_Class nodeClass,
			int dimen, std::string type, Local_Node * n_next);
		~Local_Node();
		void setNextNode(Local_Node * n_local);
		//////////////// v Gets v ////////////////
		Enum_Node_Class getNodeClass() { return m_nodeClass; }
		std::string getVarContext() { return m_n_ProcFunc; }
		Local_Node * getNextNode() { return m_nextNode; }
		//////////////// ^ Gets ^ ////////////////
	private:
		std::string m_n_ProcFunc;
		Enum_Node_Class m_nodeClass;
		Node_Val * m_N_Val;
		int m_dimen;
		std::string m_type;
		Local_Node * m_nextNode;
	};
	//////////////////////////////////  ^ Local Node ^ //////////////////////////////////
	//------------------------------------------------------------------------------------------------------------------
	//////////////////////////////////  v Global Node v //////////////////////////////////
	class Global_Node {
	public:
		Global_Node(std::string symbol, Enum_Node_Class nodeClass, int dimen, std::string type);
		~Global_Node();
		void setLocalNode(Local_Node * n_local);
		//////////////// v Gets v ////////////////
		Enum_Node_Class getNodeClass() { return m_nodeClass; }
		std::string getNodeSymbol() { return m_symbol; }
		Local_Node * const getLocalNode() { return m_n_local; }
		//////////////// ^ Gets ^ ////////////////
	private:
		std::string m_symbol;
		Enum_Node_Class m_nodeClass;
		Node_Val * m_N_Val;
		int m_dimen;
		std::string m_type;
		Local_Node * m_n_local;
	};
	//////////////////////////////////  ^ Global Node ^ //////////////////////////////////
	//------------------------------------------------------------------------------------------------------------------
	//////////////////////////////////  v Symbol Table v //////////////////////////////////
	class SymbolTable {
	public:
		SymbolTable();
		~SymbolTable();
		bool symbolExists(std::string symbol, Enum_Node_Class nodeClass, std::string n_ProcFunc);
		bool addSymbol(std::string symbol, Enum_Node_Class nodeClass, int dimen, std::string type, std::string n_ProcFunc);

	private:
		std::map<std::string, Global_Node *> m_Nodes;
	};
	//////////////////////////////////  ^ Symbol Table ^ //////////////////////////////////
}

