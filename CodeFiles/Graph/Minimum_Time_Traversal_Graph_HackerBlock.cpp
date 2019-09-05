#include<bits/stdc++.h>
using namespace std;

/*

// https://hack.codingblocks.com/app/contests/668/p/870
// https://drive.google.com/open?id=1TLPWhXNEBXxrU7NvUS9csCBGgpAAkFXr


Distance: The distance between two points in a grid based on a strictly horizontal and/or vertical path (i.e along the grid lines), as opposed to the Manhattan Distance or Diagonal Distance.

The Manhattan Distance is the simple sum of the horizontal and vertical components, where as the Diagonal Distance might be computed by applying the Pythagorean Theorem.

Problem Statements: A robot is moving on co-ordinate axis. Time taken to move from one point to another point is equal to the Manhattan Distance.

Ex. Time taken to move from point ( x1 , y1) to ( x2 , y2) is |x1 - x2| + |y1 - y2| where | a | is equal to modulus function of a.

Starting Point (S) and Ending Point (E) of the robot is fixed. There are n wormhole like pipelines also on the coordinate axis. Time taken to move from one point to another point of each pipeline is given.

Robot can use those pipelines to move from statring point to ending point. Can you help to find the minimum time required during traversal.
Input Format

The first line contains T, the number of test cases.

The description of T test cases follows.

The first line of each test case contains integer n which represents the number of pipelines.

The next line contains four space seperated integer. The first two integer is the x and y coordinate of starting point and last two integer is the x and y coordinate of the ending points. The next n lines contains 5 space-separated character x1 , y1, x2 , y2, t . The first four integers are the x and y co-ordinate of terminal of the pipelines and 5 th integer is time to cross that pipelines .
Constraints

1 <= T <= 30 0 <= n <= 5 1 <= x,y <= 2000
Output Format

For each test case you have to print the output in this format (#Test Case Number : minimum time taken by robot to traverse from begining to ending point.)
Sample Input

3
0
20 20 100 100
1
20 20 100 100
25 25 30 30 5
3
20 20 100 100
35 35 50 50 0
30 30 25 25 0
40 40 60 60 100

Sample Output

#1 : 160
#2 : 155
#3 : 120




*/


vector<pair<int,int>> coordinates;

int debug=0;

int dijkshtra(
	// keep the source pair 
	pair<int,int> src,
	// keep which pair is visited 
	map<pair<int,int>,bool> visited
	// keep the final output distance from source 
	,map<pair<int,int>,int> distance
	// keep all the graph info which is connected to which other nodes 
	,map<pair<int,int>,vector<pair<int,int>>> graph
	// keep the manhattan distances between the pair 
	,map<pair<pair<int,int>,pair<int,int>>,int> dist
	// target coorodinates 
	,pair<int,int> destination)
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

	// marking prerequistes for source nodes 
	pq.push({0,src});
	visited[src] = true;
	distance[src] = 0;

	while(pq.empty()==false)
	{
		pair<int,pair<int,int>> cur_node = pq.top();
		pq.pop();

		// getting the current coorodinates 
		pair<int,int> u = cur_node.second;

		for(auto neighbour : graph[u])
		{
			// getting diatnces between two cooridinates 
			// calculated previous ; it will be eiether pipeline 
			// time or manhattan distance between the 
			// corrodintes given 
			int weight = dist[{u,neighbour}];

			// relaxing the neighbour corridnates from source 
			if(distance[neighbour] > distance[u] + weight)
			{
				distance[neighbour] = distance[u] + weight;
				pq.push({distance[neighbour],neighbour});
			}
		}
	}

	if(debug)
	{
		cout << " Source " << endl;
		cout << src.first << " : " << src.second << endl;
		for(auto des:distance)
		{
			cout << des.first.first << " : " << des.first.second << " === " << des.second << endl;
		}
	}

	// cout << distance[destination] << endl;

	return distance[destination];

}


int main()
{
	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	int t;
	cin >> t;
	int index=1;
	while(t--)
	{
		int n;
		cin >> n;

		int nt=n;
		
		coordinates.clear();

		int srcx,srcy,desx,desy;

		cin >> srcx >> srcy >> desx >> desy;

		pair<int,int> src = {srcx,srcy};
		pair<int,int> dest = {desx,desy};

		coordinates.push_back({srcx,srcy});
		coordinates.push_back({desx,desy});

		map<pair<pair<int,int>,pair<int,int>>,int> dist;

		map<pair<int,int>,vector<pair<int,int>>> graph;
		map<pair<int,int>,bool> visited;
		map<pair<int,int>,int> distance;

		// creating the vertices for the graph 
		graph[{srcx,srcy}].push_back({desx,desy});
		graph[{desx,desy}].push_back({srcx,srcy});

		while(nt--)
		{
			int st,ed;
			int st1,ed1;
			int wt;
			cin >> st >> ed >> st1 >> ed1 >> wt;
			
			coordinates.push_back({st,ed});
			coordinates.push_back({st1,ed1});

			// adding the vertex and distance given 
			dist[{{st,ed},{st1,ed1}}] = wt;
			dist[{{st1,ed1},{st,ed}}] = wt;

			// book keeping because need to apply dijkshtra on the same 
			graph[{st,ed}].push_back({st1,ed1});
			graph[{st1,ed1}].push_back({st,ed});

			visited[{st,ed}] = false;
			visited[{st1,ed1}] = false;

			// distance stores the actual answer so 
			// initially we will set all distcnes to MAX 
			distance[{st,ed}] = INT_MAX;
			distance[{st1,ed1}] = INT_MAX;

		}

		// getting diatnces between all piar of corridinates 
		for(int i=0;i<coordinates.size();i++)
		{
			pair<pair<int,int>,pair<int,int>> actualPair = {{},{}};
			actualPair.first = coordinates[i];

			for(int j=0;j<coordinates.size();j++)
			{
				// tracking that distance calculaton should be done 
				// one and other node 
				// not self node vetices ever 
				if(i!=j)
				{
					actualPair.second = coordinates[j];

					// if the distances is calculated before 
					// then there is no point of calculating again 
					// also some distance is of pipeline time 
					// of we remove this then pipleine distance will 
					// be removed by manhattan distance which 
					// leads to wrong result 
					if(dist.find(actualPair)==dist.end())
					{
						// getting the manhattan distance 
						int _distance = 
						abs(coordinates[i].first - coordinates[j].first) 
						+ 
						abs(coordinates[i].second - coordinates[j].second);
						dist[actualPair] = _distance; 

						// book keeping for the graph 
						graph[coordinates[i]].push_back(coordinates[j]);
						graph[coordinates[j]].push_back(coordinates[i]);

						visited[coordinates[i]] = false;
						visited[coordinates[j]] = false;

						distance[actualPair.first] = INT_MAX;
						distance[coordinates[j]] = INT_MAX;				

					}
				}
			}
		}


		int _distance1 = dijkshtra(src,visited,distance,graph,dist,dest);

		cout << "#" << index++ << " : "<<_distance1 << endl; 

	}

	return 0;
}