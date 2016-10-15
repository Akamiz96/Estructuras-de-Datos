#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <regex>
#include "BinaryTreeAVL.h"
#include "NodoVocabulario.h"

void ayuda( std::string );
void leerArchivo( BinaryTreeAVL&, std::string, bool );
void insertarPalabra(BinaryTreeAVL&, std::string, bool );
int validarPalabra( std::string );
std::string voltearPalabra(std::string palabra);
int scorePalabra( BinaryTreeAVL&, std::string );

int main()
{
  BinaryTreeAVL tree;
  bool exit = false, init = false, init_inverse = false;
  std::string comando;
  do
  {
    std::cout << "$ ";
    std::getline( std::cin, comando );
    std::string aux = comando.substr( 0, comando.find( " " ) );
    if( comando.find( "ayuda" ) != std::string::npos )
    {
      ayuda( comando );
      std::cout << std::endl;
    }
    else
    {
      if( aux == "init_inverse" && !init_inverse )
      {
        //TODO funcion init_inverse
        leerArchivo( tree, comando, false);
        init_inverse = true;
        std::cout << std::endl;
      }
      else
      {
        if( aux == "score" )
        {
          std::string palabra = comando.substr( comando.find( " " ) + 1 );
          //TODO funcion score
          int scoreP = scorePalabra(tree, palabra);
          if(scoreP == -1){
            std::cout << "----------------------------------------------------" << std::endl;
            std::cout << "ERROR" << std::endl;
            std::cout << "La palabra " << palabra << " tiene caracteres invalidos." << std::endl;
            std::cout << "----------------------------------------------------" << std::endl;
          }
          else{
            if(scoreP == -2){
              std::cout << "----------------------------------------------------" << std::endl;
              std::cout << "ERROR" << std::endl;
              std::cout << "La palabra " << palabra << " no se encuentra en el diccionario." << std::endl;
              std::cout << "----------------------------------------------------" << std::endl;
            }
            else{
              std::cout << "El puntaje de la palabra " << palabra << " es: " << scoreP << std::endl;
              std::cout << std::endl;
            }
          }

        }
        else
        {
          if( aux == "init" && !init )
          {
            //TODO funcion init
            leerArchivo( tree, comando, true);
            init = true;
            std::cout << std::endl;
          }
          else
            if( aux == "exit" )
              exit = true;
            else
              if( ( aux == "init" && init ) || ( aux == "init_inverse" && init_inverse ) )
              {
                if( init )
                  std::cout << "Diccionario";
                else
                  std::cout << "Diccionario inverso";
                std::cout << " ya ha sido inicializado." << std::endl;
                std::cout << std::endl;
              }
              else
              {
                std::cout << "Error comando inexistente, teclee \"ayuda\" para ver una lista de comandos" << std::endl;
                std::cout << std::endl;
              }
        }

      }
    }
  }while( !exit );
  return 0;
}

void ayuda( std::string comando )
{
  if( comando == "ayuda init_inverse" )
  {
    std::cout << "comando: init_inverse words_file.txt." << std::endl;
    std::cout << "descripción: Inicializa el sistema a partir del archivo words_file.txt, que" << std::endl
              << "contiene un diccionario de palabras aceptadas en el idioma ingles" << std::endl
              << "(idioma original del juego). A diferencia del comando init, este comando" << std::endl
              << "almacena las palabras en sentido inverso (leidas de derecha a izquierda)" << std::endl;
  }
  else
    if( comando == "ayuda init" )
    {
      std::cout << "comando: init words_file.txt" << std::endl;
      std::cout << "descripción: Inicializa el sistema a partir del archivo words_file.txt, que" << std::endl
                << "contiene un diccionario de palabras aceptadas en el idioma ingles" << std::endl
                << "(idioma original del juego)." << std::endl << std::endl;
    }
    else
      if( comando == "ayuda score" )
      {
        std::cout << "comando: score word" << std::endl;
        std::cout << "descripción: El comando permite conocer la puntuacion que puede obtenerse con" << std::endl
                  << "una palabra dada, de acuerdo a la tabla de puntuacion de cada letra." << std::endl;
      }
      else
        if( comando == "ayuda exit" )
        {
          std::cout << "comando: exit" << std::endl;
          std::cout << "descripción: Termina la ejecucion de la aplicacion." << std::endl;
        }
        else
        {
          if( comando == "ayuda" )
          {
            std::cout << "Teclee \"ayuda <comando>\" para obtener más informacion del comando" << std::endl;
            std::cout << std::endl << "\tinit [nombre del archivo]" << std::endl;
            std::cout << "\tinit_inverse [nombre del archivo]" << std::endl;
            std::cout << "\tscore [palabra]" << std::endl;
            std::cout << "\texit" << std::endl;
          }
          else
          std::cout << "Error comando inexistente, teclee \"ayuda\" para ver una lista de comandos" << std::endl;

        }
}

