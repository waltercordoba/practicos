#pragma once
class Nodo { 
private:
	int dato;
	Nodo * siguiente;
	Nodo * anterior;
public:
	void setDato(int p_dato);
	int getDato();
	void setSiguiente(Nodo * p_siguiente);
	Nodo * getSiguiente();
	Nodo();
	~Nodo();
	void Nodo::setAnterior(Nodo * p_anterior);
	Nodo * Nodo::getAnterior();
};