#ifndef __CONECTA_4_
#define __CONECTA_4_

#include "ArbolGeneral.h"
#include "tablero.h"
#include <vector>
#include <utility>

/**
   @brief T.D.A. conecta4

   \b Definición:
   Una instancia \e c del tipo de dato abstracto conecta4 se se puede construir como

   - Un árbol que contiene un elemento destacado, el nodo raíz, indispensable para
	 crear el árbol, y dos valores, \e PROFUNDIDAD cuyo valor será decidido por los
	 autores, y \e metrica valor suministrado por el usuario que indicará en cierta
   medida el grado de dificultad.

	 En definitiva un objeto del tipo de dato abstracto conecta4 es el conjunto de
   todos los movimientos posibles del jugador automático, que son almacenados en
	 una estructura de tipo ArbolGeneral

   Para poder usar el tipo de dato conecta4 se debe incluir el fichero

   <tt>\#include conecta4.h</tt>

   El espacio requerido para el almacenamiento es O(n), donde n es el número de
   nodos del árbol.

   @authors Álvaro López Jiménez y Antonio Martín Ruíz.
   @date Enero de 2017
*/


class conecta4{

  ArbolGeneral<Tablero> arbol;
  const int PROFUNDIDAD = 3;
	int metricaelegida ;

	/**
	* @brief Dado un nodo genera todos los posibles movimientos (todos los tableros resultantes)
	* del jugador automático
	* @param n nodo padre de los futuros tableros a crear
	*/
  void GeneraHijos(ArbolGeneral<Tablero>::nodo* n);

	/**
	* @brief Función que evalua la idoneidad o no de un tablero de cara a los intereses
	* del jugador automático de cara a ganar la partida.
	* @param t Tablero a evaluar
	* @return entero con la puntuación obtenida
	*/
  int evalua1 (ArbolGeneral<Tablero>::nodo* t) ;
  int evalua2 (ArbolGeneral<Tablero>::nodo* t) ;

	/**
	* @brief Función auxiliar que calcula el máximo valor del segundo campo de los
	* pares de elementos enteros de un vector
	* @param v vector
	* @return devuelve la pareja de elementos cuyo segundo campo es el mayor del
	* vector
	*/
  pair<int, int> maximo(vector<pair<int,int> > v);

	/**
	* @brief Función auxiliar que calcula el mínimo valor del segundo campo de los
	* pares de elementos enteros de un vector
	* @param v vector
	* @return devuelve la pareja de elementos cuyo segundo campo es el menor del
	* vector
	*/
  pair<int, int> minimo(vector<pair<int,int> > v);

public:


	/**
	* @brief Función que construye un objeto de la clase conecta4, y llama sobre
	* el nodo raíz a la función recursiva.
	* @param t Tablero actual de la partida que será el nodo raíz del árbol
	* @param met, métrica que decidirá qué función evaluará los nodos del árbol
	* @return qué hijo será el elegido para que el jugador automático inserte la
	* ficha
	*/
  int jugada(Tablero t, int met = 0);

	/**
	* @brief Destructor de conecta4, libera los recursos ocupados por el árbol
	*/
	~conecta4() = default ;

	/**
	* @brief Función que dado un nodo del árbol crea evalúa (llamando a métrica)
	* dicho nodo a partir de sus hijos (creándolos y evaluándolos)
	* @param n nodo del árbol
	* @return pareja de enteros donde el primer elemento es el índice del hijo y
	* el segundo valor es la puntuación del nodo
	*/
	pair<int,int> recursiva (ArbolGeneral<Tablero>::nodo* t) ;

	/**
	* @brief Función que evalua un nodo hoja del árbol en función de los intereses
	* del jugador automático de cara a ganar la partida, llamando a las funciones
	* evalua según el dato miembro metrica.
	*/
	int metrica (ArbolGeneral<Tablero>::nodo* t);

};


#endif
