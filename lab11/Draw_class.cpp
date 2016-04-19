#include "stdafx.h"
#include <iostream>
#include "Draw_class.h"

using namespace std;

void Draw_class::drawTree(char ornament)
{
	int space = 0, row = 0, s = 0;
	cout << endl;
	for (int i = size; i>0; i--)
	{
		space = size - row;
		for (int k = 0; k<space; k++)
		{
			if (space - k == 1)
				cout << ornament;
			else
				cout << " ";
		}
		for (int j = 0; j <= row + s; j++)
		{
			cout << getBranch();
			int tmp = i;
			if (tmp + j== row + size)
				cout << ornament;
		}
		s++;
		row++;
		cout << "\n";
	}
	for (int i = 0; i < size-2; i++)
		cout << " ";
	cout << "|   |\n";
	for (int i = 0; i < size-2; i++)
		cout << " ";
	cout << "|_ _|\n\n";
	cout << endl;
}