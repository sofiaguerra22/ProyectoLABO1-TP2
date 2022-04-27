#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cValija.h"
//#include "cVuelo.h"
using namespace std;
constexpr auto maxvalijas = 3; //cantidad maxima de valijas = 3; CONSULTAR!!!
class cPasajero
{
	friend class cListaPasajeros;
	friend class cVuelo;

public: //atributos:
	int asiento, numerovuelo;
	string DNI;
	bool equipaje; // si tiene equipaje o no
	long int fecha;
	float acumpeso; // pesototal; //peso total de las valijas
	//cVuelo* vuelo;
	cValija** valijas; //lista de valijas


private: //metodos:
	cPasajero(int _asiento, string _DNI);
	~cPasajero();
	bool AgregarEquipaje(float peso);
	float PesoTotal(); //suma el peso del pasajero (75kg) con sus valijas 
	//void setVuelo(cVuelo* _vuelo); //LLAMA A AGREGAR PASAJERO y modifica numero de vuelo y fecha
		//si en vez de un set vuelo, hacemos friend class a vuelo y que este mismo lo modifique directamente?
		//en ese caso no va a ser necesario el puntero a vuelo
	
};

