#include<iostream>
#define pr pair<int,long long>
#include<map>
#include<set>
#include<limits.h>
#include<queue>
using namespace std;

map<int,long long> _distance;
map<int,int> visited;
map<int,set<pr>> graph;

int debug = 0;

void dijkshtra(int source)
{
	priority_queue<pr,vector<pr>,greater<pr>> pq;
	pq.push({0,source});
	_distance[source]=0;

	while(pq.empty()==false)
	{
		int cur_node = pq.top().second;
		long long weight = pq.top().first;
		pq.pop();

		if(debug)
		{
			cout << " Node " << cur_node << " weight " << weight << endl;
		}

		// if(visited[cur_node]==true)
		// 	continue;

		for(auto ng:graph[cur_node])
		{
			if(_distance[ng.first]>_distance[cur_node]+ng.second && _distance[cur_node]!=INT_MAX)
			{
				_distance[ng.first] = _distance[cur_node]+ng.second;	
				pq.push({_distance[ng.first],ng.first});
			}
		}

		visited[cur_node] = true;
	}

	for(auto a:_distance)
	{
		if(a.first==source)
			continue;

		if(a.second == INT_MAX)
			cout << -1 << " ";
		else
			cout << a.second << " ";
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{

		_distance.clear();
		visited.clear();
		graph.clear();

		int n,e;
		cin >> n >> e;

		set<pr> ng;
		for(int i=1;i<=n;i++)
		{
			_distance[i] = INT_MAX;
			visited[i] = false;
			graph[i] = ng;
		}

		for(int k=0;k<e;k++)
		{
			int st,ed;
			cin >> st >> ed;
			long long wt;
			cin >> wt;
			pr temp = {ed,wt};
			graph[st].insert(temp);
			graph[ed].insert({st,wt});				
		}

		int source;
		cin >> source;

		dijkshtra(source);

	}

	return 0;
}