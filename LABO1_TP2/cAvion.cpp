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
	listaVuelos = new cListaVuelos(); 
}
cAvion::~cAvion()
{
	if (listaVuelos != NULL)
	{
		for (int i = 0; i < listaVuelos->ca; i++)
		{
			listaVuelos[i] = NULL;
		}
		delete listaVuelos;
	}
	vuelo = NULL;
	aeropuerto = NULL;
}

bool cAvion::AsignarVuelo(cVuelo* _Vuelo)
{
	vuelo = _Vuelo; //en el caso que el vuelo sea NULL, sigue siendo null y devuelve false
	if (vuelo != NULL && ChequearCargaMaxima() == false)
	{
		vuelo = NULL;
		return false;
	}
	else if (vuelo != NULL && ChequearCargaMaxima() == true)
		return true;
	return false;
}

void cAvion::Despegar(cAeropuerto* Aeropuerto, Fecha* fechaActual)
{
	if (ChequearCargaMaxima() == true && aeropuerto != NULL && fechaActual->esCorrecta() == true)
	{
		aeropuerto = Aeropuerto;
		aeropuerto->DespegueAvion(); 
		vuelo->ChequearOnTimePartida(fechaActual); //se fija si despego on time o no
		cout << "El avion despego exitosamente" << endl;
	}

}

bool cAvion::Aterrizar(cAeropuerto* Aeropuerto, Fecha* fechaActual)
{
	if (Aeropuerto != NULL && vuelo != NULL && fechaActual->esCorrecta() == true)
	{
		aeropuerto = Aeropuerto;
		if (RecibirPermiso(Aeropuerto) == true)
		{
			aeropuerto->AgregarVueloAvion(vuelo);
			vuelo->ChequearOnTimeArribo(fechaActual);
			cout << "El avion aterrizo exitosamente" << endl;
			return true;
		}
		else
			aeropuerto = NULL;
	}
	cout << "No hay espacio en el hangar" << endl;
	return false;
}

void cAvion::PedirPermiso()
{
	if (aeropuerto->DarPermiso() == true)
		permiso = true; //iguala el atributo permiso a lo que responda el aeropuerto
}

bool cAvion::RecibirPermiso(cAeropuerto* Aeropuerto)
{
	PedirPermiso();
	if (permiso == true)
		return true;
		
	return false;
}

bool cAvion::ChequearCargaMaxima()
{
	pesoactual = (vuelo->getPesoVuelo()) +(4 * 75); //la suma de los 4 empleados sin equipaje
	if (pesoactual > pesomax)
		return false;
	return true;
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