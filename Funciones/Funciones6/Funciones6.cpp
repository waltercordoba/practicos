// Funciones6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
int f() { return 1; }
//double f() { return 2.5; }

int main()
{
	int ret = f();
	std::cout << "Opcion d (compilacion) Las funciones sobrecargadas solo se diferencia por el tipo devuelto \n";
	system("pause");
    return ret;
}

