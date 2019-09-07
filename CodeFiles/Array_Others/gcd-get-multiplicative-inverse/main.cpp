/******************************************************************************

...

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
    void getMultiplicativeInverse(int a,int m,int &x,int &y,int &gcd);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

void Solution::getMultiplicativeInverse(int a,int b,int &x,int &y,int &gcd)
{
    if(b==0)
    {
        x=1;
        y=0;
        gcd = a;
        return;
    }
    if(a<b)
        getMultiplicativeInverse(b,a,x,y,gcd);
    else
        getMultiplicativeInverse(b,a%b,x,y,gcd);
        
    int cx = y;
    int cy = x - ((a/b)*y);
    
    x = cx;
    y = cy;
    
    // to avoid negative value 
    // for inverse 
    if(x<0)
    {
        x = (x+b)%b;
    }
}


int main()
{
    int N1;
    int N2;
    cin >> N1 >> N2;
    
    Solution s;
    int x=0;int y=0;int gcd=0;
    s.getMultiplicativeInverse(N1,N2,x,y,gcd);
    cout << N1 << "*" << x << " + " << N2 <<  "*" << y << " = " << gcd << endl;
    cout << " MUltiplication Inverse of "<< N1 << "%" << N2 << " is " << x << endl; 
}

/*
GCD(a,b) should be 1 
Input : 18 7

Output:

18*2 + 7*-1 = 1
 MUltiplication Inverse of 18%7 is 2
 
*/








