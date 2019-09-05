#include<limits.h>
#include<iostream>
#include<cstring>
#define int long long
using namespace std;

// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0

int data[1000][1000];
int _distance[1000][1000]={INT_MAX};

int stringtoint(string str)
{
	return stol(str);
}

int debug=1;

int32_t main()
{
	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}



	int t;
	cin >> t;
	while(t--)
	{
		int n,e;
		cin >> e;

		for(int i=0;i<e;i++)
		{
			for(int j=0;j<e;j++)
			{
				int st,ed;
				cin >> st;

				if(debug)
				{
					cout << st << endl;
				}

				int ist,ied;

				// if(st=="INF")
				// 	ist = INT_MAX;
				// else
				// 	ist = stringtoint(st);
                
                ist = st;
                
				data[i][j] = ist;
				_distance[i][j] = ist;
			}
		}

		for(int k=0;k<e;k++)
		{
			for(int i=0;i<e;i++)
			{
				for(int j=0;j<e;j++)
				{
					if(_distance[i][k]+_distance[k][j]<_distance[i][j])
					{
						_distance[i][j] = _distance[i][k]+_distance[k][j];
					}
				}
			}
		}

		for(int i=0;i<e;i++)
		{
			for(int j=0;j<e;j++)
			{
				if(_distance[i][j]==1e7)
					cout << "INF" << " ";
				else
					cout << _distance[i][j] << " ";
			}
			cout << endl;
		}
	}

}


/*

Input 1:

2
2
0 25
10000000 0
3
0 1 43
1 0 6
10000000 10000000 0

Output 1:

0
25
10000000
0
0 25 
INF 0 
0
1
43
1
0
6
10000000
10000000
0
0 1 7 
1 0 6 
INF INF 0 



*/