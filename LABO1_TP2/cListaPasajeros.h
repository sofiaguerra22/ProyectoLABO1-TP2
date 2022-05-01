#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cPasajero.h"

class cListaPasajeros
{
private:
	cPasajero** ListaPasajeros;
	int ca;

public:
	cListaPasajeros(int L);
	~cListaPasajeros();
	bool operator+(cPasajero* Pasajero); //sobrecarga operador +
	cPasajero* Quitar(int pos);
	cPasajero* operator[](int posic_i); //sobrecarga operador []
	void Eliminar(int pos);
	int Buscar(string _DNI); //sobrecarga del método Buscar
	int Buscar(cPasajero* pasajero);
	void AgregarEnPos(int pos, cPasajero* pasajero); //para el cambio de pasajero
	void Listar(); //imprime la lista en pantalla
	cPasajero* PasajeroEncontrado(string DNI); //devuelve puntero del pasajero con ese DNI
	int getCA() { return ca; };
	void operator-(cPasajero* Pasajero); //sobrecarga operador -
};
