// Dynamic Allocating 2.cpp : Defines the entry point for the console application.
// Lets use an initializer with our heaping/dynamic allocating
// Leon Scott 

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	// fancy pants.... declaring pointer, pointing it to a heaped integer, and initializing that integer with 50
	int *ptr = new int(50);

	// oh... and then printing it
	cout << *ptr; 

	char f; 
	cin >> f;
    return 0;
}

