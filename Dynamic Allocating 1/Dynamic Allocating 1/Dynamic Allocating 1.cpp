// Dynamic Allocating 1.cpp : Defines the entry point for the console application.
// Going over dynamic allocation properties with pointers and (new) 

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	// create a pointer variable
	int *ptr; 

	// assign pointer variable's address to a (new) or (dynamically allocated) varaible on the heap 
	ptr = new int; 

	// set derefferenced pointer equal to 10
	*ptr = 10;

	// print out the derefferenced pointer aka the (new) variable's contents
	cout << *ptr;

	char f;
	cin >> f;
    return 0;
}

