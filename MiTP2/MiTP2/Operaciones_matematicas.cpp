#include "StdAfx.h"
#define PI 3.14
float cuadrado(float x)
{
	return (x*x);
}
float suma(float x, float y)
{
	return (x+y);
}
float areaCirculo(float radio)
{
	return (PI * radio * radio);
}
float max(float x, float y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}