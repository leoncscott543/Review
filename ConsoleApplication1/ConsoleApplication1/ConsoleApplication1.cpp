// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "stdafx.h"
#include <iostream>

using namespace std;

#include <string>
#include <math.h>
	int main()
	{
		string word[26];

		word[26] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

		int i = 0;
		string a;

		for (int c = 0; c < 26; c++)
		{
			while (i < 26)
			{
				i++;

				if (word[i] < word[i + 1])
				{
					a = word[i + 1];
					word[i + 1] = word[i];
					word[i] = a;
				}
			}
		}

		for (int i = 0; i < 26; i++)
		{
			cout << word[i] << "  ";
		}

		char f;
		cin >> f;

    return 0;
}

