// https://www.codechef.com/LTIME77B/problems/INVZCNT

// https://discuss.codechef.com/t/invzcnt-unofficial-editorial/42939



#include<bits/stdc++.h>
using namespace std;
#define int long long 

int F[40],T[40];
int digits = 31;

int debug=1;

void solve(int bit,vector<int> data)
{

	// if(debug)
	// 	cout << " bit " << bit << endl;

	if(bit<0 || data.size()==0)
		return;

	vector<int> l,r;
	for(int i=0;i<data.size();i++)
	{
		if(1 & (data[i] >> bit))
		{
			T[bit] += l.size();
			r.push_back(data[i]);
		}
		else
		{
			l.push_back(data[i]);
			F[bit] += r.size();
		}
	}
	solve(bit-1,l);	
	solve(bit-1,r);
}

int32_t main()
{
	int t,n,q;
	cin >> t;
	while(t--)
	{
		cin >> n >> q;
		vector<int> data(n);
		
		for(int i=0;i<n;i++)
			cin >> data[i];
		
		for(int k=digits;k>=0;k--)
		{
			T[k] = F[k] = 0;
		}

		solve(digits-1,data);

		for(int i=0;i<q;i++)
		{
			int v;
			cin >> v;
			int total = 0;
			for(int k=digits-1;k>=0;k--)
			{
				if(1 & (v >> k))
					total += T[k];
				else
					total += F[k];
			}

			cout << total << endl;
		} 
	}
	return 0;
}
