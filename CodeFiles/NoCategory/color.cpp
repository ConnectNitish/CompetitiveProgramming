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

void cnt(int start)
{
	if(start>=n) return;

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
		__count = (__count + 1)%MOD; return;
	}

	for(int i=start+1;i<n;i++)
	{
		if(data[i]-data[start]<=p)
		{
			temp.push_back(data[i]);
			cnt(i);
			temp.pop_back();
		}
	}
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
		
		sort(data.begin(),data.end());

		for(int i=0;i<n;i++)
		{
			temp.push_back(data[i]);
			cnt(i);
			temp.pop_back();
		}

		cout << __count << endl;

	}
}