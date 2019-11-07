#include<bits/stdc++.h>
using namespace std;
#define int long double
#define prr pair<pair<int,int>,int>
#define max_value LDBL_MAX

int debug=0;

prr source;
map<prr,vector<prr>> _graph;
map<prr,vector<prr>> _graph_2;
map<prr,int> distances;

int compute(const prr &p1,const prr &p2)
{
	return sqrtl(
		(p1.first.first - p2.first.first) * (p1.first.first - p2.first.first) + 
		(p1.first.second - p2.first.second) * (p1.first.second - p2.first.second)
			);
}

int min_of_all_node_3 = max_value;

class _comp 
{ 
	public: 
    int operator() (const pair<int,prr> &p1,const pair<int,prr> &p2) 
    { 
        return p1.first <= p2.first; 
    } 
}; 

int applyDijkshtra(map<prr,vector<prr>> &lcl_graph,int lcl_min_of_all_node_3)
{
	priority_queue<pair<int,prr>,vector<pair<int,prr>>,_comp> _q;

	_q.push({0,source});
	distances[source] = 0;

	while(!_q.empty())
	{
		pair<int,prr> top = _q.top();
		_q.pop();

		for(auto ng: lcl_graph[top.second])
		{
			int _dist = compute(ng,top.second);
			if(distances[ng] > top.first + _dist)
			{
				distances[ng] = top.first + _dist; 	
				_q.push({top.first + _dist,ng});

				if(ng.second == -4 && lcl_min_of_all_node_3>top.first + _dist)
					lcl_min_of_all_node_3 = top.first + _dist;
			}
		}		
	}

	return lcl_min_of_all_node_3;
}

int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,k;
		
		int x1,y1;
		cin >> x1 >> y1;
		_graph.clear();
		_graph_2.clear();

		distances.clear();

		min_of_all_node_3 = max_value;

		source = {{x1,y1},-1};
		
		vector<prr> empty;
		_graph[source] = empty;
		_graph_2[source] = empty;

		cin >> n >> m >> k;

		// 1 for n
		int src,dest;
		vector<prr> n_nodes;
		for(int i=0;i<n;i++)
		{
			cin >> src >> dest;
			prr temp = {{src,dest},-2};
			_graph[source].push_back(temp);
			_graph[temp] = empty;
			distances[temp] = max_value;
			n_nodes.push_back(temp);
		}

		vector<prr> m_nodes;
		for(int i=0;i<m;i++)
		{
			cin >> src >> dest;
			prr temp = {{src,dest},-3};
			m_nodes.push_back(temp);
			distances[temp] = max_value;
		}

		vector<prr> k_nodes;
		for(int i=0;i<k;i++)
		{
			cin >> src >> dest;
			prr temp = {{src,dest},-4};
			k_nodes.push_back(temp);
			distances[temp] = max_value;
		}

		// n for m
		for(auto a:n_nodes)
		{
			for(auto b:m_nodes)
			{
				_graph[a].push_back(b);
				_graph[b] = empty;
			}
		}

		// m for k 
		for(auto a:m_nodes)
		{
			for(auto b:k_nodes)
			{
				_graph[a].push_back(b);
				_graph[b] = empty;
			}
		}

		if(debug)
		{
			for(auto a:_graph)
			{
				cout << " Source (" << a.first.first.first << "," << a.first.first.second << ")";
				cout << " Level " << a.first.second << endl;

				for(auto b:_graph[a.first])
				{
					cout << "\t" <<" (" << b.first.first << "," << b.first.second << ")";
					cout << " Level " << b.second << endl; 
				}
			}
		}

		// min(applyDijkshtra(_graph,LDBL_MAX),applyDijkshtra(_graph_2,LDBL_MAX));
		int v_1 = applyDijkshtra(_graph,LDBL_MAX);
		distances.clear();

		distances[source]=max_value;

		// a - m - n - k
		// a- m
		for(auto a:m_nodes)
		{
			_graph_2[source].push_back(a);
			_graph_2[a] = empty;
			distances[a]=max_value;
		}

		// m - n
		for(auto a:m_nodes)
		{
			for(auto b:n_nodes)
			{
				_graph_2[a].push_back(b);
				_graph_2[b] = empty;
				distances[b]=max_value;
			}
		}

		// n - k
		for(auto a:n_nodes)
		{
			for(auto b:k_nodes)
			{
				_graph_2[a].push_back(b);
				_graph_2[b] = empty;
				distances[b]=max_value;
			}
		}

		int v_2 = applyDijkshtra(_graph_2,LDBL_MAX);

		cout << setprecision(11) << min(v_1,v_2) << endl;
	}

	return 0;
}