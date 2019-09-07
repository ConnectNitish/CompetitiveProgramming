/******************************************************************************

https://www.interviewbit.com/problems/size-three-subsequences-divisible-by-b/

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include<map>
using namespace std;

class Solution
{
    public : 
    int solve(vector<int> &A, int B);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int modsum = 0;
map<int,int> pr;

void sumtrack(vector<int> &A,int index,int &count,int B)
{
    if(A.size()==index)
        return;
        
    vector<int> data;
    
    int distance = 1;
    for(int i = index;i<A.size();i++)
    {
        
        if(pr[i+1]==0)
        {
            sumtrack(A,i+1,count,B);
            pr[i+1]++;
        }
        data.push_back(A[i]);
        if(data.size()==3)
        {
            if(debug)
                {
                    cout << " Temp " << endl;
                    for_each(data.begin(),data.end(),print<int>);
                    cout << endl;
                    
                }
           
            long long sumTemp = 0;
            for(auto a:data)
                sumTemp += (long)a;
            if(sumTemp%B==0)
            {
                count++;
                
                
            }
            // data.erase(data.begin(),data.begin());
            data.pop_back();
        }
        
        if(i==A.size()-1 
        && A.size()-distance>=2)
        {
            
            data.clear();
            data.push_back(A[index]);
            i=index+distance;
            distance++;
        }
        
    }
}

int Solution::solve(vector<int> &A, int B) 
{
    pr.clear();
    modsum = 0;
    pr[0]++;
    sumtrack(A,0,modsum,B);
    return modsum%1000000007;
}


int main()
{
    debug = 1;
    vector<int> ID;
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int V;
        cin >> V;
        ID.push_back(V);
    }
    int B;
    cin >> B;
    
    Solution s;
    cout << "Count " << s.solve(ID,B) << endl;
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}




