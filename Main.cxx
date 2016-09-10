#include <iostream>
#include "BinaryTreeAVL.h"
#include "NodoVocabulario.h"
int main(int argc, char* argv[]){
	std::cout << "Prueba Proyecto" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	BinaryTreeAVL tree;
	NodoVocabulario* nodoA = new NodoVocabulario('a');
	NodoVocabulario* nodoZ= new NodoVocabulario('z');
	NodoVocabulario* nodoL = new NodoVocabulario('l');
	NodoVocabulario* nodoP = new NodoVocabulario('p');
	NodoVocabulario* nodoV = new NodoVocabulario('v');
	NodoVocabulario* nodoN = new NodoVocabulario('n');
	NodoVocabulario* nodoH = new NodoVocabulario('h');
	NodoVocabulario* nodoJ = new NodoVocabulario('j');
	tree.insert(*nodoA);
	tree.insert(*nodoZ);
	tree.insert(*nodoL);
	tree.insert(*nodoP);
	tree.insert(*nodoV);
	tree.insert(*nodoV);
	tree.insert(*nodoN);
	tree.insert(*nodoH);
	tree.insert(*nodoJ);
	std::cout << "----------------------------------------------------" << std::endl;
	tree.preOrder();
	return(0);
}
