#include "Arbol.h"
#include <list>

Arbol::Arbol(){

}
Arbol::Arbol(char val)
{
    this->root=new Node(val);
}
Arbol::~Arbol(){

}

bool Arbol::isEmpty(){
	return (this->root == nullptr) ? true : false;
}

Node* Arbol::getRoot(){
	return this->root;
}

void Arbol::setRoot(Node* nroot){
	this->root = nroot;
}

bool Arbol::insertNode(char& father, char& n){
	Node* fatherNode = this->root->search(father);
	if(fatherNode != nullptr){
		fatherNode->addDesc(n);
		return true;
	}
	return false;
}


bool Arbol::search(char& n){
	return (this->root->search(n) == nullptr) ? false : true;
}

std::list<Node*> Arbol::descendants(Node* inicio){
	Node* node = (this->getRoot())->search(inicio->getData());
	std::list<Node*> descendiente;
	if(node != nullptr){
		descendiente=node->descendants();
	}
    return descendiente;
}
