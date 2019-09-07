

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
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
    void getRow();
};

//generating the only time for given row 
vector<int> get_row(int A)
{
    vector<int> d;
    d.push_back(1);
    if(A==0)
        return d;
        
    //A++;
    
    for(int i=1;i<=A;i++)
    {
        if(i==A)
        {
            d.push_back(1);
            continue;
        }
        int next = ((d[i-1] * (A-i+1))/i);
        d.push_back(next);
    }
    // d.push_back(1);
    return d;
}

vector<int> Solution::getRow(int A) 
{
    return get_row(A);
}

//genrating all the previous line 
vector<int> getRow_1(int A) 
{
    vector<int> d;
    vector<vector<int>> r;
    d.push_back(1);
    r.push_back(d);
    if(A==0)
    {
        return r[A]; 
    }
    
    int tempA=0;
    while(tempA<=A)
    {
        d.clear();
        for(int i=0;i<r[tempA].size();i++)
        {
            if(i==0)
            {
                d.push_back(1);
            }
            else
            {
               if(i-1>=0 && i<r[tempA].size())
               {
                   d.push_back(r[tempA][i]+ r[tempA][i-1]);
               }
            }
            
            if(i==r[tempA].size()-1)
            {
                d.push_back(1);
            }
        }
        r.push_back(d);
        tempA++;
    }
    return r[A];
}

int main()
{
    int ID;
    cin >> ID ; 
    Solution s;
    vector<int> D  = s.getRow(ID);
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}


