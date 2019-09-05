#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> gd;
map<int,vector<int>> rgd;

int debug=0;

void dfs(map<int,vector<int>> &gd,vector<int> &vs,
	int s,stack<int> &all_node,int first)
{
	vs[s]=1;
	for(auto ng:gd[s])
	{
		if(vs[ng]==0)
		{
			dfs(gd,vs,ng,all_node,first);
		}
	}

	// shows first 
	// traversal of the graph 
	// stack will store all the elements 
	// in order of connected component
	if(first==1)
		all_node.push(s);
}

int kosaraju(int V, vector<int> adj[])
{
	vector<pair<int,int>> edges;

	for(int i=0;i<V;i++)
	{
		gd[i] = adj[i];
		rgd[i] = {};
		for(auto a:gd[i])
		{
			edges.push_back({i,a});
		}
	}

	for(auto a:edges)
	{
		rgd[a.second].push_back(a.first);
	}

	vector<int> vs(V,0);
	stack<int> st;

	for(int i=0;i<V;i++)
	{
		if(vs[i]==0)
		{
			dfs(gd,vs,i,st,1);
		}
	}

	// if(debug)
	// {
	// 	cout << " First Run " << cmp_first_run << endl;
	// }

	int cmp_first_run=0;

	fill(vs.begin(),vs.end(),0);
	while(st.empty()==false)
	// for(int i=0;i<V;i++)
	{
		int node = st.top();
		st.pop();
		if(vs[node]==0)
		{
			cmp_first_run++;
			dfs(rgd,vs,node,st,0);
		}
	}

	return cmp_first_run;

}

int main()
{
	debug=0;

	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		int m,n;
		vector<int> adj[a+1];
		for(int i=0;i<b;i++)
		{
			cin >> m >> n;
			adj[m].push_back(n);

			if(debug)
				cout << " m n " << m << " " << n << endl;
		}

		cout << kosaraju(a,adj) << endl;
	}
}