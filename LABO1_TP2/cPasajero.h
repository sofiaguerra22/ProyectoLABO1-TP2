#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cListaValija.h"
#include "cValija.h"
using namespace std;
#define maxvalijas 3 //cantidad maxima de valijas = 3

class cPasajero
{
	friend class cListaPasajeros;
	friend class cVuelo;

private: //atributos:
	int asiento, numerovuelo;
	string DNI;
	bool equipaje; // si tiene equipaje o no
	float acumpeso; // peso total de las valijas
	const float peso = 75; //uso de atributo const
	cListaValija* valijas; //lista de valijas

public: //metodos:
	cPasajero(string _DNI);
	~cPasajero();
	void AgregarEquipaje(cValija* valija);
	float PesoTotal(); //suma el peso del pasajero (75kg) con sus valijas 
	string getDNI() { return DNI; };
	void ImprimirDatos();
	string toString();
	
};

