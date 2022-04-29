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
	float onTime; //cant de veces que salieron o llegaron a tiempo, float para después servir en el porcentaje
	long int fechaArribo, fechaPartida, horaArribo, horaPartida;
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
	bool CambiarPasajero(string DNI_1, string DNI_2, cListaPasajeros* listaTotal); //el 1 es el actual y el 2 es el nuevo pasajero
	float PesoVuelo();
	bool EliminarPasajero(string DNI);
	bool setFechas(long int fecha_a, long int fecha_p); //recibe fecha de arribo y fecha de partida
	bool setHorarios(long int hora_a, long int hora_p);
	bool ChequearOnTimePartida(long int horaActual, long int fechaActual);
	bool ChequearOnTimeArribo(long int horaActual, long int fechaActual);
	float getOnTime();
	void ImprimirDatos();
	string toString();
	int getNumeroVuelo() { return numeroVuelo; };
	int getPesoVuelo() { return pesoVuelo; };
};

