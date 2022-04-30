#include <string>
#include <iostream>
#include <stdio.h>
#include "cAeropuerto.h"

int main()
{
	//Aeropuerto:
	cAeropuerto* aeropuerto = new cAeropuerto(4, 1);
	//Pasajeros:
	cPasajero* pasajero1 = new cPasajero("43718486");
	cPasajero* pasajero2 = new cPasajero("2783848");
	cPasajero* pasajero3 = new cPasajero("1948483");
		//ListaPasajeros:
		cListaPasajeros* ListaPasajeros = new cListaPasajeros(MAX);
		*ListaPasajeros + pasajero1;
		*ListaPasajeros + pasajero2;
		*ListaPasajeros + pasajero3;
	//Valijas:
		cValija* valija1_p1 = new cValija(15, pasajero1->getDNI()); 
		cValija* valija2_p1 = new cValija(18, pasajero1->getDNI()); //pasajero 2 se excede de equipaje
		cValija* valija1_p2 = new cValija(20, pasajero2->getDNI());
		//try
		//{
		//	pasajero1->AgregarEquipaje(valija1_p1);
		//	pasajero1->AgregarEquipaje(valija1_p2); //probamos asignarle la valija de otra persona, comentar para seguir c el programa
		//	pasajero1->AgregarEquipaje(valija1_p1);
		//	pasajero2->AgregarEquipaje(valija1_p2);
		//}
		//catch(int e)
		//{
		//	cout << "Error al agregar equipaje. Numero de error: " << e << endl; //1=puntero null, 2=supera peso, 3=el equipaje no corresponde a esa persona
		//} 
		//try catch: pero por el momento agregamos el equipaje así
		pasajero1->AgregarEquipaje(valija1_p1);
		pasajero1->AgregarEquipaje(valija1_p1);
		pasajero2->AgregarEquipaje(valija1_p2);

		//ListaValijas:
		cListaValija* ListaValijas = new cListaValija(MAX);
		*ListaValijas + valija1_p1;
		*ListaValijas + valija2_p1;
		*ListaValijas + valija1_p2;

	//Fechas:
		Fecha* fecha1 = new Fecha(10, 4, 2022, 20, 30);
		Fecha* fecha2 = new Fecha(12, 7, 2022, 10, 45);
		Fecha* fecha3 = new Fecha(6, 5, 2022, 12, 10);
		Fecha* fecha4 = new Fecha(9, 11, 2022, 23, 45);
	//Vuelos:
		cVuelo* vuelo1 = new cVuelo(1);
		vuelo1->setFechas(fecha1, fecha2);
		cVuelo* vuelo2 = new cVuelo(2);
		vuelo2->setFechas(fecha3, fecha4);
		//ListaVuelos:
		cListaVuelos* ListaVuelos = new cListaVuelos(MAX);
		*ListaVuelos + vuelo1;
		*ListaVuelos + vuelo2;

	//try catch de agregarpasajero a vuelo:
		//falta probar eliminar pasajero pero quiero antes entender try catch !!
		vuelo1->AgregarPasajero(pasajero1); //para agregar al pasajero 1 tenemos q comentar el agregar de su segunda valija
		vuelo2->AgregarPasajero(pasajero2);
		vuelo1->AgregarPasajero(pasajero3);
		vuelo1->ObtenerDatos(pasajero1->getDNI()); //imprime los datos del pasajero 1, asiento 0, numero de vuelo 1, dni 43... 
		cout << "\nPeso actual del vuelo 1: " << vuelo1->getPesoVuelo() << endl;
		vuelo1->CambiarPasajero(pasajero3, pasajero2);
		vuelo1->ObtenerDatos(pasajero2->getDNI()); //asiento 1, numero de vuelo 1, dni 27...
		cout << "\nPeso luego del cambio de pasajeros del vuelo 1: " << vuelo1->getPesoVuelo() << endl;
		cout << "\nVuelo 1: " << endl;
		vuelo1->ChequearOnTimeArribo(fecha1);//en horario
		vuelo1->ChequearOnTimePartida(fecha1); //fuera de horario
		vuelo1->ImprimirDatos(); //onTime=1, fechas 1 y 2, cant pasajeros 2
		cout << "\nVuelo 2:" << endl;
		vuelo2->ChequearOnTimeArribo(fecha3);//en horario
		vuelo2->ChequearOnTimePartida(fecha4); //en horario
		vuelo2->ImprimirDatos(); //onTime=2, fechas 3 y 4, cant pasajeros 0

	//Aviones:
		cAvion* avion1 = new cAvion(1, 10, 200);
		cAvion* avion2 = new cAvion(2, 5, 100);
		//ListaAviones:
		cListaAviones* ListaAviones = new cListaAviones(MAX);
		*ListaAviones + avion1;
		*ListaAviones + avion2;
		//try catch:
		avion1->AsignarVuelo(vuelo1); //supera carga maxima, cambiar límite para seguir
		avion2->AsignarVuelo(vuelo2);
		avion1->RecibirPermiso(avion1); //recibir permiso llama a pedir permiso que llama a dar permiso, si se le da el permiso llama a aterrizar que llama a agregar avion
		aeropuerto->Estadisticas(); //se hacen las estadísticas 
		aeropuerto->ImprimirDatos(); //1, 1 ,1 y 100%
		avion2->RecibirPermiso(avion2);
		aeropuerto->Estadisticas();
		aeropuerto->ImprimirDatos();
		avion1->Despegar();


		delete aeropuerto;
		delete pasajero1;
		delete pasajero2;
		delete pasajero3;
		delete ListaPasajeros;
		delete ListaValijas;
		delete ListaAviones;
		delete ListaVuelos;
		delete valija1_p1;
		delete valija2_p1;
		delete valija1_p2;
		delete avion1;
		delete avion2;
		delete vuelo1;
		delete vuelo2;
		delete fecha1;
		delete fecha2;
		delete fecha3;
		delete fecha4;

		system("pause");
}