#include "cListaAviones.h"

cListaAviones::cListaAviones(int L)
{
	//inicializamos todos los punteros de la lista a null
	ListaAviones = new cAvion * [MAX];
	for (int i = 0; i < L; i++)
	{
		ListaAviones[i] = NULL; 
	}

}

cListaAviones::~cListaAviones() //HACER:
{
		if (ListaAviones != NULL) {

			for (int i = 0; i < ca; i++)
			{
				if (ListaAviones[i] != NULL)
					ListaAviones[i] = NULL;
			}

		}

}

bool cListaAviones::Agregar(cAvion* Avion)
{
	for (int i = ca; i < MAX; i++) //recorre desde la cantidad actual de punteros hasta el final de la lista hasta buscar un espacio libre
	{
		if (ListaAviones[i] = NULL)
		{
			ListaAviones[i] = Avion;
			return true;
			break;
		}
	}
	return false; //devuelve falso si no hay espacio diponible (se puede redimensionar)
}

cAvion* cListaAviones::Quitar(int pos)
{
	if (pos >= ca || ListaAviones[pos] == NULL) //no existe tal pos o el puntero a esa posición esta desocupado
	{
		cout << "Posicion incorrecta o desocupada";
		return NULL;
	}
	else
	{
		ca--; //disminuimos la cantidad actual
		cAvion* aux = ListaAviones[pos]; //igualamos el aux al puntero en la posición para despues devolverlo
		for (int i = pos; i < ca; i++) 
		{
			ListaAviones[i] = ListaAviones[i + 1];
		}
		ListaAviones[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	}
	
}

bool cListaAviones::Eliminar(int pos)
{
	cAvion* aux = Quitar(pos);
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

cAvion* cListaAviones::operator[](int posic_i) //HACER
{
	return nullptr;
}

int cListaAviones::Buscar(int ID) 
{
	for (int i = 0; i < ca; i++)
	{
		if (ListaAviones[i]->getID() == ID)
		{
			return i;
			break;
		}
	}
	return -1;
}

void cListaAviones::Listar() //HACER
{
	for (int i = 0; i < ca; i++)
	{
		ListaAviones[i]->toString();
	}
}
