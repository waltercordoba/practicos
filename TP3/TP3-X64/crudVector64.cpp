#pragma
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <iostream>
using namespace std;
void crudVector()
{
	// ************* PUNTO 5 *************
	// CON / SIN Signo.

	int tamano, *vector;
	tamano = 0;
	//
	cout << "Ingrese el tamaño del vector :";
	cin >> tamano;

	vector = new int[tamano];

	for (int i = 0; i < tamano; i++)
	{
		cout << "\nIngrese el elemento :" << i << endl;
		cin >> vector[i];

	}
	for (int j = 0; j < tamano; j++)
	{
		cout << "Elemento :" << j << " Contiene :" << vector[j] << endl;
	}
	delete[] vector;
}