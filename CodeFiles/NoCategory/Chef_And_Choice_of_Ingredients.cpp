#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll debug=0;

	ll n;
	cin >> n;
	vector<ll> data;
	while(n--)
	{
		ll v;
		cin >> v;
		data.push_back(v);
	}

	n= data.size();
	ll q;
	cin >> q;
	vector<ll> start,end,amt;
	while(q--)
	{
		ll l,r,y;
		cin >> l >> r >> y;
		start.push_back(l-1);
		end.push_back(r-1);
		amt.push_back(y);
	}

	q = start.size();

	vector<ll> dummy=data;
	for(ll i=0;i<q;i++)
	{
		sort(dummy.begin()+start[i],dummy.begin()+end[i]+1);

		if(debug)
		{
			cout << " Data Sorted  " << endl;
			for(ll k=start[i];k<=end[i];k++)
			{
				cout << dummy[k] << " ";	
			}
			cout << endl;
		}

		ll amount = amt[i];
		
		//amount -= dummy[i];
		ll got = -1;
		for(ll k=start[i];k<=end[i];k++)
		{
			if(k>start[i])
				dummy[k] += dummy[k-1]; 

			if(dummy[k]>=amount)
			{
				got = dummy[k];
				break;
			}
		}
		
		cout << got << endl;
		dummy = data;
	}

	return 0;
}