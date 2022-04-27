#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Enums.h"
#include "cValija.h"
#include "cPasajero.h" //es friend class 
#include "cListaPasajeros.h" //friend class

constexpr auto maxpasajeros = 100;//consultar
class cAvion;
using namespace std;
class cVuelo
{
	//atributos:
private:
	int cantpasajeros, numeroVuelo;
	float pesoVuelo;
	bool estado; //a tiempo o retrasado
	long int fechaArribo, fechaPartida, horaArribo, horaPartida;
	cPasajero** listaPasajerosVuelo; //puntero doble que almacena en posiciones de memoria cada uno de los pasajeros en el vuelo
	cListaPasajeros* pasajeroVuelo; // de tipo lista?
	cValija** listaValijasVuelo;
	cValija* valijaVuelo;
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

