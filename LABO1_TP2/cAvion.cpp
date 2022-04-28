#include "cAvion.h"

cAvion::cAvion(int _ID, int _pasajerosmax, float _pesomax)
{
	cantpasajeros_max = _pasajerosmax;
	cantpasajeros_actual = 0;
	pesoactual = 0;
	pesomax = _pesomax;
	ID = _ID;
	vuelo = NULL;
	aeropuerto = NULL;
	listaVuelos = new cListaVuelos(); //CONSULTAR AL IGUAL QUE EN CONSTRUCTOR DE VUELO
}
cAvion::~cAvion()
{

}

void cAvion::Despegar()
{
}

void cAvion::Aterrizar()
{
}

void cAvion::PedirPermiso()
{
	aeropuerto

}

void cAvion::RecibirPermiso()
{
	PedirPermiso();
}

bool cAvion::ChequearCargaMaxima()
{
	return false;
}

void cAvion::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cAvion::toString()
{
	return "ID avion:" + to_string(ID);
}