//manasa-and-pizza.cpp
//Manasa and Pizza
//Ad Infinitum - Math Programming Contest June'14
//Author: derekhh

#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 3, MOD = 1000000007;

struct Matrix
{
	int v[MAXN][MAXN], row, col;
};

Matrix add(Matrix a, Matrix b)
{
	Matrix ans;
	ans.row = a.row, ans.col = a.col;
	for (int i = 1; i <= a.row; i++)
		for (int j = 1; j <= a.col; j++)
			ans.v[i][j] = (a.v[i][j] + b.v[i][j]) % MOD;
	return ans;
}

Matrix mul(Matrix a, Matrix b)
{
	Matrix ans;
	ans.row = a.row, ans.col = b.col;
	for (int i = 1; i <= a.row; i++)
	{
		for (int j = 1; j <= b.col; j++)
		{
			ans.v[i][j] = 0;
			for (int k = 1; k <= a.col; k++)
				ans.v[i][j] = (ans.v[i][j] + (long long)a.v[i][k] * b.v[k][j]) % MOD;
		}
	}
	return ans;
}

Matrix power(Matrix a, long long n)
{
	Matrix res;
	res.row = a.row, res.col = a.col;
	memset(res.v, 0, sizeof(res.v));
	for (int i = 1; i <= a.row; i++)
		res.v[i][i] = 1;
	while (n != 0)
	{
		if (n % 2 == 1)
			res = mul(res, a);
		a = mul(a, a);
		n /= 2;
	}
	return res;
}

long long a[5101];

Matrix f[5101];

int main()
{
	int n;
	cin >> n;

	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	Matrix F;
	F.col = F.row = 2;
	F.v[1][1] = 6;
	F.v[1][2] = MOD - 1;
	F.v[2][1] = 1;
	F.v[2][2] = 0;

	Matrix tmp = power(F, sum - 1);
	Matrix F_base; 
	F_base.row = 2; F_base.col = 1;
	F_base.v[1][1] = 3; F_base.v[2][1] = 1;
	Matrix F_result = mul(tmp, F_base);
	int g0 = F_result.v[1][1];

	tmp = power(F, sum - 2);
	F_result = mul(tmp, F_base);
	int g1 = F_result.v[1][1];

	f[0].row = f[0].col = 2;
	f[0].v[1][1] = f[0].v[2][2] = 1;
	f[0].v[1][2] = f[0].v[2][1] = 0;
	
	for (int i = 1; i <= n; i++)
		f[i] = add(f[i - 1], mul(f[i - 1], power(F, 2 * a[i])));

	Matrix G_base;
	G_base.row = 2; G_base.col = 1;
	G_base.v[1][1] = g1; G_base.v[2][1] = g0;
	Matrix G_result = mul(f[n], G_base);
	cout << G_result.v[2][1] << endl;

	return 0;
}