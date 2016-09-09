#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "BinaryNodeAVL.h"
#include <list> 
template <class T>
class BinaryTreeAVL{
	protected:
		BinaryNodeAVL<T>* root;
	public:
		BinaryTreeAVL();
		BinaryTreeAVL(T& val);
		~BinaryTreeAVL();
		bool isEmpty();
		BinaryNodeAVL<T>* getRoot();
		void setRoot(BinaryNodeAVL<T>* nroot);
		T& max();
		T& min();
		bool insert(T& n);
		bool erase(T& n);
		bool eraseRoot();
		bool search(T& n);
		bool searchFather(T& n);
		int treeHeight();
		void updateHeight();
		int size();
		void inOrder();
		void preOrder();
		void posOrder();
		void levelOrder();
		void balanceCheck(BinaryNodeAVL<T>* father);
};
#include "BinaryTreeAVL.hxx"
#endif
