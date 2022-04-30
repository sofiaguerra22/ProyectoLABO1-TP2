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

cPasajero* cListaPasajeros::operator-(int pos) //excepcion
{
	if (pos >= ca)
		throw 1;
	if (ListaPasajeros[pos] == NULL)
		throw 2;

	ca--; //disminuimos la cantidad actual
	cPasajero* aux = ListaPasajeros[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
	for (int i = pos; i < ca; i++)
	{
		ListaPasajeros[i] = ListaPasajeros[i + 1];
	}
	ListaPasajeros[pos] = NULL; //quitamos el puntero
	return aux; //devolvemos el auxiliar creado

}

void cListaPasajeros::Eliminar(int pos)
{
	try
	{
		*ListaPasajeros - pos;
	}
	catch (int e)
	{
		cout << "Error al eliminar equipaje numero: " << e << endl; //1=posición mayor a ca 2=pos = NULL
	}
	cPasajero* aux = *ListaPasajeros - pos;
	aux = NULL;
	cout << "Se elimino con exito";
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
