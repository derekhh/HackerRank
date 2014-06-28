#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include<limits>
#include<cfloat>
using namespace std;

const int MAXN = 300 + 1;

double a[MAXN][MAXN], x[MAXN], g[MAXN], nx[MAXN], tmp[MAXN];

double eval(int n, double x[])
{
	double ret = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ret += x[i] * x[j] * a[i][j];
	return ret;
}

double ans;
double bestx[MAXN];

void foo(int n)
{
	double score = eval(n, x);
	int test = 100;
	while (test--)
	{
		double best = DBL_MIN;
		int bestidx = 0;
		for (int i = 1; i <= n; i++)
		{
			double tmp = score;
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
					tmp -= 4 * a[i][j] * x[i] * x[j];
			}

			if (tmp > best)
			{
				best = tmp;
				bestidx = i;
			}
		}

		if (best <= score)
			break;

		score = best;
		x[bestidx] = -x[bestidx];
	}

	if (score > ans)
	{
		ans = score;
		memcpy(bestx, x, sizeof(x));
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	ans = DBL_MIN;

	int test = 100;
	while (test--)
	{
		for (int i = 1; i <= n; i++)
		{
			int rnd = rand();
			if (1.0 * rnd / RAND_MAX > 0.5)
				x[i] = -1;
			else
				x[i] = 1;
		}
		foo(n);
	}

	for (int i = 1; i <= n; i++)
		cout << bestx[i] << " ";
	cout << endl;

	return 0;
}