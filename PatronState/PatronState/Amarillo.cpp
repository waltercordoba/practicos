#include "stdafx.h"
#include "Amarillo.h"
#include"Rojo.h"
#include<iostream>

Amarillo::Amarillo()
{
}
Amarillo::Amarillo(Context* context) : _context(context) {}

void Amarillo::Handle(int estado)
{
	if (estado == 2)
	{
		printf("Actual amarilla, cambio a Roja \n");
		State* aux = _context->getState();
		_context->setState(new Rojo(_context));
		delete aux;
	}
	else
	{
		printf("Cambio incorrecto, actual amarilla \n");
	}
}

Amarillo::~Amarillo()
{
}
