	  /******************************************************************************


	*******************************************************************************/
	#include <bits/stdc++.h>
using namespace std;

int debug=0;

	template < typename T > class Graph
{
public:
	map < T, vector < T >> adjlist;
	vector < vector < T >> adjListVector;

	map < T, T > parent;
	map < T, int >distance;
	map<T,bool> visited;
	map < T, int > indegree;



	int size = 0;

	Graph (int noofvertices)
	{
		adjlist.clear ();
		adjListVector.clear ();
	    	// 1 based Indexes 
		adjListVector.resize (noofvertices);
		this->size = noofvertices;
	}

	void reset()
	{
		this->indegree.clear();
		this->parent.clear();
		this->distance.clear();
		this->visited.clear();
		this->adjlist.clear();
		this->adjListVector.clear();
		this->size=0;
	}

	void addEdge (T u, T v, bool bidirectional)
	{
		adjListVector[u].push_back (v);
		adjlist[u].push_back (v);



		if (bidirectional)
		{
			adjListVector[v].push_back (u);
			adjlist[v].push_back (u);
		}
		else
		{
				// if the node is not there then add it 
				// and because its not bidirectional 
				// so no need of edge 
			if(adjlist.find(v)==adjlist.end())
			{
				adjlist[v] = {};
			}
		}

			// if u and v both are same 
		if(u==v)
		{
			if(indegree.find(u)==indegree.end())
			{
				indegree[u] = 0;
			}
		}
		else
		{
			indegree[v]++;

			if(indegree.find(u)==indegree.end())
			{
				indegree[u] = 0;
			}
		}

		visited[u] = false;
		visited[v] = false;

	}

	void printGraph ()
	{
		cout << endl ; 
		for (auto a:adjlist)
		{
			cout << " Start " << a.first << " :";
			for (auto b:adjlist[a.first])
			{
				cout << b << " ";
			}
			cout << endl;
		}
	}

	vector<T> getPath(T lastNode)
	{
		vector<T> AllNodeinPath;
		while(lastNode!=parent[lastNode])
		{
			AllNodeinPath.push_back(lastNode);
			lastNode = parent[lastNode];
		}
		AllNodeinPath.push_back(lastNode);
		reverse(AllNodeinPath.begin(),AllNodeinPath.end());
		return AllNodeinPath;
	}

	void bfsTraversal (T source)
	{
		if(visited[source]==true)
			return;

		distance.clear();

		queue < T > q;
		q.push (source);
		visited[source] = true;
		distance[source] = 0;
		parent[source] = source;

		T lastNode = source;

		while (q.empty () == false)
		{
			lastNode = q.front ();
			q.pop ();
			for (auto neighbour:adjlist[lastNode])
			{
				if (visited[neighbour] == false)
				{
					parent[neighbour] = lastNode;
					visited[neighbour] = true;
					distance[neighbour] = distance[lastNode] + 1;
					q.push (neighbour);
				}
			}
		}

	      // get Entire Path
		cout << " Traversal Path " << endl;
		vector<T> paths = getPath(lastNode);
		for(auto a:paths)
		{
			cout << a << " ";
		}
		cout << endl;

		cout << " Distance Path From Source " << endl;
		for(auto a:distance)
		{
			cout << " Source " << source << " : Destination " << a.first << " Distance : " << a.second << endl;
		}
		cout << endl;
	}

	bool isBiPartite_DFS(map<T,vector<T>> Graph,T source,map<T,T> &color,int curr_color)
	{
		if(color.find(source) != color.end() && color[source]==curr_color) return true;

		color[source] = curr_color;

		for(auto ng:Graph[source])
		{
			if(color.find(ng)== color.end())
			{
				bool is_value = isBiPartite_DFS(Graph,ng,color,(curr_color+1)%2);
				if(is_value == false)
					return is_value;
			}
			else
			{
				if(color[ng]!=curr_color)
					return false;
			}
		}

		return true;
	}

	bool isBiPartite_BFS(map<T,vector<T>> Graph,T source,map<T,T> &color,int curr_color)
	{
		queue<pair<T,int>> q;
		q.push({source,curr_color});
		color[source] = curr_color;

		while(q.empty()==false)
		{
			pair<T,int> cur_node = q.front();
			q.pop();
			for(auto node : Graph[cur_node.first])
			{
				int temp_curr_color = (cur_node.second + 1) % 2;

				// still not colored
				if(color.find(node)==color.end())
				{
					q.push({node,temp_curr_color});
					color[node] = temp_curr_color;
				}
				// if node is colored 
				// but not of the desired color 
				else
				{
					if(color[node]!=temp_curr_color)
						return false;
				}
			}
		}

		return true;
	}

	bool isBipartite_moreSimpler(map<T,vector<T>> graph,T source)
	{
		vector<int> color_graph(graph.size()+1,-1);
		
		// no color is assigned to any node
		// memset(color_graph,-1,sizeof(color_graph));

		// starting from 1 
		color_graph[1] = 0;
		queue<T> q;
		q.push(source);

		bool is_bi_partite = true;

		while(q.empty()==false && is_bi_partite)
		{
			T cur_node = q.front();
			q.pop();

			// visiting all the neighbour 
			for(auto ng:graph[cur_node])
			{
				// if the neighbour is 
				// not yet colored
				if(color_graph[ng]==-1)
				{
					color_graph[ng] = 1 - color_graph[cur_node];
					q.push(ng);
				}
				// if the neighbour is colored 
				// then check is it the same color 
				// of the current node 
				// if both are of same color then it 
				// is problem  
				else
				{
					if(color_graph[ng] == color_graph[cur_node])
						is_bi_partite = false; 
				}
			}
		}

		return is_bi_partite;

	}
};

int
main ()
{
	int size = 7;


	// _g.addEdge (1, 2, true);
	// _g.addEdge (1, 3, true);
	// _g.addEdge (1, 4, true);
	// _g.addEdge (2, 5, true);
	// _g.addEdge (3, 6, true);
	// _g.addEdge (4, 6, true);
	// _g.addEdge (5, 6, true);


	int n,e;
	cin >> n >> e;
	size = n+1;
	
	Graph < int >_g (size);
	for(int i=0;i<e;i++)
	{
		int start,end;
		cin >> start >> end;
		_g.addEdge (start, end, true);
	}


	cout << " Checking Bipartite " << endl;
	int count_of_Connected_Component = 0;
	map<int,int> colordetails;

	cout << _g.isBiPartite_BFS(_g.adjlist,1,colordetails,0) << endl;
	cout << " MOre Simpler Code: Is BiPartitie : " << _g.isBipartite_moreSimpler(_g.adjlist,1) << endl;
	return 0;
}


/*

Input 1:

6 7
1 2
1 3 
1 4
2 5
3 6
4 6
5 6

Output 1:
0

Input 2:

6 6
1 2
1 3
1 4
2 5
3 6
4 6

Output 2:
1
*/