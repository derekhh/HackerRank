//coin-on-the-table.cpp
//Coin on the Table
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<cstring>
using namespace std;

char map[52][52];
int best[52][52][1001];
int n, m, k;

void update(int row, int col, int time, int val)
{
	if (row < 0 || row >= n) return;
	if (col < 0 || col >= m) return;
	if (time > k) return;

	if (val < best[row][col][time] || best[row][col][time] == -1)
	{
		best[row][col][time] = val;

		if (map[row][col] != '*')
		{
			update(row, col + 1, time + 1, val + (map[row][col] != 'R'));
			update(row, col - 1, time + 1, val + (map[row][col] != 'L'));
			update(row - 1, col, time + 1, val + (map[row][col] != 'U'));
			update(row + 1, col, time + 1, val + (map[row][col] != 'D'));
		}
		else
		{
			update(row, col, time + 1, val);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	int r, c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
				r = i, c = j;
		}
	memset(best, -1, sizeof(best));
	update(0, 0, 0, 0);
	cout << best[r][c][k] << endl;
	return 0;
}