#include "cVuelo.h"
#include "cPasajero.h"
#include "cListaPasajeros.h"


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
	/*for (int i = 0; i < maxpasajeros; i++) {
		*listapasajeros[i] = cListaPasajeros<
	}*/
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
	int pos = pasajero->Buscar(DNI);

	pasajerosVuelo[cantpasajeros] = pasajero;

	
}

float cVuelo::PesoVuelo()
{
	return false;
}
