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
    //int solve(vector<int> &A);
    int solve(int A, vector<int> &B, vector<vector<int> > &C);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}


int Solution::solve(int A, vector<int> &B, vector<vector<int> > &C)
{
    int index[2*A+1];
    int pair[2*A+1];

    // put up all the indexes 
    // for each element 
    for(int i=0;i<2*A;i++)
        index[B[i]]=i+1;

    // apply the pairs in array 
    for(int i=0;i<C.size();i++)
    {
        pair[C[i][0]]=C[i][1];
        pair[C[i][1]]=C[i][0];
    }
        
    int __swap=0;
    
    for(int i=0;i<B.size()-1;i++)
    {
        // if the pairs are present 
        // in sequence no swap is required 
        if(pair[B[i]]==B[i+1])
        {
            i++;
            continue;
        }
        else
        {
            // the pair element needs to be swapped 
            // replacing B[i+1] with value
            // of second pair of B[i]
            
            /*
            Pseudo : 
            1. take the index of current pair second value
            2. take the value i.e. B[i+1]
            3. take the index of second value of pair of B[i]
            4. take the value at index of second value of pair of B[i]
            5. swap value present at B[i+1] and B[indexobtainedin3step]
            6. Update Index array beause now two values index will get changed 
            */
            
            // taking index 
            // Step 1
            int indexofsecond = index[B[i+1]];
            //Step 2
            int valueatindexofsecond_backup = B[indexofsecond-1];
            
            // Step 3
            // value with which i+1 will be replaced 
            int valueofpairoffirst_backup = pair[B[i]];
            
            // Step 4 
            // index where value should be pushed
            // value denoted by indexofsecond will be placed at 
            // this index 
            int indexofpairoffirst = index[pair[B[i]]];
            
            // Step 5 
            swap(B[indexofsecond-1],B[indexofpairoffirst-1]);
            
            // Step 6 
            // update Index Array 
            index[valueatindexofsecond_backup] = indexofpairoffirst;
            index[valueofpairoffirst_backup] = indexofsecond;
                        
            __swap++;
            
            i++;
        }
    }
    // cout << __swap << endl;
    
    return __swap;
}

int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<int> ID;
    int v;
    cin >> v;
    for(int i=0;i<v;i++)
    {
        int V;
        cin >> V;
        ID.push_back(V);
    }
    
    vector<vector<int>> pairs;
    int r,c;
    cin >> r >> c;
    // in input for each row there should be two columns 
    for(int i=0;i<r;i++)
    {
        int N1,N2;
        cin >> N1 >> N2;
        vector<int> temp;
        temp.push_back(N1);
        temp.push_back(N2);
        pairs.push_back(temp);
    }    
    
    Solution s;
    // s.solve(N,ID,pairs);
    
    cout << " Minimum Swaps  " << s.solve(N,ID,pairs) << endl;
}

/*
Innput : 
5
10 10 1 7 4 6 2 3 5 8 9 
5 2 6 7 3 9 2 5 1 4 8 10 
Output : 
4
*/




