//filling-jars.cpp
//Algorithms - Warmup
//Author: derekhh

#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	while (m--)
	{
		int a, b, k;
		cin >> a >> b >> k;
		ans += (b - a + 1)*(long long)k;
	}
	cout << ans / n << endl;
}