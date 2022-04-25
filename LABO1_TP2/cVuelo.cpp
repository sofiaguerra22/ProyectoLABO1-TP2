#include "cVuelo.h"
#include "cPasajero.h"
/*int cantpasajerosVuelos, numeroVuelo;
	float pesoVuelo;
	bool estado; //a tiempo o retrasado
	long int fechaArribo, fechaPartida, horaArribo, horaPartida;
	cListapasajerosVuelos** pasajerosVuelos; //lista de pasajerosVuelos
	eDestino destino; //enum de destinos
	cAvion* avion; 
	cListaValija* valijas; //lista de valijas*/

cVuelo::cVuelo() 
{
	cantpasajeros = 0;
	numeroVuelo++; //CONSULTAR
	pesoVuelo = 0.0;
	estado = false;
	fechaArribo, fechaPartida, horaArribo, horaPartida = 0;
	pasajerosVuelo = NULL;
	avion = NULL;
	valija = NULL;
}

cVuelo::~cVuelo()
{
	if (pasajerosVuelo != NULL)
		pasajerosVuelo = NULL;
	if (avion != NULL)
		avion = NULL;
	if (valija != NULL)
		valija = NULL;
}

bool cVuelo::AgregarPasajero(string DNI) //CONSULTAR
{
	int pos = 0;

	
}

float cVuelo::PesoVuelo()
{
	return false;
}
