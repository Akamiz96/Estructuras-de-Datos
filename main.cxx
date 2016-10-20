#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <regex>
#include "Arbol.h"
#include "BinaryTreeAVL.h"
#include "NodoVocabulario.h"

struct Arboles
{
  Arbol dicc;
  Arbol inverse_dicc;
};

void ayuda( std::string );
bool leerArchivo( BinaryTreeAVL&, std::string, bool );
void insertarPalabra(BinaryTreeAVL&, std::string, bool );
int validarPalabra( std::string );
std::string voltearPalabra(std::string palabra);
int scorePalabra( BinaryTreeAVL&, std::string );
bool leerArchivoXLetras( std::map<char, Arboles>&, std::string, bool );
void insertarPalabraXLetras(std::map<char, Arboles>&, std::string, bool );
std::list< std::string > prefix( std::map< char, Arboles > treeDic, std::string prefijo );
std::list< std::string > sufix( std::map< char, Arboles > tree_letras, std::string sufijo );
unsigned int calcularPuntaje(std::string palabra);

int main()
{
  BinaryTreeAVL tree;
  std::map<char, Arboles> tree_letras;
  bool exit = false, init = false, init_inverse = false;
  bool init_tree = false, init_inverse_tree = false;
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
        init_inverse = leerArchivo( tree, comando, false);
        std::cout << std::endl;
      }
      else
      {
        if( aux == "score" )
        {
          std::string palabra = comando.substr( comando.find( " " ) + 1 );
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
            init = leerArchivo( tree, comando, true);
            std::cout << std::endl;
          }
          else
          {
            if( aux == "init_tree" && !init_tree )
            {
              init_tree = leerArchivoXLetras( tree_letras, comando, true);
              std::cout << std::endl;
            }
            else
            {
              if( aux == "init_inverse_tree" && !init_inverse_tree )
              {
                init_inverse_tree = leerArchivoXLetras( tree_letras, comando, false );
                std::cout << std::endl;
              }
              else
                if( aux == "words_by_prefix" )
                {
                  if( init_tree )
                  {
                    std::string prefijo = comando.substr( comando.find( " " ) + 1 );
                    if( !prefijo.empty())
                    {
                      if(validarPalabra(prefijo) == 1)
                      {
                        std::transform(prefijo.begin(),prefijo.end(),prefijo.begin(),::tolower);
                        std::list< std::string > palabras = prefix( tree_letras, prefijo );
                        if( !palabras.empty() )
                        {
                          std::cout << "Palabras que empiezan por el prefijo " << prefijo << " son: " << std::endl;
                          for( std::list< std::string >::reverse_iterator it = palabras.rbegin(); it != palabras.rend(); ++it )
                            std::cout << *it << " Longitud: " << ( *it ).size() << " Puntaje: " << calcularPuntaje( *it ) << std::endl;
                        }
                        else
                          std::cout << "No hay coincidencias con el prefijo ingresado" << std::endl;
                      }
                      else
                      std::cout << "El prefijo ingresado es invalido" << std::endl;
                    }
                    else
                      std::cout << "El prefijo esta vacio" << std::endl;
                  }
                  else
                    std::cout << "El diccionario no ha sido inicializado con el comando init_tree" << std::endl;
                  std::cout << std::endl;
                }
                else
                  if( aux == "words_by_suffix" )
                  {
                    if( init_inverse_tree )
                    {
                      std::string sufijo = comando.substr( comando.find( " " ) + 1 );
                      if(!sufijo.empty())
                      {
                        if(validarPalabra(sufijo)==1)
                        {
                          std::transform(sufijo.begin(),sufijo.end(),sufijo.begin(),::tolower);
                          std::list< std::string > palabras = sufix( tree_letras, voltearPalabra( sufijo ) );
                          if( !palabras.empty() )
                          {
                            std::cout << "Palabras que terminan con el sufijo " << sufijo << " son: " << std::endl;
                            for( std::list< std::string >::reverse_iterator it = palabras.rbegin(); it != palabras.rend(); ++it )
                              std::cout << voltearPalabra( *it ) << " Longitud: " << ( *it ).size() << " Puntaje: " << calcularPuntaje( *it ) << std::endl;
                          }
                          else
                            std::cout << "No hay coincidencias con el sufijo ingresado" << std::endl;
                        }
                        else
                          std::cout << "El prefijo ingresado es invalido" << std::endl;
                      }
                      else
                        std::cout << "El sufijo esta vacio" << std::endl;
                    }
                    else
                      std::cout << "El diccionario no ha sido inicializado con el comando init_inverse_tree" << std::endl;
                    std::cout << std::endl;
                  }
                  else
                    if( aux == "exit" )
                      exit = true;
                    else
                    {
                      if( ( aux == "init" && init ) || ( aux == "init_inverse" && init_inverse ) || ( aux == "init_tree" && init_tree ) || ( aux == "init_inverse_tree" && init_inverse_tree ) )
                      {
                        if( aux == "init" && init )
                          std::cout << "Diccionario";
                        else
                          if( aux == "init_inverse" && init_inverse )
                            std::cout << "Diccionario inverso";
                          else
                            if( aux == "init_tree" && init_tree )
                              std::cout << "Diccionario Tree";
                            else
                              std::cout << "Diccionario Tree inverso";
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
    std::cout << "descripcion: Inicializa el sistema a partir del archivo words_file.txt, que" << std::endl
              << "contiene un diccionario de palabras aceptadas en el idioma ingles" << std::endl
              << "(idioma original del juego). A diferencia del comando init, este comando" << std::endl
              << "almacena las palabras en sentido inverso (leidas de derecha a izquierda)" << std::endl;
  }
  else
    if( comando == "ayuda init" )
    {
      std::cout << "comando: init words_file.txt" << std::endl;
      std::cout << "descripcion: Inicializa el sistema a partir del archivo words_file.txt, que" << std::endl
                << "contiene un diccionario de palabras aceptadas en el idioma ingles (idioma" << std::endl
                << "original del juego)." << std::endl << std::endl;
    }
    else
      if( comando == "ayuda score" )
      {
        std::cout << "comando: score word" << std::endl;
        std::cout << "descripcion: El comando permite conocer la puntuacion que puede obtenerse con" << std::endl
                  << "una palabra dada, de acuerdo a la tabla de puntuacion de cada letra." << std::endl;
      }
      else
        if( comando == "ayuda exit" )
        {
          std::cout << "comando: exit" << std::endl;
          std::cout << "descripcion: Termina la ejecucion de la aplicacion." << std::endl;
        }
        else
        {
          if( comando == "ayuda" )
          {
            std::cout << "Teclee \"ayuda <comando>\" para obtener más informacion del comando" << std::endl;
            std::cout << std::endl << "\tinit [nombre del archivo]" << std::endl
                      << "\tinit_inverse [nombre del archivo]" << std::endl
                      << "\tinit_tree [nombre del archivo]" << std::endl
                      << "\tinit_inverse_tree [nombre del archivo]" << std::endl
                      << "\twords_by_prefix [prefijo]" << std::endl
                      << "\twords_by_suffix [sufijo]" << std::endl
                      << "\tscore [palabra]" << std::endl
                      << "\texit" << std::endl;
          }
          else
            if( comando == "ayuda init_tree" )
            {
              std::cout << "comando: init_tree words_file.txt" << std::endl;
              std::cout << "descripcion: Inicializa el sistema a partir del archivo words_file.txt, que" << std::endl
                        << "contiene un diccionario depalabras aceptadas en el idioma inglés (idioma" << std::endl
                        << "original del juego). A diferencia del comando init, este comando almacena las" <<std::endl
                        << "palabras en uno o más árboles de letras (como se considere conveniente)." << std::endl;
            }
            else
              if( comando == "ayuda init_inverse_tree" )
              {
                std::cout << "comando: init_inverse_tree words_file.txt" << std::endl;
                std::cout << "descripcion: Inicializa el sistema a partir del archivo words_file.txt, que " << std::endl
                          << "contiene un diccionario de palabras aceptadas en el idioma inglés (idioma " << std::endl
                          << "original del juego). A diferencia de los comandos init_inverse e init_tree, este" << std::endl
                          << "comando almacena las palabras en uno o más árboles de letras, pero en sentido " << std::endl
                          << "inverso (leídas de derecha a izquierda). " << std::endl;
              }
              else
                if( comando == "ayuda words_by_prefix" )
                {
                  std::cout << "comando: words_by_prefix prefix" << std::endl;
                  std::cout << "descripcion: Dado un prefijo de pocas letras, el comando recorre el(los)        " << std::endl
                            << "árbol(es) de letras (construído(s) con el comando init_tree) para ubicar todas" << std::endl
                            << "las palabras posibles a construir a partir de ese prefijo." << std::endl;
                }
                else
                  if( comando == "ayuda words_by_suffix" )
                  {
                    std::cout << "comando: words_by_suffix suffix" << std::endl;
                    std::cout << "descripcion: Dado un sufijo de pocas letras, el comando recorre el(los)        " << std::endl
                              << "árbol(es) de letras (construído(s) con el comando init_inverse_tree) para" << std::endl
                              << "ubicar todas las palabras posibles a construir que terminan con ese sufijo." << std::endl;
                  }
                  else
                    std::cout << "Error comando inexistente, teclee \"ayuda\" para ver una lista de comandos" << std::endl;
        }
}

bool leerArchivo( BinaryTreeAVL& tree, std::string comando, bool tipo )
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
    return true;
  }
  else
  {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "ERROR" << std::endl;
    std::cout << "apertura del archivo: " << nombreArc << " fallida." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    return false;
  }
}

void insertarPalabra(BinaryTreeAVL& tree, std::string palabra, bool tipo){
  if(validarPalabra(palabra) == 1){
    BinaryNodeAVL* nodoLetra = tree.search(palabra[0]);
    if(nodoLetra != nullptr){
      if(tipo)
        nodoLetra->getData().insertarPalabra(palabra);
      else
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

bool leerArchivoXLetras( std::map<char, Arboles>& tree_letras, std::string comando, bool tipo )
{
  std::string nombreArc, linea;
  nombreArc = comando.substr( comando.find( " " ) + 1 );
  std::ifstream archivo( nombreArc.c_str( ) );
  if( archivo.is_open() )
  {
    do
    {
      archivo >> linea;
      std::transform(linea.begin(),linea.end(),linea.begin(),::tolower);
      if(tipo == true)
        insertarPalabraXLetras(tree_letras , linea, tipo);
      else
        insertarPalabraXLetras(tree_letras, voltearPalabra(linea), tipo);
    }while( !archivo.eof() );
    std::cout << std::endl << "----------------------------------------------------" << std::endl;
    std::cout << "El diccionario se inicializo." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    return true;
  }
  else
  {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "ERROR" << std::endl;
    std::cout << "apertura del archivo: " << nombreArc << " fallida." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    return false;
  }
}

void insertarPalabraXLetras(std::map<char, Arboles>& tree_letras, std::string palabra, bool tipo){
  bool inserta = false;
  if(validarPalabra(palabra) == 1){
    std::map<char, Arboles>::iterator iterador = tree_letras.find(palabra[0]);
    if(iterador != tree_letras.end()){
      if(tipo)
        tree_letras[palabra[0]].dicc.insertarPalabra(palabra, inserta);
      else
        tree_letras[palabra[0]].inverse_dicc.insertarPalabra(palabra, inserta);
    }
    else{
      Arboles * arboles = new Arboles();
      Node * node1 = new Node(palabra[0]);
      Node * node2 = new Node(palabra[0]);
      arboles->dicc.setRoot(node1);
      arboles->inverse_dicc.setRoot(node2);
      std::pair<std::map<char, Arboles>::iterator, bool> insercion;
      insercion = tree_letras.insert(std::pair<char, Arboles>(palabra[0], (*arboles)));
      if(insercion.second == false){
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "ERROR" << std::endl;
        std::cout << "La palabra: " << palabra << " no se pudo ingresar al diccionario." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
      }
      else{
        std::map<char, Arboles>::iterator iterador = tree_letras.find(palabra[0]);
        if(iterador != tree_letras.end()){
          if(tipo)
            tree_letras[palabra[0]].dicc.insertarPalabra(palabra, inserta);
          else
            tree_letras[palabra[0]].inverse_dicc.insertarPalabra(palabra, inserta);
        }
      }
    }
  }
  else{
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "ERROR" << std::endl;
    std::cout << "La palabra: " << palabra << " tiene caracteres invalidos." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
  }
  if(!inserta){
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "ERROR" << std::endl;
    std::cout << "La palabra: " << palabra << " no se pudo ingresar al diccionario." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
  }
}

std::list< std::string > prefix( std::map< char, Arboles > tree_letras, std::string prefijo )
{
  std::list< std::string > prefijos;
  if( !tree_letras.empty() )
  {
    std::map< char, Arboles >::iterator itTree_letras = tree_letras.find( prefijo[0] );
    if( itTree_letras != tree_letras.end() )
    {
      Arboles aux = itTree_letras->second;
      prefijos = ( aux.dicc ).prefix( prefijo );
    }
  }
  return prefijos;
}

std::list< std::string > sufix( std::map< char, Arboles > tree_letras, std::string sufijo )
{
  std::list< std::string > sufijos;
  if( !tree_letras.empty() )
  {
    std::map< char, Arboles >::iterator itTree_letras = tree_letras.find( sufijo[0] );
    if( itTree_letras != tree_letras.end() )
    {
      Arboles aux = itTree_letras->second;
      sufijos = ( aux.inverse_dicc ).prefix( sufijo );
    }
  }
  return sufijos;
}

unsigned int calcularPuntaje(std::string palabra)
{
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
