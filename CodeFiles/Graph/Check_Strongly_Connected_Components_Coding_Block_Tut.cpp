#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;

map<int,vector<int>> _g;
map<int,vector<int>> _rg;
vector<bool> _vs;
vector<int> _orderofvisit;

bool dfs(int source,vector<bool> &visited,map<int,vector<int>> graph,vector<int> &_orderofvisit)
{
	// if(visited[source]==true) return true;

	visited[source]=true;
	_orderofvisit.push_back(source);

	for(int _ng:graph[source])
	{
		if(visited[_ng]==false)
		{
			// visited[_ng]=true;
			bool retValue = dfs(_ng,visited,graph,_orderofvisit);
			// shows all its neighbours are visited 
			if(retValue == true)
				return retValue;
		}
	}	

	return false;
}

int main()
{
	int n,e;
	cin >> n >> e;
	for(int i=1;i<=n;i++)
	{
		_g[i]={};
		_rg[i]={};
	}

	for(int i=0;i<e;i++)
	{
		int start,end;
		cin >> start >> end;
		_g[start].push_back(end);
		_rg[end].push_back(start);	
	}

	_vs.clear();
	_vs.resize(n+1);
	_orderofvisit.clear();

	for(int i=0;i<=n;i++)
		_vs[i]=false;
	
	dfs(1,_vs,_g,_orderofvisit);
	for(int i=1;i<=n;i++)
	{
		if(_vs[i]==false)
		{
			cout << " NOT SCC 1" << endl;
			return 0;
		}
	}

	_vs.clear();
	_vs.resize(n+1);
	_orderofvisit.clear();
	
	for(int i=0;i<=n;i++)
		_vs[i]=false;

	dfs(1,_vs,_rg,_orderofvisit);

	cout << " Order Visited 2 " << endl;
	for(auto a:_orderofvisit)
	{
		cout << a << " : ";
	}
	cout << endl;

	for(int i=1;i<=n;i++)
	{
		if(_vs[i]==false)
		{
			cout << " NOT SCC 2 " << endl;
			return 0;
		}
	}

	cout << " SCC " << endl;
	return 0;

}