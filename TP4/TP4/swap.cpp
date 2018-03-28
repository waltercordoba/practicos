#include "stdafx.h"
void swap(int *p1, int *p2) 
{
	int aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}
void swap(int &p1, int &p2) 
{
	int aux1 = p1;
	p1 = p2;
	p2 = aux1;
}