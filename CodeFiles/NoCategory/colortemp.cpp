// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 400005;
int n, m, cv, cu, ce, M[N];
pair < int , int > P[N];
vector < pair < int , int > > Adj[N];

void DFS(int v)
{
	M[v] = 1;
	for (auto u : Adj[v])
	    if (u != P[v])
	    {
	        if (M[u.first] == 1)
	            cv = v, cu = u.first, ce = u.second;
	        else if (!M[u.first])
	            P[u.first] = {v, u.second}, DFS(u.first);
	    }
	M[v] = 2;
}
inline void Solve()
{
	cv = cu = ce = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n + n; i ++)
	    Adj[i].clear(), M[i] = 0, P[i] = {0, 0};
	for (int i = 1; i <= m; i ++)
	{
	    int v, u;
	    scanf("%d%d", &v, &u);
	    Adj[v].push_back({u + n, i});
	    Adj[u + n].push_back({v, i});
	}
	for (int i = 1; i <= n + n; i ++)
	{
	    if (M[i])
	        continue;
	    
	    DFS(i);
	    if (cv && cu)
	    {
	        vector < int > E = {ce};
	        while (cv != cu)
	            E.push_back(P[cv].second), cv = P[cv].first;
	        if (cu > n)
	            E.push_back(ce), E.erase(E.begin());
	        printf(":)\n%d\n", (int)E.size());
	        for (int id : E)
	            printf("%d ", id);
	        printf("\n");
	        return ;
	    }
	}
	printf(":(\n");
	return ;
}
int main()
{
	int q;
	scanf("%d", &q);
	for (; q; q --)
	    Solve();
	return 0;
}