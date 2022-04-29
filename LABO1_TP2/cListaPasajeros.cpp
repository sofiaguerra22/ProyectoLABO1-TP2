#include "cListaPasajeros.h"


cListaPasajeros::cListaPasajeros(int L = MAX)
{
	ca = 0;
	//inicializamos todos los punteros de la lista a null
	ListaPasajeros = new cPasajero * [MAX];
	for (int i = 0; i < L; i++)
	{
		ListaPasajeros[i] = NULL;
	}
}

cListaPasajeros::~cListaPasajeros() //CONSULTAR
{
	if (ListaPasajeros != NULL) {

		delete ListaPasajeros;

	}
}


bool cListaPasajeros::operator+(cPasajero* Pasajero)
{
	if (Pasajero != NULL)
	{
		ListaPasajeros[ca] = Pasajero;
		ca++;
		return true;
	}
	else
	{
		return false;
	}
	

}

cPasajero* cListaPasajeros::Quitar(int pos)
{
	if (pos >= ca || ListaPasajeros[pos] == NULL) //no existe tal pos o el puntero a esa posición esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}

		ca--; //disminuimos la cantidad actual
		cPasajero* aux = ListaPasajeros[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			ListaPasajeros[i] = ListaPasajeros[i + 1];
		}
		ListaPasajeros[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado

}

bool cListaPasajeros::Eliminar(int pos)
{
	cPasajero* aux = Quitar(pos);
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


int cListaPasajeros::Buscar(string _DNI) 
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaPasajeros[i]->DNI== _DNI)
		{
			return i;
		}
	}
	return -1;
}

int cListaPasajeros::Buscar(cPasajero* pasajero)
{
	for (int i = 0; i < ca; i++)
	{
		if (this->ListaPasajeros[i] == pasajero)
		{
			return i;
		}
	}
	return -1;
}

void cListaPasajeros::AgregarEnPos(int pos, cPasajero* pasajero)
{
	ListaPasajeros[pos] = NULL;
	ListaPasajeros[pos] = pasajero;
}

void cListaPasajeros::Listar() //HACER
{
}

cPasajero* cListaPasajeros::PasajeroEncontrado(string DNI)
{
	if (Buscar(DNI) != -1)
	{
		int pos = Buscar(DNI);
		cPasajero* aux = ListaPasajeros[pos];
		return aux;
	}
	else
	{
		return nullptr;
	}

}
