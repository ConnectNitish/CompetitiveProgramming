//https://www.interviewbit.com/problems/matrix-chain-multiplication/

int mCost(vector<int> &A,int i,int j,vector<vector<int>> &dp)
{
    if(i==j)
    {
        dp[i][j]=0;
        return 0;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    dp[i][j] = INT_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j] = 
        min ( dp[i][j] , 
        mCost(A,i,k,dp)+mCost(A,k+1,j,dp)+(A[i-1]*A[k]*A[j]));
    }
    
    return dp[i][j];
}

int Solution::solve(vector<int> &A) 
{
    vector<vector<int>> dp(A.size(),vector<int>(A.size(),-1));
    // invoke from 1 index because size matrix is of 
    // starting from 0th index for 1st matrix 
    int cost =  mCost(A,1,A.size()-1,dp);
    /*
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    return cost;
}

