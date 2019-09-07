#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<climits>
using namespace std;

map<int,set<int>> graph;
map<int,bool> visited;
set<pair<int,int>> bridge_details;
map<int,int> low_time;
map<int,int> visited_time;
map<int,int> parent;

int debug=0;
int _time=0;

int internaldebug=0;

void dfs(int src)
{
	visited[src] = true;
	visited_time[src] = _time;
	low_time[src] = _time;
	_time++;
	int children_count = 0;

	for(int ng : graph[src])
	{
		if(parent[src] == ng)
			continue;

		if(visited[ng] == false)
		{
			parent[ng] = src;
			children_count++;
			dfs(ng);

			low_time[src] = min(low_time[ng],low_time[src]);

			if(visited_time[src]<low_time[ng])
			{
				bridge_details.insert({min(src,ng),max(src,ng)});
			}

		}
		else
		{
			low_time[src] = min(low_time[src],visited_time[ng]);
		}
	}
}

int main()
{
	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	int count=0;

	while(true)
	{
		
		graph.clear();
		visited.clear();
		visited_time.clear();
		low_time.clear();
		bridge_details = set<pair<int,int>>();

		int int_noofserver;

		string noofserver; 
		cin >> noofserver;

		if(internaldebug)
			cout << " NO of Server " << noofserver << endl;

		if(cin.fail()==true)
			break;

		if(noofserver=="")
			continue;

		int_noofserver = stoi(noofserver);

		int server_no;
		string no_ofConnection;
		int int_no_ofConnection;

		for(int k=0;k<int_noofserver;k++)
		{
			graph[k] = {};
			visited[k] = false;
			low_time[k] = INT_MAX;
			parent[k] = -2;
		}

		for(int i=0;i<int_noofserver;i++)
		{
			
			cin >> server_no;

			if(internaldebug)
				cout << " Server No " << server_no << endl;

			cin >> no_ofConnection;
			int length = no_ofConnection.length();
			string s_new_temp = no_ofConnection;

			s_new_temp[0] = '0';
			s_new_temp[length-1] = '\0';

			int_no_ofConnection = stoi(s_new_temp);

			if(internaldebug)
				cout << " No of Connection  " << int_no_ofConnection << endl;

			for(int k=0;k<int_no_ofConnection;k++)
			{	
				int temp_in;
				cin >> temp_in;
				graph[server_no].insert(temp_in);
				graph[temp_in].insert(server_no);
			}
		}

		if(internaldebug)
		{
			for(auto a:graph)
			{
				cout << a.first << " : ";
				for(auto b:a.second)
				{
					cout << b << " ";
				}
				cout << endl;
			}
		}

		for(auto a:visited)
		{
			if(a.second==false)
				dfs(a.first);
		}

		// if(count>0)
		// 	cout << endl;

		cout << bridge_details.size() << " critical links" << endl;
		for(auto edge:bridge_details)
		{
			// if(edge.first<=edge.second)
			cout << edge.first << " - " << edge.second << endl;
			// else
			// 	cout << edge.second << " - " << edge.first << endl;
		}

		cout << endl;

		count++;
	}
}