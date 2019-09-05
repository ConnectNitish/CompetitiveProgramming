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

int debug=0;

void bfs_topo_sort(vector<int> &sorted_topo,multiset<int> &_multiset)
{
	while(_multiset.size()>0)
	{
		int current = *_multiset.begin();
		_multiset.erase(_multiset.begin());
		sorted_topo.push_back(current);
		
		for(auto ngb:graph[current])
		{
			if(indegree_count[ngb]>0)
			{
				indegree_count[ngb]--;
				if(indegree_count[ngb]==0)
				{
					_multiset.insert(ngb);
				}
			}
		}
	}
}

void bfs_helper()
{
	vector<int> sorted_topo;
	multiset<int> _multiset;

	for(auto a:indegree_count)
	{
		if(a.second==0)
		{
			_multiset.insert(a.first);
		}
	}

	bfs_topo_sort(sorted_topo,_multiset);

	if(debug)
		cout << " BFS Lexo Sorted Topo " << endl;

	for(auto a:sorted_topo)
	{
		cout << a << " ";
	}

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

	if(debug)
		cout << " Gives Topo Sort But not Lexicographiccaly Smallest " << endl;

	bfs_helper();

}
