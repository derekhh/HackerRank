//chief-hopper.cpp
//Chief Hopper
//Weekly Challenges - Week 12
//Author: derekhh

#include<iostream>
using namespace std;

int h[100001];

int main()
{
	int n;
	cin >> n;
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		if (h[i] > max)
			max = h[i];
	}
	int lo = 0, hi = max, mid;
	while (hi > lo)
	{
		mid = (lo + hi) >> 1;
		double energy = mid;
		for (int i = 1; i <= n; i++)
		{
			if (h[i] > energy)
				energy -= (h[i] - energy);
			else
				energy += (energy - h[i]);

			if (energy < 0)
				break;
		}

		if (energy < 0)
			lo = mid + 1;
		else
			hi = mid;
	}
	cout << lo << endl;
	return 0;
}