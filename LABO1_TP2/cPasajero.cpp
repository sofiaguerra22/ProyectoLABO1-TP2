#include "cPasajero.h"

cPasajero::cPasajero(string _DNI)
{
	valijas = new cListaValija(MAX); 
	equipaje = false;
	numerovuelo = -1; //cuando el numero de vuelo es -1 es porque todavia no se le asigno
	asiento = -1; //cuando el asiento es -1 es porque todaia no fue asigando
	DNI = _DNI;
	acumpeso = 0;// pesototal = 0;
}
cPasajero::~cPasajero()
{
	delete valijas;
}

void cPasajero::AgregarEquipaje(cValija* valija) 
{
	if (valija == NULL)
	{
		throw 1;
	}
	if (valija->getPeso() + acumpeso > 25)
	{
		throw 2;
	}
	*valijas + valija;
	acumpeso = acumpeso + valija->getPeso();
}


float cPasajero::PesoTotal()
{
	float _peso = acumpeso + peso; //peso total de las valijas + el peso del pasajero
	return _peso; 
}

void cPasajero::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cPasajero::toString()
{
	return "DNI: " + DNI + "\nNumero de Asiento: " + to_string(asiento) + "\nNumero de Vuelo: " + to_string(numerovuelo) +
		"\nPeso total valijas: " + to_string(acumpeso);
}

