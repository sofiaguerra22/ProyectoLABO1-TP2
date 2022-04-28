#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cAvion.h"
#include "cVuelo.h"
using namespace std;

class cAeropuerto
{
private:
	int CapacidadActual, CapacidadTotal, ID_Aeropuerto;
	cAvion* ListaAvionesEnAerop = new cAvion[CapacidadTotal];//hacer delete
	cVuelo* ListaVuelosEnAerop = new cVuelo[CapacidadTotal];//hacer delete

public:
	bool darPermiso();
	void ImprimirDatos();
	string toString();
};

