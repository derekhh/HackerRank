//sherlock-and-array.cpp
//Sherlock and Array

#include<iostream>
#include<cstring>
using namespace std;

int a[100000], sum[100000];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i == 0) sum[i] = a[i];
			else sum[i] = sum[i - 1] + a[i];
		}
		if (n == 1)
			cout << "YES" << endl;
		else if (n == 2)
			cout << "NO" << endl;
		else
		{
			bool flag = false;
			for (int i = 1; i < n; i++)
			{
				if (sum[i - 1] == sum[n - 1] - sum[i])
				{
					flag = true;
					break;
				}
			}
			cout << (flag ? "YES" : "NO") << endl;
		}
	}
	return 0;
}