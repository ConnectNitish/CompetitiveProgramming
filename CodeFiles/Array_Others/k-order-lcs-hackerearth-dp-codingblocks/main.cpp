/******************************************************************************

https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

*******************************************************************************/
#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>
using namespace std;



int computeLCSByRecurion(vector<int> &N1,vector<int> &N2,
int startN1,int startN2,int operations)
{
    if(startN1==N1.size() || startN2==N2.size())
        return 0;

    if(startN1<0 || startN2<0)
        return 0;
    
    int result = 0;
    
    if(N1[startN1]==N2[startN2])
    {
        result = 1 + computeLCSByRecurion(N1,N2,startN1+1,startN2+1,operations);
    }
    else
    {

        if(operations>0)
            result = 1 + computeLCSByRecurion(N1,N2,startN1+1,startN2+1,operations-1);
        
        result = max(result,computeLCSByRecurion(N1,N2,startN1,startN2+1,operations));
        result = max(result,computeLCSByRecurion(N1,N2,startN1+1,startN2,operations));
    }
    
    return result;
}

#define ll long long 
ll dpBottomUp[2001][2001][6];
ll IN1[2001];
ll IN2[2001];
ll n1,n2;
ll op;

// bottom Up Approach 
ll computeKOrderLCS(
ll startN1,ll startN2,ll operations)
{
    vector<vector<int>> dp(startN1+1,vector<int>(startN2+1,0));
    
    for(int i=0;i<=startN1;i++)
    {
        for(int j=0;j<=startN2;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
            {
                if(IN1[i-1]==IN2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    int performedOperations=0;
                    // if(operations>0)
                    // {
                    //     performedOperations = 1 + dp[i-1][j-1];
                    //     operations--;
                    // }
                    dp[i][j] = max(performedOperations,
                    max(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
    }
    
    int maxChnage = min(min(startN1,startN2)-dp[startN1][startN2],operations);
    
    return maxChnage+dp[startN1][startN2];
    
}

ll computeLCSByRecurionTopDown(
ll startN1,ll startN2,ll operations
)
{
    if(startN1>=n1 || startN2>=n2)
        return 0;

    //   if(operations<0) {
    //     return 0;
    //   }

    // if(startN1<0 || startN2<0)
    //     return 0;

    ll &addressofDpArray = dpBottomUp[startN1][startN2][operations];

    if(addressofDpArray!=-1) 
    return addressofDpArray;

    ll result = LONG_MIN;
    
    if(IN1[startN1]==IN2[startN2])
    {
        // result = 1 + computeLCSByRecurionTopDown(startN1+1,startN2+1,operations);
        
        ll &furthercost=dpBottomUp[startN1+1][startN2+1][operations];
        if(furthercost==-1) 
        {
            furthercost = computeLCSByRecurionTopDown(startN1+1,startN2+1,operations);
            // dpBottomUp[startN1+1][startN2+1][operations] = furthercost;
        }
        // else
        //     furthercost = dpBottomUp[startN1+1][startN2+1][operations];
        
        result = 1 + furthercost;
        
    }
    else
    {

        if(operations>0)
        {
            ll &furthercost=dpBottomUp[startN1+1][startN2+1][operations-1];
            if(furthercost==-1) 
            {
                furthercost = computeLCSByRecurionTopDown(startN1+1,startN2+1,operations-1);
                // dpBottomUp[startN1+1][startN2+1][operations-1] = furthercost;
            }
            // else
            //     furthercost = dpBottomUp[startN1+1][startN2+1][operations-1];
            
            result = 1 + furthercost;
        }
        
        
        ll &tempresultleft=dpBottomUp[startN1][startN2+1][operations];
        if(tempresultleft==-1) 
        {
            tempresultleft = computeLCSByRecurionTopDown(startN1,startN2+1,operations);
            // dpBottomUp[startN1][startN2+1][operations] = tempresultleft;
        }
        // else
        //     tempresultleft = dpBottomUp[startN1][startN2+1][operations];
        
        
        if(result<tempresultleft)
            result = tempresultleft;
            
        // result = max(result,tempresultleft);
        tempresultleft=dpBottomUp[startN1+1][startN2][operations];
        if(tempresultleft==-1) 
        {
            tempresultleft = computeLCSByRecurionTopDown(startN1+1,startN2,operations);
            // dpBottomUp[startN1+1][startN2][operations] = tempresultleft;
        }
        // else
        //     tempresultleft = dpBottomUp[startN1+1][startN2][operations];
        
        if(result<tempresultleft)
            result = tempresultleft;
        // result = max(result,tempresultleft);
        
    }
    
    addressofDpArray = result;
    
    return result;
}

// vector<vector<vector<int>>> dpBottomUp(2010,vector<vector<int>>(2010,vector<int>(9,-1)));
    
int main()
{
    // ios_base::sync_with_stdio(false);
    // ll n1;ll n2;
    
    // std::vector<ll> IN1;
    // std::vector<ll> IN2;
    scanf("%lld",&n1);
    scanf("%lld",&n2);
    scanf("%lld",&op);
    // cin >> n1 >> n2 >> op;
    // scanf("%ll %ll %ll",&n1,&n2,&op);
    for(ll i=0;i<n1;i++)
    {
        // ll V; cin >> V;
        // IN1.push_back(V);
        // IN1[i] = V;
        // cin >> IN1[i];
        scanf("%lld",&IN1[i]);
    }
    for(ll i=0;i<n2;i++)
    {
        // ll V; cin >> V;
        // IN2.push_back(V);
        
        // IN2[i] = V;
        // cin >> IN2[i];
        scanf("%lld",&IN2[i]);
        
    }
    // cout << n1 << " " << n2 << " " << op << " " << endl;
    // cout << " Compute k-LCS by Recursion " << computeLCSByRecurion(IN1,IN2,0,0,op) << endl;
    // cout << computeLCSByRecurion(IN1,IN2,n1-1,n2-1,op) << endl;
    // cout << computeKOrderLCS(IN1,IN2,n1,n2,op) << endl;
    
    // memset(&dpBottomUp,-1,sizeof(dpBottomUp));
    
    // for(ll i=0;i<2005;i++)
    //     for(ll j=0;j<2005;j++)
    //         for(ll k=0;k<8;k++)
    //             dpBottomUp[i][j][k]=-1;
    
    // cout << " Compute k-LCS by Recursion Top Down " << computeLCSByRecurionTopDown(IN1,IN2,0,0,op,dpBottomUp) << endl;
    
    // printf("%lld\n",computeLCSByRecurionTopDown(0,0,op));// << endl;
    
    cout << computeKOrderLCS(n1,n2,op) << endl;
    
    
    return 0;
}


