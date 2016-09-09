#include <iostream>
#include "BinaryTreeAVL.h"
#include "NodoVocabulario.h"
int main(int argc, char* argv[]){
	std::cout << "Prueba Proyecto" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	char a = 'a', b = 'b', k = 'k', l = 'l', p = 'p', y = 'y', o = 'o', h = 'h', g = 'g', m = 'm';
	char f = 'f', u = 'u', w = 'w', j = 'j';
	BinaryTreeAVL<char> tree = BinaryTreeAVL<char>();
	std::cout << "Insert: " << a <<  std::endl;
	tree.insert(a);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << b <<  std::endl;
	tree.insert(b);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << k <<  std::endl;
	tree.insert(k);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << l <<  std::endl;
	tree.insert(l);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << p <<  std::endl;
	tree.insert(p);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << y <<  std::endl;
	tree.insert(y);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << o <<  std::endl;
	tree.insert(o);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << h <<  std::endl;
	tree.insert(h);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << m <<  std::endl;
	tree.insert(m);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << f <<  std::endl;
	tree.insert(f);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << u <<  std::endl;
	tree.insert(u);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << w <<  std::endl;
	tree.insert(w);
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Insert: " << j <<  std::endl;
	tree.insert(j);
	std::cout << "----------------------------------------------------" << std::endl;
	tree.preOrder();
	return(0);
}
