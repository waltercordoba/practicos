#include "stdafx.h"
#include"Nodo.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<conio.h>

Nodo::Nodo() {}
Nodo::~Nodo()
{
	Nodo * aux = this;
	if (!(aux->siguiente)) // List has'nt nodes, Delete root without next nodes.
	{
		delete this;
		return;
	}
	while (aux->siguiente) // Go to the end list.
	{
		aux = aux->siguiente;
	}
	while (aux->anterior) // Go to the end list.
	{
		delete aux->siguiente;
		aux = aux->anterior;
	}
	delete this;
}
void Nodo::setDato(int p_dato)
{
	dato = p_dato;
}
int Nodo::getDato()
{
	return dato;
}
void Nodo::setSiguiente(Nodo * p_siguiente)
{
	siguiente = p_siguiente;
}
Nodo * Nodo::getSiguiente()
{
	return siguiente;
}
void Nodo::setAnterior(Nodo * p_anterior)
{
	anterior = p_anterior;
}
Nodo * Nodo::getAnterior()
{
	return anterior;
}