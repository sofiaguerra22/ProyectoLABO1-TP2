#include "cListaAviones.h"

cListaAviones::cListaAviones(int L = MAX)
{
	ca = 0;
	//inicializamos todos los punteros de la lista a null
	ListaAviones = new cAvion * [MAX];
	for (int i = 0; i < L; i++)
	{
		ListaAviones[i] = NULL; 
	}

}

cListaAviones::~cListaAviones() 
{
	if (ListaAviones != NULL) {

		for (int i = 0; i < ca; i++)
		{
			if (ListaAviones[i] != NULL)
				ListaAviones[i] = NULL;
		}
		delete ListaAviones;
	}

}

bool cListaAviones::operator+(cAvion* newAvion)
{
	if (this->ListaAviones[ca] != NULL) {
		return false;
	}
	this->ListaAviones[ca] = newAvion;
	return true;
}

cAvion* cListaAviones::Quitar(int pos)
{
	if (pos > ca || ListaAviones[pos] == NULL)
		return NULL;

	ca--; //disminuimos la cantidad actual
	cAvion* aux = ListaAviones[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
	for (int i = pos; i < ca; i++) 
	{
		ListaAviones[i] = ListaAviones[i + 1];
	}
	ListaAviones[pos] = NULL; //quitamos el puntero
	return aux; //devolvemos el auxiliar creado
	
}

void cListaAviones::Eliminar(int pos)
{
	if (Quitar(pos) != NULL)
	{
		cAvion* aux = Quitar(pos);
		aux = NULL;
		cout << "Se elimino con exito" << endl;
	}
}

cAvion* cListaAviones::operator[](int posic_i) 
{
	if (ListaAviones[posic_i] != NULL && posic_i <= ca)
	{
		return ListaAviones[posic_i];
	}
	return NULL;
}

int cListaAviones::Buscar(int ID) 
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaAviones[i]->getID() == ID)
			return i;
	}
	return -1;
}

void cListaAviones::Listar()
{
	for (int i = 0; i < ca; i++)
	{
		ListaAviones[i]->toString();
	}
}

int cListaAviones::PasajerosTotal()
{
	int PasajerosTotal = 0;
	for (int i = 0; i < ca; i++)
	{
		PasajerosTotal = PasajerosTotal + ListaAviones[i]->getCantPasajeros();
	}
	return PasajerosTotal;
}
