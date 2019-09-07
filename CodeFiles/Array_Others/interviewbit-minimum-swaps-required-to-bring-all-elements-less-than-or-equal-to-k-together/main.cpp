/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution
{
    public : 
    int solve(vector<int> &A,int b);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int Solution::solve(vector<int> &A, int B) 
{
    int minIn = INT_MAX;
    int maxIn = INT_MIN;
    int count = 0;
    int l=A.size();
    
    for(int i=0;i<l;i++)
    {
        if(A[i]<=B)
        {
            minIn = min(minIn,i);
            maxIn = max(maxIn,i);
            count++;
        }
    }
    
    int noofelemnt = (maxIn-minIn+1);
    
    if(noofelemnt==count)
        return 0;
    
    int result = 0;
    
    if(noofelemnt>count)
    {
        int s = minIn;
        int ns = minIn;
        int newData[maxIn-minIn+1];
        int countofnumberInArray = 0;
        int startIndex = 0;
        int minSwaps = 0;
        
        while(s<=ns && s<l && ns<l)
        {
            // newData[startIndex] = A[ns];
            startIndex++;
            
            // tracking no of 
            // elelemnt greater than B 
            // in window 
            if(A[ns]<=B)
            {
                countofnumberInArray++;
            }
            
            // shows no swap is required 
            // because current window is all element 
            // <= B 
            if(countofnumberInArray>=count)
            {
                return 0;    
            }
            
            if(startIndex==count)
            {
                minSwaps = max(minSwaps,countofnumberInArray);
                
                if(A[s]<=B && countofnumberInArray>0)
                    countofnumberInArray--;
                s++;
                
                startIndex = (count-1);
            }
            
            
            
            ns++;
        }
        
        result = abs(count-minSwaps);
        
    }
    
    return result;
    
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
    cout << " Minimum Swaps are " <<  s.solve(ID,B) << endl;
}

/*
Input :
8 2 12 13 6 10 15 5 7
7
Output :
2
*/


