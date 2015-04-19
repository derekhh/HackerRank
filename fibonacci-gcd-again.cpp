//fibonacci-gcd-again.cpp
//Fibonacci GCD Again
//Ad Infinitum 11 - Math Programming Contest
//By derekhh
//Apr 18, 2015

/*
Denote F_N as F, F_{N+1} as G.
We want to calculate (aF + a'G, bF + b'G).
Using Euclid's algorithm,
gcd(aF + a'G, bF + b'G) = gcd(xF + yG, zF)

Let gcd(xF + yG, F) = g
gcd(xF + yG, zF)
= g * gcd((xF + yG) / g, zF / g)

Since gcd(xF + yG, F) = g, we know that
gcd((xF + yG) / g, F / g) = 1

g * gcd((xF + yG) / g, zF / g)
= g * gcd((xF + yG) / g, z)
= gcd(xF + yG, zg)
= gcd(xF mod zg + yG mod zg, zg)

gcd(xF + yG, F)
= gcd(yG, F)
= gcd(y, F) (since gcd(F, G) = 1)
= gcd(y, F mod y)
*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

const int MAXN = 2;
int modulo;

struct Matrix
{
	int v[MAXN][MAXN], row, col;
	Matrix() {}
	Matrix(int r, int c) : row(r), col(c) {}
};

Matrix mul(Matrix& a, Matrix& b)
{
	Matrix ans(a.row, b.col);
	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < b.col; j++)
		{
			ans.v[i][j] = 0;
			for (int k = 0; k < a.col; k++)
				ans.v[i][j] = (ans.v[i][j] + static_cast<long long>(a.v[i][k]) * b.v[k][j]) % modulo;
		}
	}
	return ans;
}

Matrix power(Matrix a, long long n)
{
	Matrix res(a.row, a.col);

	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < a.col; j++)
			res.v[i][j] = 0;
		res.v[i][i] = 1;
	}

	while (n)
	{
		if (n & 1)
			res = mul(res, a);
		a = mul(a, a);
		n >>= 1;
	}

	return res;
}

int main()
{
	Matrix fib_base(2, 2);
	fib_base.v[0][0] = fib_base.v[0][1] = fib_base.v[1][0] = 1; fib_base.v[1][1] = 0;

	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		long long N;
		int a0, a1, a2, b0, b1, b2, M;
		cin >> N >> a0 >> a1 >> a2 >> b0 >> b1 >> b2 >> M;
		int a = a0 + a2, a_prime = a1 + a2;
		int b = b0 + b2, b_prime = b1 + b2;

		if (a_prime == 0)
		{
			swap(a, b);
			swap(a_prime, b_prime);
		}

		while (b_prime != 0)
		{
			if (a_prime > b_prime)
			{
				int times = a_prime / b_prime;
				if (a_prime % b_prime == 0) times--;
				a -= times * b;
				a_prime -= times * b_prime;
			}
			else
			{
				int times = b_prime / a_prime;
				b -= times * a;
				b_prime -= times * a_prime;
			}
		}

		if (b == 0)
		{
			//aF + a'G mod M
			modulo = M;
			Matrix fib_pow_n = power(fib_base, N);
			int ans = (a * static_cast<long long>(fib_pow_n.v[1][0]) + a_prime * static_cast<long long>(fib_pow_n.v[0][0])) % M;
			cout << ans << endl;
		}

		else
		{
			int z = abs(b);
			if (a < 0) a = z - (-a) % z;
			int x = abs(a), y = a_prime;

			if (y == 0)
			{
				modulo = M;
				Matrix fib_pow_n = power(fib_base, N);
				int ans = gcd(x, z) * static_cast<long long>(fib_pow_n.v[1][0]) % M;
				cout << ans << endl;
			}

			else
			{
				modulo = y;
				Matrix fib_pow_n = power(fib_base, N);
				int g = gcd(y, fib_pow_n.v[1][0]);	//gcd(y, F mod y)

				//gcd(xF mod zg + yG mod zg, zg)
				modulo = z * g;
				fib_pow_n = power(fib_base, N);
				int t1 = x * static_cast<long long>(fib_pow_n.v[1][0]) % modulo; // xF mod zg
				int t2 = y * static_cast<long long>(fib_pow_n.v[0][0]) % modulo; // yG mod zg
				int ans = gcd(t1 + t2, z * g);
				cout << ans % M << endl;
			}
		}
	}
	return 0;
}