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
	listaPasajerosVuelo = new cListaPasajeros(); //
	listaValijasVuelo = new cListaValija();
}

cVuelo::~cVuelo() //completar el destructor
{
	
}

bool cVuelo::AgregarPasajero(string DNI) //CONSULTAR
{

	if (listaPasajerosVuelo->Buscar(DNI) != -1) //si encontró el dni en la lista
	{
		pasajeroVuelo->numerovuelo = numeroVuelo;
		cantpasajeros++;
		pasajeroVuelo->asiento = cantpasajeros; //se le asigna el último asiento
		pesoVuelo = pasajeroVuelo->PesoTotal();  //se le agrega al peso total del vuelo, el peso del nuevo pasajero
		return true; // se agregó el pasajero éxitosamente 
	}
	else
	{
		return false; //no se pudo agregar el pasajero
	}
}

void cVuelo::ObtenerDatos(string DNI)
{

		if (listaPasajerosVuelo->Buscar(DNI) != -1) //si encontró el dni en la lista
		{
			//LLAMAR A FUNCIÓN IMPRIMIR 
		}

}

bool cVuelo::CambiarPasajero(string DNI_1, string DNI_2) //el 1 es el actual y el 2 es el nuevo pasajero
{
	if (listaPasajerosVuelo->Buscar(DNI_1) != -1 && listaPasajerosVuelo->Buscar(DNI_2) != -1) // si ambos existen...
	{
		//cambio de asiento:
		int auxasiento = pasajeroVuelo->asiento;
		pasajeroVuelo->asiento = 0;
		pasajeroCambio->asiento = auxasiento;

		//cambio de vuelo:
		int auxvuelo = pasajeroVuelo->numerovuelo;
		pasajeroVuelo->numerovuelo = 0;
		pasajeroCambio->numerovuelo = auxvuelo;

		//cambio peso:
		pesoVuelo = pesoVuelo - pasajeroVuelo->PesoTotal() + pasajeroCambio->PesoTotal();

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
