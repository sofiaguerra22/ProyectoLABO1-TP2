#include "cAeropuerto.h"
void cAeropuerto::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cAeropuerto::toString()
{
	return "ID Aeropuerto:" + to_string(ID_Aeropuerto);
}
