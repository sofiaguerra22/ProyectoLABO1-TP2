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
		cValija* valija2_p1 = new cValija(9, pasajero1->getDNI()); 
		cValija* valija1_p2 = new cValija(20, pasajero2->getDNI());
		cValija* valijanull = NULL;
		//ListaValijas:
		cListaValija* ListaValijas = new cListaValija(MAX);
		*ListaValijas + valija1_p1;
		*ListaValijas + valija2_p1;
		*ListaValijas + valija1_p2;
		try //demostracion de try catch
		{
			pasajero1->AgregarEquipaje(valija1_p1);
			//pasajero1->AgregarEquipaje(valija1_p1); //error 2, valijas superan peso. Comentar para continuar
			pasajero2->AgregarEquipaje(valija1_p2);
			//pasajero3->AgregarEquipaje(valijanull); //error 1, valija null. Comentar para continuar
		}
		catch(int e)
		{
			cout << "\nError al agregar equipaje. Numero de error: " << e << endl; //1=puntero null, 2=supera peso, 3=el equipaje no corresponde a esa persona
			system("pause");
		} 
		cout << "\nDatos de pasajeros sin avion asignado: " << endl;
		cout << "\nPasajero1: " << endl;
		pasajero1->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		cout << "\nPasajero2: " << endl;
		pasajero2->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		cout << "\nPasajero3: " << endl;
		pasajero3->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");
	//Fechas:
		Fecha* fecha1 = new Fecha(10, 4, 2022, 20, 30);
		Fecha* fecha2 = new Fecha(12, 7, 2022, 10, 45);
		Fecha* fecha3 = new Fecha(6, 5, 2022, 12, 10);
		Fecha* fecha4 = new Fecha(9, 11, 2022, 23, 45);
	//Vuelos:
		cVuelo* vuelo1 = new cVuelo(eDestino::Londres);
		vuelo1->setFechas(fecha1, fecha2);
		cVuelo* vuelo2 = new cVuelo(eDestino::Paris);
		vuelo2->setFechas(fecha3, fecha4);
		//ListaVuelos:
		cListaVuelos* ListaVuelos = new cListaVuelos(MAX);
		*ListaVuelos + vuelo1;
		*ListaVuelos + vuelo2;

		cout << "\nPrueba de sobrecarga de impresion ostream: " << endl;
		cout << *vuelo1 << endl; //imprime la cantidad de pasajeros
		cout << *vuelo2 << endl;
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");

		cout << "\nDatos vuelos sin pasajeros: " << endl;
		vuelo1->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		vuelo2->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");

	//try catch de agregarpasajero a vuelo:
		cout << "\nAgregamos pasajero1 y pasajero3 a vuelo1, vemos asiento y numero de vuelo de pasajero 3: " << endl;
		vuelo1->AgregarPasajero(pasajero1); 
		vuelo1->AgregarPasajero(pasajero3);
		pasajero3->ImprimirDatos(); //imprime los datos del pasajero 3
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");
		cout << "\nPeso actual del vuelo 1: " << vuelo1->getPesoVuelo() << endl;
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");
		cout << "\nCambiamos al pasajero 3 por el pasajero 2 en el vuelo 1. Imprimimos nuevos datos de pasajero 2:" << endl;
		vuelo1->CambiarPasajero(pasajero3, pasajero2);
		pasajero2->ImprimirDatos(); 
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");
		cout << "\nPeso luego del cambio de pasajeros del vuelo 1: " << vuelo1->getPesoVuelo() << endl;
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");
		cout << "\nDatos de los vuelos:" << endl;
		cout << "\nVuelo 1: " << endl;
		vuelo1->ImprimirDatos(); 
		cout << "\n---------------------------------------------------------------------------------" << endl;
		cout << "\nVuelo 2:" << endl;
		vuelo2->ImprimirDatos(); 
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");

	//Aviones:
		cAvion* avion1 = new cAvion(1, 10, 5000);
		cAvion* avion2 = new cAvion(2, 5, 6000);
		//ListaAviones:
		cListaAviones* ListaAviones = new cListaAviones(MAX);
		*ListaAviones + avion1;
		*ListaAviones + avion2;

		avion1->AsignarVuelo(vuelo1); 
		avion2->AsignarVuelo(vuelo2);
		cout << "\nAterriza el avion1" << endl;
		avion1->Aterrizar(aeropuerto, fecha1); //ontime
		cout << "\nEstadisticas del Aeropuerto con avion1: " << endl;
		aeropuerto->Estadisticas(); //se hacen las estadísticas 
		aeropuerto->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");
		cout << "\nAterriza el avion2" << endl;
		avion2->Aterrizar(aeropuerto, fecha3); //on time
		cout << "\nEstadisticas del Aeropuerto con avion2: " << endl;
		aeropuerto->Estadisticas();
		aeropuerto->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");
		cout << "\nDespega el avion1:" << endl;
		avion1->Despegar(aeropuerto, fecha1); //atrasado
		cout << "\nEstadisticas del Aeropuerto sin avion1: " << endl;
		aeropuerto->Estadisticas();
		aeropuerto->ImprimirDatos();
		cout << "\n---------------------------------------------------------------------------------" << endl;
		system("pause");

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
		delete valijanull;
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