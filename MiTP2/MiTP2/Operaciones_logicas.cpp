#include "StdAfx.h"
void intercambiar(float *x, float *y)
{
	float aux = *x;
	*x = *y;
	*y = aux;
}