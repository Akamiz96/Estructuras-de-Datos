#ifndef __NODO_H__
#define __NODO_H__
#include <list>

class Node{
	protected:
	char data;
	std::list <Node*> desc;
	public:
	Node();
	~Node();
	char& getData();
	std::list <Node*>& getDesc();
	void setData (char& val);
	void addDesc (char& nval);
	Node* search(char& val);
	void descendants();
};
#include "Nodo.hxx"

#endif
