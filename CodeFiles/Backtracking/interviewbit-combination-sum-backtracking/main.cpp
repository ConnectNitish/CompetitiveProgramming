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
    vector<vector<int>> combinationSum(vector<int> &A, int B);
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
void getTargetBasedOnIndex(set<vector<int>> &result,vector<int> &combinations,int sum,
vector<int> &data,int index)
{
    if(sum<0)
        return;
    if(sum==0)
    {
        vector<int> temp_copy = combinations;
        sort(temp_copy.begin(),temp_copy.end());
        result.insert(temp_copy);
        return;
    }
    for(int i=index;i<data.size();i++)
    {
        // considering the data in the sum 
        combinations.push_back(data[i]);
        //because here we know that old ( previous values )
        // will not be considerd because the array is sorted 
        // hence increamneting the index will save many recursive call 
        // e.g. 3 5 1 target : 6 ; if we are at 1 and array is not sorted then 
        // we try all comibanitions 
        // e.g. 1 3 5 target : 6 ; if we are at 3 then already we get 4 as sum 
        // and we will only go towards the right part so that my target gets 
        // achieved -> hence index based paraneters works here 
        getTargetBasedOnIndex(result,combinations,sum - data[i],data,index);
        // removing the element from vector to ensure 
        // that we will be getting new combiations 
        combinations.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B) 
{
    set<vector<int>> r;
    vector<int> combinations;
    bool toGetAnswerBasedOnIndexRecusrion = false;
    
    if(toGetAnswerBasedOnIndexRecusrion)
    {
        sort(A.begin(),A.end());
        getTargetBasedOnIndex(r,combinations,B,A,0);
    }
    else
    {
        getTarget(r,combinations,B,A);
    }
    
    vector<vector<int>> result;
    for(auto a:r)
    {
       result.push_back(a); 
    }
    
    return result;
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
    vector<vector<int>> allcombinations = s.combinationSum(ID,target);
    
    cout << " All Combinations " << endl;
    for(auto a:allcombinations)
    {
        for_each(a.begin(),a.end(),print<int>);
        cout << endl;
    }
    
}





