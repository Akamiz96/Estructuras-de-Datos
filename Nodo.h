#ifndef __NODO_H__
#define __NODO_H__
#include <list>
template <class T>
class Node{
	protected:
	T data;
	std::list <Node<T>*> desc;
	public:
	Node();
	~Node();
	T& getData();
	std::list <Node<T>*>& getDesc();
	void setData (T& val);
	void clearList ();
	void addDesc (T& nval);
	void removeDesc (T& val);
	Node<T>* search(T& val);
	void inOrder();
	void preOrder();
	void posOrder();
	void descendants();
	void removeDescendants();
};
#include "Nodo.hxx"

#endif
