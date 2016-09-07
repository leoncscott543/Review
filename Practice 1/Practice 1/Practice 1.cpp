// Practice 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>	

using namespace std;

int multiply (int a);

int main()
{
	int b;

	cout << "What is the number that is getting multiplied by: ";
		cin >> b; 

		cout << endl << "2 * " << b << " = " << multiply(b);

		char f; 
		cin >> f;
    return 0;
}

int multiply(int a)
{
	return a * 2; 
}
