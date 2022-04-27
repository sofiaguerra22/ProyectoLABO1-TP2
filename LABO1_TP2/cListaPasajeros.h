#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cPasajero.h"
constexpr auto MAX = 100;

class cListaPasajeros
{
	friend class cVuelo;

private:
	cPasajero** ListaPasajeros;
	float peso;
	string DNI;
	int ca;

public:
	cListaPasajeros(); //Cosntructor que no recibe par�metros
	cListaPasajeros(int L = MAX);
	~cListaPasajeros();
	cPasajero** getListaPasajeros(); //CONSULTAR
	bool Agregar(cPasajero* Pasajero);
	cPasajero* Quitar(int pos);
	bool Eliminar(int pos);
	cPasajero* operator[](int posic_i);
	int Buscar(string _DNI);
	void Listar(); //imprime la lista en pantalla
	friend class cVuelo;
	int getCA() { return ca; };
};