void leerArchivo( BinaryTreeAVL& tree, std::string comando, bool tipo )
{
  std::string nombreArc, linea;
  nombreArc = comando.substr( comando.find( " " ) + 1 );
  std::ifstream archivo( nombreArc.c_str( ) );
  if( archivo.is_open() )
  {
    while( !archivo.eof() )
    {
      archivo >> linea;
      std::transform(linea.begin(),linea.end(),linea.begin(),::tolower);
      if(tipo == true)
        insertarPalabra(tree , linea, tipo);
      else
        insertarPalabra(tree, voltearPalabra(linea), tipo);
    }
    std::cout << std::endl << "----------------------------------------------------" << std::endl;
    std::cout << "El diccionario se inicializo." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

  }
  else
  {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "ERROR" << std::endl;
    std::cout << "apertura del archivo: " << nombreArc << " fallida." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
  }
}

void insertarPalabra(BinaryTreeAVL& tree, std::string palabra, bool tipo){
  if(validarPalabra(palabra) == 1){
    BinaryNodeAVL* nodoLetra = tree.search(palabra[0]);
    if(nodoLetra != nullptr){
      if(tipo)
        nodoLetra->getData().insertarPalabra(palabra);
      else((nodoLetra->getData().getPalabras())[palabra]);
        nodoLetra->getData().insertarPalabraInv(palabra);
    }
    else{
      NodoVocabulario* nodo = new NodoVocabulario(palabra[0]);
      tree.insert(*nodo);
      if(tipo)
        nodo->insertarPalabra(palabra);
      else
        nodo->insertarPalabraInv(palabra);
    }
  }
  else{
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "ERROR" << std::endl;
    std::cout << "La palabra: " << palabra << " tiene caracteres invalidos." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
  }
}

int validarPalabra( std::string palabra )
{
    int verificado = 0;
    for( unsigned int i = 0; i < palabra.size(); i++ )
    {
        char caracter = palabra[i];
        if( ( caracter >= 65 && caracter <= 90 ) || ( caracter >= 97 && caracter <= 122 ) )
            verificado = 1;
        else
        {
          verificado = 0;
          break;
        }
    }
    return verificado;
}

std::string voltearPalabra(std::string palabra)
{
    int ind = 0;
    std::string nPalabra;
    nPalabra.resize(palabra.size());
    for(std::string::reverse_iterator apun = palabra.rbegin(); apun != palabra.rend(); apun++)
    {
        nPalabra[ind]=*apun;
        ind++;
    }
    return nPalabra;
}

int scorePalabra(BinaryTreeAVL& tree, std::string palabra){
  if(validarPalabra(palabra) == 1){
    BinaryNodeAVL* nodoLetra = tree.search(palabra[0]);
    if(nodoLetra != nullptr){
      std::map<std::string, int>::iterator iterador = nodoLetra->getData().getPalabras().find(palabra);
      if(iterador != nodoLetra->getData().getPalabras().end())
        return((nodoLetra->getData().getPalabras())[palabra]);
      else{
        iterador = nodoLetra->getData().getPalabrasInv().find(palabra);
        if(iterador != nodoLetra->getData().getPalabrasInv().end())
          return ((nodoLetra->getData().getPalabrasInv())[palabra]);
        else
          return (-2);
      }
    }
    else
      return (-2);
  }
  return (-1);
}
