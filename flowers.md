# Flowers

**Difficulty: Easy**
**Required Knowledge: Sorting**
**Time Complexity: O(N log N)**

Approach:

It is easy to see the more flowers a customer has already bought, the more additional dollars one needs to pay to purchase this flower. Therefore, we need to ensure is we try our best to "evenly distribute" the flowers between these K people. 

Another thing we need to optimize is the order in which we purchase these flowers. Since the amount of additional money we need to pay later is linear in c<sub>i</sub>, so if we have already bought x flowers, the natural expectation is we would hope the next flower we need to buy is as cheap as possible.

Based on the above two observations, we know that we first need to sort the price of flowers in decreasing order and then distribute these flowers evenly amongst our friends. 

My code follows:

```C++
//flowers.cpp
//Flowers
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;

int c[100];

int main()
{
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n, greater<int>());
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		ans += c[i] * (cnt / k + 1);
		cnt++;
	}
	cout << ans << endl;
	return 0;
}
``` 