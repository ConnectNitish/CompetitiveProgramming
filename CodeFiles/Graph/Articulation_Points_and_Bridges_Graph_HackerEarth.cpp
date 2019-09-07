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
vector<int> AP_Points;

map<int,vector<int>> componentsbyvertex;

set<pair<int,int>> bridges_edge;

int _time=0;
int count_of_artuculation_point=0;

int debug=0;

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
			}
			else
				lowtime[src] = min(lowtime[src],lowtime[neighbour]);

			// for adding bridge 
			if(visitedTime[src]<lowtime[neighbour])
			{
				bridges_edge.insert({src,neighbour});
			}
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
		// AP_Points.insert(src);
		AP_Points[src] = 1;
		count_of_artuculation_point++;
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
	bridges_edge = set<pair<int,int>>();

	count_of_artuculation_point=0;

	AP_Points.resize(v);

	for(int i=0;i<v;i++)
	{
		gr[i] = {};
		visited[i] = false;
		lowtime[i] = 0;
		parent[i] = -2;
		AP_Points[i]=0;
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
	
	if(debug)
		cout << " NO of Articulation Point " << endl;

	cout << count_of_artuculation_point << endl;

	if(debug)
		cout << " Articulation Point are : " << endl;

	for(int i=0;i<v;i++)
	{
		if(AP_Points[i]==1)
			cout << i << " ";
	}

	if(count_of_artuculation_point>0)
		cout << endl;

	if(debug)
		cout << endl;

	int no_of_bridges = 0;
	
	if(debug)
		cout << " No of Bridges " << endl;

	cout << bridges_edge.size() << endl;
	for(auto bridge:bridges_edge)
		cout << bridge.first << " " << bridge.second << endl;

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


	return 0;
}


/*


Input 1:

8 9
0 2
0 1
1 2
2 3
3 4
6 4
4 5
5 7
6 5

Output 1:

4
2 3 4 5 
3
2 3
3 4
5 7

*/