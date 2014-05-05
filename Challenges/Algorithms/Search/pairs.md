# Pairs

The first observation we can make is we don't need to enumerate all N^2 pairs and then check whether the pairs of integers have a difference of K.

What we only need to do is for each integer N, we check whether the original array consist of N-K and N+K. In fact, we can iterate over each number N in the original array and check whether N+K exists in the same array. So basically we need a data structure supporting fast membership inquiry. 

Two of the most popular data structures supporting this operation are [Binary search tree](http://en.wikipedia.org/wiki/Binary_search_tree) and [hash table](http://en.wikipedia.org/wiki/Hash_table). The former supports O(logN) time complexity for membership inquiry and the latter can answer membership queries within expected O(1) time complexity.

Most programming languages already support these data structures in their library functions. For example, if you want to use a binary search tree in C++, you can use STL [set](http://www.cplusplus.com/reference/set/set/); if you want to use a hash table in C++, you could turn to [unordered_set](http://www.cplusplus.com/reference/unordered_set/unordered_set/) for help. 

My code follows. It is easy to test the performance of both set and unordered_set and you can see that unordered_set does run faster than set, which in turn validates the advantage over time complexity.

```C++
//Pairs.cpp
//Pairs
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<int> s;

int main()
{
	int n, k, val;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		s.insert(val);
	}
	int ans = 0;
	for (unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it)
		if (s.find(*it + k) != s.end()) ans++;
	cout << ans << endl;
	return 0;
}
```