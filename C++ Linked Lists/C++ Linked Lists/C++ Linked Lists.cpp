// C++ Linked Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	List Leon;
	// creates a new List called Leon
	Leon.AddNode(3); // create node and put 3 in it
	Leon.AddNode(5); // create node and put 5 in it
	Leon.AddNode(7); // create node and put 7 in it
	Leon.AddNode(34); // create node and put 34 in it
	Leon.AddNode(1); // create node and put 1 in it
	Leon.AddNode(24); // create node and put 24 in it
	Leon.PrintList(); // print the List
	Leon.DeleteNode(3); // Detete the node that has 3 in it
	Leon.PrintList(); // print the list again with the deleted 3


	char f;
	cin >> f;
	return 0;
}

