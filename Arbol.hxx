#include "Arbol.h"
#include <list>

Arbol<char>::Arbol(){

}

Arbol<char>::~Arbol(){

}

bool Arbol<char>::isEmpty(){
	return (this->root == nullptr) ? true : false;
}

Node<char>* Arbol<char>::getRoot(){
	return this->root;
}

void Arbol<char>::setRoot(Node<char>* nroot){
	this->root = nroot;
}

bool Arbol<char>::insertNode(char& father, char& n){
	Node<char>* fatherNode = this->root->search(father);
	if(fatherNode != nullptr){
		fatherNode->addDesc(n);
		std::cout << "Valor insertado: " << n << std::endl;
		return true;
	}
	return false;
}


bool Arbol<char>::search(char& n){
	return (this->root->search(n) == nullptr) ? false : true;
}




void Arbol<char>::descendants(Node<char>* inicio){
	Node<T>* node = (this->getRoot())->search(inicio->getData());
	if(node != nullptr){
		node->descendants();
	}
}
