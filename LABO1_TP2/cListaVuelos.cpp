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

cVuelo* cListaVuelos::Quitar(int pos)
{
	if (pos >= ca || ListaVuelos[pos] == NULL) //no existe tal pos o el puntero a esa posición esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}
	
		ca--; //disminuimos la cantidad actual
		cVuelo* aux = ListaVuelos[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			ListaVuelos[i] = ListaVuelos[i + 1];
		}
		ListaVuelos[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
}

bool cListaVuelos::Eliminar(int pos)
{
	cVuelo* aux = Quitar(pos);
	if (aux == NULL)
	{
		cout << "No se puede eliminar";
		return false;
	}
	else if (aux != NULL)
	{
		aux = NULL;
		cout << "Se elimino con exito";
		return true;
	}
}

cVuelo* cListaVuelos::VueloEncontrado(int ID)
{
	int pos = Buscar(ID);
	if (pos =!- 1)
	{
		cVuelo* aux = ListaVuelos[pos];
		return aux;
	}
		return NULL;
}

int cListaVuelos::Buscar(int ID)
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaVuelos[i]->getNumeroVuelo() == ID);
		return i;
	} 
	return -1;
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
