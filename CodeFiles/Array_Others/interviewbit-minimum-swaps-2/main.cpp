/******************************************************************************

https://www.interviewbit.com/problems/minimum-swaps-2/

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution
{
    public : 
    int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int Solution::solve(vector<int> &A) 
{
    int l= A.size();
    int tswaps = 0;
    int seenzero = 0;
    
    for(int i=0;i<l;i++)
    {
        if(A[i]==i || A[i]<0)
            continue;
            
        if(A[i]==0 && seenzero==1)
            continue;
            
        int value = i;
        int startValue=i;
        int count=0;
        do
        {
            A[value] = (-1) * abs(A[value]);
            
            if(A[value]==0)
                seenzero=1;
                
            value = abs(A[value]);
            count++;
        }while(value!=startValue);
        
        tswaps += (count-1);
    }
    
    return (tswaps);
}


int main()
{
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    cout << " Minimum Swaps 2 " << s.solve(ID) << endl;
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}



