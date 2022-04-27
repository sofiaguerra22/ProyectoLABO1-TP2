#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
class cListaValija; //forward declaration 
using namespace std;
class cValija
{
private:  //atributos:
	float peso;
	string DNI;

public: //metodos:
	cValija(float _peso, string _dni);
	~cValija();
	void AgregarValijaLista();
	void ImprimirDatos();
	string toString();
};

