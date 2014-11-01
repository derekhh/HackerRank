//strange-numbers.cpp
//Strange numbers
//Weekly Challenges - Week 11
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

set<unsigned long long> s;
unsigned long long q[500];
int head, tail;

int lenDigit(unsigned long long num)
{
	int digits = 0; 
	do 
	{ 
		num /= 10; 
		digits++; 
	} while (num != 0);
	return digits;
}

int main()
{
	const long long upperBound = 1000000000000000000LL;
	head = tail = 0;
	for (int i = 0; i <= 9; i++)
	{
		q[tail++] = i;
		s.insert(i);
	}
	while (head < tail)
	{
		unsigned long long num = q[head++];
		int len = lenDigit(num);
		for (int i = len; i <= len + 2; i++)
		{
			unsigned long long candidate = num * i;
			if (s.find(candidate) == s.end() && lenDigit(candidate) == i && candidate <= upperBound)
			{
				q[tail++] = candidate;
				s.insert(candidate);
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		unsigned long long l, r;
		cin >> l >> r;
		cout << count_if(q, q + tail, [l, r](unsigned long long i) {return i >= l && i <= r; }) << endl;
	}
	return 0;
}