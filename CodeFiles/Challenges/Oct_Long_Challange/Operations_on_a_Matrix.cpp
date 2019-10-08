#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> rows;
vector<int> cols;

int debug = 1;

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
		int n,m,q;
		cin >> n >> m >> q;

		// if(m>n) swap(n,m);

		rows.clear();
		cols.clear();

		rows.resize(n+1,0);
		cols.resize(m+1,0);

		for(int i=0;i<q;i++)
		{
			int x,y;
			cin >> x >> y;
			
			rows[x]++;
			cols[y]++;

			rows[x] = rows[x] % 2;
			cols[y] = cols[y] % 2;
		}

		int odds_in_rows = 0;
		int even_in_rows = 0;
		
		for(int i=1;i<=n;i++)
		{
			if((rows[i]&1)==1)
				odds_in_rows++;
			else
				even_in_rows++;
		}		

		int countofodd = 0;

		for(int i=1;i<=m;i++)
		{
			if((cols[i]&1) == 1)
				countofodd += even_in_rows;
			else
				countofodd += odds_in_rows;
		}

		cout << countofodd << endl;
	}
	return 0;
}