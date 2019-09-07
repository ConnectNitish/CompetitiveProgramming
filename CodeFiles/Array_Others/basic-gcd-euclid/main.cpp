/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#define ll long long
using namespace std;

class Solution
{
    public : 
    int getGcd(int n1,int n2);
    void getGCDLinearComb(int n1,int n2,int &x,int &y,int &gcdValue);
    
    // input : a b m 
    // output : a^b % m 
    ll fastModulo(ll a,ll b,int m);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int Solution::getGcd(int n1,int n2)
{
    if(n1<n2) getGcd(n2,n1);
    if(n2==0) return n1;
    return getGcd(n2,(n1%n2));
}


void Solution::getGCDLinearComb(int n1,int n2,int &x,int &y,int &gcdValue)
{
    if(n2==0)
    {
        x = 1;
        y = 0;
        gcdValue = n1;
        return;
    }
    if(n1<n2)
        getGCDLinearComb(n2,n1,x,y,gcdValue);
    else
        getGCDLinearComb(n2,(n1%n2),x,y,gcdValue);
    
    int cx = y;
    int cy = x - ((n1/n2)*y);
    
    x = cx;
    y = cy;
}

ll Solution::fastModulo(ll a,ll b,int m)
{
    ll res = 1;
    while(b>0)
    {
        // checking last set bit is one 
        if(b&1)
            res = (res * a) % m;
        a = (a*a)%m;
        // clearing the last bit 
        b = b>>1;
    }
    return res;
}

int main()
{
    int N1;
    int N2;
    cin >> N1 >> N2;
    
    Solution s;
    
    cout << " GCD of " << N1 << " and  " << N2 << " is " << s.getGcd(N1,N2) << endl;
    int x=0;int y=0;int gcdValue=0;
    s.getGCDLinearComb(N1,N2,x,y,gcdValue);
    cout << N1 << "* " << x << " + " << N2 <<  "*" << y << " = " << gcdValue << endl;
    
    cout << " Using FastModulo  " << N1 << "^" << N2 << "% (10^9+7) : " << s.fastModulo(N1,N2,1000000007) << endl;   
    
}

/*
Input : 18 20

Output:

 GCD of 18 and  20 is 2
18* -1 + 20*1 = 2
 Using FastModulo  18^20% (10^9+7) : 243064873
 
*/





