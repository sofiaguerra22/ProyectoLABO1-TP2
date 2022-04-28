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
	bool onTimeArribo; //a tiempo o retrasado
	bool onTimePartida;
	long int fechaArribo, fechaPartida, horaArribo, horaPartida;
	cListaPasajeros* listaPasajeros; //puntero simple ya que apunta a la lista
	cPasajero** listaPasajerosVuelo; // lista de todos los pasajeros en el vuelo
	cPasajero* pasajeroVuelo; // de tipo lista?
	cPasajero* pasajeroCambio; // para el cambio de pasajeros 
	cListaValija* listaValijas; //lista de valijas totales 
	cValija** listaValijasVuelo; //lista de valijas en el vuelo
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
	bool EliminarPasajero(string DNI);
	bool setFechas(long int fecha_a, long int fecha_p); //recibe fecha de arribo y fecha de partida
	bool setHorarios(long int hora_a, long int hora_p);
	int ChequearOnTimePartida(long int horaActual, long int fechaActual);
	int ChequearOnTimeArribo(long int horaActual, long int fechaActual);
	void ImprimirDatos();
	string toString();
};

