#include "cPasajero.h"

cPasajero::cPasajero(string _DNI)
{

	valijas = new cListaValija(); //cómo se inicializa?
	equipaje = false;
	numerovuelo = -1; //cuando el numero de vuelo es -1 es porque todavia no se le asigno
	asiento = -1; //cuando el asiento es -1 es porque todaia no fue asigando
	DNI = _DNI;
	fecha = 0;
	acumpeso = 0;// pesototal = 0;
	valija = NULL;
}
cPasajero::~cPasajero()
{
	delete valijas;

}

bool cPasajero::AgregarEquipaje(float peso) //VER TEMA DE PASAR COMO PARÁMETRO LA LISTA COMPLETA Y TRY CATCH
{
	if (acumpeso + peso <= 25)
	{
		valija = new cValija(peso, DNI);
		valijas->Agregar(valija);
		acumpeso = acumpeso + peso;
		return true; 
	}
	return false; //devuelve false si no hay mas espacio para valijas o el peso supera los 25kg
}

float cPasajero::PesoTotal()
{
	return acumpeso + 75;
}

/*void cPasajero::setVuelo(cVuelo* _vuelo) //COMPLETAR
{

	
}*/
void cPasajero::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cPasajero::toString()
{
	return "Asiento" + to_string(asiento) + " " + "DNI:" + DNI + " " + "Equipaje" + to_string(equipaje) + "Fecha:" + to_string(fecha);
}

