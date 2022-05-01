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
	friend class cVuelo; // para que pueda modificar su capacidad actual
private:
	int CapacidadActual, CapacidadMax, cantAviones, ID_Aeropuerto; 
	//atributos para las estadísticas, cant vuelos que despegan o aterrizan:
	int cantPasajeros, cantVuelos;
	float cantOnTime, porcentajeOnTime;

	cListaAviones* ListaAviones;
	cListaVuelos* ListaVuelos;

public:
	cAeropuerto(int _capacidadmax, int _ID);
	~cAeropuerto();
	void DespegueAvion(); //disminuye por uno la capacidadActual del aeropuerto
	bool DarPermiso();
	void AgregarVueloAvion(cVuelo* Vuelo); //Agrega el Vuelo y su Avión correspondiente a las listas
	void Estadisticas(); // cant de pasajeros que volaron en un día, cant de vuelos que aterrizaron y despegaron en el día,
	//porcentaje de vuelos que despegaron y aterrizaron en horario.
	void ImprimirDatos();
	string toString();
};

