#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cAvion.h"
#include "cListaAviones.h"
#include "cListaVuelos.h"
#include <cmath>
using namespace std;

class cAeropuerto
{

private:
	int CapacidadActual, CapacidadMax, cantAviones, ID_Aeropuerto; //cantAviones=tama�o lista de Vuelos y Aviones 
	//atributos para las estad�sticas, cant vuelos que desp o aterri:
	int cantPasajeros, cantVuelos;
	float cantOnTime, porcentajeOnTime;

	cListaAviones* ListaAviones;
	cListaVuelos* ListaVuelos;

public:
	cAeropuerto(int _capacidadmax, int _ID);
	~cAeropuerto();
	void DespegueAvion(); //disminuye por uno la capacidadActual del aeropuerto
	void AgregarAvion(cAvion*Avion);
	bool DarPermiso();
	void Estadisticas(); // cant de pasajeros que volaron en un d�a, cant de vuelos que aterrizaron y despegaron en el d�a,
	//porcentaje de vuelos que despegaron y aterrizaron en horario.
	void ImprimirDatos();
	string toString();
	friend class cVuelo; // para que pueda modificar su capacidad actual
};

