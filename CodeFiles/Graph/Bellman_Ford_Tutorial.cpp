#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

int debug=0;

int main()
{

	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	map<int,vector<pair<int,long long>>> gr;
	map<pair<int,int>,long long> graph;

	int v,e;
	cin >> v >> e;

	for(int i=0;i<=v;i++)
		gr[i]={};

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st  >> ed ;
		long long wt;
		cin >> wt;
		// gr[st].push_back({ed,wt});
		// gr[ed].push_back({st,wt});
		graph[{st,ed}] = wt;
	}

	int source;
	cin >> source;

	vector<int> distance(v+1,INT_MAX);
	distance[source] = 0;

	for(int i=1;i<=v-1;i++)
	{
		for(auto edges:graph)
		{
			if(distance[edges.first.first]!=INT_MAX)
			{
				if(distance[edges.first.second] > distance[edges.first.first] + edges.second)
				{
					distance[edges.first.second] = distance[edges.first.first] + edges.second;
				}
			}
		}
	}

	bool isCycle = false;
	for(auto edges:graph)
	{
		if(distance[edges.first.first]!=INT_MAX 
			&& 
			distance[edges.first.second] > distance[edges.first.first] + edges.second)
		{
			isCycle = true;
			break;
		}
	}

	if(isCycle)
		cout << -1 << endl;
	else
	{
		long long _ans = 0;
		long long maxDistance = 0;
		for(int i=1;i<=v;i++)
		{
			if(debug)
			{
				cout << " NOde " << distance[i] << " :: " << endl;
			}
			_ans += distance[i];
			maxDistance = max((long long)distance[i],maxDistance);
		}
		cout << maxDistance << endl;
	}

	return 0;

}