// Funciones9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int modificar(const int num)
{
	//num = num * 11;
	return num;
}

int main()
{
	int num, resultado;
	std::cout << "Error (compilacion), no se puede modificar el valor" << std::endl;
	std::cout << "Introduce un numero entero: " << std::endl;
	std::cin >> num;
	resultado = modificar(num);
	std::cout << "Numero introducido: " << num << std::endl;
	std::cout << "Numero modificado: " << resultado << std::endl;

	system("pause");
}


