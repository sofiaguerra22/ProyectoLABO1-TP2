#include "cPasajero.h"

cPasajero::cPasajero(int _asiento, string _DNI)
{
	vuelo = NULL; //inicializamos el puntero vuelo a NULL
	for (int i = 0; i < maxvalijas; i++)
	{
		valijas[i] = NULL; //incializamos todas los punteros de valijas a NULL
	}
	equipaje = false;
	asiento = _asiento; 
	DNI = _DNI;
	fecha = 0;
	acumpeso, pesototal = 0;
}
cPasajero::~cPasajero()
{
	if (vuelo != NULL)
		vuelo = NULL;
	for (int i = 0; i < maxvalijas; i++)
	{
		if (valijas[i] != NULL)
			valijas[i] = NULL;
	}
}

bool cPasajero::AgregarValija(float peso) 
{
	for (int i = 0; i < maxvalijas; i++)
	{
		if (valijas[i] == NULL && (acumpeso + peso) <= 25)
		{
			acumpeso = acumpeso + peso;
			valijas[i] = new cValija(peso, DNI);
			valijas[i]->AgregarValijaLista(); //agrega la valija a la lista
			return true; //devuelve true si hay espacio y pudo agregarse la valija
		}
	}
	return false; //devuelve false si no hay mas espacio para valijas o el peso supera los 25kg
}

float cPasajero::PesoTotal()
{
	pesototal = acumpeso + 75;
	return pesototal;
}

void cPasajero::setVuelo(cVuelo* _vuelo) //COMPLETAR
{
	
}
