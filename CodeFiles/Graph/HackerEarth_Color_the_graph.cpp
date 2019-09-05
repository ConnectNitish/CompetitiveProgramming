	#include <bits/stdc++.h>
#define fr freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
using namespace std;

int debug=0;

map < int, vector < int >> adjlist;

template < typename T > 
class Graph
{
public:
	
	vector < vector < T >> adjListVector;

	int size = 0;

	Graph (int noofvertices)
	{
		adjlist.clear ();

		this->size = noofvertices;

		for(int i=1;i<=noofvertices;i++)
			adjlist[i] = {};

	}

	void reset()
	{
		adjlist.clear();
		this->size=0;
	}

	void addEdge (T u, T v, bool bidirectional)
	{
		adjlist[u].push_back (v);
		if (bidirectional)
			adjlist[v].push_back (u);
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

	int isBipartite_moreSimpler(map<T,vector<T>> graph,T source,int vertices,vector<int> &color_graph)
	{
		if(debug)
		{
			cout << " No of Nodes " << endl;
			cout << graph.size() << endl;
		}
		// vector<int> color_graph(vertices+1,-1);
		
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
					{
						is_bi_partite = false; 
						break;
					}
				}
			}
		}

		if(is_bi_partite == false)
			return -1;
		else
		{
			int zero_color=0;
			int one_color=0;
			int total_Colors = color_graph.size();

			if(debug)
			{
				cout << " Color of Graph " << endl;
				for(int i=1;i<total_Colors;i++)
				{
					cout << color_graph[i] << " : ";
				}
				cout << endl;
			}

			for(int i=1;i<total_Colors;i++)
			{
				if(color_graph[i]==0)
					zero_color++;
				else if(color_graph[i]==1)
					one_color++;
			}
			// max of zero_color or one_color 
			// return to_string(max(zero_color,one_color));
			return max(zero_color,one_color);
		}

	}
};

int
main ()
{
	int size = 7;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	while(t--)
	{
		int n,e;
		cin >> n >> e;
		size = n;

		Graph < int >_g (size);
		for(int i=0;i<e;i++)
		{
			int start,end;
			cin >> start >> end;
			_g.addEdge (start, end, true);
		}


		if(e==0)
			cout << n << endl;
		else
		{
			map<int,int> colordetails;
			vector<int> color_graph(n+1,-1);
			int result = 0;
			int totalCount=0;
			for(int i=1;i<=n;i++)
			{
				if(color_graph[i]==-1)
				{
					result = _g.isBipartite_moreSimpler(adjlist,i,n,color_graph);
					if(result==-1)
						break;
					totalCount = totalCount + result;
				}
			}
			if(result==-1)
				cout << "NO" << endl;
			else
				cout << totalCount << endl;
		}
	}

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

Input 3:
6 7
1 2
1 3 
1 4
2 5
3 6
4 6
5 3

*/