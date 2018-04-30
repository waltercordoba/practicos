#include "stdafx.h"
#include "misFunciones.h"
#include <iostream>
#include <iterator>
#include<string>
#include <sstream>
#include <fstream>
#include <deque>

const int fabricante(const int P, const int precioVenta, const int cantidadVenta, int* precioCompra, int* cantidadCompra, const int F)
 {
	load(precioVenta, cantidadVenta, precioCompra, cantidadCompra, F); // Read text file and put values on list
	int mejorOpcion = lookingBestOption(precioVenta, cantidadVenta, precioCompra, cantidadCompra, F); // look best buy option
	//
	system("cls");
	std::cout << "Comprando al Proveedor: " << F << std::endl;
	std::cout << "Cantidad: " << cantidadCompra[mejorOpcion] << std::endl;
	std::cout << "Obtenemos un sobrante de: " << cantidadCompra[mejorOpcion]- cantidadVenta << std::endl;
	std::cout << "A un costo de: " << precioCompra[mejorOpcion] << " por unidad" <<std::endl;
	std::cout << "Costo total de: " << precioCompra[mejorOpcion] * cantidadVenta << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	char resigna;
	int retorno = precioVenta * cantidadVenta - precioCompra[mejorOpcion] * cantidadVenta;
	std::cout << "Resigna el negocio? (Y/N) :" << std::endl;
	std::cin >> resigna;

	if (toupper(resigna) == 'Y')
	{
		retorno = -1;
	}
	return retorno; 
}

void load(int precioVenta, int cantidadVenta, int* precioCompra, int* cantidadCompra, int F)
{
	// Abre el fichero de entrada
	const std::string path = "C:\\" + std::to_string(F) + ".txt";
	std::ifstream fe(path);

	//// fabricante.in
	std::string cad = "";
	int pos = 0;
	int row = 1;
	while (getline(fe, cad))
	{
		std::istringstream iss(cad);
		bool proceso = true;
		do
		{
			std::string subs;
			iss >> subs;
			if (subs.size() > 0 ) // All values has been chargered to miLista.
			{
				if (pos % 2 == 0) // Price
				{
					precioCompra[row-1] = stoi(subs);
				}
				else
				{
					cantidadCompra[row-1] = stoi(subs); // Quantity
				}
				pos++;
			}
			else
			{
				proceso = false; // Exit
				
			}
		} while (proceso);
		row++;
		if (row > 50)
		{
			std::cout << "Overflow" << std::endl;
			system("pause");
			return;
		}
	}
	fe.close();
}

void splintIn(const std::string entrada, int &P, int &precioVenta, int &cantidadVenta, int &F)
{
	int ordenValores = 0;
	std::istringstream iss(entrada);
	do
	{
		std::string subs;
		iss >> subs;
		if (subs.size() > 0) // String has something
		{
			switch (ordenValores)
			{
				case 0: //Presupuesto
				{
					P = std::stoi(subs);
					break;
				}
				case 1: //Precio Venta
				{
					precioVenta = std::stoi(subs);
					break;
				}
				case 2: //Cantidad
				{
					cantidadVenta = std::stoi(subs);
					break;
				}
				case 3: //Fabricante
				{
					F = std::stoi(subs);
					break;
				}
			}
			ordenValores++;
		}
	} while (iss);
}
const int lookingBestOption(const int precioVenta, const int cantidadVenta, const int* precioCompra, const int* cantidadCompra, const int F)
{
	int opc = -1;
	int aux = 0;
	int precio = 10001;
	int compraMenor = 10001;

	for (int i = 0; i < F; i++)
	{
		aux = cantidadCompra[i] - cantidadVenta;
		if (aux <= compraMenor ) // Lower scrap
		{
			if (precioVenta * cantidadVenta >= precioCompra[i] * cantidadCompra[i]) // Have enought money :D
			{
				compraMenor = aux;
				opc = i;
			}
		}
	}
	return opc;
}