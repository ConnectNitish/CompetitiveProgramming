#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> _g;
// not needed 
map<int,vector<int>> _rg;

// track which nodes are visited 
vector<bool> _vs;

// track which nodes are cureent in Stack 
vector<bool> _onstack;

// track Low_link_number of the node
// this is updated when an SCC is found 
// with the min value of the node which is present in SCC
vector<int> _Low_link_value;

// conatin all the element 
// which is present in Stack
stack<int> data_stack;

int no_of_scc=0;
vector<vector<int>> SccNodes;
int link_src_id=0;

int debug=1;

void dfs(int src,int low_link_value)
{
	// bookepping 
	// setting visited and onStack 
	// also adding the current element to Stack 
	// setting low_link_value of the particular source  
	_vs[src]=1;
	_onstack[src]=1;
	data_stack.push(src);
	_Low_link_value[src] = low_link_value;

	if(debug)
	{
		cout << " _Low_link_value src " << src << " low_link_value " << low_link_value << endl; 

		// cout << " Neighbours ";
		// for(auto ng:_g[src])
		// {
		// 	cout << ng << " ";
		// }
		// cout << endl;

	}

	for(auto ng:_g[src])
	{

		if(_vs[ng]==false)
		{
			dfs(ng,low_link_value+1);
		}
		// if the neighbour is in the stack 
		// and an SCC is found 
		// check wther the node is in SCC 
		// with the current source trace or not 
		// if its in current source trace 
		// then its onstack will be true
		// and will update the link value of the src 
		// with that of the neighbour   
		if(_onstack[ng]==true)
		{
			_Low_link_value[src] = min(_Low_link_value[ng],_Low_link_value[src]);
		}
	}

	// All the Nodes are explored 
	// Strongly Conncted component 
	// is completetd till
	// the Link of the element 
	// is equal to Link of Source 
	if(low_link_value == _Low_link_value[src])
	{
		// storing the element to just print 
		std::vector<int> _v_data;

		// iterating till stack empty
		// and we will iterate till 
		// src node is not achieved  
		// src node is also popped 
		// it is giving SCC found in vector _v_data
		while(data_stack.empty()==false)
		{
			int top_node = data_stack.top();
			_onstack[top_node]=false;
			data_stack.pop();
			_v_data.push_back(top_node);
			if(top_node == src)
				break;
		}

		// storing the result 
		if(_v_data.size()>0)
			SccNodes.push_back(_v_data);
	}
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
	while(t--)
	{
		_g.clear();
		link_src_id=0;

		int n,e;
		cin >> n >> e;
		for(int i=0;i<n;i++)
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
		_onstack.clear();
		_Low_link_value.clear();
		SccNodes.clear();
		data_stack = stack<int>();

		_vs.resize(n);
		_onstack.resize(n);
		_Low_link_value.resize(n);

	// for(int i=0;i<=n;i++)
	// 	_vs[i]=false;

		fill(_vs.begin(),_vs.end(),false);
		fill(_onstack.begin(),_onstack.end(),false);
		fill(_Low_link_value.begin(),_Low_link_value.end(),INT_MAX);

		for(int i=0;i<n;i++)
		{
			if(_vs[i]==0)
			{
				
			// _Low_link_value[i] = link_src_id;
				dfs(i,link_src_id);	
				link_src_id++;	
			}
		}

		// if(debug)
		{
			for(auto a:SccNodes)
			{
				for(int k=0;k<a.size();k++)
				{
					if(k==a.size()-1)
						cout << a[k] << "";
					else
						cout << a[k] << " ";
				}
				cout << ",";
			}
		}
		if(debug)
			cout << SccNodes.size() << endl;
		cout<<endl;
	}
	
	return 0;

}