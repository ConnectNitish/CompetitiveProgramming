#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int debug=1;

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll k,r;
		
		cin >> k >> r;

		map<ll,ll> data;

		for(int i=0;i<=k;i++)
			data[i] = 0;

		for(int i=0;i<r;i++)
		{
			ll v;
			cin >> v;
			data[v] = 1;

			if(debug)
			{
				cout << " v " << v << endl;
			}
		}

		ll cur_height = k;
		ll coins=0;

		while(cur_height>0)
		{
			if(debug)
			{
				cout << " cur_height " << cur_height << " " << data[cur_height] << endl;
			}
			if(data[cur_height-1]==1 && data[cur_height-2]==0)
			{
				coins++;
			}
			cur_height -= 2;
		}

		cout << coins << endl;

	}
}