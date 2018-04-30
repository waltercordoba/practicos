// Fabricante.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include"misFunciones.h"
#include <deque>
#include "Fabricante.h"

int main()
{
	std::cout << "El sistema solicita informacion de entrada, abre la lista de precios del proveedor indicado y busca la mejor opcion de compra que cumpla el pedido con el menor desperdicio posible" << std::endl;
	system("pause");
	system("cls");
	// Data
	std::string entrada;
	std::cout << "Ingrese presupuesto <espacio> precio de venta <espacio> cantidad de venta <espacio> fabricante" << std::endl;
	getline(std::cin, entrada);
	int P, precioVenta, cantidadVenta, F = 0; 
	splintIn(entrada, P, precioVenta, cantidadVenta, F);

	int* precioCompra = new int[50];
	int* cantidadCompra = new int[50];

	// Call function
	int respuesta = fabricante(P, precioVenta, cantidadVenta, precioCompra, cantidadCompra, F);
	std::cout << "Gana por dia: " << respuesta << std::endl;

	system("pause");
    return 0;
}

