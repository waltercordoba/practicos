#include "stdafx.h"
#include "Nodo.h"
#include <string>

Nodo::~Nodo() {}

const std::string Nodo::getDato()
{
	return dato;
}

const int Nodo::getFE()
{
	return FE;
}

const Nodo * Nodo::getIzquierdo()
{
	return izquierdo;
}

const Nodo * Nodo::getDerecho()
{
	return derecho;
}

const Nodo * Nodo::getPadre()
{
	return padre;
}

const std::list<std::string> Nodo::getPalabras()
{
	return this->palabras;
}
