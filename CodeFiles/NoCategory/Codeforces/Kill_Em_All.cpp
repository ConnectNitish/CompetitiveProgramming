#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll k,r;
		
		cin >> k >> r;
		vector<int> data;
		// ll max_elemnt = LONG_MIN;
			
		set<int> data_set;

		for(int i=0;i<k;i++)
		{
			ll v;
			cin >> v;
			// data.push_back(v);
			data_set.insert(v);

			// max_elemnt = max(max_elemnt,v);
			
		}

		data = {data_set.begin(),data_set.end()};

		// sort(data.begin(),data.end());
		ll size = data.size();

		ll b = (long long)ceil(data.back() / r);

		ll answer = 0;
		ll cnt =0;

		for(int i=(size-1);i>=0;i--)
		{
			if(cnt * r < data[i])
			{
				cnt++;
				answer++;
			}
			else
				break;
		}

		cout << answer << endl;
		
	}	
}