// Funciones.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<iostream>

void f(signed char c) { std::cout << "Signed char \n"; }
void f(unsigned char c) { std::cout << "Unsigned char \n"; }

int main() {
	//////////////////////////////////////////////////////
	//					PUNTO 1
	//////////////////////////////////////////////////////
	std::cout << "Punto 1 \n";
	char c1 = 'a';
	//f(c1);
	std::cout << "Llamada ambigua a una funcion sobrecargada \n";
	system("pause");
	return 0;
}
