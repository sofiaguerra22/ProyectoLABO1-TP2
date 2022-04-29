#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cAvion.h"
#include "cVuelo.h"
#include "cListaAviones.h"
#include "cListaVuelos.h"
using namespace std;

class cAeropuerto
{

private:
	int CapacidadActual, CapacidadMax, ID_Aeropuerto, tam; //tam=tamaño lista de Vuelos y Aviones 
	//atributos para las estadísticas, cant vuelos que desp o aterri:
	int cantPasajeros, cantVuelos;
	float cantOnTime, porcentajeOnTime;
	//cAvion** ListaAvionesEnAerop;
	//cVuelo** ListaVuelosEnAerop;
	cListaAviones* ListaAviones;
	cListaVuelos* ListaVuelos;

public:
	cAeropuerto(int _capacidadmax, int _ID);
	~cAeropuerto();
	void DespegueAvion(); //disminuye por uno la capacidadActual del aeropuerto
	bool AgregarAvion(cAvion*Avion);
	bool DarPermiso();
	void Estadisticas(); // cant de pasajeros que volaron en un día, cant de vuelos que aterrizaron y despegaron en el día,
	//porcentaje de vuelos que despegaron y aterrizaron en horario.
	void ImprimirDatos();
	string toString();
	friend class cVuelo; // para que pueda modificar su capacidad actual
};

