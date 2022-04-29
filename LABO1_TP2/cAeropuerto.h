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
	int CapacidadActual, CapacidadTotal, ID_Aeropuerto;
	cAvion** ListaAvionesEnAerop;
	cVuelo** ListaVuelosEnAerop;
	cListaAviones* ListaAviones;
	cListaVuelos* ListaVuelos;

public:
	bool darPermiso();
	void ImprimirDatos();
	string toString();
};

