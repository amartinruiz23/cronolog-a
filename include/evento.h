#ifndef _EVENTO_H_
#define _EVENTO_H_
#include <string>
#include <vector>


class evento{
  int anio;
  vector<string> sucesos;

  public:

	/** 
	* @brief Constructor por defecto de eventos
	* 
	*/
  evento();


	/**
	* @brief Constructor copia de eventos
	* @param e evento a copiar
	*/
  evento(const evento& e);

	/**
	* @brief Destructor de eventos
	*/
  ~evento();

	/**
	* @brief Operador de asignación de eventos
	* @param e evento a asignar
	* @return referencia al evento asignado
	*/ 
  evento& operator=(const evento& e);

	/** 
	* @brief Consulta del año de un evento
	* @param e evento a consultar
	* @return año del evento // especificamos tipo devuelto ?????????
	*/
  int getanio(const evento& e);

	/** 
	* @brief Consulta de los sucesos de un evento
	* @param e evento a consultar
	* @return conjunto de sucesos del evento
	*/ 
  const vector& getsucesos(const evento& e); // ?

	/** 
	* @brief Consulta de un suceso de un evento
	* @param e evento a consultar
	* @param n posicion del suceso a consultar en el vector
	* @pre n debe ser mayor o igual a 1
	* @return suceso consultado
	*/
  string getsuceso(const evento& e, int n);

	/**
	* @brief Inserta un suceso
	* @param s suceso a insertar
	* @param p posicion del vector en la que se quiere insertar el suceso, si no se indica nada, será en la primera posición
	* @pre p tiene que ser mayor o igual a 1 en caso de que se quiera indicar la posición
	* @return // ???????????????????????????
	*/
  void insertasuceso(string s, int p=-1);

	/**
	* @brief Elimina un suceso de un evento
	* @param n posición del suceso en el vector a eliminar
	* @pre n tiene que ser mayor o igual a 1
	* @return // ?????????????????????????
	*/
	void eliminasuceso(int n);
	/**
	* @brief Elimina un suceso de un evento
	* @param s suceso a eliminar
	* @return si ha eliminado dicho suceso
	*/ 
	bool eliminasuceso(const string& s);
};

#endif
