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

class Solution
{
    public : 
    void setZeroes(vector<vector<int>> &A);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

void print2D(vector<vector<int>> A)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void Solution::setZeroes(vector<vector<int> > &A) {

int r=A.size();
int c=A[0].size();

for(int i=0;i<A.size();i++)
{
    for(int j=0;j<A[0].size();j++)
    {
        if(A[i][j]==-1)
            continue;
        
        if(A[i][j]==0)
        {
            if(A[i][0]==1)
                A[i][0]=-1;
            if(A[i][c-1]==1)
                A[i][c-1]=-1;
            if(A[0][j]==1)
                A[0][j]=-1;
            if(A[r-1][j]==1)
                A[r-1][j]=-1;
        }
    }
}

if(debug)
    print2D(A);

for(int i=0;i<A.size();i++)
{
    for(int j=0;j<A[0].size();j++)
    {
        //if(A[i][j]!=-1)
        {
            if(
            ( A[i][0]==-1 || A[i][0]==0) 
            &&
            ( A[i][c-1]==0 || A[i][c-1]==-1)
            )
                A[i][j]=-1;
            else if
            (
            (A[0][j]==-1 || A[0][j]==0) &&
            (A[r-1][j]==0 || A[r-1][j]==-1)
            )
                A[i][j]=-1;
        }
    }
}

if(debug)
{
    cout << endl;
    print2D(A);
}

for(int i=0;i<A.size();i++)
{
    for(int j=0;j<A[0].size();j++)
    {
        if(A[i][j]==-1)
            A[i][j] = 0;
    }
}


    
}




int main()
{
    debug = 1;
    vector<vector<int> > A;
    
    int r;
    int c;
    
    cin >> r >> c;
    
    for(int i=0;i<r;i++)
    {
        vector<int> d;
        for(int j=0;j<c;j++)
        {
            int V;
            cin >> V;
            d.push_back(V);
        }
        A.push_back(d);
    }
    
   
    Solution s;
    s.setZeroes(A);
     
    
   
}




