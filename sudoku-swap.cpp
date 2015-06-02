//sudoku-swap.cpp
//Sudoku Swap
//Author: derekhh
//May 26, 2015

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int sudoku[9][9];

bool valid(int sudoku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		bool flag[10];
		memset(flag, 0, sizeof(flag));
		for (int j = 0; j < 9; j++)
		{
			if (flag[sudoku[i][j]])
				return false;
			flag[sudoku[i][j]] = true;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		bool flag[10];
		memset(flag, 0, sizeof(flag));
		for (int j = 0; j < 9; j++)
		{
			if (flag[sudoku[j][i]])
				return false;
			flag[sudoku[j][i]] = true;
		}
	}

	for (int x = 0, y = 0; x < 9 && y < 9;)
	{
		bool flag[10];
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < 9;i++)
		{
			int xx = x + i / 3;
			int yy = y + i % 3;
			if (flag[sudoku[xx][yy]])
				return false;
			flag[sudoku[xx][yy]] = true;
		}
		y = (y + 3) % 9;
		if (y == 0) x += 3;
	}

	return true;
}

int main()
{
	int t, kase = 0;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 9;i++)
		{
			for (int j = 0; j < 9; j++)
				scanf("%d", &sudoku[i][j]);
		}

		printf("Case #%d:\n", ++kase);
		if (valid(sudoku))
			printf("Serendipity\n");

		else
		{
			int r1 = -1, r2 = -1, c1 = -1, c2 = -1;
			for (int i = 0; i < 9; i++)
			{
				bool flag[10];
				memset(flag, 0, sizeof(flag));
				for (int j = 0; j < 9; j++)
				{
					if (flag[sudoku[i][j]])
					{
						if (r1 == -1)
							r1 = r2 = i;
						else
							r2 = i;
					}
					flag[sudoku[i][j]] = true;
				}
			}

			for (int i = 0; i < 9; i++)
			{
				bool flag[10];
				memset(flag, 0, sizeof(flag));
				for (int j = 0; j < 9; j++)
				{
					if (flag[sudoku[j][i]])
					{
						if (c1 == -1)
							c1 = c2 = i;
						else
							c2 = i;
					}
					flag[sudoku[j][i]] = true;
				}
			}
			//printf("%d %d %d %d\n", r1, c1, r2, c2);

			if (r1 == -1)
			{
				for (int i = 0; i < 9; i++)
				{
					bool flag = false;
					for (int j = 0; j < 9; j++)
					{
						if (j == i) continue;
						if (sudoku[i][c1] == sudoku[j][c1])
						{
							flag = true;
							break;
						}
					}
					if (flag)
					{
						swap(sudoku[i][c1], sudoku[i][c2]);
						if (valid(sudoku))
							printf("(%d,%d) <-> (%d,%d)\n", i + 1, c1 + 1, i + 1, c2 + 1);
						swap(sudoku[i][c1], sudoku[i][c2]);
					}
				}
			}

			else if (c1 == -1)
			{
				for (int i = 0; i < 9; i++)
				{
					bool flag = false;
					for (int j = 0; j < 9; j++)
					{
						if (j == i) continue;
						if (sudoku[r1][i] == sudoku[r1][j])
						{
							flag = true;
							break;
						}
					}
					if (flag)
					{
						swap(sudoku[r1][i], sudoku[r2][i]);
						if (valid(sudoku))
							printf("(%d,%d) <-> (%d,%d)\n", r1 + 1, i + 1, r2 + 1, i + 1);
						swap(sudoku[r1][i], sudoku[r2][i]);
					}
				}
			}

			else
			{
				swap(sudoku[r1][c1], sudoku[r2][c2]);
				if (valid(sudoku))
					printf("(%d,%d) <-> (%d,%d)\n", r1 + 1, c1 + 1, r2 + 1, c2 + 1);
				swap(sudoku[r1][c1], sudoku[r2][c2]);

				swap(sudoku[r1][c2], sudoku[r2][c1]);
				if (valid(sudoku))
					printf("(%d,%d) <-> (%d,%d)\n", r1 + 1, c2 + 1, r2 + 1, c1 + 1);
				swap(sudoku[r1][c2], sudoku[r2][c1]);

			}
		}
	}
	return 0;
}