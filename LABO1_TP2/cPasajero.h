#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cListaValija.h"
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
	cListaValija* valijas; //lista de valijas
	cValija* valija; 

private: //metodos:
	cPasajero(string _DNI);
	~cPasajero();
	bool AgregarEquipaje(float peso);
	float PesoTotal(); //suma el peso del pasajero (75kg) con sus valijas 
	void ImprimirDatos();
	string toString();
	
};

