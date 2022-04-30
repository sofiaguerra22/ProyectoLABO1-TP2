#include "cPasajero.h"

cPasajero::cPasajero(string _DNI)
{
	valijas = new cListaValija(MAX); 
	equipaje = false;
	numerovuelo = -1; //cuando el numero de vuelo es -1 es porque todavia no se le asigno
	asiento = -1; //cuando el asiento es -1 es porque todaia no fue asigando
	DNI = _DNI;
	acumpeso = 0;// pesototal = 0;
	//valija = NULL;
}
cPasajero::~cPasajero()
{
	delete valijas;
	//valija = NULL;

}

bool cPasajero::AgregarEquipaje(cValija* valija) //Y TRY CATCH
{
	/*if (valija != NULL)
	{
		throw 1;
	}
	if (valija->getPeso() + acumpeso > 25)
	{
		throw 2;
	}
	if (valija->getDNI() != DNI)
	{
		throw 3;
	}
	
		*valijas + valija;
		return true;*/
	if (valija != NULL && (valija->getPeso() + acumpeso) <= 25 && valija->getDNI() == DNI)
	{
		*valijas + valija;
		return true;
	}
	return false;
}


float cPasajero::PesoTotal()
{
	return acumpeso + 75;
}

void cPasajero::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cPasajero::toString()
{
	return "Asiento: " + to_string(asiento) + " " + "\nDNI:" + DNI + " " + "\nEquipaje" + to_string(equipaje) + "\Numero Vuelo: " + to_string(numerovuelo);
}

