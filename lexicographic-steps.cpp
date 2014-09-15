//lexicographic-steps.cpp
//Lexicographic paths
//Weekly Challenges - Week 9
//Author: derekhh

#include<cstdio>
using namespace std;

int n, m;
int c[21][21];

void init()
{
	for (int i = 1; i <= 20; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int k;
		scanf("%d%d%d", &n, &m, &k);
		int cx = 0, cy = 0;
		while (cx != n || cy != m)
		{
			int nH = n - cx, nV = m - cy;
			if (nH == 0)
			{
				printf("V");
				cy++;
			}
			else if (nV == 0)
			{
				printf("H");
				cx++;
			}
			else
			{
				int temp = c[nH + nV - 1][nH - 1];
				if (k >= temp && temp > 0)
				{
					printf("V");
					k -= temp;
					cy++;
				}
				else
				{
					printf("H");
					cx++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}