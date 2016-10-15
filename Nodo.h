#ifndef __NODO_H__
#define __NODO_H__
#include <list>

class Node{
	protected:
	char data;
	std::list <Node*> desc;
	public:
	Node();
	Node(char val);
	~Node();
	char& getData();
	std::list <Node*>& getDesc();
	void setData (char& val);
	void addDesc (char& nval);
	Node* search(char& val);
	std::list<Node*> descendants();
	void prefix( std::list< std::string >& palabras, std::string& palabra );
};
#include "Nodo.hxx"

#endif
