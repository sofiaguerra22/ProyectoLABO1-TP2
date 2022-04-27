#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class cAvion
{
private:
	int ID;
public:
	cAvion() {};
	~cAvion();
	int getID() { return ID; };
	void ImprimirDatos();
	string toString();
};

