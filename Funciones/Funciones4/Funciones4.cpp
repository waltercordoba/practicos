// Funciones4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using std::cout;
void f(float) { std::cout << "f(float) \n"; }
void f(long double) { std::cout << "f(long double) \n"; }

int main()
{
	//f(2.0);
	std::cout << "Opcion c (compilacion) Llamada ambigua a funcion sobrecargada \n";
	system("pause");
    return 0;
}

