// Funciones11.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////
float segundaFuncion(char a) { return 0.0f; } // "that takes a char argument and returns a float. "
typedef float(*ptrSegunda) (char a);
//////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////
typedef ptrSegunda(*ptrPrimera) (int a); //"Declare a pointer to a function taking an int argument"
ptrSegunda primeraFuncion(int a)		 // "and returning a pointer to a function"

{
	ptrSegunda myPointer;
	myPointer = segundaFuncion;
	return myPointer;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	std::cout << "Declare a pointer to a function taking an ​int argument" << std::endl;
	std::cout << "and returning a pointer to a function " << std::endl;
	std::cout << "that takes a ​char ​​argument and returns a ​float​​. " << std::endl;
	system("pause");
	return 0;
}



