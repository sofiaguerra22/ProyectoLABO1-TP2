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
	cListaAviones(int L); //L=length, tamaño
	~cListaAviones();
	bool operator+(cAvion* newAvion); //sobrecarga operador +
	cAvion* Quitar(int pos);
	void Eliminar(int pos);
	cAvion* operator[](int posic_i); //sobrecarga operador []
	int Buscar(int ID);
	void Listar(); //imprime la lista en pantalla
	int PasajerosTotal(); //itera la lista y va sumando la cantidad de pasajeros a un acumulador
	cAvion** getLista() { return ListaAviones; }; //devuelve la lista completa
};

