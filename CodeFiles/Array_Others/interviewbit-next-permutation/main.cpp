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
#include <set>
using namespace std;

class Solution
{
    public : 
    void nextPermutation(vector<int> &A);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

// n1 <= n2 true
// false
bool compare(int n1,int n2)
{
    string sn1 = to_string(n1);
    string sn2 = to_string(n2);
    
    int l = min(sn1.length(),sn2.length());
    int counter=0;
    for(int i=0;i<l;i++)
    {
        if(sn1[i]<sn2[i])
            return true;
        else if(sn1[i]==sn2[i])
            counter++;
    }
    
    if(counter==l)
        return true;
        
    return false;
    
}

void Solution::nextPermutation(vector<int> &A) 
{
    int l=A.size();
    
    if(l<=1)
        return;
    
    int sortedcount = 0;
    int reversedSortedCount=0;
    for(int i=1;i<l;i++)
    {
        if(A[i-1]<=A[i])
            sortedcount++;
        if(A[i-1]>=A[i])
            reversedSortedCount++;
    }
    
    if(sortedcount==(l-1))
    {
        // Array is sorted just swap Last 
        // two digits
        int lastDigit = A[l-1];
        int secondLastDigit = A[l-2];
        A[l-2] = lastDigit;
        A[l-1] = secondLastDigit;
        return;
    }
    
    if(reversedSortedCount==(l-1))
    {
        // Aray is reverse Sorted 
        // so sort in in-place and return
        // int first = A[0];
        // for(int i=(l-1);i>=1;i--)
        // {
        //     int tempFirst = A[i];
        //     A[i] = first;
        //     first = tempFirst;
        // }
        
        int s=0;
        int e=l-1;
        
        while(s<=e)
        {
            swap(A[s],A[e]);
            s++;
            e--;
        }
        
        return;
    }
    
    int lastValue = A[l-1];
    int indextobreak = -1;
    int lastGreaterIndex = (l-1);
    
    set<int> data;
    data.insert(A[l-1]);
    
    for(int i=l-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        // if(compare(A[i],lastValue))
        {
            indextobreak=i;
            break;
        }
        data.insert(A[i]);
        // else
        // {
        //     lastValue = A[i];
        //     lastGreaterIndex = i;
        // }
    }
    
    if(debug)
    {
        cout << " indextobreak " << indextobreak << endl;
    }
    
    if(indextobreak!=-1 && lastGreaterIndex!=-1)
    {
        // swap(A[lastGreaterIndex],A[indextobreak]);
        // A.insert(A.begin()+indextobreak,lastValue);
        // A.pop_back();
        
        //A.erase(A.begin()+indextobreak);
        
        set<int>::iterator itr = data.begin();
        
        int index_temp = 0;
        int next_g_value = 0;
        for(auto a:data)
        {
            next_g_value = a;
            
            if(a>A[indextobreak])
                break;
            
            index_temp++;    
        }
        
        // itr = data.begin() + index_temp;
        advance(itr,index_temp);
        
        data.erase(next_g_value);
        data.insert(A[indextobreak]);
        
        swap(A[indextobreak],next_g_value);
        
        // if(indextobreak+1<l)
        //     sort(A.begin()+indextobreak+1,A.end());
        
        A.erase(A.begin()+indextobreak+1,A.end());
        for(auto a:data)
        {
            A.push_back(a);
        }
        
        if(debug)
        {
            for(auto a:data)
            {
                cout << a << " ";
            }
            cout << endl;
        }
    }
    
}


int main()
{
    int N;
    cin >> N;
    
    debug = 1;
    
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    
    // cout << " Input " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
    cout << endl;
    
    Solution s;
    s.nextPermutation(ID);
    // cout << " Output " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}

/*
Input 1 : 
6 55 3 44 6 19 18
Output 1 : 
55 3 44 18 6 19

6 55 3 44 26 19 18
55 18 3 19 26 44

6 3 55 44 6 18 19
3 55 44 6 19 18

6 55 3 44 56 19 18
55 3 56 18 19 44

6 55 3 44 56 199 59
55 3 44 59 56 199

6 55 3 44 76 199 59
55 3 44 199 59 76

6 55 3 44 46 199 59
55 3 44 59 46 199

7 6 2 1 5 4 3 0
6 2 3 0 1 4 5

*/

