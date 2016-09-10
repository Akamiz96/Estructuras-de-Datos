#ifndef __NODOVOCABULARIO_H__
#define __NODOVOCABULARIO_H__
#include <map>
class NodoVocabulario{
protected:
  char letra;
  std::map<std::string, int> palabras;
public:
  NodoVocabulario();
  NodoVocabulario(char letraNodo);
  NodoVocabulario(char letraNodo, std::map<std::string, int> palabrasNodo);
  ~NodoVocabulario();
  void setLetra (char letraNodo);
  void setPalabras (std::map<std::string, int> palabrasNodo);
  char getLetra ();
  std::map<std::string, int> getPalabras();
  void insertarPalabra(std::string palabra);
private:
  unsigned int calcularPuntaje(std::string palabra);
};
#include "NodoVocabulario.hxx"
#endif
