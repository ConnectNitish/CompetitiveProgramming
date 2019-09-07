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
    int solve(vector<vector<int> > &A, int B);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int Solution::solve(vector<vector<int> > &A, int B) 
{
    if(A.size()<=0)
        return -1;
    if(A[0].size()<=0)
        return -1;
    
    int r=A.size();
    int c = A[0].size();
    
    int i=0;
    int j=(c-1);
    
    // starting the search from top right corner 
    
    while(j>=0 && i<r)
    {
        if(A[i][j]==B)
            return ((i+1)*1009+(j+1));
        else if(A[i][j]>B)
            // decreament the column 
            // because current element is greater than 
            // given element 
            j--;
        else
            // increament the row 
            // because current elamet is less than 
            // given element 
            i++;
    }
    return -1;
}


int main()
{
    debug = 1;
    int r;
    int c;
    cin >> r >> c;
    vector<vector<int> > rd;
    for(int i=0;i<r;i++)
    {
        vector<int> ID;
        for(int j=0;j<c;j++)
        {
            int V;
            cin >> V;
            ID.push_back(V);
        }
        rd.push_back(ID);
    }
    int B;
    cin >> B;
   
    Solution s;
    cout << " Present " << s.solve(rd,B) << endl;
}



