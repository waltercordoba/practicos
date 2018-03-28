#include "stdafx.h"
#include<iostream>
using namespace std;
void pointer1() 
{
	// PUNTO 1
	cout << "int var = 40; \n";
	cout << "int &ref = var; \n";
	cout << "El segundo parrafo es una referencia correcta al primero, ambos apuntan a la direccion donde se almacena el valor 40\n\n\n";
	cout << "int​ &ref = 1; \n";
	cout << "Incorrecto, no se puede referenciar una constante \n\n\n";

	cout << "int var = 1; (Asigna un valor a una variable) \n";
	cout << "int *ptr; (Declara una variable de tipo puntero)\n";
	cout << "int &ref = var; (ref toma la direccion de var)\n";
	cout << "*ptr = ref; (La variable de tipo puntero toma el valor de ref, por ende apunta a var) \n";
	cout << "Correcto \n\n\n";
}
