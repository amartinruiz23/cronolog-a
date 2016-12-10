#ifndef _Cronologia_H_
#define _Cronologia_H_

#include <map>
#include "eventohistorico.h"
using namespace std;

class Cronologia{

  map<int, EventoHistorico> eventos; // eventos = conjunto de <fecha,evento(=fecha,sucesos)>

public:

  Cronologia() = default;
  ~Cronologia () = default;
  Cronologia(const Cronologia& c1, const Cronologia& c2); 

  typedef typename map<int, EventoHistorico>::iterator it;
  typedef typename map<int, EventoHIstorico>::const_iterator constit;

  it begin();
  it end();
  constit begin() const;
  constit end() const;

  EventoHistorico GetEventos(int anio); //devuelve el evento histórico con el año indicado
  void inserta(const EventoHistorico& e); //inserta un evento histórico en la cronología

  friend ostream& operator<<(ostream& os, EventoHistorico& e);
  friend istream& operator>>(istream& is, EventoHistorico& e);

  /*estas funciones deben hacerse en cpps a parte de cronologia.cpp, cada una en un cpp*/

   Cronologia filtrarEventos(const string& palabraclave); //devuelve una cronología con los eventos que contengan la palabra clave
   Cronologia filtrarEventos(int fechacomienzo, int fechafinal); //devuelve la subcronología entre la fecha de inicio y la final, posible uso de valores predeterminados.
   void estadisticas(int& total_anios, int& total_acont, int& max_acont, double& media_acont); //realiza funciones de estadística como descrito en pdf

};

/*
      >[TO DO]<
      > Implementar funciones en los distintos cpps (no olvidar incluir el .h)
      > Makefike
      > Doxygen
      > Alvaro pornte bueno
*/
#endif
