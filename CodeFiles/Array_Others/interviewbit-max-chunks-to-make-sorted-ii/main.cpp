
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <limits.h>
using namespace std;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

class Solution
{
    public : 
    int solve(vector<int> &A);
};

bool bsort(const pair<int,int> &p1,const pair<int,int> &p2)
{
    if(p1.first==p2.first)
    {
        if(p1.second<=p2.second)
            return true;
        return false;
    }
    if(p1.first<p2.first)
    {
        return true;
    }
    return false;
}

int Solution::solve(vector<int> &A) 
{
    vector<pair<int,int>> d;
    for(int i=0;i<A.size();i++)
    {
        d.push_back({A[i],i});
    }
    
    sort(d.begin(),d.end(),bsort);
    
    int max_so_far = INT_MIN;
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        max_so_far = max(max_so_far,d[i].second);
        if(max_so_far==i)
            count++;
    }
    return count;
}

int main()
{
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));

    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);

    Solution s;
    cout << " Max Chunks " << s.solve(ID) << endl;
    
}
