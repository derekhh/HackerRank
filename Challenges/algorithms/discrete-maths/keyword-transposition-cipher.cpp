//keyword-transposition-cipher.cpp
//Keyword Transposition Cipher
//Algorithms - Discrete Mathematics
//Author: derekhh

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

char grid[20][20];
string str;

bool cmp(int a, int b)
{
	return grid[0][a] < grid[0][b];
}

int mapping[26], reversemap[26];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		bool used[26];
		memset(used, false, sizeof(used));
		memset(grid, 0, sizeof(grid));
		cin >> str;
		int len = (int)str.size(), ncol = 0;
		int order[10];
		for (int i = 0; i < len; i++)
			order[i] = i;
		for (int i = 0; i < len; i++)
		{
			if (!used[str[i] - 'A'])
			{
				used[str[i] - 'A'] = true;
				grid[0][ncol++] = str[i];
			}
		}
		sort(order, order + ncol, cmp);
		int nrow = 1, col = 0;
		for (int i = 0; i < 26; i++)
		{
			if (!used[i])
			{
				used[i] = true;
				grid[nrow][col++] = i + 'A';
				if (col == ncol)
				{
					nrow++;
					col = 0;
				}
			}
		}
		int cur = 0;
		for (int i = 0; i < ncol; i++)
			for (int j = 0; j <= nrow;j++)
				if (grid[j][order[i]] != 0)
				{
					mapping[cur++] = grid[j][order[i]];
					reversemap[grid[j][order[i]] - 'A'] = cur - 1;
				}

		getchar();
		string line;
		getline(cin, line);
		int sz = (int)line.size();
		for (int i = 0; i < sz; i++)
			if (line[i] >= 'A' && line[i] <= 'Z')
				cout << (char)(reversemap[line[i] - 'A'] + 'A');
			else
				cout << line[i];
		cout << endl;
	}
	return 0;
}