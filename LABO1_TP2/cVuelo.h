#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Enums.h"
#include "cListaValija.h"
#include "cListaPasajeros.h"
#include "cPasajero.h" //friend class
#include "Fecha.h"
class cAvion;
using namespace std;
class cVuelo
{
	//atributos:
private:
	int cantpasajeros, numeroVuelo;
	float pesoVuelo;
	float onTime; //cant de veces que salieron o llegaron a tiempo, float para después servir en el porcentaje
	Fecha* fechaArribo;
	Fecha* fechaPartida;
	cListaPasajeros* listaPasajerosVuelo; //puntero simple ya que apunta a la lista
	cPasajero* PasajeroVuelo; 
	cPasajero* PasajeroCambio; // para el cambio de pasajeros 
	cListaValija* listaValijasVuelo; //lista de valijas en vuelo
	cValija* valija;
	eDestino destino; //enum de destinos
	cAvion* avion; 


public:
	cVuelo();
	~cVuelo();
	bool AgregarPasajero(cPasajero* pasajero_vuelo);
	void ObtenerDatos(string DNI);
	bool CambiarPasajero(cPasajero* PasajeroVuelo, cPasajero* PasajeroCambio); //el 1 es el actual y el 2 es el nuevo pasajero
	bool EliminarPasajero(string DNI);
	bool setFechas(Fecha* fecha_a, Fecha* fecha_p); //recibe fecha de arribo y fecha de partida
	bool ChequearOnTimePartida(Fecha* FechaActual);
	bool ChequearOnTimeArribo(Fecha* FechaActual);
	float getOnTime();
	void ImprimirDatos();
	string toString();
	int getNumeroVuelo() { return numeroVuelo; };
	int getPesoVuelo() { return pesoVuelo; };
};

