#include <bits/stdc++.h> 
using namespace std; 
#define int long long int 
map<int,int> dp;

#define MOD 1000000007

int countWays(int n,int a,int b) 
{ 
	dp.clear();

	dp[a]=1;
	dp[b]=1; 

	for (int i = min(a,b)+1; i <= n; i++)
	{
		if(i==a || i==b)
			continue;

		if(dp.find(i-a)!=dp.end() && dp.find(i-b)!=dp.end())
			dp[i] = (dp[i - a] + dp[i - b]) % MOD;  		
		else if(dp.find(i-a)!=dp.end())
			dp[i] = dp[i - a] % MOD;
		else if(dp.find(i-b)!=dp.end())
			dp[i] = dp[i - b] % MOD;  		
	} 
	
	return dp.find(n) != dp.end() ? dp[n] % MOD : 0 ; 
} 

// driver code 
int32_t main() 
{ 
	int t;
	cin >> t;
	while(t--)
	{
		int n,a,b;
		cin >> n >> a >> b; 
		cout << countWays(n,a,b) % MOD << endl; 
	}
	return 0; 
} 
