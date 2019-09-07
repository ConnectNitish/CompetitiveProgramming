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

// int xdir[4] = {+1,-1,+0,+0};
// int ydir[4] = {+0,+0,+1,-1};

int xdir[8]={-1,1,0,0,-1,-1,1,1};
int ydir[8]={0,0,-1,1,-1,1,-1,1};

int debug=0;
// char delimiterChacharcter = '#';
char delimiterChacharcter = '$';

int max_r,max_c;

void matrixInput(int r,int c)
{
	_for(i,0,r)
		_for(j,0,c)
			cin >> fg[i][j];
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

// track how many dots comes in between 
int holes=0;

// it will instruct and repalce all the cur char with the replaced one 
// provided indexes are in range 
// and if new char other than to be replace is found
// then it will be ignored 
void fill_all_data(int r,int c,char cur_char,char new_char)
{
	if(r>=max_r || r<0) return;
	if(c>=max_c || c<0) return;

	if(fg[r][c]!=cur_char)
		return;
	
	fg[r][c] = new_char;

	for(int dir=0;dir<4;dir++)
	{
		int new_x = xdir[dir] + r;
		int new_y = ydir[dir] + c;
		fill_all_data(new_x,new_y,cur_char,new_char);
	}
}

// if '1' is identified ; then i will try
// to fill with sign same as i have repalced . 
// if any '.' is identifeid it shows 
// a new region is starting so we need to fill
// that region with any other marker 
// region should be counted once 
void dfs_to_track_holes(int r,int c)
{

	if(r>=max_r || r<0) return;
	if(c>=max_c || c<0) return;

	if(fg[r][c]=='1')
	{
		fg[r][c]=delimiterChacharcter;
		for(int dir=0;dir<8;dir++)
			dfs_to_track_holes(r+xdir[dir],c+ydir[dir]);
	}
	else if(fg[r][c]=='.')
	{
		holes++;
		fill_all_data(r,c,'.','*');
	}

}

int main()
{
	if(debug)
	{
		forinop;
	}

	cin >> max_r >> max_c;
	matrixInput(max_r,max_c);
	memset(vs,0,sizeof(vs));
	// fill outer boundary first diff character
	fill_all_data(0,0,'.',delimiterChacharcter);

	char * ch_data = new char[3];
	ch_data[0]='F';
	ch_data[1]='O';
	ch_data[2]='P';
	int * ch_data_count = new int[3];
	ch_data_count[0]=0;
	ch_data_count[1]=0;
	ch_data_count[2]=0;

	// if(debug)
	// 	cout << " Start " << endl;

	for(int i=0;i<max_r;i++)
	{
		for(int j=0;j<max_c;j++)
		{
			if(fg[i][j]=='1')
			{
				holes = 0;
				dfs_to_track_holes(i,j);
				if(debug)
					cout << " NO OF HOLES " << holes << endl;
				ch_data_count[holes]++;
			}
		}
	}

	if(debug)
	{
		printOutput(max_r,max_c);
	}

	bool anyAppPresent = false;

	for(int i=0;i<3;i++)
		if(ch_data_count[i]>0)
		{
			for(int k=0;k<ch_data_count[i];k++)
				cout << ch_data[i];
			anyAppPresent = true;
		}

	if(anyAppPresent==false)
		cout << "N" << endl;

	return 0;
}


/*

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

 NO OF HOLES 2
 NO OF HOLES 1
$$$$$$$$$
$$$$$$$$$
$$*****$$
$$*****$$
$$*****$$
$$$$$$$$$
$$*****$$
$$*****$$
$$*****$$
$$$$$$$$$
$$$$$$$$$
$$$$$$$$$
$$*****$$
$$*****$$
$$*****$$
$$$$$$$$$
$$$$$$$$$
OP


Input 5:

18 26
..........................
..........................
........11111111111.......
........11.......11.......
........11.......11.......
........11.......11.......
........11.......11.......
........11111111111.......
..........................
.....11111111.............
.....1....................
.....1....................
.....1....................
.....1111111..............
.....1....................
.....1....................
.....1....................
..........................

Output 5:

 NO OF HOLES 1
 NO OF HOLES 0
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$*******$$$$$$$$$
$$$$$$$$$$*******$$$$$$$$$
$$$$$$$$$$*******$$$$$$$$$
$$$$$$$$$$*******$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
FO

Input :

35 26
..........................
..........................
...111111111.......111111.
...11.....11.......11.....
...11.....11.......11.....
...111111111.......11111..
...11.....11.......11.....
...11.....11.......11.....
...111111111..............
..........................
..........111111111.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........111111111.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........11.....11.......
..........111111111.......
..........................
..........................

Output:

 NO OF HOLES 2
 NO OF HOLES 0
 NO OF HOLES 2
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$*****$$$$$$$$$$$$$$$$
$$$$$*****$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$*****$$$$$$$$$$$$$$$$
$$$$$*****$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$*****$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$
FP

*/