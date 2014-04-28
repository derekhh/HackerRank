//MaximizingXOR.cpp
//Daily Challenges - Week 1
//Author: derekhh

#include<iostream>
using namespace std;

int main()
{
	int l, r;
	int ans = 0;
	cin >> l >> r;
	bool flag = false;
	for (int i = 30; i >= 0; i--)
	{
		int val1 = l & (1 << i);
		int val2 = r & (1 << i);
		if (val1 != val2)
			flag = true;
		if (flag)
			ans |= (1 << i);
	}
	cout << ans << endl;
	return 0;
}