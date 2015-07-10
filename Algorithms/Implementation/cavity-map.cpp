//cavity-map.cpp
//Cavity Map
//101 Hack July'14
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

string map[110];
bool marked[110][110];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n;

bool valid(int tx, int ty)
{
	return 0 <= tx && tx < n && 0 <= ty && ty < n;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val = map[i][j] - '0';
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int ti = i + dx[k];
				int tj = j + dy[k];
				if (valid(ti, tj) && val > map[ti][tj] - '0')
					cnt++;
			}
			if (cnt == 4)
				cout << 'X';
			else
				cout << map[i][j];

			if (j == n - 1)
				cout << endl;
		}
	}

}