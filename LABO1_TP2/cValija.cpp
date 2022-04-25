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

void cValija::AgregarValijaLista()
{
	cListaValija* valija = new cListaValija(peso, DNI);
}
