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
	onTime = 0;
	fechaArribo, fechaPartida, horaArribo, horaPartida = 0;
	listaPasajerosVuelo = NULL;
	avion = NULL;
	valija = NULL;
	listaValijasVuelo = new cListaValija();
	listaPasajerosVuelo = new cListaPasajeros(maxpasajeros);
	PasajeroCambio = NULL;
	PasajeroVuelo = NULL;

}

cVuelo::~cVuelo() //completar el destructor
{
	
}

bool cVuelo::AgregarPasajero(string DNI, cListaPasajeros* listaTotal) //CONSULTAR
{
	if (listaTotal->PasajeroEncontrado(DNI) != nullptr)
	{
		listaPasajerosVuelo->Agregar(listaTotal->PasajeroEncontrado(DNI));
		return true;
	}
	else
	{
		return false;
	}

}

void cVuelo::ObtenerDatos(string DNI)
{
	int pos = listaPasajerosVuelo->Buscar(DNI);
	if (pos != -1)
	{
		PasajeroVuelo = listaPasajerosVuelo->PasajeroEncontrado(DNI);
		{
			PasajeroVuelo->toString();
		}
	}

}

bool cVuelo::CambiarPasajero(string DNI_1, string DNI_2, cListaPasajeros* listaTotal) //el 1 es el actual y el 2 es el nuevo pasajero
{
	PasajeroVuelo = listaPasajerosVuelo->PasajeroEncontrado(DNI_1);
	PasajeroCambio = listaTotal->PasajeroEncontrado(DNI_2);
	if (PasajeroVuelo != nullptr && PasajeroCambio != nullptr)
	{
		int pos = listaPasajerosVuelo->Buscar(DNI_1); // buscamos la posición en la lista de vuelos del primer dni
		PasajeroCambio->asiento = PasajeroVuelo->asiento;
		PasajeroCambio->numerovuelo = PasajeroVuelo->numerovuelo;
		pesoVuelo = pesoVuelo - PasajeroVuelo->PesoTotal() + PasajeroCambio->PesoTotal();
		listaPasajerosVuelo->AgregarEnPos(pos, PasajeroCambio);  //preguntar 
		return true;
	}
	else
	{
		return false;
	}
	
}

float cVuelo::PesoVuelo()
{
	return false;
}

bool cVuelo::EliminarPasajero(string DNI)
{
	int pos = listaPasajerosVuelo->Buscar(DNI);
	if (pos != -1)
	{
		listaPasajerosVuelo->Eliminar(pos);
		return true;
	}
	else
	{
		return false;
	}
}

bool cVuelo::setFechas(long int fecha_a, long int fecha_p)
{
	if (fecha_a > 31120000 || fecha_p > 31120000 || fecha_a < 0 || fecha_p < 0)
	{
		cout << "fecha no valida" << endl; //la fecha de pasa del 31/12
		return false;
	}
	else
	{
		fechaArribo = fecha_a;
		fechaPartida = fecha_p;
		return true;
	}
}

bool cVuelo::setHorarios(long int hora_a, long int hora_p)
{
	if (hora_a > 2359 || hora_p > 2359 || hora_a < 0 || hora_p < 0)
	{
		cout << "horario no valido" << endl;
		return false;
	}
	else
	{
		horaArribo = hora_a;
		horaPartida = hora_p;
		return true;
	}

}

bool cVuelo::ChequearOnTimePartida(long int horaActual, long int fechaActual) //devuelve false so la fecha u horario son inválidos
{
	if (fechaActual > 31120000 || fechaActual < 0 || horaActual>2359 || horaActual < 0)
	{
		cout << "Fecha u horario no valido" << endl;
		return false;
	}
	else
	{
		if (fechaActual != fechaPartida)
		{
			return true;
		}
		else
		{
			if (horaActual != horaPartida)
			{
				return true;
			}
			else
			{
				onTime++; 
				return true;
			}
		}
	}
}

bool cVuelo::ChequearOnTimeArribo(long int horaActual, long int fechaActual) // devuelve false si la fecha u horario son inválidos
{
	if (fechaActual > 31120000 || fechaActual < 0 || horaActual>2359 || horaActual < 0)
	{
		cout << "Fecha u horario no valido" << endl;
		return false;
	}
	else
	{
		if (fechaActual != fechaArribo)
		{
			return true;
		}
		else
		{
			if (horaActual != horaArribo)
			{
				return true;
			}
			else
			{
				onTime++;
				return true;
			}
		}
	}
}

float cVuelo::getOnTime()
{
	return onTime;
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
