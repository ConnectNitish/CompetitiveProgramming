#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// https://www.hackerrank.com/challenges/primsmstsub/problem

vector<vector<pair<int,long long>>> gr(10000,vector<pair<int,long long>>({}));

int debug=0;

// giving through Loop minwieght
// for each node 
// O(n) it is taking  
int findMinVertices(int* weight,int *visited,int no_of_vertices)
{
	int minWeightVertex=-1;
	int weight_Local = INT_MAX;

	// 1 based indexes 
	for(int k=1;k<=no_of_vertices;k++)
	{
		if(visited[k]==false)
		{
			if(weight_Local>weight[k])
			{
				weight_Local = weight[k];
				minWeightVertex = k;
			}
		}
	}
	return minWeightVertex;
}

// print MST weight 
void applyPrim(int *visited,int *parent,int *weight
	,int no_of_vertices)
{
	// find Vertex with Min weight 
	// mark its visited true
	// get all its neighbour 
	// relax the weight for each node 
	// which are not visisted 

	for(int i=0;i<no_of_vertices;i++)
	{

		// finiding min Weight Vertex 
		int minWeightVertex = findMinVertices(weight,visited,
			no_of_vertices);

		// marking its as visited
		// so that it should not be visited again 
		visited[minWeightVertex] = true;

		// Exploring all the neighbour and relaxing 
		// the edges correspoding to the other node   
		for(auto neighbour:gr[minWeightVertex])
		{
			int neighbour_node = neighbour.first;
			int weight_of_edge = neighbour.second;

			// ensuring its is not visited again  
			if(visited[neighbour_node]==false)
			{
				// relaxing the edge from the source 
				if(weight[neighbour_node]>weight_of_edge)
				{
					// updating parent of the current node 
					// to the source from which it is 
					// getting relaxed 
					parent[neighbour_node] = minWeightVertex;
					weight[neighbour_node] = weight_of_edge;
				}
			}
		}
	}

	if(debug)
	{
		for(int i=1;i<=no_of_vertices;i++)
		{
			cout << i << " -- " << parent[i] << " Weight " << weight[i] << endl;
		}
	}

	long long totalweight=0;
	for(int i=1;i<=no_of_vertices;i++)
	{
		totalweight+= weight[i];
	}

	cout << totalweight << endl;

}

int main()
{
	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	int n,e;
	cin >> n >> e;

	for(int k=0;k<e;k++)
	{
		int st,ed;
		long long wt;
		cin >> st >> ed >> wt;
		gr[st].push_back({ed,wt});
		gr[ed].push_back({st,wt});
	}

	int * visited = new int[n+1];
	int * parent = new int[n+1];
	int * weight = new int[n+1];

	for(int i=0;i<=n;i++)
	{
		visited[i]=false;
		weight[i]=INT_MAX;
	}

	int source = 1;
	cin >> source;
	parent[source] = -1;
	weight[source] = 0;

	applyPrim(visited,parent,weight,n);

	return 0;
}