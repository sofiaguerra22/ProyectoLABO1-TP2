#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cAvion.h"
#define MAX 100
class cListaAviones
{
	friend class cAeropuerto; // para que pueda acceder a la lista de aviones y sus atributos

	cAvion** ListaAviones;
	int ca; //cantidad actual

public:
	cListaAviones(unsigned int L = MAX);
	~cListaAviones();
	bool operator+(cAvion* newAvion);
	cAvion* operator-(int pos);
	void Eliminar(int pos);
	cAvion* operator[](int posic_i); //=buscar???
	int Buscar(int ID);
	void Listar(); //imprime la lista en pantalla
	int PasajerosTotal();
	cAvion** getLista() { return ListaAviones; }; //puntero simple o doble?
};

