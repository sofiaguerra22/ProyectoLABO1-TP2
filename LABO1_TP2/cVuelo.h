#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Enums.h"
#include "cListaPasajeros.h"
#include "cListaValija.h"
#define maxpasajeros 100;
class cAvion;
class cPasajero;
using namespace std;
class cVuelo
{
	//atributos:
	int cantpasajeros, numeroVuelo;
	float pesoVuelo;
	bool estado; //a tiempo o retrasado
	long int fechaArribo, fechaPartida, horaArribo, horaPartida;
	cPasajero** pasajerosVuelo; //lista de pasajeros
	cListaPasajeros** listapasajeros; //puntero a la lista CONSULTAR!!
	eDestino destino; //enum de destinos
	cAvion* avion; 
	cListaValija* valija; //lista de valijas

public:
	cVuelo();
	~cVuelo();
	bool AgregarPasajero(string DNI);
	float PesoVuelo();
};

