#include "cValija.h"
#include "cListaValija.h"

cValija::cValija(float _peso, string _dni)
{
	peso = _peso;
	DNI = _dni;
}

cValija::~cValija()
{
}

void cValija::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cValija::toString()
{
	return "Valija del DNI:" + DNI + "\nPeso:" + to_string(peso);
}
