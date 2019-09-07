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
    int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

bool _comp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first>=p2.first)
    {
        if(p1.second<=p2.second)
            return true;
    }
    if(p1.first<p2.first)
        return true;
    return false;
}

int Solution::solve(vector<int> &A)
{
    sort(A.begin(),A.end());
    
    cout << " Input " << endl;
    for_each(A.begin(),A.end(),print<int>);
    
    vector<int> chunk1;
    vector<int> chunk2;
    // int sumofchunk1;
    // int sumofchunk2;
    
    int i1=A.size()-1;
    int i2=i1-1;
    
    int sumofchunk1=A[A.size()-1];
    i1--;
    chunk1.push_back(sumofchunk1);
    
    int sumofchunk2=A[i1];
    i2--;
    i1--;
    chunk2.push_back(sumofchunk2);    
    i2--;
    // cout << endl << " i1 " << i1 << " i2 " << i2 << endl;
    
    
    while(i1>=0 && i2>=0)
    {
        cout << " i1 " << i1 << " i2 " << i2 << endl;
        
        int tempSumofChunk1 = sumofchunk1;
        int tempSumofChunk2 = sumofchunk2;
        
        pair<int,int> diff1 = {abs((tempSumofChunk1+A[i2]) - (tempSumofChunk2+A[i1])),0};
        pair<int,int> diff2 = {abs((tempSumofChunk1+A[i1]) - (tempSumofChunk2+A[i2])),1};
        pair<int,int> diff3 = {abs((tempSumofChunk1+A[i1]+A[i2]) - (tempSumofChunk2)),2};
        pair<int,int> diff4 = {abs((tempSumofChunk1) - (tempSumofChunk2+A[i1]+A[i2])),3};
        
        vector<pair<int,int>> details;
        details.push_back(diff1);
        details.push_back(diff2);
        details.push_back(diff3);
        details.push_back(diff4);
        
        sort(details.begin(),details.end(),_comp);
        
        pair<int,int> final = details[0];
        
        if(final.second==0)
        {
            chunk1.push_back(A[i2]);
            chunk2.push_back(A[i1]);
            sumofchunk1 += A[i2];
            sumofchunk2 += A[i1];
        }
        if(final.second==1)
        {
            chunk2.push_back(A[i2]);
            chunk1.push_back(A[i1]);
            sumofchunk2 += A[i2];
            sumofchunk1 += A[i1];
        }
        if(final.second==2)
        {
            chunk1.push_back(A[i2]);
            chunk1.push_back(A[i1]);
            sumofchunk1 += A[i2];
            sumofchunk1 += A[i1];
        }
        if(final.second==3)
        {
            chunk2.push_back(A[i2]);
            chunk2.push_back(A[i1]);
            sumofchunk2 += A[i2];
            sumofchunk2 += A[i1];
        }
        
        
        
        i1-=2;
        i2-=2;
        
    }
    
    while(i1>=0)
    {
        int tempSumofChunk1 = sumofchunk1;
        int tempSumofChunk2 = sumofchunk2;
        
        int diff1 = abs((tempSumofChunk1) - (tempSumofChunk2+A[i1]));
        int diff2 = abs((tempSumofChunk1+A[i1]) - (tempSumofChunk2));
        
        if(diff1==diff2)
        {
            chunk1.push_back(A[i1]);
            sumofchunk1+=A[i1];
        }
        else if(diff1>diff2)
        {
            chunk2.push_back(A[i1]);
            sumofchunk2+=A[i1];
        }
        else
        {
            chunk1.push_back(A[i1]);
            sumofchunk1+=A[i1];
        }
        
        i1--;
 
    }
    
    while(i2>=0)
    {
        int tempSumofChunk1 = sumofchunk1;
        int tempSumofChunk2 = sumofchunk2;
        
        int diff1 = abs((tempSumofChunk1) - (tempSumofChunk2+A[i2]));
        int diff2 = abs((tempSumofChunk1+A[i2]) - (tempSumofChunk2));
        
        if(diff1==diff2)
        {
            chunk1.push_back(A[i2]);
            sumofchunk2+=A[i2];
        }
        else if(diff1>diff2)
        {
            chunk1.push_back(A[i2]);
            sumofchunk1+=A[i2];
        }
        else
        {
            chunk2.push_back(A[i2]);
            sumofchunk2+=A[i2];
        }
        
        i2--;
    }
    
    cout << " chunk1 " << endl;
    for_each(chunk1.begin(),chunk1.end(),print<int>);
    
    cout << " chunk2 " << endl;
    for_each(chunk2.begin(),chunk2.end(),print<int>);
    
    
    return abs(sumofchunk2-sumofchunk1);
}

int main()
{
    int N;
    cin >> N;
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    cout << " aaa " << s.solve(ID) << endl;
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}




