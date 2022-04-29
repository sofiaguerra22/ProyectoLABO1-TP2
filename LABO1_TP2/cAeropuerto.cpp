#include "cAeropuerto.h"

cAeropuerto::cAeropuerto(int _capacidadmax, int _ID)
{
	ID_Aeropuerto = _ID;
	CapacidadMax = _capacidadmax;
	CapacidadActual = 0;
	cantAviones = 0;
	cantPasajeros = 0;
	cantVuelos = 0;
	cantOnTime = 0;
	porcentajeOnTime = 0;
	ListaAviones = new cListaAviones();
	ListaVuelos = new cListaVuelos();
}
cAeropuerto::~cAeropuerto() //HACER
{
	delete ListaAviones;
	delete ListaVuelos;
}
bool cAeropuerto::AgregarAvion(cAvion*Avion) 
{
	*ListaAviones + Avion;//llamo al operator+ que se encuentra dentro de la clase cListaAviones y me agrego el avion que yo decida asignar
	*ListaVuelos + (Avion->vuelo);
	cantVuelos++;
	cantAviones++;
}
void cAeropuerto::Estadisticas()
{
	cantPasajeros = ListaAviones->PasajerosTotal();
	cantOnTime = ListaVuelos->CantidadOnTime();
	porcentajeOnTime = cantOnTime / cantVuelos;
}
bool cAeropuerto::DarPermiso()
{
	if (CapacidadActual < CapacidadMax)
		return true;
	else
		return false;
}
void cAeropuerto::ImprimirDatos()
{
	cout << this->toString() << endl;
}

void cAeropuerto::DespegueAvion()
{
	CapacidadActual--;
}

string cAeropuerto::toString()
{
	return "ID Aeropuerto:" + to_string(ID_Aeropuerto);
}
