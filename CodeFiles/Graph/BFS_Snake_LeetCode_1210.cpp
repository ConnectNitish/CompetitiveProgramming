#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>

// https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/

int compute(vector<vector<int>> &In,int N)
{
	set<pair<pr,pr>> visited;
	queue<pair<pair<pr,pr>,int>> Adjancey_Q;
	Adjancey_Q.push({{{0,0},{0,1}},0});

	while(Adjancey_Q.empty()==false)
	{
		pair<pair<pr,pr>,int> node = Adjancey_Q.front();
		Adjancey_Q.pop();

		vector<pair<pr,pr>> Adjancey;

		pair<pr,pr> node_first = node.first;

		int aff = node_first.first.first;
		int afs = node_first.first.second;

		int bff = node_first.second.first;
		int bfs = node_first.second.second;

		int distance = node.second;

		if(aff == N-1 && afs == N-2 && bff == N-1 && bfs == N-1)
			return distance;

		// Horizontal Direction 
		if(aff == bff)
		{
			// can go right down rotate
			
			// shift towards Right  
			if(bfs + 1 <N && In[bff][bfs+1]!=1)
			{
				// right 
				Adjancey.push_back({{aff,afs+1},{bff,bfs+1}});
			}

			// shift towards down 
			if(aff+1<N && In[aff+1][afs]!=1 && In[bff+1][bfs]!=1)
			{
				// down 
				Adjancey.push_back({{aff+1,afs},{bff+1,bfs}});

				// rotate towrads next row 
				Adjancey.push_back({{aff,afs},{aff+1,afs}});
			}
		}

		// Vertical Direction 
		if(afs == bfs)
		{
			// can go right down rotate

			// shift towards down 
			if(bff+1 < N && In[bff+1][bfs]!=1)
			{
				Adjancey.push_back({{aff+1,afs},{bff+1,bfs}});
			}

			if(afs+1 < N && In[aff][afs+1]!=1 && In[bff][bfs+1]!=1)
			{
				// shift right 
				Adjancey.push_back({{aff,afs+1},{bff,bfs+1}});

				// rotate 
				Adjancey.push_back({{aff,afs},{aff,afs+1}});
			}
		}

		for(auto a:Adjancey)
		{
			if(visited.find(a)==visited.end())
			{
				Adjancey_Q.push({a,distance+1});
                visited.insert(a);
			}
		}
	}

	return -1;	
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> In;

	for(int i=0;i<n;i++)
	{
		std::vector<int> v1;
		for(int j=0;j<n;j++)
		{
			int v;
			cin >> v;
			v1.push_back(v);
		}
		In.push_back(v1);
	}

	cout << compute(In,n) << endl; 


}

/*

// https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/

[[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]

Output : 
-1 


In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).

In one move the snake can:

a Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
b Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
c Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).

d Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).

Return the minimum number of moves to reach the target.
If there is no way to reach the target, return -1.

Input: grid = [[0,0,0,0,0,1],
               [1,1,0,0,1,0],
               [0,0,0,0,1,1],
               [0,0,1,0,1,0],
               [0,1,1,0,0,0],
               [0,1,1,0,0,0]]
Output: 11
Explanation:
One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].

Input: grid = [[0,0,1,1,1,1],
               [0,0,0,0,1,1],
               [1,1,0,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,0]]
Output: 9

*/