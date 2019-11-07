#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> m_c[10010];

int debug=0;

bool _customSort(const pair<int,int> &p1,const pair<int,int> &p2)
{
	return (p1.first <= p2.first);
}

int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m,n;
		cin >> m >> n;

		// vector<vector<int>> m_c(n);

		for(int i=0;i<10010;i++)
			m_c[i] = {};

		int diff_value = INT_MAX;

		int c_i=0;
		for(int i=0;i<m;i++)
		{
			int v;
			cin >> v;
			m_c[c_i].push_back(v);
			c_i++;
			if(c_i == n)
				c_i=0;
		}

		int m_max[n+1]={0};

		for(int i=0;i<n;i++)
			sort(m_c[i].begin(),m_c[i].end()),m_max[i] = m_c[i].size();


		int index_m[n+1]={0};
		bool toBreak = false;

		if(debug)
		{
			for(int i=0;i<n;i++)
			{
				cout << " Index " << i << endl;
				for(auto b:m_c[i])
					cout << b << " ";
				cout << endl;
			}
		}

		vector<pair<int,int>> c_data;
		memset(index_m,0,sizeof index_m);

		for(int k=0;k<n;k++)
			c_data.push_back({m_c[k][index_m[k]],k});

		pair<int,int> min_pr = *min_element(c_data.begin(),c_data.end());
		pair<int,int> max_pr = *max_element(c_data.begin(),c_data.end());
		diff_value = abs(min_pr.first - max_pr.first);

		c_data.erase(min_element(c_data.begin(),c_data.end()));

		while(true)
		{
			index_m[min_pr.second]++;
			
			if(index_m[min_pr.second] >= m_c[min_pr.second].size())
				break;

			c_data.push_back({m_c[min_pr.second][index_m[min_pr.second]],min_pr.second});

			min_pr = *min_element(c_data.begin(),c_data.end());
			max_pr = *max_element(c_data.begin(),c_data.end());

			if(diff_value>abs(min_pr.first - max_pr.first))
				diff_value = abs(min_pr.first - max_pr.first);

			c_data.erase(min_element(c_data.begin(),c_data.end()));
		}

		cout << diff_value << endl;


	}
}
