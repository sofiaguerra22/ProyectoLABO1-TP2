#include "cListaValija.h"

cListaValija::cListaValija(float _peso, string _DNI)
{
	peso = _peso;
	ca = 0;
	DNI = _DNI;
	//inicializamos todos los punteros de la lista a null
	ListaValija = new cValija * [MAX];
	for (int i = 0; i < MAX; i++)
	{
		ListaValija[i] = NULL;
	}

}

cListaValija::~cListaValija() //CONSULTAR
{
	if (ListaValija != NULL) {

		for (int i = 0; i < ca; i++)
		{
			if (ListaValija[i] != NULL)
				ListaValija[i] = NULL;
		}

	}
}

bool cListaValija::Agregar(cValija* Valija)
{
	for (int i = ca; i < MAX; i++) //recorre desde la cantidad actual de punteros hasta el final de la lista hasta buscar un espacio libre
	{
		if (ListaValija[i] == NULL)
		{
			ListaValija[i] = Valija;
			return true;
			break;
		}
	}
	return false; //devuelve falso si no hay espacio diponible (se puede redimensionar)
}

cValija* cListaValija::Quitar(int pos)
{
	if (pos >= ca || ListaValija[pos] == NULL) //no existe tal pos o el puntero a esa posición esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}
	else
	{
		ca--; //disminuimos la cantidad actual
		cValija* aux = ListaValija[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			ListaValija[i] = ListaValija[i + 1];
		}
		ListaValija[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	}
}

bool cListaValija::Eliminar(int pos)
{
	cValija* aux = Quitar(pos);
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

cValija* cListaValija::operator[](int posic_i) //HACER
{
	return nullptr;
}

int cListaValija::Buscar(int clave) //HACER
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaValija[i]);
	}
}

void cListaValija::Listar() //HACER
{
}
