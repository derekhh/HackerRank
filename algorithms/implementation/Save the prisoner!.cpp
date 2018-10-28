#include<iostream>
using namespace std;
int main()
{
    long int n,m,s,a;  int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m>>s;
        a=s+m-1;
        if(a>n)
        {
            if(a%n==0)
            {
                cout<<n<<endl;
            }
            else
                cout<<a%n<<endl;
        }
        else
            cout<<a<<"\n";
        
    }
}
