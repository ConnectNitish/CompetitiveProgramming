#include<bits/stdc++.h>
#define ll long long
// https://www.codechef.com/SGHC2019/problems/BFLSEQ
using namespace std;

ll __count=0;
vector<ll> data;
ll n,k,p;
vector<ll> temp;

#define MOD 1000000007
ll debug=0;

vector<vector<int>> dp;

ll cnt(int start,int tempk)
{
	if(start>=n) return 0;



	if(temp.size()==k)
	{
		if(debug)
		{
			for(auto a:temp)
			{
				cout << a << " ";
			}
			cout << endl;
		}
		// __count = (__count + 1)%MOD; 
		return 1;
	}

	if(dp[start][tempk]!=-1) return dp[start][tempk];
	ll tempreturn =0;
	for(int i=start+1;i<n-tempk+1;i++)
	{
		if(data[i]-data[start]<=p)
		{
			temp.push_back(data[i]);
			tempreturn = (tempreturn + cnt(i,tempk-1)) % MOD;
			temp.pop_back();
		}
		else
			break;
	}

	dp[start][tempk] = tempreturn;

	return tempreturn;
}

int main()
{

	ll t;
	cin >> t;
	while(t--)
	{
		
		cin >> n >> k >> p;
		data.clear();
		temp.clear();
		__count=0;
		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			data.push_back(v);
		}
		dp.clear();
		dp.resize(n,vector<int>(k,-1));
		sort(data.begin(),data.end());

		ll tempreturn =0 ;

		for(int i=0;i<n-k+1;i++)
		{
			temp.push_back(data[i]);
			
			tempreturn = (tempreturn + cnt(i,k-1)) % MOD;
			
			temp.pop_back();
		}

		cout << tempreturn << endl;

	}
}