// TP4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"pointer1.h"
#include"pointer2.h"
#include"integerList.h"
#include"swap.h"

int main()
{
	int opc = 0;
	do {
		system("cls");
		std::cout << "Seleccione la opcion (0-Salir) :\n";
		std::cout << "1-Referencias: Indicar en cada caso si es o no valido\n";
		std::cout << "2-Aritmética de punteros. Completar el siguiente código para que imprima 'true'\n";
		std::cout << "3-Funcion Swap\n";
		std::cout << "4-Lista de Enteros\n";
		std::cin >> opc;
		system("cls");
		switch (opc) {
				case 0:
					break;

				case 1:
					pointer1();
					system("pause");
					break;

				case 2:
					pointer2();
					system("pause");
					break;

				case 3:
					int num1, num2;
					std::cout << "Ingrese un entero como primer elemento :";
					std::cin >> num1;
					std::cout << "Ingrese un entero como segundo elemento :";
					std::cin >> num2;
					std::cout << "\nAntes del intercambio :\n";
					std::cout << "Primero : \n" << num1;
					std::cout << "Segundo : \n" << num2;

					std::cout << "\n\nDespues del 1er intercambio :";
					swap(&num1, &num2);
					std::cout << "Primero : " << num1;
					std::cout << "Segundo : " << num2;

					std::cout << "\n\nDespues del 2do intercambio :";
					swap(num1, num2);
					std::cout << "Primero : " << num1;
					std::cout << "Segundo : " << num2;

					system("pause");
					break;

				case 4:
					integerList();
					system("pause");
					break;

		}
	} while (opc != 0);
	return 0;
}

