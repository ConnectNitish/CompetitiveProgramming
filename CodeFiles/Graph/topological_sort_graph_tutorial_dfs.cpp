#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<set>
#include<queue>
using namespace std;

map<int,bool> visited;
map<int,set<int>> graph;
stack<int> nodes_in_topo;
map<int,int> indegree_count;

stack<pair<int,int>> levelWise_stack;

int debug=1;

void dfs_topo_sort(int src)
{
	visited[src] = true;
	for(auto ng:graph[src])
		if(visited[ng]==false)
			dfs_topo_sort(ng);

		nodes_in_topo.push(src);
	}

	void dfs_helper()
	{
		vector<int> topo_sort;
		
		for(auto a:visited)
		{
			if(a.second==false)
			{
				dfs_topo_sort(a.first);
			}
		}

		while(nodes_in_topo.empty()==false)
		{
			topo_sort.push_back(nodes_in_topo.top());
			nodes_in_topo.pop();
		}

		if(debug)
			cout << " DFS : Gives Topo Sort But not Guaranteed Lexicographiccaly Smallest " << endl;

		for(auto a:topo_sort)
		{
			cout << a << " ";
		}

		if(debug)
			cout<<endl;

	}


	int main()
	{
		if(debug)
		{
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		}
		int v,e;
		cin >> v >> e;

	// because graph is 1 based index 
		for(int i=1;i<=v;i++)
		{
			visited[i] = false;
			graph[i] = {};
			indegree_count[i]=0;
		}

		for(int i=0;i<e;i++)
		{
			int st,ed;
			cin >> st >> ed;
			graph[st].insert(ed);
		// graph[ed].insert(st);
			indegree_count[ed]++;
		}

		dfs_helper();

	}
