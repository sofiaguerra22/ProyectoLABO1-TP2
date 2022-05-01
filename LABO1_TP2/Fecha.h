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
	bool esCorrecta(); //se fija si es correcta la fecha del puntero actual
	bool esCorrecta(Fecha* fecha_); //se fija si es correcta la fecha pasada
	bool Comparar(Fecha* fecha_);
	string toString();
	~Fecha();

};

