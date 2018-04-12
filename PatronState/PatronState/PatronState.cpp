// PatronState.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include"Context.h"
#include"Amarillo.h"
#include"Verde.h"
#include"Rojo.h"
#include<iostream>

int main()
{
	Context semaforo;
	int cambio;
	Context context; // Se genera en estado Amarillo.
	do {
		system("cls");
		std::cout << "Ingrese el nuevo estado del semaforo (0:Salir - 1: Amarillo - 2:Rojo - 3:Verde)" << std::endl;
		std::cin >> cambio;
		if (cambio > 0 && cambio < 4)
		{
			semaforo.Handle(cambio);
			system("pause");
		}
	} while (cambio != 0);
    return 0;
}

