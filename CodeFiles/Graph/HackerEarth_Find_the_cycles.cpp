#include<iostream>
#define frin freopen("input.txt","r",stdin)
#define frop freopen("output.txt","w",stdout)
#include<vector>
#include<map>
using namespace std;

map<int,vector<int>> gd;
map<int,bool> visited;

// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/find-the-cycles/

int debug=0;

// why we have to pass parent refrence also ?

void check_if_cycle_DFS(int source,int parent,vector<int> &nodes,bool &is_det)
{
	visited[source]=true;

	// if(gd[source].size()>=3)
	// 	return false;

	nodes.push_back(source);

	for(int ng:gd[source])
	{
		if(visited[ng]==false)
		{
			// Already we are setting 
			// at initial of the call  
			// visited[ng] = true;
			check_if_cycle_DFS(ng,source,nodes,is_det);
			// if(return_value==true)
			// 	return return_value;
			// else
			// 	return false;
		}
		else
		{
			// i have seen a node which 
			// is not parent of mine 
			// and already been visited
			// shows ng is visited by some other
			// way    
			if(ng!=parent)
			{
				is_det = true;
				// return true;
			}

			// check for self loop 
			// if any present 
			// if(ng==source)
			// 	return true;
		}
	}

	// return false;
}

int main()
{
	if(debug)
	{
		frin;
		frop;
	}

	gd.clear();
	visited.clear();

	int n,e;
	cin >> n >> e;

	for(int i=1;i<=n;i++)
	{
		gd[i]={};
		visited[i] = false;
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		gd[st].push_back(ed);
		gd[ed].push_back(st);
	}

	bool check_cycle_flag = false;
	int countofCycles = 0;
	for(auto a:visited)
	{
		if(a.second==false)
		{
			vector<int> nodes;
			bool is_det=false;
			check_if_cycle_DFS(a.first,a.first,nodes,is_det);
			if(is_det==true)
			{
				if(debug)
				{
					cout << " countofCycles " << countofCycles << endl;
					for(auto a:nodes)
				{
					cout << a << " : ";
				}
				cout << endl;
				}

				for(auto a:nodes)
				{
					if(gd[a].size()>=3)
					{
						countofCycles--;
						break;
					}
				}
				countofCycles++;
			}
		}
	}

	cout << countofCycles << endl;

}

/*

Input : 
5 4
1 2
3 4
5 4
3 5

Output:
1

Input:
*/