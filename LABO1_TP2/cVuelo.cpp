#include "cVuelo.h"

/*cPasajero** listaPasajerosVuelo; //puntero doble que almacena en posiciones de memoria cada uno de los pasajeros en el vuelo
	cPasajero* pasajero;
	cValija** listaValijasVuelo;
	cValija* valijaVuelo;*/

cVuelo::cVuelo() 
{
	cantpasajeros = 0;
	numeroVuelo++; //CONSULTAR
	pesoVuelo = 0.0;
	estado = false;
	fechaArribo, fechaPartida, horaArribo, horaPartida = 0;
	listaPasajerosVuelo = NULL;
	avion = NULL;
	valija = NULL;
	for (int i = 0; i < maxpasajeros; i++)
	{
		listaPasajerosVuelo[i] = NULL;
	}
	for (int i = 0; i < 300; i++) //maximo de tres valijas por persona (3) * maximo de personas (100) = 300
	{
		listaValijasVuelo[i] = NULL;
	}
	pasajeroVuelo = NULL;
	valijaVuelo = NULL;
}

cVuelo::~cVuelo() //completar el destructor
{
	
}

bool cVuelo::AgregarPasajero(string DNI) //CONSULTAR
{
	pasajeroVuelo->Buscar(DNI);
}

float cVuelo::PesoVuelo()
{
	return false;
}
