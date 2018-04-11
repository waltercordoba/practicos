#pragma once
#include"Nodo.h"
#include<string>
#include <iostream>

class AVL {
private:
	enum { IZQUIERDO, DERECHO };
	// Punteros de la lista, para cabeza y nodo actual:
	Nodo *raiz;
	Nodo *actual;
	int contador;
	int altura;

public:
	// Constructor y destructor básicos:
	AVL() : raiz(NULL), actual(NULL) {}
	~AVL() { Podar(raiz); }
	// Insertar en árbol ordenado:
	void Insertar(const std::string dat, std::string palabra, bool sinDuplicados);
	// Borrar un elemento del árbol:
	void Borrar(const std::string dat);
	// Función de búsqueda:
	bool Buscar(const std::string dat);
	// Comprobar si el árbol está vacío:
	bool Vacio(Nodo *r) { return r == NULL; }
	bool VacioL(Singleword *r) { return r == NULL; }
	// Comprobar si es un nodo hoja:
	bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
	// Contar número de nodos:
	const int NumeroNodos();
	const int AlturaArbol();
	// Calcular altura de un dato:
	int Altura(const std::string dat);
	// Devolver referencia al dato del nodo actual:
	std::string &ValorActual() { return actual->dato; }
	// Moverse al nodo raiz:
	void Raiz() { actual = raiz; }
	// Aplicar una función a cada elemento del árbol:
	void InOrden(void(*func)(std::string&, int), Nodo *nodo = NULL, bool r = true);
	void PreOrden(void(*func)(std::string&, int), Nodo *nodo = NULL, bool r = true);
	void PostOrden(void(*func)(std::string&, int), Nodo *nodo = NULL, bool r = true);
	// Funciones de equilibrado:
	void Equilibrar(Nodo *nodo, int, bool);
	void RSI(Nodo* nodo);
	void RSD(Nodo* nodo);
	void RDI(Nodo* nodo);
	void RDD(Nodo* nodo);
	// Funciones auxiliares
	void auxContador(Nodo*);
	void auxAltura(Nodo*, int);
	Nodo * buscarNodo(const std::string dat, int & visitas);
	std::list<std::string> buscarKeys(const std::string dat);
	void Podar(Nodo* &);
};