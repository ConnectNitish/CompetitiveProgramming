#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> graph;
vector<int> visited;
int min_node;

void dfs(int src)
{
	// min_node = min(min_node,src);

	if(min_node>src)
		min_node = src;

	visited[src] = 1;

	for(auto a:graph[src])
	{
		if(visited[a]==0)
			dfs(a);
	}
}

int debug=0;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int u,v;
		cin >> u >> v;

		visited.clear();
		graph.clear();
		visited.resize(u+1,0);

		for(int i=0;i<=u;i++)
		{
			graph[i] = {};
			visited[i] = 0;
		}

		for(int i=0;i<v;i++)
		{
			int s,d;
			cin >> s >> d;
			graph[s].push_back(d);
		}

		vector<int> values;
		long long total_sum = 0;
		for(int i=1;i<=u;i++)
		{
			min_node = (u+2);
			if(visited[i]==0)
			{
				dfs(i);
				
				if(debug)
					cout << ":" << min_node << endl;

				total_sum += min_node;
			}
			// values.push_back(min_node);

			

			
		}

		// sort(values.begin(),values.end());

		cout << (total_sum>0 ? total_sum-1 : total_sum) << endl;
	}
}