#include<bits/stdc++.h>
using namespace std;
#define int long long

#define N 900000
#define K 9

#define MOD 1000000007

map<int,int> frequency;
vector<int> data_distinct;
vector<int> data;

int debug=1;

int nCr(int r,int index,vector<vector<int>> &dp)
{
	if(index<r) return 0;
	if(r<0) return 0;
	if(index<=0) return 0;

	if(debug)
	{
		cout << index << " N " << r << " R " << endl;
	}

	if(r==0)
	{
		dp[index][r] = 1;
		return 1;
	}
	
	if(dp[index][r]!=-1) return dp[index][r];

	
	 
	dp[index][r] = (( frequency[data_distinct[index]] % MOD * ( nCr(r-1,index-1,dp) % MOD ) ) 
		+ ( nCr(r,index-1,dp) % MOD ) ) % MOD;

	 return dp[index][r];
}

int32_t main()
{
	int k,n;

	cin >> n >> k;
	
	frequency.clear();
	data_distinct.clear();
	data.clear();

	// data.push_back(1);

	for(int i=0;i<n;i++)
	{
		int v;
		cin >> v;
		frequency[v]++;
		data.push_back(v);
	}

	// Making 1 based index 
	// data_distinct.push_back(1);

	for(auto a:frequency)
		data_distinct.push_back(a.first);

	if(debug)
	{
		for(auto a:data_distinct)
			cout << a << " ";
		cout << endl;
	}
	
	int index = data_distinct.size();
	
	k = min(k,index);
	 
	vector<vector<int>> dp(index+1,vector<int>(k+1,-1));

	nCr(k,index,dp);

	cout << " Array " << endl;
	for(int i=1;i<=index;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	int value_final = 0;
	for(int i=1;i<=k;i++)
		value_final = (value_final + dp[index][i]) % MOD ;
	
	cout << value_final << endl;

	return 0;
}