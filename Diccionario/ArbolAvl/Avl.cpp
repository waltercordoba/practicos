#include "stdafx.h"
#include "Avl.h"
#include<iostream>
#include<string>
#include <iostream>
#include <list>

// Poda: borrar todos los nodos a partir de uno, incluido
void AVL::Podar(Nodo* &nodo)
{
	// Algoritmo recursivo, recorrido en postorden
	if (nodo) {
		Podar(nodo->izquierdo); // Podar izquierdo
		Podar(nodo->derecho);   // Podar derecho
		(nodo->palabras).erase((nodo->palabras).begin(), (nodo->palabras).end()); //Elimino lista de palabras
		delete nodo;            // Eliminar nodo
		nodo = NULL;
	}
}
// Insertar un dato en el árbol AVL
void AVL::Insertar(const std::string dat, std::string palabra, bool sinDuplicados)
{
	Nodo *padre = NULL;

	actual = raiz;

	while (!Vacio(actual) && dat != actual->dato) {
		padre = actual;
		if (dat > actual->dato) actual = actual->derecho;
		else if (dat < actual->dato) actual = actual->izquierdo;
	}
	// Si se ha encontrado el key, agrega la palabra al final de la lista
	if (!Vacio(actual)) // Agrega a la lista
	{
		///
		std::list<std::string>::iterator pos;
		pos = (actual->palabras).begin();
		while (pos != (actual->palabras).end())
		{
			if ((*pos == palabra) && sinDuplicados)
			{
				return;
			}
			pos++;
		}
		///
		(actual->palabras).push_back(palabra);
		// Buscar el dato en el árbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
		return;
	}
	// Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
	// el nodo raiz
	if (Vacio(padre))
	{
		raiz = new Nodo(dat, NULL, NULL, NULL, palabra);
		// Buscar el dato en el árbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
		return;
	}
	// Si el dato es menor que el que contiene el nodo padre, lo insertamos
	// en la rama izquierda
	if (dat < padre->dato) 
	{
		padre->izquierdo = new Nodo(dat, padre, NULL, NULL, palabra);
		Equilibrar(padre, IZQUIERDO, true);
		// Buscar el dato en el árbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
		return;
	}
	// Si el dato es mayor que el que contiene el nodo padre, lo insertamos
	// en la rama derecha
	if (dat > padre->dato) 
	{
		padre->derecho = new Nodo(dat, padre, NULL, NULL, palabra);
		Equilibrar(padre, DERECHO, true);
		// Buscar el dato en el árbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
	}
}

