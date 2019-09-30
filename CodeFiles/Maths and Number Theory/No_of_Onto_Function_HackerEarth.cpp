/*
https://www.hackerearth.com/problem/algorithm/alice-and-her-sequence-43/
*/

#include <iostream>

using namespace std;
#define ll long long 
#define MOD 1000000007

ll pow(ll a, ll b)
{
    if(a==1) return 1;
    if(b==0) return 1;
    if(b==1) return a%MOD;
    
    ll small = pow(a,b/2);
    
    if((b&1)==1)
        return ( ( (a%MOD*small%MOD)%MOD * small )%MOD);
    return (small*small)%MOD;
}
int main() {
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        if(n<=2)
        {
            cout << 0 << endl;
            continue;
        }
        
        ll first = pow(3,n)%MOD;
        ll second = (3 * pow(2,n)) % MOD;
        ll third = 3;
        
        cout << ((first - second + MOD)%MOD + third)%MOD << endl; 
    }
}