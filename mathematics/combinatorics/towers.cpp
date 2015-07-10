//towers.cpp
//Towers
//Weekly Challenges - Week 10
//Author: derekhh

#include<iostream>
#include<cstring>
using namespace std;

const int MOD = 1000000007;

struct Type
{
	int val[15][15];
} mat;

Type mul(Type a, Type b)
{
	Type ret;
	memset(ret.val, 0, sizeof(ret.val));
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			for (int k = 0; k < 15; k++)
				ret.val[i][j] = (ret.val[i][j] + (long long) a.val[i][k] * b.val[k][j]) % MOD;
	return ret;
}

Type pow(Type a, long long n)
{
	Type ret;
	memset(ret.val, 0, sizeof(ret.val));
	for (int i = 0; i < 15; i++)
		ret.val[i][i] = 1;
	while (n != 0)
	{
		if (n % 2 == 1)
			ret = mul(ret, a);
		a = mul(a, a);
		n /= 2;
	}
	return ret;
}

int main()
{
	long long n, k;
	cin >> n >> k;
	memset(mat.val, 0, sizeof(mat.val));
	for (int i = 0; i < k; i++)
	{
		int h;
		cin >> h;
		mat.val[0][h - 1] = 1;
	}
	for (int i = 1; i <= 14; i++)
		mat.val[i][i - 1] = 1;
	Type ret = pow(mat, n);
	cout << (ret.val[0][0] * 2) % MOD << endl;
	return 0;
}