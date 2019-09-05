#include<bits/stdc++.h>
#define in(i) scanf("%d",&i)
#define forin(i,s,e) for(int i=s;i<=e;i++)

using namespace std;

/*

https://online.codingblocks.com/player/33819/content/13653/5265

EXPAND THE POND
You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water such that any cell is accessible from any other cell by moving only along neighbours. You should add water to exactly one cell in order to maximise the size of the pond.

Input Format:
The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell and 1 for a cell containing water.

Constraints:
1 ≤ N,M ≤ 1000 There is at least one dry cell and one cell filled with water in the matrix.

Output Format
Print a single integer representing the largest possible size of the pond.

Sample Input
3 3
0 1 1
0 0 1
0 1 0
Sample Output
5

Refrences:
https://github.com/prateek27/editorials/blob/master/Graphs/Expand%20the%20Pond.md

*/

int xdir[4] = {+1,-1,+0,+0};
int ydir[4] = {+0,+0,-1,+1};

int debug=0;

int main()
{
	int N,M;
	in(N);in(M);
	int d[N][M];
	forin(i,0,N-1)
	forin(j,0,M-1)
	in(d[i][j]);

	forin(i,0,N-1)
	forin(j,0,M-1)
	if(d[i][j])	
		d[i][j]=-1;

	int VS[N][M]={0};

	queue<pair<int,int>> _q;	
	int maxLength=0;
	int pondNumber = 1;

	map<int,int> pondNumber_length;

	forin(i,0,N-1)
	{
		forin(j,0,M-1)
		{
			// if(VS[i][j]) continue;

			if(d[i][j]==0) continue;

			bool changed = false;

			// if(d[i][j]==0)
			// {
			// 	d[i][j] = 1;
			// 	changed = true;
			// }

			// _q = queue();
			std::vector<pair<int,int>> coordinates;
			int length = 0;
			if(d[i][j]==-1)
			{
				_q.push({i,j});
				coordinates.push_back({i,j});
				length++;
			}

			

			// if(i==1 && j==1)
			// 	debug=0;
			// else
			// 	debug=0;


			

			while(_q.empty()==false)
			{
				pair<int,int> current = _q.front();
				_q.pop();
				VS[current.first][current.second]  = 1;
				// length++;

				forin(dir,0,3)
				{
					int newx = xdir[dir] + current.first;
					int newy = ydir[dir] + current.second;

					if(newx>=N || newx<0 || newy>=M || newy<0)
						continue;

					if(VS[newx][newy]==0 && d[newx][newy]==-1)
					{
						_q.push({newx,newy});
						length++;

						if(debug)
						{
							cout << " newx " << newx << " newy " << newy << endl;
						}

						VS[newx][newy] = 1;
						coordinates.push_back({newx,newy});
					}
				}
			}

			for(auto a:coordinates)
			{
				d[a.first][a.second] = pondNumber;
			}

			pondNumber_length[pondNumber] = length;

			pondNumber++;

			if(length>maxLength)
				maxLength = length;

			if(debug)
			{
				cout << endl;
				forin(i1,0,N-1)
				{
					forin(j1,0,M-1)
					cout << d[i1][j1] << " ";
					cout << endl;
				}
				cout << endl;
			}

			if(debug)
				cout << " Length Obtained " << length << endl;

			// if(changed==true)
			// {
			// 	d[i][j] = 0;
			// }

			// forin(i1,0,N-1)
			// {
			// 	forin(j1,0,M-1)
			// 	VS[i1][j1] = 0;
			// }
		}
	}

	forin(i,0,N-1)
	{
		forin(j,0,M-1)
		{
			if(d[i][j]==0)
			{
				int lengthofGroup = 0;
				set<int> data_set;
				if(i-1>=0 && d[i-1][j]>0) data_set.insert(d[i-1][j]);
				if(j-1>=0 && d[i][j-1]>0) data_set.insert(d[i][j-1]);
				if(i+1<N && d[i+1][j]>0) data_set.insert(d[i+1][j]);
				if(j+1<M && d[i][j+1]>0) data_set.insert(d[i][j+1]);

				if(debug)
				{
					cout << endl;
					for(auto a:data_set)
					cout << a << ":" << pondNumber_length[a] << endl;
				}

				for(auto a:data_set)
					lengthofGroup += pondNumber_length[a];

				maxLength = max(maxLength,1+lengthofGroup);   
			}
		}
	}

	printf("%d",maxLength);
	return 0;
}