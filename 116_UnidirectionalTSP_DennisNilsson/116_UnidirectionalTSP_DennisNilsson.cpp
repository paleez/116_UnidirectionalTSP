// 116_UnidirectionalTSP_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int rows, columns;
int MAZE[30][110];
int COST[30][110];
int PATH[30][110];
int start = 0;

int main()
{
	while (std::cin >> rows >> columns)
	{
		for (auto i = 1; i <= rows; i++)
		{
			for (auto j = 1; j <= columns; j++)
			{
				std::cin >> MAZE[i][j];
			}
		}
		for (auto i = 1; i <= rows; i++)
		{
			for (auto j = 1; j <= columns; j++)
			{
				COST[i][j] = 214325437;
			}
		}
		
		for (int i = 1; i <= rows; i++)
		{
			COST[i][columns] = MAZE[i][columns];
		}
		for (int j = columns; j > 1; j--)
		{
			for (int i = 1; i <= rows; i++)
			{
				int row[3] = { i - 1, i, i + 1 };
				if (i == 1) row[0] = rows;
				if (i == rows) row[2] = 1;
				std::sort(row, row + 3); //lexiographic
				for (int x = 0; x < 3; x++)
				{
					int tmp = COST[i][j] + MAZE[row[x]][j - 1];
					if (tmp < COST[row[x]][j - 1])
					{
						COST[row[x]][j - 1] = tmp;
						PATH[row[x]][j - 1] = i;
					}
				}
			}
		}
		int minCostPath = 214325437;
		for (int i = 1; i <= rows; i++)
		{
			if (minCostPath > COST[i][1])
			{
				start = i;
				minCostPath = COST[i][1];
			}
		}
		printf("%d", start);
		for (int path = PATH[start][1], j = 1; j < columns; j++, path = PATH[path][j])
		{
			printf(" %d", path);
		}
		printf("\n%d\n", minCostPath);
	}
	return 0;
}
