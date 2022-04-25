#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cValija.h"
#define MAX 100
class cListaValija
{
	cValija** ListaValija;
	float peso;
	string DNI;
	int ca;

public:
	cListaValija(float _peso, string _DNI);
	~cListaValija();
	bool Agregar(cValija* Valija);
	cValija* Quitar(int pos);
	bool Eliminar(int pos);
	cValija* operator[](int posic_i);
	int Buscar(int clave);
	void Listar(); //imprime la lista en pantalla

};

