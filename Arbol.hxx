#include "Arbol.h"
#include <list>

Arbol::Arbol(){
	this->root = nullptr;
}
Arbol::Arbol(char val)
{
    this->root=new Node(val);
}
Arbol::~Arbol(){
	this->root = nullptr;
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
		descendiente=node->getDesc();
	}
    return descendiente;
}

void Arbol::insertarPalabra(std::string palabra, bool& insercion){
	if(palabra[0] == this->root->getData()){
		palabra.erase(palabra.begin());
		this->root->insertarPalabra(palabra, insercion);
	}
	else
		insercion = false;
}

std::list< std::string > Arbol::prefix( std::string prefijo )
{
  Node* aux = this->root;
  bool encontrado = true;
  for( int i = 1; i < prefijo.size() && encontrado; i++ )
  {
    encontrado = false;
    for( std::list< Node* >::iterator it = ( aux->getDesc() ).begin(); it != ( aux->getDesc() ).end(); it++ )
		{
      if( ( *it )->getData() == prefijo[i] )
      {
        encontrado = true;
        aux = *it;
				break;
      }
    }
  }
  std::string palabra = prefijo;
  std::list< std::string > palabras;
	if( encontrado )
	{
  	for( std::list < Node* >::const_iterator iterador = ( aux->getDesc() ).begin();
         iterador != ( aux->getDesc() ).end(); iterador++)
  	{
			( *iterador )->prefix( palabras, palabra );
		}
	}
  return palabras;
}
