// TP3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <iostream>
#include"SizeOf64.h"
#include"crudVector64.h"
#include"dataType64.h"
#include"numericLimits64.h"
#include"unsignedResult64.h"
using namespace std;

short svar;
int ivar;
float fvar;
double dvar;
long lvar;
long long llvar;
size_t stvar;
char cvar = 65;
//
int a = 0xFFFFFFFF;
unsigned int b = 0xFFFFFFFF;

int main()
{
	int opc = 0;
	do {
		system("cls");
		cout << "X64" << endl;
		cout << "Seleccione la opcion (0-Salir) :" << endl;
		cout << "1-SizeOf en diferentes arquitectura" << endl;
		cout << "2-Char 65 en diferentes formatos" << endl;
		cout << "3-Limites numericos" << endl;
		cout << "4-Imprimir variables a y b" << endl;
		cout << "5-Array" << endl;
		cin >> opc;
		system("cls");
		switch (opc) {
		case 0:
			break;

		case 1:
			showSize(svar, ivar, fvar, dvar, lvar, llvar, stvar);
			system("pause");
			break;

		case 2:
			showDataType(cvar);
			system("pause");
			break;

		case 3:
			numericLimits(svar, ivar, fvar, dvar, lvar, llvar, stvar);
			system("pause");
			break;

		case 4:
			unsignedResult(a, b);
			system("pause");
			break;

		case 5:
			crudVector();
			system("pause");
			break;
		}
	} while (opc != 0);
	return 0;
}
