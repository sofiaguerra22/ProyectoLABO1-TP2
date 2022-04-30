#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class cValija
{
private:  //atributos:
	float peso;
	string DNI;

public: //metodos:
	cValija(float _peso, string _dni);
	~cValija();
	float getPeso() { return peso; };
	string getDNI() { return DNI; };
	void ImprimirDatos();
	string toString();
};

