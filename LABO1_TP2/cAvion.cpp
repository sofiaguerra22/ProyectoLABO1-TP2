#include "cAvion.h"
#include "cAeropuerto.h"

cAvion::cAvion(int _ID, int _pasajerosmax, float _pesomax)
{
	cantpasajeros_max = _pasajerosmax;
	cantpasajeros_actual = 0;
	pesoactual = 0;
	pesomax = _pesomax;
	ID = _ID;
	vuelo = NULL;
	aeropuerto = NULL;
	permiso = false;
	listaVuelos = new cListaVuelos(); //CONSULTAR AL IGUAL QUE EN CONSTRUCTOR DE VUELO
}
cAvion::~cAvion()
{

}

void cAvion::Despegar()
{
	aeropuerto->DespegueAvion();
	cout << "El avion despego exitosamente" << endl;
}

void cAvion::Aterrizar()
{
	aeropuerto->AgregarAvion(ID);
	cout << "El avion aterrizo exitosamente" << endl;
}

void cAvion::PedirPermiso()
{
	permiso == aeropuerto->DarPermiso(); //iguala el atributo permiso a lo que responda el aeropuerto
}

bool cAvion::RecibirPermiso()
{
	if (aeropuerto->DarPermiso() == true)
	{
		Aterrizar(); //llama a aterrizar
		return true;
	}
	else
		return false;
}

bool cAvion::ChequearCargaMaxima()
{
	pesoactual = vuelo->getPesoVuelo() +(4 * 75); //la suma de los 4 empleados sin equipaje
	if (pesoactual <= pesomax)
	{
		return true;
	}
	else if (pesoactual > pesomax)
	{
		return false;
	}
}

int cAvion::getCantPasajerosActual()
{
	return cantpasajeros_actual;
}

void cAvion::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cAvion::toString()
{
	return "ID avion:" + to_string(ID);
}