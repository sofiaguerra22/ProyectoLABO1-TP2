#include "cVuelo.h"

/*cPasajero** listaPasajerosVuelo; //puntero doble que almacena en posiciones de memoria cada uno de los pasajeros en el vuelo
	cPasajero* pasajero;
	cValija** listaValijasVuelo;
	cValija* valijaVuelo;*/

cVuelo::cVuelo() 
{
	cantpasajeros = 0;
	numeroVuelo++; //CONSULTAR
	pesoVuelo = 0.0;
	estado = false;
	fechaArribo, fechaPartida, horaArribo, horaPartida = 0;
	listaPasajerosVuelo = NULL;
	avion = NULL;
	valija = NULL;
	pasajeroVuelo = NULL;
	pasajeroCambio = NULL;
	listaPasajeros = new cListaPasajeros(); // CONSULTA
	listaValijas = new cListaValija();
	for (int i = 0; i < listaPasajeros->getCA(); i++) //CONSULTAR POR INICIALIZACION
	{
		listaPasajerosVuelo == NULL;
	}
	for (int i = 0; i < listaValijas->getCA(); i++)
	{
		listaValijasVuelo == NULL;
	}

}

cVuelo::~cVuelo() //completar el destructor
{
	
}

bool cVuelo::AgregarPasajero(string DNI) //CONSULTAR
{

	if (listaPasajeros->Buscar(DNI) != -1) //si encontró el dni en la lista
	{
		pasajeroVuelo->numerovuelo = numeroVuelo;
		cantpasajeros++;
		pasajeroVuelo->asiento = cantpasajeros; //se le asigna el último asiento
		pesoVuelo = pasajeroVuelo->PesoTotal();  //se le agrega al peso total del vuelo, el peso del nuevo pasajero
		listaPasajerosVuelo[cantpasajeros] = pasajeroVuelo; //agregamos el pasajero a la lista de pasajeros del vuelo
		return true; // se agregó el pasajero éxitosamente 
	}
	else
	{
		return false; //no se pudo agregar el pasajero
	}
}

void cVuelo::ObtenerDatos(string DNI)
{
	for (int i = 0; i < cantpasajeros; i++)
	{
		if (listaPasajerosVuelo[i]->DNI == DNI)
		{
			//LLAMA A FUNCION IMPRIMIR E IMPRIME LOS DATOS DE ESE PASAJERO
		}
	}

}

bool cVuelo::CambiarPasajero(string DNI_1, string DNI_2) //el 1 es el actual y el 2 es el nuevo pasajero
{
	int i, pos_1, pos_2 = 0;
	for (i = 0; i < cantpasajeros; i++);
	{
		if (listaPasajerosVuelo[i]->DNI == DNI_1) //encuentra al pasajero en la lista de pasajeros del vuelo
		{
			pos_1 = i; //guarda la posición del pasajero
		}
	}
	if (listaPasajeros->Buscar(DNI_2) != -1) //el dni dos existe en la lista
	{
		pos_2 = listaPasajeros->Buscar(DNI_2);
		pasajeroVuelo = listaPasajeros->; //CONSULTAR PORQUE QUIERO IGUALAR EL PUNTERO AL PASAJERO EN ESA POSICION !!
		//cambio de asiento:
		int auxasiento = pasajeroVuelo->asiento;
		pasajeroVuelo->asiento = -1; //si el asiento es -1 es pq no tiene ningun asiento asigando
		pasajeroCambio->asiento = auxasiento;

		//cambio de vuelo:
		int auxvuelo = pasajeroVuelo->numerovuelo;
		pasajeroVuelo->numerovuelo = -1;
		pasajeroCambio->numerovuelo = auxvuelo;

		//cambio peso:
		pesoVuelo = pesoVuelo - pasajeroVuelo->PesoTotal() + pasajeroCambio->PesoTotal();

		//cambio lista: 
		listaPasajerosVuelo[pos_1] = pasajeroCambio;

		return true; //se realizo el cambio de manr¿era exitosa 

	}
	
	else
	{
		return false; // en el caso que no exista alguno de los dnis enviados
	}
}

float cVuelo::PesoVuelo()
{
	return false;
}

bool cVuelo::EliminarPasajero(string DNI)
{
	for (int i = 0; i < cantpasajeros; i++)
	{
		if (listaPasajerosVuelo[i]->DNI == DNI)
		{
			//el pasajero existe en la lista de pasajeros del vuelo entonces:
			listaPasajerosVuelo[i] == NULL; //vaciamos la posición de memoria donde se encuentra
			for (int j = i; j < cantpasajeros; j++)
			{
				listaPasajerosVuelo[j] = listaPasajerosVuelo[j + 1];
			}
			return true;
			break;
		}
	}
	return false;
}

void cVuelo::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cVuelo::toString()
{
	return "Cantidad de pasajeros:" + to_string(cantpasajeros) + " " + "Num vuelo:" + to_string(numeroVuelo) + " "
		+ "peso vuelo:" + to_string(pesoVuelo) + "Fecha y hora arribo:" + to_string(fechaArribo) + to_string(horaArribo) + " " +
		"Fecha y hora partida:" + to_string(fechaPartida) + to_string(horaPartida) + " " + "Destino:" + DestinoToString(destino);
}
