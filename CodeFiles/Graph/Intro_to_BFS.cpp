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

	void TopoSort()
	{


		T lastNode = NULL;
		queue<T> _q;
		debug=1;
		if(debug)
		{
			cout << " Indegree Data " << endl;
			for(auto a:indegree)
			{
				cout << a.first << " : " << a.second << endl;
			}

			printGraph();
		}
		debug=0;

			// Storing all the vertices with 
			// inorder 0 
		for(auto a:indegree)
		{
			if(a.second==0)
			{
				if(lastNode==NULL)
					lastNode = a.first;
				_q.push(a.first);
				parent[a.first] = a.first;
				visited[a.first] = true;
			}
		}

		parent[lastNode] = lastNode;
		visited[lastNode] = true;


		bool firstLoop = false;

		while(_q.empty()==false)
		{
			lastNode = _q.front();
			_q.pop();

			for(T neighbour:adjlist[lastNode])
			{
				if(visited[neighbour]==false)
				{
					visited[neighbour]=true;

					indegree[neighbour]--;
					parent[neighbour] = lastNode;
					if(indegree[neighbour]==0)
						_q.push(neighbour);
				}
						// else if(lastNode==neighbour)
						// {
						// 	cout << " Same Node " << endl;
						// }
			}

			// if(adjlist[lastNode].size()==0)
			// {
			// 	parent[lastNode] = lastNode;
			// 	visited[lastNode] = true;
			// }		

		}

		firstLoop = true;


		debug=1;
		if(debug)
		{
			cout << " Parent Data " << endl;
			for(auto a:parent)
			{
				cout << a.first << " : " << a.second << endl;
			}
		}
		debug=0;
		std::map<T,bool> visited_temp; 
		cout << " Topo Sort using BFS " << endl;
		for(auto a1:adjlist)
		{
			if(visited_temp[a1.first]==true)
				continue;

			vector<T> paths = getPath(a1.first);
			for(auto a:paths)
			{
				cout << a << " ";
				visited_temp[a] = true;
			}
			cout << endl;
		}
	}




};

int
main ()
{
	int size = 6;
	Graph < int >_g (size);

	_g.addEdge (1, 2, true);
	_g.addEdge (2, 3, true);
	_g.addEdge (3, 4, true);
	_g.addEdge (5, 5, true);


	cout << " Invoking BFS " << endl;
	int count_of_Connected_Component = 0;
	for(auto a:_g.adjlist)
	{
		if(_g.visited[a.first]==false)
		{
			_g.bfsTraversal(a.first);
			count_of_Connected_Component++;
		}
	}

	cout << " No of Connected Component " << count_of_Connected_Component << endl;


	_g.reset();
	_g.addEdge (4, 3, false);
	_g.addEdge (3, 1, false);
	_g.addEdge (2, 2, false);
	_g.addEdge (5, 5, false);

	_g.TopoSort();

	if(debug)
		_g.printGraph ();

	return 0;
}
