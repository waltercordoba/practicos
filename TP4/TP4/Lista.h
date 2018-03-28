#pragma once
#include"Nodo.h"
class Lista {
private:
	Nodo * miNodo;
public:
	Lista::Lista();
	void Lista::addElement(int p_dato);
	void toList();
};