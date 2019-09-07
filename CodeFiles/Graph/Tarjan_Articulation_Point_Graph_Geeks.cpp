#include<iostream>
#include<map>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;

map<int,vector<int>> gr;
map<int,bool> visited;
map<int,int> visitedTime;
map<int,int> parent;
map<int,int> lowtime;
std::vector<int> AP_Points;

map<int,vector<int>> componentsbyvertex;

set<pair<int,int>> bridges_edge;

int _time=0;
int debug=1;

void dfs_for_AP(int src)
{
	_time++;

	visited[src] = true;
	visitedTime[src] = _time;
	lowtime[src] = _time;
	
	// used only for root 
	int noofchildren = 0;

	if(debug)
	{
		cout << " Start : src " << src ;
		cout << " visitedTime[src] " << visitedTime[src] ;
		cout << " lowtime[src] " << lowtime[src] ;
		cout << " parent[src] " << parent[src] ;
		cout << endl;
	}

	bool isArticulationPointEligible = false;

	for(auto neighbour:gr[src])
	{
		// if i am not parent of source 
		// skipping src 
		if(parent[src]==neighbour)
		{
			if(debug)
			{
				cout << " SRC " << src << " Parent " << parent[neighbour] << endl;
			}
			continue;
		}

		if(visited[neighbour]==false)
		{
			noofchildren++;
			
			parent[neighbour] = src;

			dfs_for_AP(neighbour);

			// if visited time is less than either 
			// of its neighbour 
			// it shows if I remove from src then 
			// respective neighbour will get disconnets 
			// from graph 
			// we can count how many components can be made 
			// if we remove the particular src vertex  
			if(visitedTime[src]<=lowtime[neighbour])
			{
				isArticulationPointEligible = true;

				// add on not essentials 
				if(componentsbyvertex.find(src)==componentsbyvertex.end())
					componentsbyvertex[src] = {neighbour};
				else
					componentsbyvertex[src].push_back(neighbour);

				if(visitedTime[src]<lowtime[neighbour])
					bridges_edge.insert({src,neighbour});
			}
			else
				lowtime[src] = min(lowtime[src],lowtime[neighbour]);
		}
		// if the node is visited 
		// then as per Tarjan algo we 
		// need to set low time of 
		// node 
		else
		{
			lowtime[src] = min(lowtime[src],visitedTime[neighbour]);
		}
	}

	if(debug)
	{
		cout << " End : src " << src ;
		cout << " visitedTime[src] " << visitedTime[src] ;
		cout << " lowtime[src] " << lowtime[src] ;
		cout << " isArticulationPointEligible " << isArticulationPointEligible ;
		cout << " parent[src] " << parent[src] ;
		cout << endl;
	}

	bool isArticulationPointFinal = false;

	if(parent[src] == -1 && noofchildren>=2)
	{
		isArticulationPointFinal = true;
	}
	else if(parent[src]!= -1 && isArticulationPointEligible==true)
	{
		isArticulationPointFinal = true;
	}

	if(isArticulationPointFinal == true)
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
		lowtime[i] = 0;
		parent[i] = -2;
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		gr[st].push_back(ed);
		gr[ed].push_back(st);
	}

	for(auto a:visited)
	{
		if(a.second==false)
		{
			parent[a.first] = -1;
			dfs_for_AP(a.first);
		}
	}

	cout << " Articulation Point " << endl;
	for(auto a:AP_Points)
	{
		cout << a << " ";
	}
	cout << endl;

	if(debug)
	{
		for(auto a:componentsbyvertex)
		{
			cout << " through " << a.first << " following edge ensures its Articulation Point " << endl;
			for(auto edge:a.second)
			{
				cout << " Edge : " << a.first << " -> " << edge << endl;
			}
		}
		cout << endl;


	}

	if(debug)
		cout << " No of Bridges " << endl;

	cout << bridges_edge.size() << endl;
	for(auto bridge:bridges_edge)
		cout << bridge.first << " " << bridge.second << endl;


	return 0;
}