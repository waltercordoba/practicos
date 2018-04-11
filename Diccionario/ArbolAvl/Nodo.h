#pragma once
class AVL;
#include"Singleword.h"
#include<string>
#include <list>
// Clase Nodo de Arbol AVL:
class Nodo {
public:
	// Constructor:
	Nodo(const std::string dat, Nodo *pad = NULL, Nodo *izq = NULL, Nodo *der = NULL, std::string palabra=NULL) :
		dato(dat), padre(pad), izquierdo(izq), derecho(der), FE()
	{
		FE = 0;
		palabras.push_back(palabra);
	}
	~Nodo();
	const std::string getDato();
	const int getFE();
	const Nodo * getIzquierdo();
	const Nodo * getDerecho();
	const Nodo * getPadre();
	const std::list <std::string> getPalabras();
	// Miembros:
private:
	std::string dato;
	int FE;
	Nodo *izquierdo;
	Nodo *derecho;
	Nodo *padre;
	std::list <std::string> palabras;
	friend class AVL;
};

