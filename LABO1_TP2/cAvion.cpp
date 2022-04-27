#include "cAvion.h"


cAvion::~cAvion()
{
}

void cAvion::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cAvion::toString()
{
	return "ID avion:" + to_string(ID);
}