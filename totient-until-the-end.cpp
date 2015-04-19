//totient-until-the-end.cpp
//Totient Until The End
//Ad Infinitum 11 - Math Programming Contest
//By derekhh
//Apr 18, 2015

//Reference
//An Arithmetic Function Arising From the Phi function
//Harold Shapiro, Princeton University, The American Mathematical Monthly, 1943

#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 2000000;
bool isprime[MAXN + 1];
int eulerphi[MAXN + 1], f[MAXN + 1], factor[MAXN + 1];

void init()
{
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;

	for (int i = 1; i <= MAXN; i++)
		eulerphi[i] = i;

	for (int i = 2; i <= MAXN; i++)
	{
		if (isprime[i])
		{
			factor[i] = i;
			for (int j = i + i; j <= MAXN; j += i)
			{
				factor[j] = i;
				isprime[j] = false;
			}
		}
	}
	
	for (int i = 1; i <= MAXN;i++)
	{
		if (isprime[i])
		{
			for (int j = i; j <= MAXN; j += i)
			{
				eulerphi[j] -= eulerphi[j] / i;
			}
		}
	}

	// f is the C function in the paper
	f[1] = f[2] = 0;
	for (int i = 3; i <= MAXN; i++)
		f[i] = f[eulerphi[i]] + 1;
}

int base[4], power[4];

long long foo()
{
	int nEven = 0;
	long long ans = 0;

	for (int i = 0; i < 4; i++)
	{
		if (base[i] % 2 == 0)
			nEven++, ans--;

		// Theorem 2 and 3
		while (base[i] % 2 == 0)
		{
			ans += power[i];
			base[i] /= 2;
		}

		// Theorem 5
		while (base[i] != 1)
		{
			if (factor[base[i]] != 2)
				ans += power[i] * f[factor[base[i]]];
			base[i] /= factor[base[i]];
		}
	}
	
	// Theorem 1
	if (nEven >= 1)
		ans += nEven - 1;

	// C function is defined on phi*(n) = 2 and in this problem we need phi*(n) = 1
	ans++;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	init();
	int t;
	cin >> t;
	while (t--)
	{
		bool baseAllOne = true;
		for (int i = 0; i < 4; i++)
		{
			cin >> base[i] >> power[i];
			if (base[i] == 1)
				power[i] = 1;
			else
				baseAllOne = false;
		}

		if (baseAllOne)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << foo() << endl;
		}
	}
	return 0;
}