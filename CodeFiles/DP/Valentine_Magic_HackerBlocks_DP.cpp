#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<string.h>
#define int long long 
using namespace std;

int debug=0;
int no_of_boys,no_of_girls;
vector<int> chocolates,candies;
int dp[5001][5001];

int getMinCostMapping(int curr_boy,int curr_girl)
{
    if(debug)
    cout << " Curr " << curr_boy << " girl Index " << curr_girl << endl;

    // Base Case 

    // all boys gets Consumed 
    // to sum nothing will be added 
    if(curr_boy==no_of_boys)
        return 0;
    
    // It means all girls are Consumed 
    // no girls is available with boy to make pair
    // and this case should be ignored 
    // because there are no girls and only boys are left 
    // there can't be any pair 
    // because we have to ignore 
    // so we will return INF 
    if(curr_girl==no_of_girls)
        return INT_MAX;

    if(dp[curr_boy][curr_girl]!=-1) return dp[curr_boy][curr_girl];

    int boy_paired_with_girl = abs(chocolates[curr_boy]-candies[curr_girl]) + 
    getMinCostMapping(curr_boy+1,curr_girl+1);

    int boy_not_paired_with_girl = getMinCostMapping(curr_boy,curr_girl+1);
    
    return (dp[curr_boy][curr_girl] = min(boy_not_paired_with_girl,boy_paired_with_girl));
}

int32_t main()
{
    cin >> no_of_boys >> no_of_girls;

    chocolates.clear();
    candies.clear();
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<no_of_boys;i++)
    {
        int value;
        cin >> value;
        chocolates.push_back(value);
    }

    for(int i=0;i<no_of_girls;i++)
    {
        int value;
        cin >> value;
        candies.push_back(value);
    }

    sort(chocolates.begin(),chocolates.end());
    sort(candies.begin(),candies.end());

     if(debug)
     {
    for(int i=0;i<no_of_boys;i++)
    {
        cout << chocolates[i] << " : ";   
    }
    cout << endl;
    for(int i=0;i<no_of_girls;i++)
    {
        cout << candies[i] << " : ";   
    }
    cout << endl;
     }

    getMinCostMapping(0,0);
    if(debug)
    cout << " Cost :" << dp[0][0] << endl;
    else
    {
        cout << dp[0][0] << endl;
    }
    
    return 0;
}
