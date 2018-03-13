#include "StdAfx.h"
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int andBinario(int x, int y)
{
	return (x & y);
}
int orBinario(int x, int y)
{
	return (x | y);
}
int derechaBinario(int x)
{
	int y = 1;
	int z = x >> y;
	return z;
}
int izquierdaBinario(int x)
{
	int y = 1;
	unsigned long z = x << y;
	return z;
}
void aBinario(int x)
{
	bool fin = false;
	cout << "Valor :" << x << ".......";
	int binario[100];
	int i = 0, j = 0, k=0, r = 0;
	for (i = 99; i>=0; i--)
	{
		binario[i] = x % 2;
		x = x / 2;
	}
	for (i = 1; i < 100; i++)
	{
		if (binario[i] == 1)
		{
			r = 16 - (100 - i); // Cantidad de espacios adelante
			for (k = 0; k < r; k++)
			{
				//printf("%0d",0);
				printf("%c", 32);
			}
			for (j = i; j < 100; j++)
			{
				printf("%0d", binario[j]);
				r++;
			}
			break;
		}
	}
}
std::string num(int i)
{
	//   int to string en c++
	std::string num;
	int temp;
	while (i / 10 != 0) {
		temp = i % 10;
		i = i / 10;
		temp = temp + 48;
		num = (char)temp + num;

	}
	i = i + 48;
	num = (char)i + num;
	return num;
}