NodoVocabulario::NodoVocabulario(){

}
NodoVocabulario::NodoVocabulario(char letraNodo){
  letra = letraNodo;
}
NodoVocabulario::NodoVocabulario(char letraNodo, std::map<std::string, int> palabrasNodo){
  letra = letraNodo;
  palabras = palabrasNodo;
}
NodoVocabulario::~NodoVocabulario(){

}
void NodoVocabulario::setLetra (char letraNodo){
  this->letra = letraNodo;
}
void NodoVocabulario::setPalabras (std::map<std::string, int> palabrasNodo){
  this->palabras = palabrasNodo;
}
char NodoVocabulario::getLetra (){  
  return this->letra;
}
std::map<std::string, int> NodoVocabulario::getPalabras(){
  return this->palabras;
}
void insertarPalabra(std::string palabra){
  std::pair<std::map<std::string, int>::iterator, bool> insercion;
  insercion = this->palabras.insert(std::pair<std::string, int>(palabra, calcularPuntaje(palabra)))
}
unsigned int calcularPuntaje(std::string palabra){
  unsigned int puntaje = 0;
  for(std::string::iterator iterador = palabra.begin(); iterador != palabra.end(); iterador++){
    if(*(iterador) == 'e' || *(iterador) == 'a' || *(iterador) == 'i' || *(iterador) == 'o' || *(iterador) == 'n' || *(iterador) == 'r' || *(iterador) == 't' || *(iterador) == 'l' || *(iterador) == 's' || *(iterador) == 'u')
      puntaje ++;
    if(*(iterador) == 'd' || *(iterador) == 'g')
      puntaje = puntaje + 2;
    if(*(iterador) == 'b' || *(iterador) == 'c' || *(iterador) == 'm' || *(iterador) == 'p')
      puntaje = puntaje + 3;
    if(*(iterador) == 'f' || *(iterador) == 'h' || *(iterador) == 'v' || *(iterador) == 'w' || *(iterador) == 'y')
      puntaje = puntaje + 4;
    if(*(iterador) == 'k')
      puntaje = puntaje + 5;
    if(*(iterador) == 'j' || *(iterador) == 'x')
      puntaje = puntaje + 8;
    if(*(iterador) == 'q' || *(iterador) == 'z')
      puntaje = puntaje + 10;
  }
  return puntaje;
}
