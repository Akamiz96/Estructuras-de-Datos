#include <iostream>
#include "BinaryTreeAVL.h"
int main(int argc, char* argv[]){
	std::cout << "Prueba Arbol Binario AVL" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	int i = 10, j = 3, k = 11, l = 0, p = 13, y = 5, o = 9, h = 4, g = 2, m = 1;
	int f = 6, u = 7, w = 8;
	BinaryTreeAVL<int> tree = BinaryTreeAVL<int>();
	std::cout << "Insert: " << j << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(j);
	std::cout << "Insert: " << k << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(k);
	std::cout << "Insert: " << l << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(l);
	std::cout << "Insert: " << p << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(p);
	std::cout << "Insert: " << y << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(y);
	std::cout << "Insert: " << o << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(o);
	tree.getRoot()->getRight()->descendants();
	std::cout << "Insert: " << h << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(h);
	std::cout << "Insert: " << g << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(g);
	std::cout << "Insert: " << m << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(m);
	std::cout << "++++---------------------------------------------------" << std::endl;
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	tree.erase(y);
	tree.getRoot()->getLeft()->descendants();
	std::cout << "----------------------------------------------------" << std::endl;
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	tree.insert(y);
	tree.insert(f);
	tree.insert(u);
	std::cout << "=====----------------------------------------------------" << std::endl;
	tree.inOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "=====----------------------------------------------------" << std::endl;
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	tree.getRoot()->getRight()->getLeft()->getLeft()->descendants();
	std::cout << "----------------------------------------------------" << std::endl;
	tree.erase(o);
	std::cout << "(((()))----------------------------------------------------" << std::endl;
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Erase: " << y << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.erase(y);
	std::cout << "Erase: " << f << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.erase(f);
	std::cout << "99999----------------------------------------------------" << std::endl;
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << o << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(o);
	std::cout << "{{{{{{----------------------------------------------------" << std::endl;
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << w << std::endl;
	std::cout << "+++++++++++++++++++++"<< std::endl;
	tree.insert(w);
	std::cout << "@@@@----------------------------------------------------" << std::endl;
	tree.getRoot()->getRight()->descendants();
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;


	/*if(tree.search(g))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	std::cout << tree.erase(i)<< std::endl;
	std::cout << tree.erase(y)<< std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	tree.posOrder();
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << tree.treeHeight() << std::endl;*/
	return(0);
}
