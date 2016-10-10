#ifndef __NODOVOCABULARIO_H__
#define __NODOVOCABULARIO_H__
#include <map>
class NodoVocabulario{
protected:
  char letra;
  std::map<std::string, int> palabras;
  std::map<std::string, int> palabrasInv;
public:
  NodoVocabulario();
  NodoVocabulario(char letraNodo);
  NodoVocabulario(char letraNodo, std::map<std::string, int> palabrasNodo);
  NodoVocabulario(char letraNodo, std::map<std::string, int> palabrasNodo, std::map<std::string, int> palabrasInvNodo);
  ~NodoVocabulario();
  void setLetra (char letraNodo);
  void setPalabras (std::map<std::string, int> palabrasNodo);
  void setPalabrasInv (std::map<std::string, int> palabrasInvNodo);
  char getLetra ();
  std::map<std::string, int> getPalabras();
  std::map<std::string,int> getPalabrasInv();
  void insertarPalabra(std::string palabra);
  void insetarPalabraInv(std::string palabraInv);
private:
  unsigned int calcularPuntaje(std::string palabra);
};
#include "NodoVocabulario.hxx"
#endif
