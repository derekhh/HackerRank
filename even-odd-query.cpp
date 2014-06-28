//even-odd-query.cpp
//Even Odd Query
//Weekly Challenges - Week 5
//Author: derekhh

#include<iostream>
using namespace std;

int A[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if ((x + 1 <= n) && (A[x + 1] == 0) && (x != y))
			cout << "Odd" << endl;
		else
			cout << (A[x] % 2 == 0 ? "Even" : "Odd") << endl;
	}
	return 0;
}