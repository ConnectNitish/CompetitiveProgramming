#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

// https://leetcode.com/problems/network-delay-time/submissions/

int debug=1;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) 
	{

		vector<int> distance(N+1,INT_MAX);
		distance[K] =0;

		for(int i=1;i<=N-1;i++)
		{
			for(auto node:times)
			{
				int src = node[0],des = node[1],wt = node[2];

				if(distance[src]!=INT_MAX)
				{
					if(distance[des]>distance[src]+wt)
					{
						distance[des] = distance[src] + wt;
					}
				}
			}
		}

		for(auto node:times)
		{
			int src = node[0],des = node[1],wt = node[2];
			if(distance[src]!=INT_MAX)
			{
				if(distance[des]>distance[src]+wt)
				{
					return -1;
				}
			}
		}

		int max_distance = INT_MIN;

		for(int i=1;i<=N;i++)
		{
			max_distance = max(max_distance,distance[i]);
		}

		return (max_distance == INT_MAX ? -1 : max_distance) ;
	}
};

int main()
{
	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	vector<vector<int>> graph;

	int v,e;
	cin >> v >> e;

	for(int i=0;i<e;i++)
	{
		int st,ed,wt;
		cin >> st >> ed >> wt;
		graph.push_back({st,ed,wt});
	}

	int src;
	cin >> src;

	Solution s;
	cout << s.networkDelayTime(graph,v,src) << endl;

}


/*

Input 1:
4 3
2 1 1
2 3 1
3 4 1
2
Output1:
2

Input 2:
2 1
1 2 1
2
*/