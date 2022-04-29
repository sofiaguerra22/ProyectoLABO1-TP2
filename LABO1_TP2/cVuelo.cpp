#include "cVuelo.h"

/*cPasajero** listaPasajerosVuelo; //puntero doble que almacena en posiciones de memoria cada uno de los pasajeros en el vuelo
	cPasajero* pasajero;
	cValija** listaValijasVuelo;
	cValija* valijaVuelo;*/

cVuelo::cVuelo() 
{
	cantpasajeros = 0;
	destino = "";
	numeroVuelo = 0; //CONSULTAR
	pesoVuelo = 0.0;
	onTime = 0;
	fechaArribo = new Fecha();
	fechaPartida = new Fecha();
	avion = NULL;
	valija = NULL;
	listaValijasVuelo = new cListaValija();
	listaPasajerosVuelo = new cListaPasajeros(MAX);
	PasajeroCambio = NULL;
	PasajeroVuelo = NULL;

}

cVuelo::~cVuelo() //completar el destructor
{
	delete fechaArribo;
	delete fechaPartida;
	delete listaValijasVuelo;
	delete listaPasajerosVuelo;
	PasajeroCambio = NULL;
	PasajeroVuelo = NULL;
	avion = NULL;
	valija = NULL;
}

bool cVuelo::AgregarPasajero(cPasajero* pasajero_vuelo) //Recibe el puntero al pasajero a agregar LLA,AR EN EL MAIN AL TRY CATCH
{
	if (pasajero_vuelo == NULL)
		throw new exception();//llenar
	*listaPasajerosVuelo + pasajero_vuelo;

}

void cVuelo::ObtenerDatos(string DNI)
{
	int pos = listaPasajerosVuelo->Buscar(DNI);
	if (pos != -1)
	{
		PasajeroVuelo = listaPasajerosVuelo->PasajeroEncontrado(DNI);
			PasajeroVuelo->toString();
	}

}

bool cVuelo::CambiarPasajero(cPasajero* Pasajero_Vuelo, cPasajero* Pasajero_Cambio) //TRY CATCH EN MAIN
{
	if(Pasajero_Vuelo != NULL || Pasajero_Cambio != NULL)
		throw exception(); //completar
	
		int pos = listaPasajerosVuelo->Buscar(Pasajero_Vuelo->DNI); // buscamos la posición en la lista de vuelos del primer dni
		Pasajero_Cambio->asiento = Pasajero_Vuelo->asiento;
		Pasajero_Cambio->numerovuelo = Pasajero_Vuelo->numerovuelo;
		pesoVuelo = pesoVuelo - Pasajero_Vuelo->PesoTotal() + Pasajero_Cambio->PesoTotal();
		listaPasajerosVuelo->AgregarEnPos(pos, Pasajero_Cambio);  //preguntar 
		return true;

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
	if (FechaActual->esCorrecta() == true && fechaPartida->Comparar(FechaActual))
	{
		onTime++;
		return true;
	}
	return false;
}

bool cVuelo::ChequearOnTimeArribo(Fecha* FechaActual) // devuelve false si la fecha u horario son inválidos
{
	if (FechaActual->esCorrecta() == true && fechaArribo->Comparar(FechaActual))
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
	return "Cantidad de pasajeros: " + to_string(cantpasajeros) + "\nNum vuelo: " + to_string(numeroVuelo) + " "
		+ "\npeso vuelo: " + to_string(pesoVuelo) + "\nFecha y hora arribo: " + fechaArribo->toString() + "\nFecha y hora despegue: " +
		fechaPartida->toString();
}
