#include<iostream>
#define frin freopen("input.txt","r",stdin)
#define frop freopen("output.txt","w",stdout)
#include<vector>
#include<map>
using namespace std;

map<int,vector<int>> gd;
map<int,bool> visited;
int debug=0;

//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// why we have to pass parent refrence also ?
// because if we do not pass the parent we will 
// not be able to trace out what is calling source 
// through which current node has been called 

bool check_if_cycle_DFS(int source,int parent)
{
	// if(visited[source]) return true;

	visited[source]=true;

	for(int ng:gd[source])
	{
		if(visited[ng]==false)
		{
			//visited[ng] = true;
			bool return_value = check_if_cycle_DFS(ng,source);
			if(return_value==true)
				return return_value;
		}
		else
		{
			// i have visited to a node which 
			// is not parent of mine 
			// and already been visited
			// shows ng is visited by some other
			// way    
			if(ng!=parent)
				return true;

			// check for self loop 
			// if any present 
			if(ng==source)
				return true;
		}
	}

	return false;
}

int main()
{
	if(debug)
	{
		frin;
		frop;
	}

	int t;
	cin >> t;
	while(t--)
	{
		gd.clear();
		visited.clear();

		int n,e;
		cin >> n >> e;

		for(int i=0;i<n;i++)
		{
			gd[i]={};
			visited[i] = false;
		}

		bool check_cycle_flag = false;

		for(int i=0;i<e;i++)
		{
			int st,ed;
			cin >> st >> ed;
			// if(st==ed)
			// {
			// 	check_cycle_flag=true;
			// 	break;
			// }
			gd[st].push_back(ed);
			gd[ed].push_back(st);
		}

		if(check_cycle_flag)
		{
			cout << check_cycle_flag << endl;
			continue;
		}
		
		for(auto a:visited)
		{
			if(a.second==false)
			{
				check_cycle_flag = check_if_cycle_DFS(a.first,a.first);
				if(check_cycle_flag==true)
					break;
			}
		}

		cout << check_cycle_flag << endl;
	}

}