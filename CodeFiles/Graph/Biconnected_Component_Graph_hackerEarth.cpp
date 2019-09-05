#include<iostream>
#include<map>
#include<limits.h>
#include<set>
#include<vector>
#include<stack>
using namespace std;

// https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/

//refrences:
//https://github.com/jgrapht/jgrapht/blob/master/jgrapht-core/src/main/java/org/jgrapht/alg/connectivity/BiconnectivityInspector.java

map<int,set<int>> graph;
map<int,bool> visited;
map<int,int> parent;
map<int,int> visitedtime;
map<int,int> lowtime;

stack<pair<int,int>> biconnected_component_edges;
vector<set<int>> all_biconnected_component_vertices;

set<int> AP_point; 

set<pair<int,int>> bridges_edge;

int _time=-1;
int debug=0;

void get_biconnected_component(int src,int ngb,int disc_visited_time_of_AP)
{
	// now because the node is for articulation point 
				// and it is not root of DFS call 
				// pop all the edges from the stack till the 
				// current edge is seen 

	set<int> vertices_in_biconnected_component;
	while(biconnected_component_edges.empty()==false)
	{
		pair<int,int> TOS = biconnected_component_edges.top();

		// if the current edge is visited before the 
		// src then the edge is not considerd 
		// because it will not belong to biconncted component
		// only the edge considerd are the one visited 
		// post the src node is visited not previous to that 
		// edge_visited_1 -- src visited -- edge_visited_2
		// time -----> 
		// edge_visited_1 is not considerd in biconnectedcomponent by vertex src
		// edge_visited_2 are only considerd in biconnected compoment by vertex src

		if(visitedtime[TOS.first]<disc_visited_time_of_AP 
			|| visitedtime[TOS.second] < disc_visited_time_of_AP)
		{
			break;
		}

		biconnected_component_edges.pop();
		vertices_in_biconnected_component.insert(TOS.first);
		vertices_in_biconnected_component.insert(TOS.second);

		if(debug)
		{
			cout << " edges are " << TOS.first << " " << TOS.second << " " << endl;
		}

		// till current edge is not seen 
		if(TOS.first==src && TOS.second==ngb)
			break;
	} 

	if(vertices_in_biconnected_component.size()>0)
		all_biconnected_component_vertices.push_back(vertices_in_biconnected_component);
}

void dfs(int src)
{
	_time++;

	visited[src]=true;
	visitedtime[src]=_time;
	lowtime[src]=_time;
	int childCount=0;

	bool isEligibleForArticulationPoint=false;
	
	for(int ngb:graph[src])
	{
		if(parent[src]==ngb)
			continue;

		if(visited[ngb]==false)
		{
			childCount++;
			parent[ngb] = src;

			// pushing edge for bi conncted component 
			biconnected_component_edges.push({src,ngb});

			if(debug)
			{
				cout << " Pushed in Stack Not Visited " << endl;
				cout << src << " :: " << ngb << endl;
			}

			dfs(ngb);

			lowtime[src] = min(lowtime[src],lowtime[ngb]);

			if(visitedtime[src]<=lowtime[ngb])
				isEligibleForArticulationPoint=true;

			// logic for adding bridge
			// not relevant for this question 
			if(visitedtime[src]<lowtime[ngb])
				bridges_edge.insert({src,ngb});

			// logic for getting biconncted component edges
			// Case 1 root of DFS and at least two neighbouring child  
			if(parent[src]==-1 && childCount>1)
			{
				if(debug)
				{
					cout << " AP is " << src << endl;
				}
				get_biconnected_component(src,ngb,visitedtime[src]);
				AP_point.insert(src);
			}
			// Case 2 current node is not root of DFS tree 
			// but neighbour is satisfying condition 
			// visitedtime[src] <= lowtime[neighbour]
			else if(parent[src]!=-1 && isEligibleForArticulationPoint==true)
			{
				if(debug)
				{
					cout << " AP is " << src << endl;
				}
				get_biconnected_component(src,ngb,visitedtime[src]);
				AP_point.insert(src);
			}
		}
		// modification to Tarjan Algo 
		// update the low link only when 
		// the neighbour is previously visited 
		// from the current node 
		else if(visitedtime[ngb]<visitedtime[src])
		{
			lowtime[src] = min(lowtime[src],lowtime[ngb]);
			biconnected_component_edges.push({src,ngb});

			if(debug)
			{
				cout << " Pushed in Stack Visited " << endl;
				cout << src << " :: " << ngb << endl;
			}

			
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

	int v,e;
	cin >> v >> e;

	for(int i=0;i<=v;i++)
	{
		graph[i] = {};
		visited[i] = false;
		lowtime[i] = INT_MAX;
		parent[i] = -2;
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		graph[st].insert(ed);
		graph[ed].insert(st);
	}

	for(auto vs:visited)
	{
		if(vs.second==false)
		{
			parent[vs.first] = -1;
			dfs(vs.first);

			set<int> vertices_in_biconnected_component;
			while(biconnected_component_edges.empty()==false)
			{
				pair<int,int> TOS = biconnected_component_edges.top();
				biconnected_component_edges.pop();
				vertices_in_biconnected_component.insert(TOS.first);
				vertices_in_biconnected_component.insert(TOS.second);
			} 

			if(vertices_in_biconnected_component.size()>0)
				all_biconnected_component_vertices.push_back(vertices_in_biconnected_component);
		}
	}

	if(debug)
	{
		for(auto a:all_biconnected_component_vertices)
		{
			cout << " Vertices for conncted component " << endl;
			for(auto vertices:a)
				cout << vertices << " ";
			cout << endl;
		}

		cout << " articulation point " << endl;
		for(auto a:AP_point)
			cout << a << " ";
		cout << endl;
	}

	int no_of_odd_vertices = 0;
	for(auto a:all_biconnected_component_vertices)
	{
		if((a.size()&1)==1)
			no_of_odd_vertices++;
	}

	cout << no_of_odd_vertices << " ";
	cout << (all_biconnected_component_vertices.size()-no_of_odd_vertices) << endl;



	return 0;
} 


/*


Input 1:

6 6
0 3
3 2
2 5
4 5
1 4
2 4

Output 1:

2 4

*/