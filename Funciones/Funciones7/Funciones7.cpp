// Funciones7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
void f(int) { std::cout << "f(int) \n"; }
void f(double) { std::cout << "f(double) \n"; }

int main()
{
	char a = 'a';
	f(a);
	system("pause");
	return 0;
}



