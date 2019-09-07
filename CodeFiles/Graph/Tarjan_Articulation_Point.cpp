#include<iostream>
#include<map>
#include<vector>
#include<limits.h>
using namespace std;

map<int,vector<int>> gr;
map<int,bool> visited;
map<int,int> visitedTime;
map<int,int> parent;
map<int,int> lowtime;
std::vector<int> AP_Points;

int time=0;
int debug=1;

void dfs_for_AP(int src)
{
	visited[src] = true;
	time++;
	visitedTime[src] = time;
	lowtime[src] = time;
	int noofchildren = 0;

	bool isArticulationPointEligible = false;

	for(auto neighbour:gr[src])
	{
		if(parent[neighbour]==src)
			continue;

		if(visited[neighbour]==false)
		{
			noofchildren++;
			
			parent[neighbour] = src;

			dfs_for_AP(neighbour);
			
			if(visitedTime[src]<=lowtime[neighbour])
				isArticulationPointEligible = true;
			else
				lowtime[src] = min(lowtime[src],lowtime[neighbour]);


		}
		// if the node is visited 
		else
		{
			lowtime[src] = min(lowtime[src],visitedTime[neighbour]);
		}
	}

	bool isArticulationPointFinal = false;

	if(parent[src] == NULL && noofchildren==2)
	{
		isArticulationPointFinal = true;
	}
	else if(parent[src]!= NULL && isArticulationPointEligible==true)
	{
		isArticulationPointFinal = true;
	}

	if(isArticulationPointFinal)
	{
		AP_Points.push_back(src);
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

	gr.clear();
	visited.clear();
	lowtime.clear();
	visitedTime.clear();
	AP_Points.clear();
	parent.clear();

	for(int i=0;i<v;i++)
	{
		gr[i] = {};
		visited[i] = false;
		lowtime[i] = INT_MAX;
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		gr[st].push_back(ed);
		gr[ed].push_back(st);
	}




	return 0;
}