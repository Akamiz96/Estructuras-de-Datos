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
