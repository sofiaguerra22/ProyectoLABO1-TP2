#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cValija.h"
#define MAX 100
class cListaValija
{
	cValija** ListaValija;
	int ca;

public:
	cListaValija(int L);
	~cListaValija();
	bool operator+(cValija* Valija);
	cValija* operator-(int pos);
	bool Eliminar(int pos);
	cValija* operator[](int posic_i);
	void Listar(); //imprime la lista en pantalla
	int getCA() { return ca; };

};

