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
// Insertar un dato en el �rbol AVL
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
		// Buscar el dato en el �rbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
		return;
	}
	// Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
	// el nodo raiz
	if (Vacio(padre))
	{
		raiz = new Nodo(dat, NULL, NULL, NULL, palabra);
		// Buscar el dato en el �rbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
		return;
	}
	// Si el dato es menor que el que contiene el nodo padre, lo insertamos
	// en la rama izquierda
	if (dat < padre->dato) 
	{
		padre->izquierdo = new Nodo(dat, padre, NULL, NULL, palabra);
		Equilibrar(padre, IZQUIERDO, true);
		// Buscar el dato en el �rbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
		return;
	}
	// Si el dato es mayor que el que contiene el nodo padre, lo insertamos
	// en la rama derecha
	if (dat > padre->dato) 
	{
		padre->derecho = new Nodo(dat, padre, NULL, NULL, palabra);
		Equilibrar(padre, DERECHO, true);
		// Buscar el dato en el �rbol, manteniendo un puntero al nodo padre
		std::cout << "Inserta: " << palabra << " en nodo " << dat << std::endl;
	}
}

// Equilibrar �rbol AVL partiendo del nodo nuevo
void AVL::Equilibrar(Nodo *nodo, int rama, bool nuevo)
{
	bool salir = false;

	// Recorrer camino inverso actualizando valores de FE:
	while (nodo && !salir) {
		if (nuevo)
			if (rama == IZQUIERDO) nodo->FE--; // Depende de si a�adimos ...
			else                  nodo->FE++;
		else
			if (rama == IZQUIERDO) nodo->FE++; // ... o borramos
			else                  nodo->FE--;
			if (nodo->FE == 0) salir = true; // La altura de las rama que
											 // empieza en nodo no ha variado,
											 // salir de Equilibrar
			else if (nodo->FE == -2) { // Rotar a derechas y salir:
				if (nodo->izquierdo->FE == 1) RDD(nodo); // Rotaci�n doble
				else RSD(nodo);                         // Rotaci�n simple
				salir = true;
			}
			else if (nodo->FE == 2) {  // Rotar a izquierdas y salir:
				if (nodo->derecho->FE == -1) RDI(nodo); // Rotaci�n doble
				else RSI(nodo);                        // Rotaci�n simple
				salir = true;
			}
			if (nodo->padre)
				if (nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
			nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
	}
}

// Rotaci�n doble a derechas
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

	// Reconstruir �rbol:
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

// Rotaci�n doble a izquierdas
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

	// Reconstruir �rbol:
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

// Rotaci�n simple a derechas
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

	// Reconstruir �rbol:
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

// Rotaci�n simple a izquierdas
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

	// Reconstruir �rbol:
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

// Eliminar un elemento de un �rbol AVL
void AVL::Borrar(const std::string dat)
{
	Nodo *padre = NULL;
	Nodo *nodo;
	std::string aux;

	actual = raiz;
	// Mientras sea posible que el valor est� en el �rbol
	while (!Vacio(actual)) {
		if (dat == actual->dato) { // Si el valor est� en el nodo actual
			if (EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
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
			else { // Si el valor est� en el nodo actual, pero no es hoja
				   // Buscar nodo
				padre = actual;
				// Buscar nodo m�s izquierdo de rama derecha
				if (actual->derecho) {
					nodo = actual->derecho;
					while (nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}
				// O buscar nodo m�s derecho de rama izquierda
				else {
					nodo = actual->izquierdo;
					while (nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				// Intercambiar valores de no a borrar u nodo encontrado
				// y continuar, cerrando el bucle. El nodo encontrado no tiene
				// por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
				// de que s�lo se eliminan nodos hoja.
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		}
		else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
			padre = actual;
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
}

// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
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

// Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PreOrden(void(*func)(std::string&, int), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	func(nodo->dato, nodo->FE);
	if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PostOrden(void(*func)(std::string&, int), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PostOrden(func, nodo->derecho, false);
	func(nodo->dato, nodo->FE);
}

// Buscar un valor en el �rbol
bool AVL::Buscar(const std::string dat)
{
	actual = raiz;

	// Todav�a puede aparecer, ya que quedan nodos por mirar
	while (!Vacio(actual)) {
		if (dat == actual->dato) return true; // dato encontrado
		else if (dat > actual->dato) actual = actual->derecho; // Seguir
		else if (dat < actual->dato) actual = actual->izquierdo;
	}
	return false; // No est� en �rbol
}

// Calcular la altura del nodo que contiene el dato dat
int AVL::Altura(const std::string dat)
{
	int altura = 0;
	actual = raiz;

	// Todav�a puede aparecer, ya que quedan nodos por mirar
	while (!Vacio(actual)) {
		if (dat == actual->dato) return altura; // dato encontrado
		else {
			altura++; // Incrementamos la altura, seguimos buscando
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
	return -1; // No est� en �rbol
}

// Contar el n�mero de nodos
const int AVL::NumeroNodos()
{
	contador = 0;

	auxContador(raiz); // FUnci�n auxiliar
	return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void AVL::auxContador(Nodo *nodo)
{
	contador++;  // Otro nodo
				 // Continuar recorrido
	if (nodo->izquierdo) auxContador(nodo->izquierdo);
	if (nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
const int AVL::AlturaArbol()
{
	altura = 0;

	auxAltura(raiz, 0); // Funci�n auxiliar
	return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual
void AVL::auxAltura(Nodo *nodo, int a)
{
	// Recorrido postorden
	if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1);
	if (nodo->derecho)   auxAltura(nodo->derecho, a + 1);
	// Proceso, si es un nodo hoja, y su altura es mayor que la actual del
	// �rbol, actualizamos la altura actual del �rbol
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
	return NULL; // No est� en �rbol
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