#ifndef __ARBOL_H__
#define __ARBOL_H__
#include "Nodo.h"

class Arbol{
	protected:
		Node* root;
	public:
		Arbol();
		Arbol(char& val);
		~Arbol();
		bool isEmpty();
		Node* getRoot();
		void setRoot(Node* nroot);
		bool insertNode(char& father, char& n);
		bool search(char& n);
		void descendants(Node* inicio);
};
#include "Arbol.hxx"
#endif
