#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Enums.h"
#include "cListaValija.h"
#include "cListaPasajeros.h"
#include "cPasajero.h" //friend class
#include "Fecha.h"
class cAvion; //forward declaration
using namespace std;
class cVuelo
{
	//atributos:
private:
	int cantpasajeros, numeroVuelo; 
	static int ContadorVuelos; //uso de static
	float pesoVuelo;
	float onTime; //cant de veces que salieron o llegaron a tiempo, float para después servir en el porcentaje
	Fecha* fechaArribo;
	Fecha* fechaPartida;
	cListaPasajeros* listaPasajerosVuelo; 
	cListaValija* listaValijasVuelo; 
	cValija* valija;
	eDestino destino; //enum de destinos
	cAvion* avion; 


public:
	cVuelo(eDestino _destino);
	~cVuelo();
	int getNumeroVuelo() { return numeroVuelo; }; 
	bool AgregarPasajero(cPasajero* pasajero_vuelo);
	void ObtenerDatos(string DNI);
	void CambiarPasajero(cPasajero* Pasajero_Vuelo, cPasajero* Pasajero_Cambio); 
	bool EliminarPasajero(string DNI);
	bool setFechas(Fecha* fecha_a, Fecha* fecha_p); //recibe fecha de arribo y fecha de partida
	bool ChequearOnTimePartida(Fecha* FechaActual);
	bool ChequearOnTimeArribo(Fecha* FechaActual);
	float getOnTime();
	void ImprimirDatos();
	string ImprimirDestino() { return DestinoToString(destino); };
	string toString();
	float getPesoVuelo() { return this->pesoVuelo; };
	cAvion* getAvion() { return avion; };
	friend ostream& operator<<(ostream& output, cVuelo &V) {
		output << "Cantidad Pasajeros : " << V.cantpasajeros << endl;
		return output;
	}
};

