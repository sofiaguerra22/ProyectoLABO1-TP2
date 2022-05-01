#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cVuelo.h"
#define MAX 100
class cListaVuelos
{
	friend class cAvion;
	friend class cAeropuerto;

private:
	cVuelo** ListaVuelos;
	int ca;

public:
	cListaVuelos(int L = MAX);
	~cListaVuelos();
	bool operator+(cVuelo* Vuelo); //sobrecarga operador +
	cVuelo* Quitar(int pos);
	cVuelo* operator[](int posic_i); //sobrecarga operador[]
	void Eliminar(int pos);
	cVuelo* VueloEncontrado(int ID); //devuelve un puntero al vuelo con ese ID
	int Buscar(int ID); //recibe el id del vuelo y devuelve su posicion
	void Listar(); //imprime la lista en pantalla
	float CantidadOnTime(); //acum de de cantidadOnTime de cada vuelo
};

