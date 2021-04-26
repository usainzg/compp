#ifndef CODIGO_HPP_
#define CODIGO_HPP_
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>
#include "Structs.hpp"

/* Estructura de datos para el código generado. El código, en vez de escribirlo directamente, 
 * se guarda en esta estructura y, al final, se escribirán en un fichero.
 */
class Codigo {

private:

	/**************************/
	/* REPRESENTACION INTERNA */
	/**************************/

	/* Clave para generar identificaciones nuevos. Cada vez que se crea un idse incrementa. */
	int siguienteIdentificador;

	/* Devuelve el número correspondiente a la siguiente instrucción, para que cada instrucción tenga su referencia. */
	int siguienteInstruccion() const;

	/* Instrucciones que forman el código. */
	std::vector<std::string> instrucciones;

public:

	/************************************/
	/* METODOS PARA GESTIONAR EL CODIGO */
	/************************************/

	/* Constructora */
	Codigo();

	/* Crea un nuevo identificador del tipo "_t1, _t2, ...", siempre diferente. */
	std::string nuevoId() ;

	/* Añade una nueva instrucción a la estructura. */
	void anadirInstruccion(const std::string &instruccion);

	/* Dada una lista de variables y su tipo, crea y añade las instrucciones de declaración */
	void anadirDeclaraciones(const std::vector<std::string> &idNombres, const std::string &tipoNombre);

	/* Dada una lista de parámetros y su tipo, crea y añade las instrucciones de declaración */
	void anadirParametros(const std::vector<std::string> &idNombres, const std::string &pTipo, const std::string &tipoNombre) ;

	/* Añade a las instrucciones que se especifican la referencia que les falta.
	 * Por ejemplo: "goto" => "goto 20;" */
	void completarInstrucciones(std::vector<int> &numerosInstrucciones, const int referencia);

	/* Escribe las instrucciones acumuladas en la estructura en el fichero de salida. */
	void escribir() const;

	/* Devuelve el número de la siguiente instrucción. */
	int obtenRef() const;

	/* Devuelve un string vacío */
	std::string iniNom();

	/* Devuelve una lista de enteros vacía en caso de que &arg sea 0, en otro caso devuelve la lista con &arg. */
	std::vector<int> iniLista(const int &arg);

	/* Devuelve una lista de string vacía en caso de que &arg sea un string vacío, en otro caso devuelve la lista con &arg. */
	std::vector<std::string> iniLista(const std::string &arg);

	/* Devuelve true si &lista es una lista de enteros vacía. */
	bool esVacia(const std::vector<int> &lista);

	/* Devuelve el puntero a la lista resultante de unir las listas &list1 y &list2. */
	std::vector<int> *unir(const std::vector<int> &list1, const std::vector<int> &list2);

	/* Devuelve el puntero a la lista resultante de unir las listas &list1 y &list2. */
	std::vector<std::string> *unir(const std::vector<std::string> &list1, const std::vector<std::string> &list2);

	/* Constante que indica el tipo numérico, tanto ent como real. */
	static const std::string NUMERO;

	/* Constante que indica el tipo entero. */
	static const std::string NUMERO_INT;

	/* Constante que indica el tipo real. */ 
	static const std::string NUMERO_FLOAT;

	/* Constante que indica el tipo booleano. */
	static const std::string BOOLEANO;

};

#endif /* CODIGO_HPP_ */
