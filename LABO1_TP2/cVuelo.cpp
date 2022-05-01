#include "cVuelo.h"

int cVuelo::numeroVuelo = 0;

cVuelo::cVuelo(eDestino _destino)
{
	cantpasajeros = 0;
	numeroVuelo++; 
	pesoVuelo = 0;
	onTime = 0;
	fechaArribo = new Fecha();
	fechaPartida = new Fecha();
	avion = NULL;
	valija = NULL;
	listaValijasVuelo = new cListaValija(MAX);
	listaPasajerosVuelo = new cListaPasajeros(MAX);
	destino = _destino; 
}

cVuelo::~cVuelo() //completar el destructor
{
	delete fechaArribo;
	delete fechaPartida;
	delete listaValijasVuelo;
	delete listaPasajerosVuelo;
	avion = NULL;
	valija = NULL;
}

bool cVuelo::AgregarPasajero(cPasajero* pasajero_vuelo) //Recibe el puntero al pasajero a agregar LLA,AR EN EL MAIN AL TRY CATCH
{
	if (pasajero_vuelo == NULL)
		return false;
		//throw new exception();//llenar
	*listaPasajerosVuelo + pasajero_vuelo;
	pasajero_vuelo->asiento = cantpasajeros;
	pasajero_vuelo->numerovuelo = numeroVuelo;
	cantpasajeros++;
	pesoVuelo = pesoVuelo + (pasajero_vuelo->PesoTotal());
	return true;
}

void cVuelo::ObtenerDatos(string DNI)
{
	int pos = listaPasajerosVuelo->Buscar(DNI);
	if (pos != -1)
	{
		cPasajero* pasajeroVuelo = listaPasajerosVuelo->PasajeroEncontrado(DNI);
			pasajeroVuelo->toString();
	}

}

void cVuelo::CambiarPasajero(cPasajero* Pasajero_Vuelo, cPasajero* Pasajero_Cambio) //excepcion
{
	if (Pasajero_Vuelo == NULL || Pasajero_Cambio == NULL) 
		throw 1;
	if (listaPasajerosVuelo->Buscar(Pasajero_Vuelo) == -1)
		throw 2;

	int pos = (listaPasajerosVuelo->Buscar(Pasajero_Vuelo)); // buscamos la posición en la lista de vuelos del primer dni
	(Pasajero_Cambio->asiento) = (Pasajero_Vuelo->asiento);
	(Pasajero_Cambio->numerovuelo) = (Pasajero_Vuelo->numerovuelo);
	pesoVuelo = (pesoVuelo - (Pasajero_Vuelo->acumpeso) + (Pasajero_Cambio->acumpeso));
	Pasajero_Vuelo->asiento = -1;
	Pasajero_Vuelo->numerovuelo = -1;
	listaPasajerosVuelo->AgregarEnPos(pos, Pasajero_Cambio);  

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

bool cVuelo::setFechas(Fecha* fecha_a, Fecha* fecha_p)
{
	if (fecha_a->esCorrecta() == true && fecha_p->esCorrecta() == true)
	{
		fechaArribo = fecha_a;
		fechaPartida = fecha_p;
		return true;
	}
	return false;
}

bool cVuelo::ChequearOnTimePartida(Fecha* FechaActual) //devuelve false so la fecha u horario son inválidos
{
	if (FechaActual->esCorrecta() == true && fechaPartida->Comparar(FechaActual) == true)
	{
		onTime++;
		return true;
	}
	return false;
}

bool cVuelo::ChequearOnTimeArribo(Fecha* FechaActual) // devuelve false si la fecha u horario son inválidos
{
	if (FechaActual->esCorrecta() == true && fechaArribo->Comparar(FechaActual) == true)
	{
		onTime++;
		return true;
	}
	return false;
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
	return "Num vuelo : " + to_string(numeroVuelo) + "\nDestino: " + DestinoToString(destino) + "\nCantidad de pasajeros : " + to_string(cantpasajeros) + 
		"\npeso vuelo: " + to_string(pesoVuelo) + "\nFecha y hora arribo: " + fechaArribo->toString() + "\nFecha y hora despegue: " +
		fechaPartida->toString() + "\nCantidad onTime: " + to_string(onTime);
}
