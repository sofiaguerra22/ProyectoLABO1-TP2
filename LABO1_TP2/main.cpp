#include <string>
#include <iostream>
#include <stdio.h>
#include "cAeropuerto.h"
//#include "cAvion.h"
//#include "cPasajero.h"
//#include "cValija.h"
//#include "Fecha.h"
//#include "cVuelo.h"
//#include "cListaAviones.h"
//#include "cListaPasajeros.h"
//#include "cListaValija.h"
//#include "cListaVuelos.h"

int main()
{
	//Aeropuerto:
	cAeropuerto* aeropuerto = new cAeropuerto(4, 1);
	//Pasajeros:
	cPasajero* pasajero1 = new cPasajero("43718486");
	cPasajero* pasajero2 = new cPasajero("2783848");
	cPasajero* pasajero3 = new cPasajero("1948483");
		//ListaPasajeros:
		cListaPasajeros* ListaPasajeros = new cListaPasajeros(MAX);
		*ListaPasajeros + pasajero1;
		*ListaPasajeros + pasajero2;
		*ListaPasajeros + pasajero3;
	//Valijas:
		cValija* valija1_p1 = new cValija(15, pasajero1->getDNI());
		cValija* valija2_p1 = new cValija(18, pasajero1->getDNI());
		cValija* valija1_p2 = new cValija(20, pasajero2->getDNI());
		//ListaValijas:
		cListaValija* ListaValijas = new cListaValija(MAX);
		*ListaValijas + valija1_p1;
		*ListaValijas + valija2_p1;
		*ListaValijas + valija1_p2;
	//Aviones:
		cAvion* avion1 = new cAvion(1, 10, 200);
		cAvion* avion2 = new cAvion(2, 5, 100);
		//ListaAviones:
		cListaAviones* ListaAviones = new cListaAviones(MAX);
		*ListaAviones + avion1;
		*ListaAviones + avion2;

		//agregar deletes 





}