// Funciones8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
const int size = 10;
int array[size]; //{ 40, 20, 30 }

void llenar(int *p, const int size)
{
	srand(time(NULL));
	int random_number;

	for (int i = 0; i < size; i++)
	{
		random_number = std::rand(); // rand() return a number between ​0​ and RAND_MAX
		p[i] = 1 + (rand() % (101 - 1));
	}
}

void ver(int *p, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << p[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void burbuja(int *ele, const int size)
{
	int temp;
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (ele[j] > ele[j + 1])
			{
				temp = ele[j];
				ele[j] = ele[j + 1];
				ele[j + 1] = temp;
			}
		}
	}
}



int main()
{
	int* p = array; 
	llenar(p, size);
	std::cout << "Antes" << std::endl;
	ver(p, size);
	burbuja(p, size);
	std::cout << "Despues burbuja" << std::endl;
	ver(p, size);
	system("pause");
    return 0;
}