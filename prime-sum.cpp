//prime-sum.cpp
//Prime Sum
//Weekly Challenges - Week 3
//Author: derekhh

#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;

// k >= 3
bool Judge(long long n, long long k)
{
	if (n >= 4)
	{
		if (n % 2 == 0) return k <= n / 2;
		else return (k - 1) <= (n - 3) / 2;
	}
	return false;
}

long long modmult(long long a, long long b, long long mod)
{
	if (a == 0 || b < mod / a)
		return (a*b) % mod;
	long long sum;
	sum = 0;
	while (b>0)
	{
		if (b & 1)
			sum = (sum + a) % mod;
		a = (2 * a) % mod;
		b >>= 1;
	}
	return sum;
}

long long modpow(long long a, long long b, long long mod)
{
	long long product, pseq;
	product = 1;
	pseq = a%mod;
	while (b>0)
	{
		if (b & 1)
			product = modmult(product, pseq, mod);
		pseq = modmult(pseq, pseq, mod);
		b >>= 1;
	}
	return product;
}

bool MillerRabin(long long n, int seed)
{
	int k = 0;
	if (n < 2) return false;
	if (n == 2) return true;
	if (!(n & 1)) return false;

	long long m = n - 1;
	while (!(m & 1)) m >>= 1, k++;

	long long a = seed;
	a = modpow(a, m, n);
	if (a == 1 || a == n - 1) return true;
	
	for (int j = 0; j < k - 1; j++)
	{
		a = modpow(a, 2, n);
		if (a == 1) return false;
		if (a == n - 1) return true;
	}
	return false;
}

const int MAXN = 1000000;
bool isprime[MAXN + 10];

void Sieve()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 2; i*i <= MAXN; i++)
		if (isprime[i])
			for (int j = 2 * i; j <= MAXN; j += i)
				isprime[j] = false;
}

bool PrimalityTest(long long n)
{
	if (n <= MAXN)
		return isprime[n];
	else
		return MillerRabin(n, 2) && MillerRabin(n, 13) && MillerRabin(n, 23) && MillerRabin(n, 1662803);
}

int main()
{
	time_t start = clock();
	Sieve();
	int t;
	cin >> t;
	while (t--)
	{
		long long n, k;
		cin >> n >> k;
		if (k > 2)
			cout << (Judge(n, k) ? "Yes" : "No") << endl;
		else if (k == 2)
		{
			if (n % 2 == 0) cout << (n > 2 ? "Yes" : "No") << endl;
			else cout << (PrimalityTest(n - 2) ? "Yes" : "No") << endl;
		}
		else cout << (PrimalityTest(n) ? "Yes" : "No") << endl;
	}
	cerr << difftime(clock(), start) << endl;
	return 0;
}