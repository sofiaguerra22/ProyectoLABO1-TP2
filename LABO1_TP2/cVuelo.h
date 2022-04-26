#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Enums.h"
#include "cListaValija.h"

constexpr auto maxpasajeros = 100;//consultar
class cAvion;
class cPasajero;
class cListaPasajeros;
using namespace std;
class cVuelo
{
	//atributos:
private:
	int cantpasajeros, numeroVuelo;
	float pesoVuelo;
	bool estado; //a tiempo o retrasado
	long int fechaArribo, fechaPartida, horaArribo, horaPartida;
	cListaPasajeros** pasajerosVuelo; //lista de pasajeros en el vuelo
	cListaPasajeros* pasajero;
	//cListaPasajeros** listapasajeros; //puntero a la lista total de pasajeros
	eDestino destino; //enum de destinos
	cAvion* avion; 
	cListaValija* valija; //lista de valijas

public:
	cVuelo();
	~cVuelo();
	bool AgregarPasajero(string DNI);
	float PesoVuelo();
};

