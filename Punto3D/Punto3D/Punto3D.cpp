// Punto3D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <iomanip>
#include<cassert>
#include"Point.h"
#include"MathUtils.h"

int main()
{
	MathUtils f;
	//
	// Default constructor
	Cpp_math::Point p1;
	assert(f.is_equal(p1.getmX(), 0.0F));
	std::cout << "Assert Constructor por defecto validado \n";
	std::cout << std::fixed << std::setprecision(2) << p1.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p1.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p1.getmZ() << "\n";
	//
	// Constructor with parameters
	Cpp_math::Point p2(3.05f, 2.08f, 1.90f);
	assert(f.is_equal(p2.getmX(), 3.05f));
	assert(f.is_equal(p2.getmY(), 2.08f));
	assert(f.is_equal(p2.getmZ(), 1.90f));
	std::cout << "Assert Constructor con parametros validado \n";
	std::cout << std::fixed << std::setprecision(2) << p2.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p2.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p2.getmZ() << "\n";
	//
	// Copy constructor
	Cpp_math::Point p3(p2);
	assert(f.is_equal(p3.getmX(), 3.05f));
	assert(f.is_equal(p3.getmY(), 2.08f));
	assert(f.is_equal(p3.getmZ(), 1.90f));
	std::cout << "Assert Constructor copia validado \n";
	std::cout << std::fixed << std::setprecision(2) << p3.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p3.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p3.getmZ() << "\n";
	//
	// Operator =
	Cpp_math::Point p4;
	p4 = p2;
	assert(f.is_equal(p4.getmX(), 3.05f));
	assert(f.is_equal(p4.getmY(), 2.08f));
	assert(f.is_equal(p4.getmZ(), 1.90f));
	std::cout << "Assert Operator = validado \n";
	std::cout << std::fixed << std::setprecision(2) << p4.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p4.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p4.getmZ() << "\n";
	//
	// set() / get()
	Cpp_math::Point p5;
	p5.setmX(3.05f);
	p5.setmY(2.08f);
	p5.setmZ(1.90f);
	assert(f.is_equal(p5.getmX(), 3.05f));
	assert(f.is_equal(p5.getmY(), 2.08f));
	assert(f.is_equal(p5.getmZ(), 1.90f));
	std::cout << "Assert sets()  /gets() validado \n";
	std::cout << std::fixed << std::setprecision(2) << p5.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p5.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p5.getmZ() << "\n";
	//
	// getAddition()
	Cpp_math::Point p6(3.00f, 0.0f, 0.11f), p7(1.18f, 9.44f, 2.33f), p8;
	p8 = p6.getAddition(p7);
	assert(f.is_equal(p8.getmX(), 4.18f));
	assert(f.is_equal(p8.getmY(), 9.44f));
	assert(f.is_equal(p8.getmZ(), 2.44f));
	std::cout << "Assert getAddition() validado \n";
	std::cout << std::fixed << std::setprecision(2) << p8.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p8.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p8.getmZ() << "\n";
	//
	// addPoint()
	Cpp_math::Point p9(3.00f, 0.0f, 0.11f), p10(1.18f, 9.44f, 2.33f);
	p9 = p9.add(p10);
	assert(f.is_equal(p9.getmX(), 4.18f));
	assert(f.is_equal(p9.getmY(), 9.44f));
	assert(f.is_equal(p9.getmZ(), 2.44f));
	std::cout << "Assert addPoint() validado \n";
	std::cout << std::fixed << std::setprecision(2) << p9.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p9.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p9.getmZ() << "\n";
	//
	// getSubstraction()
	Cpp_math::Point p11, p12(1.18f, 9.44f, 2.33f), p13(4.18f, 9.44f, 2.44f);
	p11 = p13.getSubtraction(p12);
	assert(f.is_equal(p11.getmX(), 3.00f));
	assert(f.is_equal(p11.getmY(), 0.0f));
	assert(f.is_equal(p11.getmZ(), 0.11f));
	std::cout << "Assert getSubstraction() validado \n";
	std::cout << std::fixed << std::setprecision(2) << p11.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p11.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p11.getmZ() << "\n";
	//
	// substract() 
	Cpp_math::Point p15(3.00f, 0.0f, 0.11f), p14(4.18f, 9.44f, 2.44f);
	p15 = p14.subtract(p15);
	assert(f.is_equal(p15.getmX(), 1.18f));
	assert(f.is_equal(p15.getmY(), 9.44f));
	assert(f.is_equal(p15.getmZ(), 2.33f));
	std::cout << "Assert substract() validado \n";
	std::cout << std::fixed << std::setprecision(2) << p15.getmX() << " ";
	std::cout << std::fixed << std::setprecision(2) << p15.getmY() << " ";
	std::cout << std::fixed << std::setprecision(2) << p15.getmZ() << "\n";
	//
	// distance()
	Cpp_math::Point p16(1.18f, 9.44f, 2.33f), p17(4.18f, 9.44f, 2.44f);
	assert(f.is_equal(p17.distance(p16), 1.76351929f));
	std::cout << "Assert distance() validado \n";
	std::cout << std::fixed << std::setprecision(2) << p17.distance(p16) << "\n";
	//
	system("pause");
	return 0;
}

