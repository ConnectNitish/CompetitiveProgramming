/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

class Solution
{
    public : 
    int solve(string A);
};

int Solution::solve(string A) 
{
    bool startwith1=false;
    bool startwith0=false;
    bool seen1=false;
    int idx1=-1;
    int idx0=-1;
    
    int l=A.length();
    
    if(l==0)
        return 0;
    
    int count0=0;
    
    if(l>0)
    {
        if(A[0]=='1')
        {
            startwith1 = true;
            idx1 = 0;
        }
        else
        {
            startwith0 = true;
            idx0 = 0;
            count0++;
        }
    }
    
    vector<pair<int,int>> _d;
    
    cout << count0 << endl;
    
    for(int i=1;i<l;i++)
    {
        if(A[i]=='0')
            count0++;
            
        cout << " startwith1 " << startwith1  << "count0" << count0 << endl;
        if(startwith1==true)
        {
            if(i==l-1)
            {
                if(count0==1)
                    return (l-1);
                if(count0==0)
                    return l;
            }
            else
            {
                if(count0>1)
                {
                    if(idx1!=-1)
                        _d.push_back({idx1,i-1});
                    if(A[i]=='0')
                    {
                        count0=1;
                        startwith0=true;
                        idx0=i;
                        seen1=false;
                        startwith1 = false;
                    }
                }        
            }
        }
        else if(startwith0==true)
        {
            if(count0>1)
            {
                if(seen1==true && idx0!=-1)
                {
                    _d.push_back({idx0,i-1});
                    seen1=false;
                    idx1=i-1;
                    startwith1=true;
                }
                count0=1;
                idx0=i;
            }
            else if(count0==1)
            {
                if(seen1==false)
                {
                    idx1 = i;
                    seen1=true;
                }
            }
        }
    }
    
    cout << _d.size() << endl;
    
    for(auto a:_d)
    {
        cout << a.first << " : " << a.second << endl;
    }
    
    return 0;
}

int main()
{
    string sIn;
    cin >> sIn;
    
    Solution s;
    s.solve(sIn);
    return 0;
}



