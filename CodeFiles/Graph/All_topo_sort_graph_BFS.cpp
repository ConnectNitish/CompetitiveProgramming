#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;


map<int,set<int>> graph;
map<int,bool> visited;
map<int,int> indegree;

vector<vector<int>> allTopo;

int debug=1;

void generateAlltopo(int no_of_nodes,map<int,bool> &_visited,map<int,int> &_indegree
	,vector<int> &particular_topo)
{
	bool allVisited = false;

	for(int i=0;i<no_of_nodes;i++)
	{
		if(_visited[i]==false)
		{
			if(_indegree[i]==0)
			{
				particular_topo.push_back(i);
				_visited[i] = true;
				for(auto a:graph[i])
				{
					_indegree[a]--;
				}

				generateAlltopo(no_of_nodes,_visited,_indegree,particular_topo);

				for(auto a:graph[i])
				{
					_indegree[a]++;
				}
				_visited[i]=false;
				particular_topo.pop_back();
				
				

				allVisited = true;
			}
		}
	}

	if(allVisited == false)
	{
		if(particular_topo.size()>0)
			allTopo.push_back(particular_topo);
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

	if(debug)
	{
		cout << " Vertices " << v << " edges " << e << endl;
	}

	for(int i=0;i<v;i++)
	{
		graph[i] = {};
		visited[i] = false;
		indegree[i] = 0;
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		graph[st].insert(ed);
		indegree[ed]++;
	}

	if(debug)
	{
		cout << " INdegree " << endl;
		for(auto a:indegree)
			cout << a.first << " : " << a.second << endl;
		cout << endl;

	}


	vector<int> a_topo;
	generateAlltopo(v,visited,indegree,a_topo);

	if(debug)
		cout << " All topo Sort are " << endl;

	for(auto a:allTopo)
	{
		for(auto b:a)
		{
			cout << b << " ";
		}
		cout << endl;
	}

}

/*

Input 1:

6 6
5 2
5 0
4 0
4 1
2 3
3 1

Output 1 : 

4 5 0 2 3 1 
4 5 2 0 3 1 
4 5 2 3 0 1 
4 5 2 3 1 0 
5 2 3 4 0 1 
5 2 3 4 1 0 
5 2 4 0 3 1 
5 2 4 3 0 1 
5 2 4 3 1 0 
5 4 0 2 3 1 
5 4 2 0 3 1 
5 4 2 3 0 1 
5 4 2 3 1 0

Input 2:

3 2
0 1
2 1


*/