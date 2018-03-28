#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include"primo.h"
#include"Nodo.h"
#include"Lista.h"
Lista * miLista = new Lista();

void integerList()
{
	int opc = 0, valor = 0;
	do {
		std::cout << "Seleccione la opcion (0-Salir) :\n";
		std::cout << "1-Agregar / 2-Listar\n";
		std::cin >> opc;
		system("cls");

		switch (opc) {
				case 0:
					break;

				case 1:// Agregar
					std::cout << "Ingrese el numero :\n";
					std::cin >> valor;
					if (!isPrime(valor, valor - 1))
					{
						miLista->addElement(valor);
					}
					else
					{
						std::cout << "El numero es primo, intente de nuevo \n";
					}
					break;

				case 2: // Listar
					miLista->toList();
					break;
		}
	} while (opc != 0);
}