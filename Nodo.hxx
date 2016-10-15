#include "Nodo.h"
#include <list>

Node<char>::Node(){

}

Node<char>::~Node(){

}

char& Node<char>::getData(){
	return (this->data);
}

std::list<Node<char>*>& Node<char>::getDesc(){
	return (this->desc);
}

void Node<char>::setData(char& val){
	this->data = val;
}


void Node<char>::addDesc(char& nval){
	Node<char> * node = new Node<T>;
	node->setData(nval);
	this->desc.push_back(node);
}


Node<char>* Node<char>::search(char& val){
	if(this->data == val)
		return this;
	for(typename std::list<Node <char>*>::iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
		Node<char>* node = (*iterador)->search(val);
		if(node != nullptr)
			return node;
	}
	return nullptr;
}


void Node<char>::descendants(){
	std::cout << "Father: " << this->data << std::endl;
	for(typename std::list<Node <char>*>::iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
			std::cout << "Son: " << (*iterador)->getData() << std::endl;
	}
}


