// ArbolAvl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include <fstream>
#include"Nodo.h"
#include"Avl.h"

///////////////////////////////////////
//			Funciónes
//////////////////////////////////////
// Muestra recorridos del árbol
void Mostrar(std::string &d, int FE)
{
	std::cout << d << "(" << FE << "),";
}
std::string getKey(std::string cad)
{
	std::string strkey = "";
	int tam = cad.size();
	for (int i = 0; i < tam; i++)
	{
		if (cad[i] == 'a' || cad[i] == 'b' || cad[i] == 'c')
		{
			strkey = strkey + "2";
		}
		else if (cad[i] == 'd' || cad[i] == 'e' || cad[i] == 'f')
		{
			strkey = strkey + "3";
		}
		else if (cad[i] == 'g' || cad[i] == 'h' || cad[i] == 'i')
		{
			strkey = strkey + "4";
		}
		else if (cad[i] == 'j' || cad[i] == 'k' || cad[i] == 'l')
		{
			strkey = strkey + "5";
		}
		else if (cad[i] == 'm' || cad[i] == 'n' || cad[i] == 'o')
		{
			strkey = strkey + "6";
		}
		else if (cad[i] == 'p' || cad[i] == 'q' || cad[i] == 'r' || cad[i] == 's')
		{
			strkey = strkey + "7";
		}
		else if (cad[i] == 't' || cad[i] == 'u' || cad[i] == 'v')
		{
			strkey = strkey + "8";
		}
		else if (cad[i] == 'w' || cad[i] == 'x' || cad[i] == 'y' || cad[i] == 'z')
		{
			strkey = strkey + "9";
		}
		else
		{
			strkey = strkey + "0";
		}
	}
	return strkey;
}

// Crea el arbol con los datos del path
void load(const std::string path, AVL& p_Arbol)
{
	// Pregunto si admite repeticiones
	char repetido;
	bool sinDuplicados = true;
	std::cout << "Permite duplicados? (Y/N) :" << std::endl;
	std::cin >> repetido;
	if (toupper(repetido) == 'Y')
	{
		sinDuplicados = false;
	}
	//// Diccionario 
	std::string cad = "";

	// Abre el fichero de entrada
	std::ifstream fe(path);

	while (getline(fe, cad))
	{
		p_Arbol.Insertar(getKey(cad), cad, sinDuplicados);
	}
	fe.close();
	system("pause");
}

int main()
{
	// Leo el diccionario
	AVL miarbol;
	try
	{
		load("C:\\archivo.txt", miarbol);
	}
	catch (int e)
	{
		std::cout << "Ocurrio un error al abrir el archivo " << e << '\n';
		std::cin.get();
		return -1;
	}

	std::list <std::string> aux;
	std::list<std::string>::iterator pos;
	int opc = 0;

	do {
		system("cls");
		std::cout << "Seleccione la opcion (0-Salir) :" << std::endl;
		std::cout << "1.-Buscar key" << std::endl;
		std::cout << "2.-Listar datos" << std::endl;
		std::string strkey = "";
		std::cin >> opc;
		system("cls");
		std::cin.ignore();

		switch (opc) {
		case 0: //Salida
			std::cout << "Adios!" << std::endl;
			break;

		case 1: // Busqueda
			std::cout << "Ingrese la key a buscar :" << std::endl;
			std::cin >> strkey;
			aux = miarbol.buscarKeys(strkey);
			// Reccorro la lista de palabras
			pos = aux.begin();
			std::cout << "Plabras :";
			while (pos != aux.end())
			{
				std::cout << *pos << " ";
				pos++;
			}
			std::cout << std::endl;
			system("pause");
			break;

		case 2: // Mostrar el árbol
			std::cout << "Clave-Valor (InOrden): " << std::endl;
			miarbol.InOrden(Mostrar);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			// Estructura
			std::cout << "Info de la estructura" << std::endl;
			std::cout << "N nodos: " << miarbol.NumeroNodos() << std::endl;
			std::cout << "Altura de arbol " << miarbol.AlturaArbol() << std::endl;
			system("pause");
			break;
		}
	} while (opc != 0);

	return 0;
}


