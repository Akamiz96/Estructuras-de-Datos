#ifndef __BINARYNODEAVL_H__
#define __BINARYNODEAVL_H__
#include <list>
template <class T>
class BinaryNodeAVL{
	protected:
	T data;
	unsigned int height;
	BinaryNodeAVL<T>* left;
	BinaryNodeAVL<T>* right;
	public:
	BinaryNodeAVL();
	BinaryNodeAVL(T& val);
	BinaryNodeAVL(T& val, BinaryNodeAVL<T>* rightSon, BinaryNodeAVL<T>* leftSon);
	~BinaryNodeAVL();
	T& getData();
	BinaryNodeAVL<T>*& getRight();
	BinaryNodeAVL<T>*& getLeft();
	unsigned int getHeight();
	void setData (T& val);
	void setRight (BinaryNodeAVL<T>* val);
	void setLeft (BinaryNodeAVL<T>* val);
	void setHeight (unsigned int val);
	BinaryNodeAVL<T>* max();
	BinaryNodeAVL<T>* min();
	bool insert (T& nval);
	void erase (T& val);
	BinaryNodeAVL<T>* search(T& val);
	BinaryNodeAVL<T>* searchFather(T& val);
	int nodeHeight();
	void updateHeight();
	int size();
	void inOrder();
	void preOrder();
	void posOrder();
	void levelOrder(std::list<BinaryNodeAVL<T>*> & List);
	void descendants();
	BinaryNodeAVL<T>* rightRotation();
	BinaryNodeAVL<T>* leftRotation();
	BinaryNodeAVL<T>* rightLeftRotation();
	BinaryNodeAVL<T>* leftRightRotation();
	bool balanceCheck(BinaryNodeAVL<T>* father, BinaryNodeAVL<T>*& root);
	BinaryNodeAVL<T>* balance(short int type);
};
#include "BinaryNodeAVL.hxx"

#endif
