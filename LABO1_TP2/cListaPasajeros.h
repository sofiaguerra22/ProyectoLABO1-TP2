#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cPasajero.h"
#define MAX 100
class cListaPasajeros
{
	cPasajero** ListaPasajeros;
	float peso;
	string DNI;
	int ca;

public:
	cListaPasajeros(int L = MAX);
	~cListaPasajeros();
	bool Agregar(cPasajero* Pasajero);
	cPasajero* Quitar(int pos);
	bool Eliminar(int pos);
	cPasajero* operator[](int posic_i);
	int Buscar(string _DNI);
	void Listar(); //imprime la lista en pantalla
};

