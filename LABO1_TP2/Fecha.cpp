#include "Fecha.h"

Fecha::Fecha()
{
	dia = 0;
	mes = 0;
	anio = 0;
	hora = 0;
	minuto = 0;
}

Fecha::Fecha(unsigned int _dia, unsigned int _mes, unsigned int _anio, unsigned int _hora, unsigned int _minuto)
{
	this->dia = _dia;
	this->mes = _mes;
	this->anio = _anio;
	this->hora = _hora;
	this->minuto = _minuto;
}

bool Fecha::esCorrecta()
{
	if (0 < dia < 32 && 0 < mes < 13 && anio >= 0 && hora < 24 && minuto < 60)
		return true;
	else
		return false;
}

bool Fecha::esCorrecta(Fecha* fecha_)
{
	if (0 < fecha_->dia < 32 && 0 < fecha_->mes < 13 && fecha_->anio >= 0 && fecha_->hora < 24 && fecha_->minuto < 60)
		return true;
	else
		return false;
}

bool Fecha::Comparar(Fecha* fecha_)
{
	
	if (esCorrecta(fecha_) == true)
	{
		if (dia == fecha_->dia && mes == fecha_->mes && anio == fecha_->anio && hora == fecha_->hora && minuto == fecha_->minuto)
			return true;
	}
	return false;
}

string Fecha::toString()
{
	return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio) + "  " + to_string(hora) + ":" + to_string(minuto);
}

Fecha::~Fecha()
{
}
