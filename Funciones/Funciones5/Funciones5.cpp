// Funciones5.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<iostream>
using std::cout;
using std::endl;

void f(int&) { cout << "A \n"; }
void f(const int&) { cout << "B \n"; }

int main()
{
	int i = 10;
	const int ci = 11;
	f(i);
	f(ci);
	system("pause");
	return 0;
}



