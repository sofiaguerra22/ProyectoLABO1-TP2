#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cAvion.h"
#define MAX 100
class cListaAviones
{
	cAvion** ListaAviones;
	float peso;
	int ID;
	int ca; //cantidad actual

public:
	cListaAviones(int L = MAX);
	~cListaAviones();
	bool Agregar(cAvion* Avion);
	cAvion* Quitar(int pos);
	bool Eliminar(int pos);
	cAvion* operator[](int posic_i);
	int Buscar(string ID);
	void Listar(); //imprime la lista en pantalla
};

