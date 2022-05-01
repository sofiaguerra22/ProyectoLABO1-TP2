#include "cListaVuelos.h"

cListaVuelos::cListaVuelos(int L)
{
	ca = 0;
	//inicializamos todos los punteros de la lista a null
	ListaVuelos = new cVuelo * [MAX];
	for (int i = 0; i < L; i++)
	{
		ListaVuelos[i] = NULL;
	}
}

cListaVuelos::~cListaVuelos()
{
	if (ListaVuelos != NULL) {

		for (int i = 0; i < ca; i++)
		{
			if (ListaVuelos[i] != NULL)
				ListaVuelos[i] = NULL;
		}
		delete ListaVuelos;
	}
}

bool cListaVuelos::operator+(cVuelo* Vuelo)
{
	if (Vuelo != NULL)
	{
		ListaVuelos[ca] = Vuelo;
		ca++;
		return true;
	}
		return false;
}

cVuelo* cListaVuelos::Quitar(int pos) //excepcion
{
	if (pos >= ca || ListaVuelos[pos] == NULL)
		return NULL;

	ca--; //disminuimos la cantidad actual
	cVuelo* aux = ListaVuelos[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
	for (int i = pos; i < ca; i++)
	{
		ListaVuelos[i] = ListaVuelos[i + 1];
	}
	ListaVuelos[pos] = NULL; //quitamos el puntero
	return aux; //devolvemos el auxiliar creado
}

cVuelo* cListaVuelos::operator[](int posic_i)
{
	if (ListaVuelos[posic_i] != NULL && posic_i <= ca)
	{
		return ListaVuelos[posic_i];
	}
	return NULL;
}

void cListaVuelos::Eliminar(int pos)
{
	if (Quitar(pos) != NULL)
	{
		cVuelo* aux = Quitar(pos);
		aux = NULL;
		cout << "Se elimino con exito";
	}
}

int cListaVuelos::Buscar(int ID)
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaVuelos[i]->getNumeroVuelo() == ID)
		return i;
	}
	return -1;
}

cVuelo* cListaVuelos::VueloEncontrado(int ID)
{
	int pos = Buscar(ID);
	if (pos != -1)
	{
		cVuelo* aux = ListaVuelos[pos];
		return aux;
	}
		return NULL;
}

void cListaVuelos::Listar() 
{
	for (int i = 0; i < ca; i++)
	{
		ListaVuelos[i]->toString(); //imprime todos los vuelos en la lista
	}
}

float cListaVuelos::CantidadOnTime()
{
	float cant = 0;
	for (int i = 0; i < ca; i++)
	{
		cant = cant + ListaVuelos[i]->getOnTime();
	}
	return cant;
}
