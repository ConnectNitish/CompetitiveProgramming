/******************************************************************************


*******************************************************************************/
#include <iterator>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int noofrecusrionCalls = 0;
// function is giving result 
// of cutting rod for provided specific 
// length 
int rodcutting(vector<int> profitateachCut,int lengthofrod)
{
    ++noofrecusrionCalls;
    if(lengthofrod==0) return 0;
    
    int maxCost = INT_MIN;
    
    for(int cutlength = 1;cutlength <= lengthofrod ; cutlength++)
    {
        int costofcutting = profitateachCut[cutlength-1]
        + rodcutting(profitateachCut,lengthofrod - cutlength);
        
        maxCost = max(maxCost,costofcutting);
    }
    
    return maxCost;
}

int noofrecusrionCallsTopDown = 0;
// applying memoisation 
// function is giving result 
// of cutting rod for provided specific 
// length 
int memoLength[10000];
int rodcuttingMemoisation(vector<int> profitateachCut,int lengthofrod)
{
    ++noofrecusrionCallsTopDown;
    if(lengthofrod==0) return 0;
    
    // if specific length 
    // is already computed 
    // then retreive the store data from the following 
    if(memoLength[lengthofrod-1]!=-1)
        return memoLength[lengthofrod-1];
    
    int maxCost = INT_MIN;
    
    for(int cutlength = 1;cutlength <= lengthofrod ; cutlength++)
    {
        int costofcutting = profitateachCut[cutlength-1]
        + rodcuttingMemoisation(profitateachCut,lengthofrod - cutlength);
        
        maxCost = max(maxCost,costofcutting);
    }
    
    // Store the computed data 
    memoLength[lengthofrod-1] = maxCost;
    
    return maxCost;
}

int noofrecusrionCallsBottomUp = 0;
int memoLengthBottomUp[10000];
// applying bottom up approach because 
// no recursive will be needed 
// for getting max sales of length n 
// we will start from length 0 to length n 
int rodcuttingBottomUp(vector<int> &profitateachCut,int lengthofrod)
{
    ++noofrecusrionCallsBottomUp;
    // we will start by computing leght 0 
    // then length 1 using help of length 0 
    // then length 2 using help of length 1 , length 0 ... 
    
    // cost of cutting of rod of length 0 is 0 
    memoLengthBottomUp[0] = 0;
    
    for(int cutlength=1;cutlength <= lengthofrod ;cutlength++)
    {
        // we were collecting cost for current length 
        // and calling recusrion method in top down 
        // to give (lengthofrod-cutlength) value 
        
        // in bottom up if we have to compute for length 1 
        // then we will take the cost for 1 length and request for 
        // length (cutlength - length) // i.e. 1 - 1 
        // i.e. request for length 0 i.e. memoLengthBottomUp[0]
        // memoLengthBottomUp[cutlength - length ]
        
        int resultforcurrentCutlength = INT_MIN;
        
        // example : requesting for length 3 ( cutlength 3)
        // 1st loop i = 1 ( length 1 cut performed ) 
        // request for profit from residue length i.e. ( cutlength - i )
        // i.e. for length 2 request is made 
        // by calling memoLengthBottomUp[cutlength-i] i.e. memoLengthBottomUp[2]
        // 2nd loop i = 2 ( length 2 cut performed )
        // request for profit from residue length i.e. (cutlength -i)
        // i.e. for length 1 request is made 
        // by calling memoLengthBottomUp[cutlength-i] i.e. memoLengthBottomUp[1]
        // 3rd loop i = 3 ( length 3 cut performed )
        // request for profit from residue length i.e. (cutlength -i)
        // i.e. for length 0 request is made 
        // by calling memoLengthBottomUp[cutlength-i] i.e. memoLengthBottomUp[0]
        // taking maximum of all three and cost is calclauted for length 3 
        
        for(int i=1;i<=cutlength;i++)
        {
            // because profitateachCut is 0 based 
            // index 0 - cost of 1 length rod 
            // index 1 - cost of 2 length rod 
            // index 2 - cost of 3 length rod 
            int cost = profitateachCut[i-1] + memoLengthBottomUp[cutlength - i];
            resultforcurrentCutlength = max(cost,resultforcurrentCutlength);
        }
        
        // storing the result for current cut 
        memoLengthBottomUp[cutlength] = resultforcurrentCutlength;
        
    }
    
    return memoLengthBottomUp[lengthofrod];
    
}

int main()
{
    int N;
    cin >> N;
    // index 0 - cost of 1 length rod 
    // index 1 - cost of 2 length rod 
    // index 2 - cost of 3 length rod 
    vector<int> profitateachCut;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(profitateachCut));
    
    cout << " Rod Cutting Recursion " << rodcutting(profitateachCut,N) << endl;
    cout << " No of Recusrive Calls " << noofrecusrionCalls << endl;
    // because Cost can never be negative 
    // so we can fill with -1 
    fill(memoLength,memoLength+10000,-1);
    
    cout << " Rod Cutting Top Down Memoisation " << rodcuttingMemoisation(profitateachCut,N) << endl;
    cout << " No of Recusrive Calls Top Down " << noofrecusrionCallsTopDown << endl;
    
    // because Cost can never be negative 
    // so we can fill with -1 
    fill(memoLengthBottomUp,memoLengthBottomUp+10000,-1);
    
    cout << " Rod Cutting Bottom Up " << rodcuttingBottomUp(profitateachCut,N) << endl;
    cout << " No of Recusrive Calls Bottom Up " << noofrecusrionCallsBottomUp << endl;
    
    return 0;
}

