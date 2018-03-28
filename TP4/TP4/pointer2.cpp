#include "stdafx.h"
#include<iostream>
using namespace std;
void pointer2()
{
	cout << "Se ejecuta el codigo con cambios para que de verdadero \n";
	cout << "int *ptr = indice;\n";
	cout << "if ((*ptr * 5) == (*(ptr + 8)))\n\n\n";
	int indice[] = { 1,2,3,4,5,6,7,8,9,10 };
	int *ptr = indice;
	ptr++;
	if ((*ptr * 5) == (*(ptr + 8)))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
}