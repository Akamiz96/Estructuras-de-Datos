#ifndef __BINARYNODEAVL_H__
#define __BINARYNODEAVL_H__
#include "NodoVocabulario.h"
#include <list>
class BinaryNodeAVL{
	protected:
		NodoVocabulario data;
		unsigned int height;
		BinaryNodeAVL* left;
		BinaryNodeAVL* right;
	public:
		BinaryNodeAVL();
		BinaryNodeAVL(NodoVocabulario& val);
		BinaryNodeAVL(NodoVocabulario& val, BinaryNodeAVL* rightSon, BinaryNodeAVL* leftSon);
		~BinaryNodeAVL();
		NodoVocabulario& getData();
		BinaryNodeAVL*& getRight();
		BinaryNodeAVL*& getLeft();
		unsigned int getHeight();
		void setData (NodoVocabulario& val);
		void setRight (BinaryNodeAVL* val);
		void setLeft (BinaryNodeAVL* val);
		void setHeight (unsigned int val);
		BinaryNodeAVL* max();
		BinaryNodeAVL* min();
		bool insert (NodoVocabulario& nval);
		void erase (NodoVocabulario& val);
		BinaryNodeAVL* search(NodoVocabulario& val);
		BinaryNodeAVL* search(char val);
		BinaryNodeAVL* searchFather(NodoVocabulario& val);
		int nodeHeight();
		void updateHeight();
		void inOrder();
		void preOrder();
		void posOrder();
		void levelOrder(std::list<BinaryNodeAVL*> & List);
		void descendants();
		bool balanceCheck(BinaryNodeAVL* father, BinaryNodeAVL*& root);
	private:
		BinaryNodeAVL* rightRotation();
		BinaryNodeAVL* leftRotation();
		BinaryNodeAVL* rightLeftRotation();
		BinaryNodeAVL* leftRightRotation();
		BinaryNodeAVL* balance(short int type);
};
#include "BinaryNodeAVL.hxx"

#endif
