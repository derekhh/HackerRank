//bst-maintenance.cpp
//BST maintenance
//Daily Challenges - Week 1
//Author: derekhh

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int val, numNode, depth;
	long long heightSum;
	Node* left;
	Node* right;
	Node* parent;
};

Node* root;

long long sumdist;

void Insert(int val)
{
	if (root == NULL)
	{
		root = new Node;
		root->val = val;
		root->heightSum = 0;
		root->numNode = 1;
		root->depth = 0;
		root->left = root->right = NULL;
		root->parent = NULL;
	}
	else
	{
		Node* cur = root;
		Node* tmp;
		
		vector<Node*> v;
		v.clear();

		while (true)
		{
			if (cur->val < val)
			{
				if (cur->right == NULL)
				{
					tmp = cur;
					cur->right = new Node;

					if (cur->left != NULL)
						v.push_back(cur->left);

					cur = cur->right;
					break;
				}
				else
				{
					if (cur->left != NULL)
						v.push_back(cur->left);
					cur = cur->right;
				}
			}
			else
			{
				if (cur->left == NULL)
				{
					tmp = cur;
					cur->left = new Node;
					
					if (cur->right != NULL)
						v.push_back(cur->right);

					cur = cur->left;
					break;
				}
				else
				{
					if (cur->right != NULL)
						v.push_back(cur->right);
					cur = cur->left;
				}
			}
		}

		cur->val = val;
		cur->heightSum = 0;
		cur->numNode = 1;
		cur->left = cur->right = NULL;
		cur->parent = tmp;
		cur->depth = tmp->depth + 1;
		long long leafdepth = cur->depth;
		sumdist += (leafdepth)* (leafdepth + 1) / 2;

		int height = 1;
		cur = cur->parent;
		while (cur != NULL)
		{
			cur->heightSum += height;
			cur->numNode++;
			cur = cur->parent;
			height++;
		}

		int num = (int)v.size();
		for (int i = 0; i < num; i++)
			sumdist += v[i]->heightSum + (long long)v[i]->numNode * (leafdepth - v[i]->depth + 2);
	}
}

void Traverse(Node* cur)
{
	if (cur != NULL)
	{
		printf("val: %d, heightSum: %lld, numNode: %d, depth:%d\n", cur->val, cur->heightSum, cur->numNode, cur->depth);
		Traverse(cur->left);
		Traverse(cur->right);
	}
}

int a[250000];

bool IsSpecial(int a[], int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == i + 1)
			cnt++;
	if (cnt == n) return true;
	cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == n - i)
			cnt++;
	if (cnt == n) return true;
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (IsSpecial(a, n))
	{
		for (int i = 0; i < n; i++)
			printf("%lld\n", (long long)i * (i + 1) * (i + 2) / 6);
	}
	else
	{
		sumdist = 0;
		for (int i = 0; i < n; i++)
		{
			Insert(a[i]);
			printf("%lld\n", sumdist);
		}
	}
	return 0;
}