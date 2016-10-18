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


void Node::addDesc(char nval){
	Node * node = new Node();
	node->setData(nval);
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

void Node::insertarPalabra(std::string palabra, bool& insercion){
  if(!palabra.empty()){
    Node* node = nullptr;
    for(std::list<Node*>:: iterator iterador = this->desc.begin(); iterador != this->desc.end() && node == nullptr; iterador++){
      if((*iterador)->getData() == palabra[0])
        node = *iterador;
    }
    if(node != nullptr){
      palabra.erase(palabra.begin());
  		node->insertarPalabra(palabra, insercion);
    }
    else{
      this->addDesc(palabra[0]);
      this->insertarPalabra(palabra, insercion);
      insercion = true;
    }
  }
  else
    this->addDesc('\0');
}

void Node::prefix( std::list< std::string >& palabras, std::string& palabra )
{
  palabra.push_back( this->data );
  if( !( this->desc ).empty() )
	  for( std::list < Node* >::const_iterator iterador = ( this->desc ).begin(); iterador != ( this->desc ).end(); iterador++)
    {
	    ( *iterador )->prefix( palabras, palabra );
	  }
  if( ( this->desc ).empty() )
  {
    std::list< std::string >::iterator it = std::find( palabras.begin(), palabras.end(), palabra );
    if( it == palabras.end() )
      palabras.push_back( palabra );
  }
  palabra.pop_back();
}
