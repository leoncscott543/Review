// Pointers 2.cpp : Defines the entry point for the console application.
// Working with some more pointers

#include "stdafx.h"
#include <iostream>

using namespace std;

// here comes the func, this is sweet
void add(int b)
{
	cout << endl << b; // print the value of b at the beginning of every progression through the function
	int *p2; // initialize the pointer variable p2
	p2 = &b; // point p2 to b's address

	*p2 = *p2+1; // adding 1 to b's value every time we progress through the function

		if (*p2 < 21) // this is a recursive conditinoal statement 
		{
			add(b); // call the function add and pass the current value for b
		}
		else
			return; // return nothing at the end of the loop 
}

int main()
{
	int a = 10; // create and set varaible a to 10

	int *p; // creating a pointer variable aptley called "p"

	p = &a; // point p to a's address. 

	cout << "Dereferenced pointer: " << *p; // printing the value p is pointing to
	cout << endl << endl << "Address being pointed to: " << p; // print address being pointed to by p
	cout << endl << endl << "Address of the pointer itself: " << &p; // print pointer p's address

	cout << endl << endl << "Adding one to the pointer: "; // print'n stuff

	add(a); // calling the add() function we made above, and passing varaible (a) 

	
	char f;
	cin >> f;
    return 0;
}


