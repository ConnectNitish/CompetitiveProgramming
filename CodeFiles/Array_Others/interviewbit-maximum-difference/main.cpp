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
#include <string.h>
using namespace std;

class Solution
{
    public : 
    int solve(vector<int> &A,int B);
    //vector<int> solve(vector<int> &A);
};

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int debug = 0;
int Data[100005];

int Solution::solve(vector<int> &A, int B) 
{
    memset(Data,0,sizeof(Data));
    
    long long int SumofAll = 0;
    
    for(int i=0;i<A.size();i++)
    {
        if(Data[A[i]]>=0)
            Data[A[i]]++;
        
        SumofAll += A[i];
        
    }
    
    if(debug)
    {
        cout << endl;
        for(int i=0;i<100005;i++)
        {
            if(Data[i]>0)
                cout << i << " Count " << Data[i] << " " << endl;
        }
        cout << endl;
    }
    
    int count=B;
    long long int SumofS1=0;
    long long int SumofAllRS=SumofAll;
    
    int DataCopy[100005];
    
    for(int i=0;i<100005;i++)
        DataCopy[i] = Data[i];
    
    for(int i=100004;i>=0;i--)
    {
        if(DataCopy[i]>0)
        {
            while(DataCopy[i]>0)
            {
                DataCopy[i]--;
                SumofS1 += i;
                SumofAllRS -= i;
                count--;
                if(count<=0)
                    break;
            }
        }
        
        if(count<=0)
            break;
    }
    
    for(int i=0;i<100005;i++)
        DataCopy[i] = Data[i];
        
    count=B;
    long long int SumofS1LS=0;
    long long int SumofAllLS=SumofAll;
    
    for(int i=0;i<100005;i++)
    {
        if(DataCopy[i]>0)
        {
            while(DataCopy[i]>0)
            {
                DataCopy[i]--;
                SumofS1LS += i;
                SumofAllLS -= i;
                count--;
                if(count<=0)
                    break;
            }
        }
        
        if(count<=0)
            break;
    }
    
    int diffLS = 
    SumofAllLS>SumofS1LS ? SumofAllLS-SumofS1LS : SumofS1LS-SumofAllLS;
    
    int diffRS = 
    SumofAllRS>SumofS1 ? SumofAllRS-SumofS1 : SumofS1-SumofAllRS;
    
    return max(abs(diffLS),abs(diffRS));
    
}

int main()
{
    vector<int> ID;
    int size;
    cin >> size;
    for(int i=0;i<size;i++)
    {
        int V;
        cin >> V;
        ID.push_back(V);
    }
    int B;
    cin >> B;
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
    
    debug = 1;
    Solution s;
    cout << " Maximum Value of s1-s2 " <<  s.solve(ID,B) << endl;
    
    
}


