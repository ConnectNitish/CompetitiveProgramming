/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/alternate-positive-and-negative-elements/

*******************************************************************************/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


// to get the poisition of element which need to be swapped 
// if start is greater than end then -2 will be returned 
// if no such element found then -1 will be returned 
// 0 is considerd as positive element 
int position(vector<int> &A,int s,int e,bool p)
{
    if(s>e)
        return -1;
    
    for(int i=s;i<=e;i++)
    {
        if(p)
        {
            if(A[i]>=0)
            {
                return i;
            }
        }
        else
        {
            if(A[i]<0)
                return i;
        }
    }
    return -2;
}





class Solution
{
    public : 
    vector<int> solve(vector<int> &A);
};

vector<int> Solution::solve(vector<int> &A) 
{
    int l = A.size();
    
    // pointer to negative value 
    // if the value pointed by this index 
    // is not negative then search from 
    // next index till length to get any negative value
    // if no negative value is found then return 
    // because no negative value to rearrange 
    int np = 0;
    
    // pointer to positive value 
    // if the value pointed by this index 
    // is not positive number then search from 
    // next index till length to get any positive value
    // if no positive value is found the return 
    // because no positive value to rearrange 
    int pp = np + 1;
    
    while(np<l && pp<l)
    {
        // if the value pointed by this index 
        if(A[np]>=0)
        {
            // search from next index to end of array 
            int index = position(A,pp,l-1,false);
            // shows no negative value to rearrange 
            if(index==-2)
                break;
            // swap will not work because result arrangment will not 
            // match with actual output 
            //swap(A,np,index);
            //show index of next pointer goes beyond 
            // length of array 
            if(index!=-1)
            {
                // got an negative number to rearrange 
                A.insert(A.begin()+np,A[index]);
                A.erase(A.begin()+index+1);
            }
        }
        
        // shifting the pointer to next to next element 
        // for next iteration
        np += 2;
        
        if(A[pp]<0)
        {
            // search from next index to end of array 
            // for positive value 
            int index = position(A,np,l-1,true);
            // shows no positive value to rearrange 
            if(index == -2)
                break;
            //swap(A,pp,index);
            //show index of next pointer goes beyond 
            // length of array 
            if(index!=-1)
            {
                // got an positive number to rearrange 
                A.insert(A.begin()+pp,A[index]);
                A.erase(A.begin()+index+1);
            }
        }
        
        // shifting the pointer to next to next element 
        // for next iteration
        pp+=2;
    }
    return A;
}

/**
 * Input : 24 -8 7 20 -19 -13 -3 25 -10 10 -25 7 22 -15 23 6 -2 26 10 -14 -8 5 -7 27 19 15 -28 -30 9 -19 -30 -2 -27 -9 4 14 -8 -4 15 24 -8 -27 -16 -11 1 18 -2 -5 9 28 -23 23 -26 8 -17 20 -7 5 -18 8 -24 -20 20 -28 -3 -18 1 -8 26 14 -6 15 9 12 -1 29 -12 -3 8 23 -21 0 -7 -4 -25 -18 -12 -17 -15 -11 -3 -29 -13 10 1 11 11 15 -9 -29 12 -21 -17 1 7 11 7 15 21 -4 -20 17 -8 1 -3 28 -8 -29 9 29 26 -16 -21 -23 -5 25 -13 -1 -29 25 17 3 11 26 14 -30 12 -4 29 21 -25 8 -4 11 -28 -16 -26 
 * Output : -8 24 -19 7 -13 20 -3 25 -10 10 -25 7 -15 22 -2 23 -14 6 -8 26 -7 10 -28 5 -30 27 -19 19 -30 15 -2 9 -27 4 -9 14 -8 15 -4 24 -8 1 -27 18 -16 9 -11 28 -2 23 -5 8 -23 20 -26 5 -17 8 -7 20 -18 1 -24 26 -20 14 -28 15 -3 9 -18 12 -8 29 -6 8 -1 23 -12 0 -3 10 -21 1 -7 11 -4 11 -25 15 -18 12 -12 1 -17 7 -15 11 -11 7 -3 15 -29 21 -13 17 -9 1 -29 28 -21 9 -17 29 -4 26 -20 25 -8 25 -3 17 -8 3 -29 11 -16 26 -21 14 -23 12 -5 29 -13 21 -1 8 -29 11 -30 -4 -25 -4 -28 -16 -26 
*/

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int main()
{
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    s.solve(ID);
    
    //cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}
