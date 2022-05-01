#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cPasajero.h"

class cListaPasajeros
{
	friend class cVuelo;

private:
	cPasajero** ListaPasajeros;
	int ca;

public:
	cListaPasajeros(int L);
	~cListaPasajeros();
	bool operator+(cPasajero* Pasajero);
	cPasajero* Quitar(int pos);
	cPasajero* operator[](int posic_i);
	void Eliminar(int pos);
	int Buscar(string _DNI);
	int Buscar(cPasajero* pasajero);
	void AgregarEnPos(int pos, cPasajero* pasajero);
	void Listar(); //imprime la lista en pantalla
	cPasajero* PasajeroEncontrado(string DNI);
	int getCA() { return ca; };
	void operator-(cPasajero* Pasajero); //sobrecarga -
};
