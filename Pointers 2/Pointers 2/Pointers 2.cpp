// Pointers 2.cpp : Defines the entry point for the console application.
// Working with some more pointers

#include "stdafx.h"
#include <iostream>

using namespace std;

int add(int b)
{
	cout << endl << b;
	int *p2;
	p2 = &b;

	*p2 = *p2+1;

		if (*p2 < 21)
		{
			add(b);
		}
		else
			return NULL;
}
int main()
{
	int a = 10;

	int *p;

	p = &a;

	cout << "Dereferenced pointer: " << *p;
	cout << endl << endl << "Address being pointed to: " << p;
	cout << endl << endl << "Address of the pointer itself: " << &p;

	cout << endl << endl << "Adding one to the pointer: ";

	add(a);

	char f;
	cin >> f;
    return 0;
}


