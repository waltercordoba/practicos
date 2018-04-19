// Fabricante.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include <sstream>
#include <fstream>
#include <deque>

// Read text file
void load(const std::string path, std::deque<int> &miLista)
{
	// Abre el fichero de entrada
	std::ifstream fe(path);

	//// fabricante.in
	std::string cad = "";

	while (getline(fe, cad))
	{
		std::istringstream iss(cad);
		bool proceso = true;
		do
		{
			std::string subs;
			iss >> subs;
			if (subs.size() > 0) // All values has been chargered to miLista.
			{ 
				miLista.push_back(stoi(subs));
			}
			else
			{
				proceso = false;
			}
		} while (proceso);
	}
	fe.close();
}

int main()
{
	std::deque<int> miLista;
	load("C:\\entrada.txt", miLista); // Send location text file.
	
	std::deque<int>::iterator miIterador = miLista.begin();
	//
	int lugar = 0;
	int lugarMenorDiferencia = 10001;
	int diferenciaLote = 10001;
	int precioVenta = 0;
	int cantidadVendida = 0;
	int mejorProveedor = 0;
	int cantidadAComprar = 0;
	int precioAComprar = 0;
	int totalCompra = 0;
	int totalVta = 0;

	//
	for (auto elemento : miLista)
	{
		switch (lugar)
		{
				case 0: // presupuesto
					break;

				case 1: // precioVenta
					precioVenta = elemento;
					break;

				case 2: // cantidadVendida
					cantidadVendida = elemento;
					break;

				case 3: //  Provider
					mejorProveedor = elemento;
					// Compute total sold
					totalVta = precioVenta * cantidadVendida;
					break;

				default: // 
					if (lugar > 3) // All of them are quantitys and cost.
					{
						if ((lugar % 2) != 0) //When lugar is Odd => Quantity 
						{
							if (elemento - cantidadVendida < diferenciaLote)
							{
								diferenciaLote = elemento - cantidadVendida;
								lugarMenorDiferencia = lugar; // Place on list deque
								cantidadAComprar = elemento;
								totalCompra = precioAComprar * cantidadAComprar;
							}
						}
						else // When lugar is pair => = Cost
						{
							precioAComprar = elemento; 
						}
					}
		}
		lugar++;
	}
	std::cout << "Comprando al Proveedor: " << mejorProveedor << std::endl;
	std::cout << "Cantidad: " << cantidadAComprar << std::endl;
	std::cout << "Ganancia: " << totalVta-totalCompra << std::endl;
	system("pause");
    return 0;
}

