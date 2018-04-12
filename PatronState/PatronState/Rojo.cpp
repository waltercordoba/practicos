#include "stdafx.h"
#include "Rojo.h"
#include "Verde.h"

Rojo::Rojo()
{
}

Rojo::Rojo(Context* context) : _context(context) {}

void Rojo::Handle(int estado)
{
	if (estado == 3)
	{
		printf("Actual roja, cambia a verde \n");
		State* aux = _context->getState();
		_context->setState(new Verde(_context));
		delete aux;
	}
	else
	{
		printf("Cambio incorrecto, actual rojo \n");
	}
}
 
Rojo::~Rojo()
{
}

