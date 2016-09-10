#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "BinaryNodeAVL.h"
#include <list>
class BinaryTreeAVL{
	protected:
		BinaryNodeAVL* root;
	public:
		BinaryTreeAVL();
		BinaryTreeAVL(NodoVocabulario& val);
		~BinaryTreeAVL();
		bool isEmpty();
		BinaryNodeAVL* getRoot();
		void setRoot(BinaryNodeAVL* nroot);
		BinaryNodeAVL* max();
		BinaryNodeAVL* min();
		bool insert(NodoVocabulario& n);
		bool erase(NodoVocabulario& n);
		bool search(NodoVocabulario& n);
		BinaryNodeAVL* search(char val);
		bool searchFather(NodoVocabulario& n);
		int treeHeight();
		void updateHeight();
		void inOrder();
		void preOrder();
		void posOrder();
		void levelOrder();
		void balanceCheck(BinaryNodeAVL* father);
	private:
		bool eraseRoot();
};
#include "BinaryTreeAVL.hxx"
#endif
