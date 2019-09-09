#include<iostream>
#include<map>
#include<set>
using namespace std;

/*

https://online.codingblocks.com/player/33819/content/13653/5256

Pairing

There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.
Input Format:

The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.
Constraints:

1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1
output format

An integer that denotes the number of permissible ways to choose a pair of cities.
sample input

5 3
0 1
2 3
0 4

sample output

6

*/

map<int,set<int>> gr;
map<int,int> vs;

void dfs(int s,int &ct)
{
    vs[s]=1;
    ct = ct + 1;
    for(auto a:gr[s])
        if(vs[a]==0)
            dfs(a,ct);
}

int main() {
	
	int n,e;
	cin >> n >> e;

	for(int i=0;i<n;i++)
	{
		vs[i]=false;
		gr[i] = set<int>();
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		gr[st].insert(ed);
		gr[ed].insert(st);
	}

	long long totalPair = ((long long)((long long)n*(long long)(n-1)) >> 1 );

	for(auto a:vs)
	{
		int count=0;
		if(a.second == 0)
			dfs(a.first,count);
		// excluding all the pairs which can be made between the nodes 
		// in a connected component 
		totalPair -= ((long long)((long long)count*(long long)(count-1)) >> 1 );
	}

	cout << totalPair << endl;

	return 0;
}