// Funciones10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int dameUnEntero(const double a)
{
	int respuesta = static_cast<int>(a);
	return respuesta;
}

int(*funcion) (const double);

int main() {
	funcion = dameUnEntero;
	int x = funcion(53.21);  
	cout << "Valor 53.21 llevado a entero :" << x << endl;
	system("pause");
	return 0;
}

