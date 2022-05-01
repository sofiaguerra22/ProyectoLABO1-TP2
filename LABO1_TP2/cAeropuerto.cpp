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
	ListaAviones = new cListaAviones(MAX);
	ListaVuelos = new cListaVuelos(MAX);
}

cAeropuerto::~cAeropuerto() 
{
	if (ListaAviones != NULL)
	{
		for (int i = 0; i < ListaAviones->ca; i++)
		{
			ListaAviones[i] = NULL;
		}
		delete ListaAviones;
	}
	if (ListaVuelos != NULL)
	{
		for (int i = 0; i < ListaVuelos->ca; i++)
		{
			ListaVuelos[i] = NULL;
		}
		delete ListaVuelos;
	}
}
void cAeropuerto::AgregarVueloAvion(cVuelo* Vuelo) 
{
	if (Vuelo != NULL)
	{
		*ListaVuelos + Vuelo; //se agrega el vuelo a la lista
		cantVuelos++; 
		CapacidadActual++;
		cAvion* auxAvion = Vuelo->getAvion(); //se crea un auxiliar para agregar a la lista de aviones
		*ListaAviones + auxAvion; //se agrega el avion a la lista
		cantAviones++;
	}

}
void cAeropuerto::Estadisticas()
{
	cantPasajeros = ListaAviones->PasajerosTotal();
	cantOnTime = ListaVuelos->CantidadOnTime();
	porcentajeOnTime = ((cantOnTime / cantVuelos) * 100);
}
bool cAeropuerto::DarPermiso()
{
	if (CapacidadActual < CapacidadMax) //si no se supera la capacidad maxima da el permiso
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
	cantVuelos++; //se suma un vuelo pq despegó
	CapacidadActual = CapacidadActual - 1;
}

string cAeropuerto::toString()
{
	return "ID Aeropuerto:" + to_string(ID_Aeropuerto) + "\nCantidad de Aviones en Aeropuerto: " + to_string(CapacidadActual)
		+ "\nCantidad de Vuelos en total: " + to_string(cantVuelos) + "\nCantidad de onTime: " + to_string(cantOnTime) + "\nPorcentaje onTime: " +
		to_string(porcentajeOnTime) + "%";
}
