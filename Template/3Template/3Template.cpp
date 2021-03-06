// 3Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T, int length>
class StaticArray
{
public:
	StaticArray()
	{
		size = 0;
	}
	void insert(T item);
	T getElement(int pos);
	void dellete();
	void reverse();
	int totalSize();
	int availableSize();
	void swap(int i, int j);
	friend ostream& operator<<(ostream& out, const StaticArray& list)
	{
		return list.put(out);
	}

private:
	ostream& put(ostream& out) const;
	T list[length];
	int size;
};

template<typename T, int length>
void StaticArray<T, length>::insert(T item)
{
	if (size == length)
		throw exception("Lista llena");
	int i = size - 1;
	list[i + 1] = item;
	size++;
}

template<typename T, int length>
void StaticArray<T, length>::dellete()
{
	if (size == 0)
		throw exception("Lista vacia");
	int i = size - 1;
	list[i]=NULL;
	size--;
}

template<typename T, int length>
T StaticArray<T, length>::getElement(int pos)
{
	if (size == 0)
		throw exception("Lista vacia");
	if (pos >= size )
		throw exception("Indice erroneo");
	return list[pos];
}

template<typename T, int length>
ostream& StaticArray<T, length>::put(ostream& out) const
{
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;
	return out;
}
template<typename T, int length>
void StaticArray<T, length>::reverse()
{
	T aux;
	for (int i = 0; i<size / 2; i++)
	{
		aux = list[i];
		list[i] = list[size - 1 - i];
		list[size - 1 - i] = aux;
	}
}

template<typename T, int length>
int StaticArray<T, length>::totalSize()
{
	return size;
}

template<typename T, int length>
int StaticArray<T, length>::availableSize()
{
	return (size - length);
}

template<typename T, int length>
void StaticArray<T, length>::swap(int i, int j)
{
	T aux= list[i];
	list[i] = list[j];
	list[j] = aux;

}
int main()
{
	int values[] = { 5, 1, 7, 8, 11, 2 };
	StaticArray<int, 10> list;
	for (int i = 0; i < 6; i++)
		list.insert(values[i]);
	cout << "Elementos: " << list;
	list.dellete();
	cout << "Elimino el ultimo: " << list;
	cout << "Posicion dos: " << list.getElement(2) << endl;
	list.reverse(); 
	cout << "Invertidos: " << list << endl;
	cout << "Total Size(): " << list.totalSize() << endl;
	cout << "Available Size(): " << list.availableSize() << endl;
	cout << "Swap(0,2): ";
	list.swap(0, 2);
	cout << "Elementos: " << list;
	system("pause");
	return 0;
}
