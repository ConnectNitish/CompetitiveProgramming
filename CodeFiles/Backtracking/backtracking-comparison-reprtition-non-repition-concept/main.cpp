/******************************************************************************


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
    //int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
    void combinationSum(vector<int> &A, int B);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

// Because here we are caling self element 
// multiple times so loop will start from 0 index always 
void getTarget(set<vector<int>> &result,vector<int> &combinations,int sum,
vector<int> &data)
{
    if(sum<0)
        return;
    if(sum==0)
    {
        vector<int> temp_copy = combinations;
        // sorint gbecaue we dont need duplicates in set 
        sort(temp_copy.begin(),temp_copy.end());
        result.insert(temp_copy);
        return;
    }
    for(int i=0;i<data.size();i++)
    {
        // creating up the combinations 
        combinations.push_back(data[i]);
        // No index based call because always 
        // we need to start from zero index 
        getTarget(result,combinations,sum - data[i],data);
        // popping the last from vector 
        // so that it will create new combinations 
        // when above pushing is done  
        // it ensures all cmbinations will be generated 
        // with given array 
        combinations.pop_back();
    }
}

// In case we need to start from next keeping in aspect the old 
// comibations is not relevant as per need 
// we can iterate from index passing parameter 
// in recursion 
// similarly as to that we see in N-Queen or rat in a maje 
// here we are using index 
// because current element need not be considerd again  
void getTargetBasedOnIndex(set<vector<int>> &result,int index,vector<int> combination,
int sum,vector<int> &data)
{
    if(sum<0)return;
    if(sum==0)
    {
        vector<int> combinationCopy = combination;
        sort(combinationCopy.begin(),combinationCopy.end());
        result.insert(combinationCopy);
        return;
    }
    
    // because here we do not need to consider 
    // current element again and again 
    for(int i=index;i<data.size();i++)
    {
        combination.push_back(data[i]);
        // because we are not considering the current element 
        // again hence we are passing next pointer 
        // here there is no necessity that array need to be sorted or so 
        getTargetBasedOnIndex(result,i+1,combination,sum-data[i],data);
        combination.pop_back();
    }
}

void Solution::combinationSum(vector<int> &A, int B) 
{
    set<vector<int>> r;
    vector<int> combinations;
    bool toGetAnswerBasedOnIndexRecusrion = false;
    
    r.clear();
    combinations.clear();
    getTargetBasedOnIndex(r,0,combinations,B,A);

    cout << " Not Consdering Repition " << endl;
    for(auto a:r)
    {
       for_each(a.begin(),a.end(),print<int>);
        cout << endl;
    }
    
    cout << " Consdering Repition " << endl;
    r.clear();
    combinations.clear();
    getTarget(r,combinations,B,A);
    for(auto a:r)
    {
       for_each(a.begin(),a.end(),print<int>);
        cout << endl;
    }
}


int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    int target ;
    cin >> target;
    
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    s.combinationSum(ID,target);
}

/*
Input : 
8
4 10 1 1 1
Output :

*/






