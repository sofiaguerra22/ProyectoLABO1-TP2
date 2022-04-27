#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Enums.h"
#include "cListaValija.h"
#include "cListaPasajeros.h"
#include "cPasajero.h" //friend class

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
	cListaPasajeros* listaPasajerosVuelo; //puntero simple ya que apunta a la lista
	cPasajero* pasajeroVuelo; // de tipo lista?
	cPasajero* pasajeroCambio; // para el cambio de pasajeros 
	cListaValija* listaValijasVuelo;
	eDestino destino; //enum de destinos
	cAvion* avion; 
	cListaValija* valija; //lista de valijas

public:
	cVuelo();
	~cVuelo();
	bool AgregarPasajero(string DNI);
	void ObtenerDatos(string DNI);
	bool CambiarPasajero(string DNI_1, string DNI_2); //el 1 es el actual y el 2 es el nuevo pasajero
	float PesoVuelo();
	void ImprimirDatos();
	string toString();
};

