# Triplets

Let's consider a simplified version of the original problem. Instead of counting the number of *distinct* ascending triples, let's count the number of ascending tuples first.

So the problem here is very easy. For each number a[i], we only need to know how many numbers before a[i] are smaller than this number. Many data structures can support this type of query but for this problem I would recommend [Fenwick tree](http://en.wikipedia.org/wiki/Fenwick_tree). You may also check this [TopCoder tutorial page](http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees) to learn more about this data structure.

In short, a Fenwick tree can support two types of operations in logarithmic time complexity. One is to add a number x to a particular number a[i]. The other is to query the sum of numbers from a[1] to a[i].

Therefore, the number of integers smaller than a[i] is equal to a query operation in the Fenwick tree for the range [1..i-1]. So we've solved the "simplified version" within O(NlogN) time.

How should we extend this solution to the original problem? We now create three Fenwick trees. For the first Fenwick tree T1, T1[i] == 1 indicates there exists a number i in the array; for the second tree T2, T2[i] indicates the number of ascending tuples ending with i; for the third tree T3, T3[i] indicates the number of ascending triplets ending with i. Now we can see there are connections between T1 and T2 and T3. The value of T2[i] equals to  the sum of T1[1] to T1[i]. Similarly, the value of T3[i] equals to the sum of T2[1] to T2[i].

My code follows:

```C++
//triplets.cpp
//Triplets
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
using namespace std;

const int MAXN = 100000;
int v[MAXN], h[MAXN];
set<int> s;
map<int, int> m;

class FenwickTree
{
private:
	long long tree[MAXN];

public:
	FenwickTree()
	{
		memset(tree, 0, sizeof(tree));
	}

	long long get(int idx)
	{
		return query(idx) - query(idx - 1);
	}

	void set(int idx, long long val)
	{
		long long curr = get(idx);
		update(idx, val - curr);
	}

	void update(int idx, long long val)
	{
		while (idx <= MAXN)
		{
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}

	long long query(int idx)
	{
		long long sum = 0;
		while (idx > 0)
		{
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
};

FenwickTree a, b, c;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s.insert(v[i]);
	}
	int cnt = 1;
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
		m.insert(make_pair(*it, cnt++));
	for (int i = 0; i < n; i++)
	{
		h[i] = m[v[i]];
		a.set(h[i], 1);
		b.set(h[i], a.query(h[i] - 1));
		c.set(h[i], b.query(h[i] - 1));
	}
	cout << c.query(MAXN) << endl;
	return 0;
}
