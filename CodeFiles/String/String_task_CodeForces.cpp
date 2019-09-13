// http://codeforces.com/problemset/problem/33/B

#include<iostream>
#include<map>
#include<unordered_map>
#include<climits>
#include<set>
using namespace std ;

map<pair<char,char>,long long> data; 
int alledge[26][26] = {0};
map<char,set<char>> map_all_graph;
long long shortest_path[26][26] = {INT_MAX};

set<char> all_nodes;

int debug=0;

void dfs(
	char source, map<char,set<char>> &data_graph,set<char> &nodes,map<char,bool> &visited)
{
	nodes.insert(source);
	visited[source] = true;
	for(auto a:data_graph[source])
		if(visited.find(a) == visited.end())
			dfs(a,data_graph,nodes,visited);
	}

	int main()
	{
		if(debug)
		{
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		}

		string s1,s2;
		cin >> s1 >> s2;
		int n;
		cin >> n;
		int n1=n;


		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				shortest_path[i][j]=INT_MAX;
			}
		}

		while(n--)
		{
			char c1,c2;
			cin >> c1 >> c2 ;
			long long wt;
			cin >> wt;
			if(data.find({c1,c2})==data.end())
				data[{c1,c2}] = wt;
			else 
				data[{c1,c2}] = min(wt,data[{c1,c2}]);

		// alledge[c1-'a'][c2-'a'] = min(alledge[c1-'a'][c2-'a'],wt);
			if(shortest_path[c1-'a'][c2-'a']>wt)
				shortest_path[c1-'a'][c2-'a'] = wt;

			map_all_graph[c1].insert(c2);

			all_nodes.insert(c1);
			all_nodes.insert(c2);
		}

		for(int k=0;k<26;k++)
		{
			for(int i=0;i<26;i++)
			{
				for(int j=0;j<26;j++)
				{
					shortest_path[i][j] = min(shortest_path[i][j],
						(shortest_path[i][k] == INT_MAX || shortest_path[k][j] == INT_MAX) 
						? INT_MAX : 
						shortest_path[i][k]+shortest_path[k][j]
						);
				}
			}
		}

		map<char,set<char>> all_reachable_from_src;

		map<char,bool> visited;
		set<char> nodes_visited;
		
		for(auto a:all_nodes)
		{
			visited.clear();
			nodes_visited.clear();
		// visited[a.first] = true;
			dfs(a,map_all_graph,nodes_visited,visited);
			all_reachable_from_src[a] = nodes_visited;

			for(auto ss:nodes_visited)
				alledge[a-'a'][ss-'a'] = 1;

		}

		if(debug)
		{
			// for(auto a:data)
			// {
			// 	cout << a.first.first << " " << a.first.second << endl;
			// 	cout << a.second << endl;
			// }

			// cout << " Shortest Path " << endl;
			// for(int i=0;i<26;i++)
			// {
			// 	for(int j=0;j<26;j++)
			// 	{
			// 		if(shortest_path[i][j]==INT_MAX)
			// 			cout << "-1" << " ";
			// 		else
			// 			cout << shortest_path[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << " End of SHortest Path " <<  endl;

			// cout << " All Nodes Reachables From Node ( Character ): " << endl;
			// for(auto a:all_reachable_from_src)
			// {
			// 	cout << " Source " << a.first << " : ";
			// 	for(auto b:a.second)
			// 	{
			// 		cout << b << " ";
			// 	}
			// 	cout << endl;
			// }

			// cout << " All Nodes Reachables From Node : " << endl;
			// for(int i=0;i<26;i++)
			// {
			// 	for(int j=0;j<26;j++)
			// 	{
			// 		cout << alledge[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }

		}

		if(s1.length()!=s2.length())
			cout << "-1" << endl;
		else
		{
			string newString = "";
			long long minCost = 0;

			for(int i=0;i<s1.length();i++)
			{

				if(debug)
				{
					cout << " s1[i] " << s1[i] << endl;
					cout << " s2[i] " << s2[i] << endl;
				}

				if(s1[i]==s2[i])
				{
					newString += s1[i];

					if(debug)
						cout << " Same " << endl;
				}
				else
				{
					pair<char,char> pr = {s1[i],s2[i]};

					int costofs1s2 = INT_MAX;
					int costofs2s1 = INT_MAX;

					char char_at_min = ' ';
					long long finalCost = INT_MAX;

					costofs1s2 = shortest_path[s1[i]-'a'][s2[i]-'a'];
					costofs2s1 = shortest_path[s2[i]-'a'][s1[i]-'a'];

					if(costofs1s2!=INT_MAX || costofs2s1!=INT_MAX)
					{
						if(costofs1s2<costofs2s1)
							char_at_min = s2[i];
						else
							char_at_min = s1[i];

						finalCost = min(costofs2s1,costofs1s2);
					}

					if(debug)
					{
						cout << " Before Loop : " << endl; 
						cout << " char at min " << char_at_min << endl;
						cout << finalCost << endl;
						cout << endl;
					}

					int s1Index = s1[i]-'a';
					int s2Index = s2[i]-'a';

					for(int k=0;k<26;k++)
					{
						if(s1Index!=k && s2Index!=k && alledge[s1Index][k]==1 && alledge[s2Index][k]==1)
						{
							if(finalCost>shortest_path[s1Index][k] + shortest_path[s2Index][k])
							{
								char_at_min = ('a' + k);
								finalCost = shortest_path[s1Index][k] + shortest_path[s2Index][k];
							}
						}
					}		

					if(debug)
					{
						cout << " After Loop : " << endl; 
						cout << " char at min " << char_at_min << endl;
						cout << finalCost << endl;
						cout << endl;
					}		

					if(finalCost == INT_MAX)
					{
						cout << "-1" << endl;
						return 0;
					}

					newString += char_at_min;
					minCost += finalCost;					

					if(debug)
					{ 
						cout << " Min Cost " << minCost << endl;
						cout << " costofs1s2 " << costofs1s2 << endl;
						cout << " costofs2s1 " << costofs2s1 << endl;	
					}
				}
			}

			cout << minCost << endl;
			cout << newString << endl;

		}

		return 0;
	}

/*

Input 1 : 
abcd
acer
6
b c 100
c b 10
c x 1
e x 3
c e 7
r d 11


Output:

 s1[i] a
 s2[i] a
 Same 
 s1[i] b
 s2[i] c
 Before Loop : 
 char at min b
10

 After Loop : 
 char at min b
10

 Min Cost 10
 costofs1s2 100
 costofs2s1 10
 s1[i] c
 s2[i] e
 Before Loop : 
 char at min e
7

 After Loop : 
 char at min x
4

 Min Cost 14
 costofs1s2 7
 costofs2s1 2147483647
 s1[i] d
 s2[i] r
 Before Loop : 
 char at min d
11

 After Loop : 
 char at min d
11

 Min Cost 25
 costofs1s2 2147483647
 costofs2s1 11
25
abxd


*/