#include "cAeropuerto.h"

cAeropuerto::cAeropuerto(int _capacidadmax, int _ID)
{
	CapacidadMax = _capacidadmax;
	ID_Aeropuerto = _ID;
	CapacidadActual = 0;
	tam = 0;
	cantPasajeros = 0;
	cantVuelos = 0;
	cantOnTime = 0;
	porcentajeOnTime = 0;
	//falta inicializar los punteros pero sigo c las dudas para ezequiel
}
cAeropuerto::~cAeropuerto() //HACER
{
}
//
bool cAeropuerto::AgregarAvion(cAvion*Avion) // agrega los aviones a una lista de registro de los aviones que pasaron por el aeropuerto
// para así facilitar luego la función estadísticas (además no pidieron un quitar)
{
	ListaAviones+(Avion);//llamo al operator+ que se encuentra dentro de la clase cListaAviones y me agrego el avion que yo decida asignar
}
void cAeropuerto::Estadisticas()
{
	//cuenta la cantidad de pasajeros en un día
	for (int i = 0; i < tam; i++)
	{
		cantPasajeros = cantPasajeros + ListaAvionesEnAerop[i]->getCantPasajerosActual();
		cantOnTime = cantOnTime + ListaVuelosEnAerop[i]->getOnTime();
	}
	//cantidad de vuelos va a ser tam
	porcentajeOnTime = (cantOnTime / tam); //después cuando imprimimos habría que multiplicarlo por 100 y quedarnos sin las comas
}
bool cAeropuerto::DarPermiso()
{
	if (CapacidadActual < CapacidadMax)
	{
		return true;
	}
	else
	{
		return false;
	}
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
