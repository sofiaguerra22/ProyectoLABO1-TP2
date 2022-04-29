#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cPasajero.h"

class cListaPasajeros
{

private:
	cPasajero** ListaPasajeros;
	float peso;
	string DNI;
	int ca;

public:
	cListaPasajeros(int L);
	~cListaPasajeros();
	bool operator+(cPasajero* Pasajero);
	cPasajero* Quitar(int pos);
	bool Eliminar(int pos);
	int Buscar(string _DNI);
	int Buscar(cPasajero* pasajero);
	void AgregarEnPos(int pos, cPasajero* pasajero);
	void Listar(); //imprime la lista en pantalla
	cPasajero* PasajeroEncontrado(string DNI);
	int getCA() { return ca; };
	friend class cVuelo;
};
