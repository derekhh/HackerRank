//guessing-numbers.cpp
//Guessing Numbers
//Addepar Hackathon
//Author: derekhh

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

double p[200000];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	double win = 0;
	sort(p, p + n, greater<double>());
	for (int i = 0; i < min((1 << k) - 1, n); i++)
		win += p[i];
	printf("%.8lf\n", win);
	return 0;
}