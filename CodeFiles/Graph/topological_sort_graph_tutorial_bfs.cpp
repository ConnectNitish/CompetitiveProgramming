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

void bfs_topo_sort(vector<int> &sorted_topo,queue<int> &_queue)
{
	while(_queue.size()>0)
	{
		int current = _queue.front();
		_queue.pop();

		sorted_topo.push_back(current);
		
		for(auto ngb:graph[current])
		{
			if(indegree_count[ngb]>0)
			{
				indegree_count[ngb]--;
				if(indegree_count[ngb]==0)
				{
					_queue.push(ngb);
				}
			}
		}
	}
}

void bfs_helper()
{
	vector<int> sorted_topo;
	queue<int> _queue;

	for(auto a:indegree_count)
	{
		if(a.second==0)
		{
			_queue.push(a.first);
		}
	}

	bfs_topo_sort(sorted_topo,_queue);

	if(debug)
		cout << " BFS Topo " << endl;

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
		cout << " BFS : Gives Topo Sort But not Lexicographiccaly Smallest " << endl;

	bfs_helper();

}
