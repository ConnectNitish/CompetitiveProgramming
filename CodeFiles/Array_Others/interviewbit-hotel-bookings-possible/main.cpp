/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public: 
    bool hotel(vector<int> &a,vector<int> &b,int K);
};

bool Solution::hotel(vector<int> &a, vector<int> &d, int K) 
{
    
    vector<pair<int,int>> da;
    
    for(int i=0;i<a.size();i++)
    {
        da.push_back({a[i],1});    
        da.push_back({d[i],0});
    }
    
    sort(da.begin(),da.end());
    
    int current =0;
    int currentmax = 0;
    
    for(int i=0;i<da.size();i++)
    {
        if(da[i].second == 1)
        {
            current++;
            currentmax = max(currentmax,current); 
        }
        else
            current--;
    }
    
    cout << currentmax << endl;
    
    if(currentmax>K)
        return false;
    return true;
}


int main()
{
    int v;
    cin >> v;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<v;i++)
    {
        int d;
        cin >> d;
        a.push_back(d);
    }
    for(int i=0;i<v;i++)
    {
        int d;
        cin >> d;
        b.push_back(d);
    }
    int k;
    cin >> k;
    Solution s;
    
    cout << s.hotel(a,b,k) << endl;
    
    return 0;
}


