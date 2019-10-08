#include<bits/stdc++.h>
using namespace std;
#define int long long

int debug=1;

int32_t main()
{
	if(debug)
	{
		freopen("input.txt","rb",stdin);
		freopen("output.txt","wb",stdout);	
	}

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int v;
		cin >> v;

		int count = 1;

		int min_price = v;

		vector<int> last5;
		last5.push_back(v);

		for(int i=1;i<n;i++)
		{
			cin >> v;
			if(i<=4)
			{
				last5.push_back(v);
				if(min_price > v)
				{
					count++;
					min_price = min(min_price,v);
				}
				continue;
			}

			int k=0;
			for(;k<5;k++)
			{
				if(last5[k]<=v)
					break;
			}

			if(k==5)
				count++;

			last5.erase(last5.begin());
			last5.push_back(v);

		}

		cout << count << endl;

	}
}