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

bool cListaVuelos::Agregar(cVuelo* Vuelo)
{
	for (int i = ca; i < MAX; i++) //recorre desde la cantidad actual de punteros hasta el final de la lista hasta buscar un espacio libre
	{
		if (ListaVuelos[i] = NULL)
		{
			ListaVuelos[i] = Vuelo;
			return true;
			break;
		}
	}
	return false; //devuelve falso si no hay espacio diponible (se puede redimensionar)
}

cVuelo* cListaVuelos::Quitar(int pos)
{
	if (pos >= ca || ListaVuelos[pos] == NULL) //no existe tal pos o el puntero a esa posición esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}
	else
	{
		ca--; //disminuimos la cantidad actual
		cVuelo* aux = ListaVuelos[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			ListaVuelos[i] = ListaVuelos[i + 1];
		}
		ListaVuelos[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	}
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

cVuelo* cListaVuelos::operator[](int posic_i) //HACER
{
	return nullptr;
}

int cListaVuelos::Buscar(int ID)
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaVuelos[i]->getNumeroVuelo() == ID);
		return i;
		break;
	} 
	return -1;
}

void cListaVuelos::Listar() //HACER
{
	for (int i = 0; i < ca; i++)
	{
		ListaVuelos[i]->toString(); //imprime todos los vuelos en la lista
	}
}
