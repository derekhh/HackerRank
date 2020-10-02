//sansa-and-xor.cpp
//Sansa and XOR
//Weekly Challenges - Week 9
//Author: derekhh

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
    {
        int n,x;
        cin>>n;
        as(n,1,100000);
        int val = 0;
        for(int i=1 ; i<=n ; i++)
        {
            cin>>x;
            as(x,1,100000000);
            if(i%2 != 0)
                val = val^x;
        }
        if(n%2 == 0)
            cout<<0<<endl;
        else
            cout<<val<<endl;
    }
}
