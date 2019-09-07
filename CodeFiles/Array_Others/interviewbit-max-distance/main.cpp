/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

// https://www.interviewbit.com/problems/max-distance/

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
    public : 
    int maximumGap(const vector<int> &A);
    //vector<int> solve(vector<int> &A);
};

int debug=0;
template<typename T>
void print(T value)
{
    cout << value << " " << endl;
}

template<typename T>
void printpair(T value)
{
    cout << value.first << ":" << value.second << " " << endl;
}

// sort the pair on the basis 
// of first smallest 
// if both first are same
// gives precedence to smallest second 
bool bsort(const pair<int,int> p1,const pair<int,int> p2)
{
    if(p1.first>p2.first)
        return false;
    else if(p1.first==p2.first)
    {
        if(p1.second<=p2.second)
            return true;
        return false;
    }
    return true;
}

// update the BIT 
// along with the scalar value which it hold 
// for each index tracking the min index which which 
// it was updated 
// for any query I will return the result of how many indexes 
// arrived before the requested indexes ( gives inversion ) 
// also in index param i will provide the 
// minimum of all indexes used till the time 
int res(pair<int,int> d[],int i,int &index)
{
    int result = 0;
    
    index = INT_MAX;
    
    while(i>0)
    {
        result += d[i].first;
        if(d[i].second!=-2)
            index = min(index,d[i].second);
        i -= (i&(-i));
    }
    
    if(result==0 || index==INT_MAX)
        index=-1;
    
    return result;
}

// along with increament of value , I will store the value 
// of min index with which value was increamented 
// supoose index 4 is updated 1,2,4 indexes then 1 will be stored 
// in pair second value. 
void update(pair<int,int> d[],int i,int maxN)
{
    int ptr = i;
    while(i<=maxN)
    {
        d[i].first++;
        if(d[i].second==-2)
            d[i].second = min(i,ptr);
        else
            d[i].second = min(min(i,ptr),d[i].second);
        i += (i&(-i));
    }
}


int Solution::maximumGap(const vector<int> &A) 
{
    vector<pair<int,int>> d;
    int i=0;
    for(;i<A.size();i++)
    {
        d.push_back({A[i],i+1});
    }
    
    sort(d.begin(),d.end(),bsort);
    
    if(debug)
    {
        cout << " Post Sort " << endl;
        for_each(d.begin(),d.end(),printpair<pair<int,int>>);
    }
    
    pair<int,int> BIT[i+1];
    
    for(int j=0;j<=(i);j++)
    {
        BIT[j] = {0,-2};
    }
    
    int maxJI = INT_MIN;
    
    for(int j=0;j<(i);j++)
    {
        int index = -1;
        int result = res(BIT,d[j].second-1,index);
        
        if(index!=-1)
        {
            maxJI = max(maxJI,(d[j].second-index));
        }
        
        // updating BIT array as well as respective 
        // indexes of other element 
        update(BIT,d[j].second,i);
        
        if(debug)
        {
            cout << " Print BIT " << endl;
            for(int tt=0;tt<=i;tt++)
            {
                cout << BIT[tt].first << " : " << BIT[tt].second << " $ ";
            }
            cout <<endl;
        }
        
    }
    
    return maxJI;
}


int main()
{
    debug=0;
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    cout << " Maximum (j-i) such that A[i]<=A[j] : "  << s.maximumGap(ID) << endl;
    
    // cout << "Print using For Each Iterator " << endl;
    // for_each(ID.begin(),ID.end(),print<int>);
}

/*
Input 1: 
3 5 4 2
Output 1:
2

Input 2: 
7 5 2 6 4 7 1 1
Output 2:
5

*/



