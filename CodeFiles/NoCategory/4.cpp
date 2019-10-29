#include <bits/stdc++.h> 
using namespace std; 
#define int long long
const int N = 400010; 
int debug=0;

vector<int> graph[N]; 
map<pair<int,int>,int> edge_number;
vector<bool> visited;

// map<pair<int,int>,int> edge_came;

// int color[N]; 
// int par[N]; 
// int mark[N];

void get_cycle(int source,int parent,vector<int> &cycles,
	vector<bool> &visited, bool &b_isCycle)
{
	if(b_isCycle==true)
		return;

	visited[source] = true;
	cycles.push_back(source);

	for(auto a:graph[source])
	{
		if(visited[a]==false)
		{
			get_cycle(a,source,cycles,visited,b_isCycle);
		}
		else
		{
			if(a!=parent)
				b_isCycle=true;
		}
	}
}

int n;

vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

// Driver Code 
int32_t main() 
{ 

	if(debug)
	{
		freopen("input.txt","rb",stdin);
		freopen("output.txt","wb",stdout);
	}

	int t;
	cin >> t;

	while(t--)
	{
		edge_number.clear();

		int edge = 1;
		int v,e;
		cin >> v >> e;
		int v1 = v;

		v = 2*v;

		n = v;

		for(int i=0;i<N;i++)
		{
			graph[i] = {};
		}

		for(int i=0;i<e;i++)
		{
			int e1,e2;
			cin >> e1 >> e2;
			edge_number[{e1,e2}] = edge;

			e2 = v1 + e2;

			edge++; 

			graph[e1].push_back(e2);
			graph[e2].push_back(e1);

		}
		
		
		vector<int> dfs_nodes;	

		visited.clear();
		visited.resize(v,false);

		bool found_even = false;

		for(int i=1;i<=v;i++)
		{
			if(visited[i])
				continue;

			dfs_nodes.clear();
			bool b_isCycle=false;
			get_cycle(i,-1,dfs_nodes,visited,b_isCycle);

			if(b_isCycle && dfs_nodes.size()>0 && dfs_nodes.size()%2==0)
			{
				if(debug)
				{
					cout << " Cycle Detected " << endl;
					for(auto a:dfs_nodes)
					{
						// if(a>v1)
						// 	cout << (a-v1) << " ";
						// else
							cout << a << " ";
					} 
					cout << endl;
				}

				found_even = true;
				break;
			}

			if(found_even == true)
				break;

		}

		if(debug)
		{
			cout << " edge Details " << endl;
			for(auto a:edge_number)
			{
				cout << a.first.first << " " << a.first.second << " " << a.second << endl;
			}

		}

		vector<int> result;
		if(found_even == true && dfs_nodes.size()>0)
		{
			int first = dfs_nodes[0];

			if(first > v1)
			{
				// moonwalking 
				reverse(dfs_nodes.begin(),dfs_nodes.begin());
				first = dfs_nodes[0];
			}

			for(int i=1;i<=dfs_nodes.size();i++)
			{
				int second;
				if(i==dfs_nodes.size())
				{
					second = dfs_nodes[0];
				}
				else
				{
					second = dfs_nodes[i]; 
				}

				int normal_u = first;
				int normal_v = second;

				

				if(first>v1)
				{
					normal_u = normal_u - v1;
					
					if(debug)
					{
						cout << " normal_u " << normal_u << endl;
						cout << " normal_v " << normal_v << endl;
					}

					result.push_back(edge_number[{normal_v,normal_u}]);
				}
				else if(second>v1)
				{
					normal_v = normal_v - v1;
					if(debug)
					{
						cout << " normal_u " << normal_u << endl;
						cout << " normal_v " << normal_v << endl;
					}
					result.push_back(edge_number[{normal_u,normal_v}]);
				}
				else
				{
					if(debug)
					{
						cout << " normal_u " << normal_u << endl;
						cout << " normal_v " << normal_v << endl;
					}

					result.push_back(edge_number[{normal_u,normal_v}]);					
				}	

				first = second;	
			}
		}

		if(result.size()>0)
		{
			// reverse(result.begin(),result.end());
			cout << ":)" << endl << result.size() << endl;
			for(auto a:result)
			{
				cout << a << " ";
			}
			cout << endl;
		}
		else
		{
			cout << ":(" << endl;
		}
	}
} 


/*


5
5 6
1 2
2 3
3 1
3 5
4 5
4 1
3 3
1 2
3 2
3 1
2 1
1 2
2 2
1 2
2 1
1 1
1 1


*/