//gneck.cpp
//Girlfriend & Necklace
//Weekly Challenges - Week 8
//Author: derekhh

#include<iostream>
#include<cstring>
using namespace std;

const int MOD = 1000000007;

struct Matrix
{
	long long val[3][3];
	int row, col;
};

Matrix m, b;

Matrix mul(Matrix a, Matrix b)
{
	Matrix ret;
	ret.row = a.row;
	ret.col = b.col;
	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < b.col; j++)
		{
			ret.val[i][j] = 0;
			for (int k = 0; k < a.col; k++)
				ret.val[i][j] = (ret.val[i][j] + a.val[i][k] * b.val[k][j]) % MOD;
		}
	}
	return ret;
}

Matrix pow(long long n)
{
	Matrix ret;
	ret.row = ret.col = 3;
	memset(ret.val, 0, sizeof(ret.val));
	ret.val[0][0] = ret.val[1][1] = ret.val[2][2] = 1;
	Matrix cur = m;
	while (n)
	{
		if (n % 2) ret = mul(ret, cur);
		cur = mul(cur, cur);
		n /= 2;
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;

	b.row = 3;
	b.col = 1;
	memset(b.val, 0, sizeof(b.val));
	b.val[0][0] = b.val[1][0] = b.val[2][0] = 1;

	while (t--)
	{
		long long n;
		cin >> n;

		m.row = 3; m.col = 3;
		memset(m.val, 0, sizeof(m.val));
		m.val[0][0] = 1; 
		m.val[0][1] = 1; 
		m.val[1][2] = 1; 
		m.val[2][0] = 1;

		Matrix ans_m = mul(pow(n - 2), b);
		long long ans = 0;
		for (int i = 0; i < 3; i++)
			ans = (ans + ans_m.val[i][0]) % MOD;
		cout << ans << endl;
	}
	return 0;
}