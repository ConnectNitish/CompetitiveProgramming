#include<bits/stdc++.h>
using namespace std;
#define int long long 

int t;
int e,v;

int debug=0;

int32_t main()
{

	cin >> t;

	while(t--)
	{
		cin >> v >> e;

		if(debug)
		{
			cout << " Vertices " << v << endl;
			cout << " edges " << e << endl;
		}

		vector<vector<int>> graph;

		graph.resize(v+1);

		int u1,v1;

		for(int i=0;i<e;i++)
		{
			cin >> u1 >> v1;
			graph[u1].push_back(v1);
			graph[v1].push_back(u1);
		}

		int k = 0;

		int degree = 0; 
		int odd_degree_node=-1;
		int even_degree_node=-1;

		for(int i=1;i<=v;i++)
		{
			degree+=graph[i].size();

			if(graph[i].size()%2==1 && odd_degree_node==-1)
			{
				odd_degree_node = i; 
			}
			else if(graph[i].size() > 0 && graph[i].size()%2==0 && even_degree_node==-1)
			{
				even_degree_node = i;
			} 
		}

		k = (degree/2) % 2;

		// even 
		if(k==0)
		{
			cout << "1" << endl;
			for(int i=1;i<=v;i++)
			{
				cout << "1" << " "; 
			}
		}
		// odd 
		else
		{
			if(odd_degree_node!=-1)
			{
				cout << "2" << endl;

				if(debug)
					cout << " -- Vertices " << v << endl;

				for(int i=1;i<=v;i++)
				{
					if(i!=odd_degree_node)
						cout << "1" << " ";
					else
						cout << "2" << " ";
				}
			}
			else 
			{
				vector<int> ng = graph[even_degree_node];
				int ng_node = ng[0];						
				cout << "3" << endl;
				for(int i=1;i<=v;i++)
				{
					if(i!=even_degree_node && i!=ng_node)
						cout << "1" << " ";
					else if(i==even_degree_node && i!=ng_node)
						cout << "2" << " ";
					else
						cout << "3" << " ";
				}

			}
		}
		cout << endl;
	}

}