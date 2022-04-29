#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cPasajero.h"
constexpr auto MAX = 100;

class cListaPasajeros
{

private:
	cPasajero** ListaPasajeros;
	float peso;
	string DNI;
	int ca;

public:
	cListaPasajeros(); //Cosntructor que no recibe parámetros
	cListaPasajeros(int L = MAX);
	~cListaPasajeros();
	cPasajero** getListaPasajeros(); //CONSULTAR
	bool Agregar(cPasajero* Pasajero);
	cPasajero* Quitar(int pos);
	bool Eliminar(int pos);
	cPasajero* operator[](int posic_i);
	int Buscar(string _DNI);
	void Listar(); //imprime la lista en pantalla
	int getCA() { return ca; };
	friend class cVuelo;
};
