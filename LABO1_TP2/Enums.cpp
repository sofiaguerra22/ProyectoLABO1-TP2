#include "Enums.h"

string DestinoToString(eDestino destino)
{
	switch (destino)
	{
	case eDestino::Londres:
		return "Londres";
		break;
	case eDestino::Paris:
		return "Paris";
		break;
	case eDestino::NY:
		return "NY";
		break;
	default:
		return "";
		break;
	}
}
