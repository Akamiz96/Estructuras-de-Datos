#include "Nodo.h"
#include <list>

Node::Node(){

}

Node::Node(char val){
    this->data=val;
}

Node::~Node(){

}

char& Node::getData(){
	return (this->data);
}

std::list<Node*>& Node::getDesc(){
	return (this->desc);
}

void Node::setData(char& val){
	this->data = val;
}


void Node::addDesc(char& nval){
	Node * node = new Node();
	node->data=nval;
	this->desc.push_back(node);
}


Node* Node::search(char& val){
	if(this->data == val)
		return this;
	for(typename std::list<Node*>::iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
		Node* node = (*iterador)->search(val);
		if(node != nullptr)
			return node;
	}
	return nullptr;
}


std::list<Node*> Node::descendants(){
	std::list<Node*> descendientes;
	for(typename std::list<Node*>::iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
			descendientes.push_back(*iterador);
	}
	return descendientes;
}

void Node::insertarPalabra(std::string palabra){
  if(!palabra.empty()){
    Node* node = nullptr;
    for(std::list<Node*>:: iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
      if((*iterador)->getData() == palabra[0])
        node = *iterador;
    }
    if(node != nullptr){
      palabra.erase(palabra.begin());
  		node->insertarPalabra(palabra);
    }
    else{
      this->addDesc(palabra[0]);
      this->insertarPalabra(palabra);
    }
  }
}
