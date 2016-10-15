#include "Arbol.h"
#include <list>
template <class T>
Arbol<T>::Arbol(){
	
}
template <class T>
Arbol<T>::~Arbol(){

}
template <class T>
bool Arbol<T>::isEmpty(){
	return (this->root == nullptr) ? true : false;
}
template <class T>
Node<T>* Arbol<T>::getRoot(){
	return this->root;
}
template <class T>
void Arbol<T>::setRoot(Node<T>* nroot){
	this->root = nroot;
}
template <class T>
bool Arbol<T>::insertNode(T& father, T& n){
	Node<T>* fatherNode = this->root->search(father);
	if(fatherNode != nullptr){
		fatherNode->addDesc(n);
		std::cout << "Valor insertado: " << n << std::endl;
		return true;
	}
	return false;
}
template <class T>
bool Arbol<T>::removeNode(T& n){
	Node<T>* node = this->root->search(n);
	if(node != nullptr){
		node->removeDescendants();
		return true;
	}
	return false;
}
template <class T>
bool Arbol<T>::search(T& n){
	return (this->root->search(n) == nullptr) ? false : true;
}
template <class T>
unsigned int Arbol<T>::height(Node<T>* inicio){

}
template <class T>
unsigned int Arbol<T>::size(Node<T>* inicio){

}
template <class T>
void Arbol<T>::inOrder(Node<T>* inicio){
	Node<T>* node = this->root->search(inicio->getData());
	if(node != nullptr){
		typename std::list <Node<T>*>::const_iterator iterador = (node->getDesc()).begin(); 
		(*iterador)->inOrder();
		std::cout << "Inicio: " << node->getData() << std::endl;
		iterador++;
		while(iterador != (node->getDesc()).end()){
			(*iterador)->inOrder();
			iterador++;	
		} 
	}
}
template <class T>
void Arbol<T>::preOrder(Node<T>* inicio){
	Node<T>* node = this->root->search(inicio->getData());
	if(node != nullptr){
		std::cout << "Inicio: " << node->getData() << std::endl;
		for(typename std::list <Node<T>*>::const_iterator iterador = (node->getDesc()).begin(); iterador != (node->getDesc()).end(); iterador++){
			(*iterador)->preOrder();
		}
	}
}
template <class T>
void Arbol<T>::posOrder(Node<T>* inicio){
	Node<T>* node = this->root->search(inicio->getData());
	if(node != nullptr){
		for(typename std::list <Node<T>*>::const_iterator iterador = (node->getDesc()).begin(); iterador != (node->getDesc()).end(); iterador++){
			(*iterador)->posOrder();
		}
		std::cout << "Inicio: " << node->getData() << std::endl;
	}
}
template <class T>
void Arbol<T>::levelOrder(Node<T>* inicio){

}
template <class T>
void Arbol<T>::descendants(Node<T>* inicio){
	Node<T>* node = (this->getRoot())->search(inicio->getData());
	if(node != nullptr){
		node->descendants();
	}
}