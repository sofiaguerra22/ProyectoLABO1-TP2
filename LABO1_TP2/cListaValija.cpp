#include "cListaValija.h"


cListaValija::cListaValija(int L = MAX)
{
	ca = 0;
	//inicializamos todos los punteros de la lista a null
	ListaValija = new cValija * [MAX];
	for (int i = 0; i < MAX; i++)
	{
		ListaValija[i] = NULL;
	}
}

cListaValija::~cListaValija() 
{
	if (ListaValija != NULL)
	{
		for (int i = 0; i < ca; i++)
		{
			if (ListaValija[i] != NULL)
				ListaValija[i] = NULL;
		}
		delete ListaValija;
	}
}

bool cListaValija::operator+(cValija* Valija)
{
	if (Valija != NULL)
	{
		ListaValija[ca] = Valija;
		ca++;
		return true;
	}
	return false;
}

cValija* cListaValija::Quitar(int pos)
{
	if (pos > ca || ListaValija[pos] == NULL) //no existe tal pos o el puntero a esa posición esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}

	ca--; //disminuimos la cantidad actual
	cValija* aux = ListaValija[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
	for (int i = pos; i < ca; i++)
	{
		ListaValija[i] = ListaValija[i + 1];
	}
	ListaValija[pos] = NULL; //quitamos el puntero
	return aux; //devolvemos el auxiliar creado
}

bool cListaValija::Eliminar(int pos)
{
	if (Quitar(pos) != NULL)
	{
		cValija* aux = Quitar(pos);
		aux = NULL;
		cout << "Se elimino con exito";
		return true;
	}
	return false;
}

cValija* cListaValija::operator[](int posic_i) //HACER
{
	if (ListaValija[posic_i] != NULL && posic_i <= ca)
	{
		return ListaValija[posic_i];
	}
	return NULL;
}

void cListaValija::Listar()
{
	for (int i = 0; i < ca; i++)
	{
		ListaValija[i]->ImprimirDatos();
	}
}
