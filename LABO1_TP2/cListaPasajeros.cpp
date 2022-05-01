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

		for (int i = 0; i < ca; i++)
		{
			if (ListaPasajeros[i] != NULL)
				ListaPasajeros[i] = NULL;
		}
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
	return false;
}

cPasajero* cListaPasajeros::Quitar(int pos) //excepcion
{
	if (pos > ca || ListaPasajeros[pos] == NULL)
		return NULL;
	ca--; //disminuimos la cantidad actual
	cPasajero* aux = ListaPasajeros[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
	for (int i = pos; i < ca; i++)
	{
		ListaPasajeros[i] = ListaPasajeros[i + 1];
	}
	ListaPasajeros[pos] = NULL; //quitamos el puntero
	return aux; //devolvemos el auxiliar creado

}

cPasajero* cListaPasajeros::operator[](int posic_i)
{
	if (ListaPasajeros[posic_i] != NULL && posic_i <= ca)
	{
		return ListaPasajeros[posic_i];
	}
	return NULL;
}

void cListaPasajeros::Eliminar(int pos)
{
	if (Quitar(pos) != NULL)
	{
	cPasajero* aux = Quitar(pos);
	aux = NULL;
	cout << "Se elimino con exito";
	}
}


int cListaPasajeros::Buscar(string _DNI) 
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaPasajeros[i]->DNI== _DNI)
			return i;
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

void cListaPasajeros::Listar() 
{
	for (int i = 0; i < ca; i++)
	{
		ListaPasajeros[i]->ImprimirDatos();
	}
}

cPasajero* cListaPasajeros::PasajeroEncontrado(string DNI)
{
	if (Buscar(DNI) != -1)
	{
		int pos = Buscar(DNI);
		cPasajero* aux = ListaPasajeros[pos];
		return aux;
	}
	return NULL;
}

void cListaPasajeros::operator-(cPasajero* Pasajero)
{
	if (Pasajero != NULL && (Buscar(Pasajero) != -1))
		Eliminar((Buscar(Pasajero)));
}
