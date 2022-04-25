#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cVuelo.h"
#define MAX 100
class cListaVuelos
{
	cVuelo** ListaVuelos;
	int ca;

public:
	cListaVuelos(int L = MAX);
	~cListaVuelos();
	bool Agregar(cVuelo* Vuelo);
	cVuelo* Quitar(int pos);
	bool Eliminar(int pos);
	cVuelo* operator[](int posic_i);
	int Buscar(int clave);
	void Listar(); //imprime la lista en pantalla
};