// Equilibrar árbol AVL partiendo del nodo nuevo
void AVL::Equilibrar(Nodo *nodo, int rama, bool nuevo)
{
	bool salir = false;

	// Recorrer camino inverso actualizando valores de FE:
	while (nodo && !salir) {
		if (nuevo)
			if (rama == IZQUIERDO) nodo->FE--; // Depende de si añadimos ...
			else                  nodo->FE++;
		else
			if (rama == IZQUIERDO) nodo->FE++; // ... o borramos
			else                  nodo->FE--;
			if (nodo->FE == 0) salir = true; // La altura de las rama que
											 // empieza en nodo no ha variado,
											 // salir de Equilibrar
			else if (nodo->FE == -2) { // Rotar a derechas y salir:
				if (nodo->izquierdo->FE == 1) RDD(nodo); // Rotación doble
				else RSD(nodo);                         // Rotación simple
				salir = true;
			}
			else if (nodo->FE == 2) {  // Rotar a izquierdas y salir:
				if (nodo->derecho->FE == -1) RDI(nodo); // Rotación doble
				else RSI(nodo);                        // Rotación simple
				salir = true;
			}
			if (nodo->padre)
				if (nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
			nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
	}
}

// Rotación doble a derechas
void AVL::RDD(Nodo* nodo)
{
	std::cout << "Rotacion doble derecha" << "\n";
	Nodo *Padre = nodo->padre;
	Nodo *P = nodo;
	Nodo *Q = P->izquierdo;
	Nodo *R = Q->derecho;
	Nodo *B = R->izquierdo;
	Nodo *C = R->derecho;

	if (Padre)
		if (Padre->derecho == nodo) Padre->derecho = R;
		else Padre->izquierdo = R;
	else raiz = R;

	// Reconstruir árbol:
	Q->derecho = B;
	P->izquierdo = C;
	R->izquierdo = Q;
	R->derecho = P;

	// Reasignar padres:
	R->padre = Padre;
	P->padre = Q->padre = R;
	if (B) B->padre = Q;
	if (C) C->padre = P;

	// Ajustar valores de FE:
	switch (R->FE) {
	case -1: Q->FE = 0; P->FE = 1; break;
	case 0:  Q->FE = 0; P->FE = 0; break;
	case 1:  Q->FE = -1; P->FE = 0; break;
	}
	R->FE = 0;
}

// Rotación doble a izquierdas
void AVL::RDI(Nodo* nodo)
{
	std::cout << "Rotacion doble izquierda" << "\n";
	Nodo *Padre = nodo->padre;
	Nodo *P = nodo;
	Nodo *Q = P->derecho;
	Nodo *R = Q->izquierdo;
	Nodo *B = R->izquierdo;
	Nodo *C = R->derecho;

	if (Padre)
		if (Padre->derecho == nodo) Padre->derecho = R;
		else Padre->izquierdo = R;
	else raiz = R;

	// Reconstruir árbol:
	P->derecho = B;
	Q->izquierdo = C;
	R->izquierdo = P;
	R->derecho = Q;

	// Reasignar padres:
	R->padre = Padre;
	P->padre = Q->padre = R;
	if (B) B->padre = P;
	if (C) C->padre = Q;

	// Ajustar valores de FE:
	switch (R->FE) {
	case -1: P->FE = 0; Q->FE = 1; break;
	case 0:  P->FE = 0; Q->FE = 0; break;
	case 1:  P->FE = -1; Q->FE = 0; break;
	}
	R->FE = 0;
}

// Rotación simple a derechas
void AVL::RSD(Nodo* nodo)
{
	std::cout << "Rotacion simple derecha" << "\n";
	Nodo *Padre = nodo->padre;
	Nodo *P = nodo;
	Nodo *Q = P->izquierdo;
	Nodo *B = Q->derecho;

	if (Padre)
		if (Padre->derecho == P) Padre->derecho = Q;
		else Padre->izquierdo = Q;
	else raiz = Q;

	// Reconstruir árbol:
	P->izquierdo = B;
	Q->derecho = P;

	// Reasignar padres:
	P->padre = Q;
	if (B) B->padre = P;
	Q->padre = Padre;

	// Ajustar valores de FE:
	P->FE = 0;
	Q->FE = 0;
}

// Rotación simple a izquierdas
void AVL::RSI(Nodo* nodo)
{
	std::cout << "Rotacion simple izquierda" << "\n";
	Nodo *Padre = nodo->padre;
	Nodo *P = nodo;
	Nodo *Q = P->derecho;
	Nodo *B = Q->izquierdo;

	if (Padre)
		if (Padre->derecho == P) Padre->derecho = Q;
		else Padre->izquierdo = Q;
	else raiz = Q;

	// Reconstruir árbol:
	P->derecho = B;
	Q->izquierdo = P;

	// Reasignar padres:
	P->padre = Q;
	if (B) B->padre = P;
	Q->padre = Padre;

	// Ajustar valores de FE:
	P->FE = 0;
	Q->FE = 0;
}

// Eliminar un elemento de un árbol AVL
void AVL::Borrar(const std::string dat)
{
	Nodo *padre = NULL;
	Nodo *nodo;
	std::string aux;

	actual = raiz;
	// Mientras sea posible que el valor esté en el árbol
	while (!Vacio(actual)) {
		if (dat == actual->dato) { // Si el valor está en el nodo actual
			if (EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
				if (padre) // Si tiene padre (no es el nodo raiz)
						   // Anulamos el puntero que le hace referencia
					if (padre->derecho == actual) padre->derecho = NULL;
					else if (padre->izquierdo == actual) padre->izquierdo = NULL;
					delete actual; // Borrar el nodo
					actual = NULL;
					// El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
					// FE es cero, pero debemos seguir el camino a partir de su padre, si existe.
					if ((padre->derecho == actual && padre->FE == 1) ||
						(padre->izquierdo == actual && padre->FE == -1)) {
						padre->FE = 0;
						actual = padre;
						padre = actual->padre;
					}
					if (padre)
						if (padre->derecho == actual) Equilibrar(padre, DERECHO, false);
						else                         Equilibrar(padre, IZQUIERDO, false);
						return;
			}
			else { // Si el valor está en el nodo actual, pero no es hoja
				   // Buscar nodo
				padre = actual;
				// Buscar nodo más izquierdo de rama derecha
				if (actual->derecho) {
					nodo = actual->derecho;
					while (nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}
				// O buscar nodo más derecho de rama izquierda
				else {
					nodo = actual->izquierdo;
					while (nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				// Intercambiar valores de no a borrar u nodo encontrado
				// y continuar, cerrando el bucle. El nodo encontrado no tiene
				// por qué ser un nodo hoja, cerrando el bucle nos aseguramos
				// de que sólo se eliminan nodos hoja.
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		}
		else { // Todavía no hemos encontrado el valor, seguir buscándolo
			padre = actual;
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::InOrden(void(*func)(std::string&, int), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) InOrden(func,nodo->izquierdo, false);
	std::cout << std::endl << nodo->dato << " ";
	// Reccorro la lista 
	std::list<std::string>::iterator pos;
	pos = (nodo->palabras).begin();
	
	while (pos != (nodo->palabras).end())
	{
		std::cout << *pos;
		if ((nodo->palabras).size() > 1)
		{
			std::cout << " ";
		}
		pos++;
	}
	///
	if (nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PreOrden(void(*func)(std::string&, int), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	func(nodo->dato, nodo->FE);
	if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PostOrden(void(*func)(std::string&, int), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PostOrden(func, nodo->derecho, false);
	func(nodo->dato, nodo->FE);
}

// Buscar un valor en el árbol
bool AVL::Buscar(const std::string dat)
{
	actual = raiz;

	// Todavía puede aparecer, ya que quedan nodos por mirar
	while (!Vacio(actual)) {
		if (dat == actual->dato) return true; // dato encontrado
		else if (dat > actual->dato) actual = actual->derecho; // Seguir
		else if (dat < actual->dato) actual = actual->izquierdo;
	}
	return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el dato dat
int AVL::Altura(const std::string dat)
{
	int altura = 0;
	actual = raiz;

	// Todavía puede aparecer, ya que quedan nodos por mirar
	while (!Vacio(actual)) {
		if (dat == actual->dato) return altura; // dato encontrado
		else {
			altura++; // Incrementamos la altura, seguimos buscando
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
	return -1; // No está en árbol
}

// Contar el número de nodos
const int AVL::NumeroNodos()
{
	contador = 0;

	auxContador(raiz); // FUnción auxiliar
	return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void AVL::auxContador(Nodo *nodo)
{
	contador++;  // Otro nodo
				 // Continuar recorrido
	if (nodo->izquierdo) auxContador(nodo->izquierdo);
	if (nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int AVL::AlturaArbol()
{
	altura = 0;

	auxAltura(raiz, 0); // Función auxiliar
	return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void AVL::auxAltura(Nodo *nodo, int a)
{
	// Recorrido postorden
	if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1);
	if (nodo->derecho)   auxAltura(nodo->derecho, a + 1);
	// Proceso, si es un nodo hoja, y su altura es mayor que la actual del
	// árbol, actualizamos la altura actual del árbol
	if (EsHoja(nodo) && a > altura) altura = a;
}
Nodo * AVL::buscarNodo(const std::string dat, int & visitas)
{
	actual = raiz;
	while (!Vacio(actual)) {
		visitas++;
		if (dat == actual->dato)
			return actual; // dato encontrado
		else if (dat > actual->dato) actual = actual->derecho; // Seguir
		else if (dat < actual->dato) actual = actual->izquierdo;
	}
	return NULL; // No está en árbol
}
std::list <std::string> AVL::buscarKeys(const std::string dat)
{
	int visitas = 0;
	std::list <std::string> aux;
	Nodo * actual = buscarNodo(dat, visitas);
	if (!Vacio(actual)) {
		std::cout << "Nodos recorridos :" << visitas << std::endl;
		return actual->getPalabras();
	}
	else
	{
		return aux;
	}
}