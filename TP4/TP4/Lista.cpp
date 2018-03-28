#include "stdafx.h"
#include"Nodo.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<conio.h>
#include"Lista.h"

Lista::Lista() 
{
}
void Lista::addElement(int p_dato)
{
	Nodo * aux, *vistoantes = NULL;
	Nodo * nuevo = new Nodo();
	nuevo->setDato(p_dato);

	if (!miNodo) { // New node depend on root.
		miNodo = nuevo;
		miNodo->setSiguiente(NULL);
		miNodo->setSiguiente(NULL);
		std::cout << "Agregado en la raiz \n";
		return;
	}
	aux = miNodo;
	while (aux) // Reccorre hasta el final de la lista
	{
		vistoantes = aux;
		aux = aux->getSiguiente();
	}
	if (!aux) // LLego al final de la lista e inserta el nodo.
	{
		vistoantes->setSiguiente(nuevo);
		nuevo->setAnterior(vistoantes);
		std::cout << "Agregado al final \n";
	}
}
void Lista::toList()
{
	Nodo * aux = miNodo;
	while ((aux)) // Reccorre hasta el final de la lista
	{
		std::cout << aux->getDato();
		aux = aux->getSiguiente();
		if (aux) 
		{ 
			std::cout << "-"; 
		}
		else
		{
			std::cout << "\n";
		}
	}
}