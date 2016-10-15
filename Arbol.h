#ifndef __ARBOL_H__
#define __ARBOL_H__
#include "Nodo.h"
template <class T>
class Arbol{
	protected:
		Node<T>* root;
	public:
		Arbol();
		Arbol(T& val);
		~Arbol();
		bool isEmpty();
		Node<T>* getRoot();
		void setRoot(Node<T>* nroot);
		bool insertNode(T& father, T& n);
		bool removeNode(T& n);
		bool search(T& n);
		unsigned int height(Node<T>* inicio);
		unsigned int size(Node<T>* inicio);
		void inOrder(Node<T>* inicio);
		void preOrder(Node<T>* inicio);
		void posOrder(Node<T>* inicio);
		void levelOrder(Node<T>* inicio);
		void descendants(Node<T>* inicio);
};
#include "Arbol.hxx"
#endif
