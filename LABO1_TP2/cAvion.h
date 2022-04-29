#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cVuelo.h"
#include "cListaVuelos.h"
using namespace std;
class cAeropuerto; //forward declaration
class cAvion
{
private:
	int ID, cantpasajeros_actual, cantpasajeros_max; //atributo const
	float pesomax, pesoactual;
	bool permiso;
	cVuelo* vuelo;
	cListaVuelos* listaVuelos; //puntero a la lista total de vuelos
	cAeropuerto* aeropuerto; 


public:
	cAvion(int _ID, int _pasajerosmax, float _pesomax);
	~cAvion();
	bool AsignarVuelo(cVuelo* Vuelo);
	void Despegar();
	void Aterrizar(cAvion* Avion);
	void PedirPermiso();
	bool RecibirPermiso(cAvion* Avion);
	bool ChequearCargaMaxima();
	int getCantPasajerosActual();
	int getID() { return ID; };
	void ImprimirDatos();
	int getCantPasajeros() { return cantpasajeros_actual; };
	string toString();
	friend class cAeropuerto;
};
