// https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/practice-problems/algorithm/logo-hunting-2d4068ca/

#include<iostream>
#define _for(k,s,e) for(int k=s;k<e;k++)
#define forinop freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
#include<queue>
#include<cstring>
#include<map>
using namespace std;

char fg[100][100];
int vs[100][100];

int xdir[4] = {+1,-1,+0,+0};
int ydir[4] = {+0,+0,+1,-1};

int debug=1;
// char delimiterChacharcter = '#';
char delimiterChacharcter = '1';

void matrixInput(int r,int c)
{
	_for(i,0,r)
		_for(j,0,c)
			cin >> fg[i][j];
}

int get_filled_Connected_Component(int r,int c)
{
	int noofconnectedComponent = 0;
	bool isoriginContained = false;

	// int noofconnectedComponent_row_wise = 0;

	// int index= 0;
	// map<pair<int,int>>,int> details;

	// pair<int,int> startingPair = {0,0};

	_for(i,0,r)
	{
		_for(j,0,c)
		{
			// if the cell is already visited 
			if(vs[i][j]==1) continue;

			// if the cell is # then 
			// no need to color it 
			// but mark it is visited 
			// if(fg[i][j]==delimiterChacharcter)
			// {
			// 	vs[i][j] = 1;
			// 	continue;
			// }

			// track the connected component 
			// of boundary 
			// because connected componenet 
			// which has boundary will be having dfferent color
			if(i==0 && j==0)
			{
				isoriginContained = true;
			}

			queue<pair<int,int>> q;
			q.push({i,j});
			vs[i][j]=1;

			if(debug)
			{
				
			}

			// fill with color 
			if(isoriginContained==true)
			{
				fg[i][j] = 'W';
			}
			else
			{
				fg[i][j] = 'R';
			}

			while(q.empty()==false)
			{
				pair<int,int> cur_pair = q.front();
				q.pop();
				_for(dir,0,4)
				{
					int xnew = cur_pair.first + xdir[dir];
					int ynew = cur_pair.second + ydir[dir];

					// outside cordinate is ignored 
					if(xnew>=r || xnew<0) continue;
					if(ynew>=c || ynew<0) continue; 

					if(vs[xnew][ynew]==1) continue;

					// ensures cell is hash but 
					// not yet visited 
					if(fg[xnew][ynew]==delimiterChacharcter) 
					{
						vs[xnew][ynew] = 1;
						continue;
					}

					q.push({xnew,ynew});

					if(isoriginContained==true)
					{
						fg[xnew][ynew] = 'W';
					}
					else
					{
						fg[xnew][ynew] = 'R';
					}

					vs[xnew][ynew] = 1;
				}
			}


			if(isoriginContained==true)
			{
				isoriginContained = false;
			}

			noofconnectedComponent++;

		}
	}

	return noofconnectedComponent;
}

void printOutput(int r,int c)
{
	_for(i,0,r)
	{
		_for(j,0,c)
			cout << fg[i][j];
		cout << endl;
	}

}

map<int,char> outputchar;

char mapOutput(int noofconnectedComponent)
{
	if(outputchar.size()==0)
	{
		outputchar[1] = 'F';
		outputchar[2] = 'O';
		outputchar[3] = 'P';
		outputchar[4] = 'N';
	}
	if(outputchar.find(noofconnectedComponent)==outputchar.end())
		return 'N';
	return outputchar[noofconnectedComponent];
}

int main()
{
	if(debug)
	{
		forinop;
	}

	int r,c;
	cin >> r >> c;
	matrixInput(r,c);
	memset(vs,0,sizeof(vs));
	int noofconnectedComponent = get_filled_Connected_Component(r,c);
	
	cout << mapOutput(noofconnectedComponent) << endl;

	if(debug)
	{
		printOutput(r,c);
	}

	return 0;
}


/*
Input 1:
8 8
........
.######.
.#....#.
.#....#.
.#....#.
.#....#.
.######.
........
Output 1:
WWWWWWWW
W######W
W#RRRR#W
W#RRRR#W
W#RRRR#W
W#RRRR#W
W######W
WWWWWWWW

Input 2:
6 6
......
.1111.
.1..1.
.1..1.
.1111.
......
Output 2:
2
WWWWWW
W1111W
W1RR1W
W1RR1W
W1111W
WWWWWW

Input 3:
11 9
.........
.1111111.
.1.....1.
.1.....1.
.1.....1.
.1111111.
.1.....1.
.1.....1.
.1.....1.
.1111111.
.........
Output 3:
3
WWWWWWWWW
W1111111W
W1RRRRR1W
W1RRRRR1W
W1RRRRR1W
W1111111W
W1RRRRR1W
W1RRRRR1W
W1RRRRR1W
W1111111W
WWWWWWWWW

Input 4:
17 9
.........
.1111111.
.1.....1.
.1.....1.
.1.....1.
.1111111.
.1.....1.
.1.....1.
.1.....1.
.1111111.
.........
.1111111.
.1.....1.
.1.....1.
.1.....1.
.1111111.
.........
Output 4:
N
WWWWWWWWW
W1111111W
W1RRRRR1W
W1RRRRR1W
W1RRRRR1W
W1111111W
W1RRRRR1W
W1RRRRR1W
W1RRRRR1W
W1111111W
WWWWWWWWW
W1111111W
W1RRRRR1W
W1RRRRR1W
W1RRRRR1W
W1111111W
WWWWWWWWW

*/