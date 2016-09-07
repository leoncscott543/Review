// String Bubble Sort.cpp : Defines the entry point for the console application.
// Sorting the Alphabet

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string array[26] = { "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "a", "s", "d", "f", "g", "h", "j", "k", "l", "z", "x", "c", "v", "b", "n", "m" };
	// this is our array that has the alpha bet in the order the it appears on my keyboard

	string save;
	// I created a string called save that will be used later on to help switch elements within the array

	bool sort;
	// This boolean variable is used to check whether or not the array is finished sorting to save time complexity and avoid reading all the way through a sorted array mulitple times

	cout << "Unsorted: " << endl;
	// this is just interface stuff

	for (int i = 0; i < 26; i++) // we just print out the previous array just to compare nd contrast later on
	{

		cout << array[i];

		if (i != 25)
		{
			cout << ", ";
		}
	}

	cout << endl << endl;
	// interfacing/organization 

	for ( int i = 0; i < 26; i++ )
	// this loop loops the nested loop below
	{
		sort = false;
		// we set and reset sort to false each time the nested loop is finsihed looping to recalibrate the checking boolean variable

		for (int i = 0; i < 26 - 1; i++)
		// this is the nested loop that passes over each element in the array
		{
			if (array[i + 1] < array[i])
			// this conditional checks if the element in array[i+1] is less than array[i]. IF it is, they need to switch. 
			// Although they are comparing strings, the enumeration for strings are still chronilogical and integers
			{
				sort = true;
				// we set sort boolean variable to true so that we know a sort was made in this iteration

				// this switches the elements
				save = array[i];
				array[i] = array[i + 1];
				array[i + 1] = save;
			}

		}

		if (sort = false)
		// if the sort boolean variable is still false, then there was no sort made in the previous loop, which means the array is sorted, and we may exit the Bubble sort
		{
			goto End;
			// this takes us to the end
		}
	}

End:
	cout << endl << "Sorted: " << endl;
	// interface/organization stuff

	for (int i = 0; i < 26; i++)
		// finally we print out the SORTED alphabet array
	{

		cout << array[i];

		if (i != 25)
			// this just makes sure we dont have a comma at the end
		{
			cout << ", ";
		}
	}

	cout << endl << endl << "Thanks for your time!!!";


	char f;
	cin >> f;
	return 0;
}

