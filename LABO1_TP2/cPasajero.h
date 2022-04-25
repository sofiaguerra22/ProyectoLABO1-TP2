#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cValija.h"
#include "cVuelo.h"
#define maxvalijas 3 //cantidad maxima de valijas = 3
using namespace std;

class cPasajero
{
public: //atributos:
	int asiento;
	string DNI;
	bool equipaje;
	long int fecha;
	float acumpeso, pesototal; //peso total de las valijas
	cVuelo* vuelo;
	cValija** valijas; //lista de valijas


private: //metodos:
	cPasajero(int _asiento, string _DNI);
	~cPasajero();
	bool AgregarValija(float peso);
	float PesoTotal(); //suma el peso del pasajero (75kg) con sus valijas 
	void setVuelo(cVuelo* _vuelo);
	
};

