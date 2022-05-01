#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cVuelo.h"
#include "cListaVuelos.h"
#include "cVuelo.h"
#include "Fecha.h"
using namespace std;
class cAeropuerto; //forward declaration
class cAvion
{
	friend class cAeropuerto; //aeropuerto tiene que poder acceder a su puntero de vuelo

private:
	int ID, cantpasajeros_actual, cantpasajeros_max; 
	float pesomax, pesoactual;
	bool permiso;
	cVuelo* vuelo;
	cListaVuelos* listaVuelos; 
	cAeropuerto* aeropuerto; 


public:
	cAvion(int _ID, int _pasajerosmax, float _pesomax);
	~cAvion();
	bool AsignarVuelo(cVuelo* Vuelo);
	void Despegar(cAeropuerto* Aeropuerto, Fecha* fechaActual);
	bool Aterrizar(cAeropuerto* Aeropuerto, Fecha* fechaActual);
	void PedirPermiso();
	bool RecibirPermiso(cAeropuerto* Aeropuerto);
	bool ChequearCargaMaxima();
	int getCantPasajerosActual();
	int getID() { return ID; };
	int getCantPasajeros() { return cantpasajeros_actual; };
	void ImprimirDatos();
	string toString();
};
