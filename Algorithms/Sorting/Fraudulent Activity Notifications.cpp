
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (i = 0; i < n; i++)
#define fore(i, n) for (i = n - 1; i >= 0; i--)
#define li long
#define ll long long

int t_median_calc(int csort[],int d)
{
    int i,n=0,t_median=0;
    if(d%2!=0)
    {
        i=0;
        while(i<201)
        {
            n+=csort[i];
            if(n>=d/2+1)break;
            i++;
        }
        t_median=2*i;
    }
    else
    {
      i = 0;
      bool check = false;
      while (i < 201) 
      {
        n += csort[i];
        if (n >= d / 2 && check == false) 
        {
          t_median += i;
          check = true;
            }
            if(n>=d/2+1)
            {
              t_median += i;
              break;
            }
            
            i++;
      }
    }

    return t_median;
}



int main() 
{


    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);

  int n, d;
  cin >> n >> d;
  int ar[n];
  int i;
  forn(i, n) cin >> ar[i];

  int csort[201] = {};
  int sum=0;

  forn(i,d)csort[ar[i]]++;

  // if(ar[d]>=t_median_calc(csort[],d))sum++;

  for(i=d;i<n;i++)
    {

       if(ar[i]>=t_median_calc(csort,d))sum++; 
       csort[ar[i-d]]--;
       csort[ar[i]]++;
    }

    cout<<sum;
}
