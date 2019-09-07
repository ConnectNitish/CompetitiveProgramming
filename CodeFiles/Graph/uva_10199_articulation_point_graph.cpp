#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<limits.h>
using namespace std;


map<string,int> mapping;
map<int,string> r_mapping;
map<int,set<int>> graph;
map<int,int> visitedtime;
map<int,bool> visited;
map<int,int> lowtime;
map<int,int> parent;

set<string> AP_Point;

int debug=0;

int _time=0;

void dfs(int src)
{
	visited[src]=true;
	lowtime[src]=_time;
	visitedtime[src] = _time;

	_time++;

	int childCount=0;

	for(auto ng:graph[src])
	{
		if(parent[ng]==src)
			continue;

		if(visited[ng]==false)
		{
			parent[ng] = src;
			childCount++;

			dfs(ng);

			lowtime[src] = min(lowtime[ng],lowtime[src]);

			if(visitedtime[src]<=lowtime[ng])
			{
				if(parent[src]!=-1)
				{
					AP_Point.insert(r_mapping[src]);
				}
			}

			if(parent[src]==-1 && childCount>1)
			{
				AP_Point.insert(r_mapping[src]);
			}
			
		}
		else 
		{
			lowtime[src] = min(lowtime[src],visitedtime[ng]);
		}
	}

	

}

int main()
{

	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	int noofnodes;
	int test_case_count=1;
	while(true)
	{
		cin >> noofnodes;
		if(noofnodes==0)
			break;
		else if(test_case_count!=1)
			cout << endl;

		AP_Point.clear();
		visited.clear();
		visitedtime.clear();
		graph.clear();
		lowtime.clear();
		mapping.clear();
		r_mapping.clear();
		parent.clear();
		_time=0;

		for(int i=0;i<noofnodes;i++)
		{
			string names;
			cin >> names;
			mapping[names] = i;
			r_mapping[i] = names;
			graph[i] = {}; 
			visited[i] = false;
			lowtime[i] = INT_MAX; 
			parent[i] = -2;
		}

		int routers;
		cin >> routers;

		for(int i=0;i<routers;i++)
		{
			string names1,names2;
			cin >> names1 >> names2;
			
			int src = mapping[names1];
			int dest = mapping[names2];

			graph[src].insert(dest);
			graph[dest].insert(src);
		}

		for(int i=0;i<noofnodes;i++)
		{
			if(visited[i]==false)
			{
				parent[i] = -1;
				dfs(i);
			}
		}

		// cout << AP_Point.size() << endl;
		cout << "City map #"<< test_case_count << ": " << AP_Point.size() <<" camera(s) found" << endl;
		for(auto a:AP_Point)
			cout << a << endl;

		

		test_case_count++;

	}
	return 0;
}