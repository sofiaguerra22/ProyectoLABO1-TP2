#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class Fecha
{

	unsigned int dia, mes, anio, hora, minuto;
public:
	Fecha();
	Fecha(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
	bool esCorrecta();
	bool esCorrecta(Fecha* fecha_);
	bool Comparar(Fecha* fecha_);
	string toString();
	~Fecha();

};

