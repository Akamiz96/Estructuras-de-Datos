#include "Nodo.h"
#include <list>
template <class T>
Node<T>::Node(){

}
template <class T>
Node<T>::~Node(){

}
template <class T>
T& Node<T>::getData(){
	return (this->data);
}
template <class T>
std::list<Node<T>*>& Node<T>::getDesc(){
	return (this->desc);
}
template <class T>
void Node<T>::setData(T& val){
	this->data = val;
}
template <class T>
void Node<T>::clearList(){
	for(typename std::list<Node <T>*>::iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
		delete *iterador;
	}
	this->desc.clear();
}
template <class T>
void Node<T>::addDesc(T& nval){
	Node<T> * node = new Node<T>;
	node->setData(nval);
	this->desc.push_back(node);
}
template <class T>
void Node<T>::removeDesc(T& val){
	Node<T>* node;
	bool found = false;
	for(typename std::list<Node <T>*>::iterator iterador = this->desc.begin(); iterador != this->desc.end() && !found; iterador++){
		if((*iterador)->getData() == val)
		{
			node = *iterador;
			iterador = this->desc.erase(iterador);
			delete node;
			found = true;
		}
	}
}
template <class T>
Node<T>* Node<T>::search(T& val){
	if(this->data == val)
		return this;
	for(typename std::list<Node <T>*>::iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
		Node<T>* node = (*iterador)->search(val);
		if(node != nullptr)
			return node;
	}
	return nullptr;
}
template <class T>
void Node<T>::inOrder(){
	if(!this->desc.empty()){
		typename std::list <Node<T>*>::const_iterator iterador = this->desc.begin();
		(*iterador)->inOrder();
		std::cout << "Inicio: " << this->data << std::endl;
		iterador++;
		while(iterador != this->desc.end()){
			(*iterador)->inOrder();
			iterador++;
		}
	}
	else
		std::cout << "Inicio: " << this->data << std::endl;
}
template <class T>
void Node<T>::preOrder(){
	std::cout << "Inicio: " << this->data << std::endl;
	for(typename std::list <Node<T>*>::const_iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
		(*iterador)->preOrder();
	}
}
template <class T>
void Node<T>::posOrder(){
	for(typename std::list <Node<T>*>::const_iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
		(*iterador)->preOrder();
	}
	std::cout << "Inicio: " << this->data << std::endl;
}
template <class T>
void Node<T>::descendants(){
	std::cout << "Father: " << this->data << std::endl;
	for(typename std::list<Node <T>*>::iterator iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
			std::cout << "Son: " << (*iterador)->getData() << std::endl;
	}
}
template <class T>
void Node<T>::removeDescendants(){
	typename std::list <Node<T>*>::const_iterator iterador;
	for(iterador = this->desc.begin(); iterador != this->desc.end(); iterador++){
		(*iterador)->removeDescendants();
		(*iterador)->clearList();
	}
}