// 116_UnidirectionalTSP_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
int F(int i, int m);
int main()
{
	int rows, columns;
	int A[10][100];
	int memo[10][100] = { 9999999 };
	bool checked[10][100] = { false };
	
	while (std::cin >> rows >> columns)
	{
		int minCost = INFINITY;
		int start;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				std::cin >> A[i][j];

		for (int i = 0; i < rows; i++)
		{

		}
			
	}
	
    return 0;
}

int F(int i, int m)
{
	if (i == -1)
		return m - 1;
	if (i == m)
		return 0;
	return i;
}

//For example, using the natural order of the integers, the lexicographical ordering on the subsets of three elements of S = {1, 2, 3, 4, 5, 6} is
// 123 < 124 < 125 < 126 < 134 < 135 < 136 < 145 < 146 < 156 <
//	234 < 235 < 236 < 245 < 246 < 256 < 345 < 346 < 356 < 456.
