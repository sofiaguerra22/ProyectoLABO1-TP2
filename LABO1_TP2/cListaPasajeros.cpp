#include "cListaPasajeros.h"

cListaPasajeros::cListaPasajeros()
{
}

cListaPasajeros::cListaPasajeros(int L)
{
	peso = 0.0;
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

cPasajero** cListaPasajeros::getListaPasajeros()
{
	return ListaPasajeros; 
	
}

bool cListaPasajeros::Agregar(cPasajero* Pasajero)
{
	for (int i = ca; i < MAX; i++) //recorre desde la cantidad actual de punteros hasta el final de la lista hasta buscar un espacio libre
	{
		if (ListaPasajeros[i] == NULL)
		{
			ListaPasajeros[i] = Pasajero;
			return true;
			break;
		}
	}
	return false; //devuelve falso si no hay espacio diponible (se puede redimensionar)
}

cPasajero* cListaPasajeros::Quitar(int pos)
{
	if (pos >= ca || ListaPasajeros[pos] == NULL) //no existe tal pos o el puntero a esa posici�n esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}
	else
	{
		ca--; //disminuimos la cantidad actual
		cPasajero* aux = ListaPasajeros[pos]; //igualamos el aux al puntero en la posici�n para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			ListaPasajeros[i] = ListaPasajeros[i + 1];
		}
		ListaPasajeros[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	}

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

cPasajero* cListaPasajeros::operator[](int posic_i) //HACER
{
	return nullptr;
}

int cListaPasajeros::Buscar(string _DNI) //CONSULTAR
{
	for (int i = 0; i < ca; i++)
	{
		if (DNI == _DNI)
		{
			return i;
			break;
		}
	}
	return -1;
}

void cListaPasajeros::Listar() //HACER
{
}
