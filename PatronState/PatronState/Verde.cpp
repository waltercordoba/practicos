#include "stdafx.h"
#include "Verde.h"
#include "Amarillo.h"

Verde::Verde()
{
}

Verde::Verde(Context* context) : _context(context) {}

void Verde::Handle(int estado)
{
	if (estado == 1)
	{
		printf("Actual verde, cambia a Amarilla \n");
		State* aux = _context->getState();
		_context->setState(new Amarillo(_context));
		delete aux;
	}
	else
	{
		printf("Cambio incorrecto, actual verde \n");
	}
}

Verde::~Verde()
{
}