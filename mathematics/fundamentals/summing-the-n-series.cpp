#include <iostream>
using namespace std;

const long long int mod = 1000000007;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        cout << ((n % mod) * (n % mod)) % mod << '\n';
    }
    
    return 0;
}
