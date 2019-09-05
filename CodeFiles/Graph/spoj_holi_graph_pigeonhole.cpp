#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<vector<pair<int,long long>>> gd(100001,vector<pair<int,long long>>(0));
std::vector<int> vs(100001);
std::vector<int> des(100001);

int debug=0;

int dfs(int s,vector<vector<pair<int,long long>>> &gd,vector<int> &vs,vector<int> &des,
	long long &max_distance,int &no_of_vertices)
{
	// mark node as visited
	// so that it should get visited again 
	vs[s]=1;

	// adding myself as a node 
	int count=1;

	for(auto ngs:gd[s])
	{
		// taking the configuration of the edge
		int ng = ngs.first;

		// picking weight of the correspoding edge
		int wt = ngs.second;

		// if the node is not visited 
		if(vs[ng]==0)
		{

			// giving the no of nodes 
			// including myself for subtree
			// rooted with node named 'ng'
			int desc = dfs(ng,gd,vs,des,max_distance,no_of_vertices);

			// getting the min no of traverse 
			// perform by min(desc,no_of_vertices-desc)
			// getting cost by multiplying with weight
			// because to and fro can be performed hence 
			// multiplied by 2 ( i.e.) no of travellers 
			// passes through this particular edge ( by pigeon hole principle ) 
			max_distance += (2*min(desc,no_of_vertices-desc)*wt);

			// counting all the desc nodes 
			// for the current source node 
			count += desc;			
			
		}
	}

	if(debug)
		cout << " Source " << s << " neighbour size " << gd[s].size() << " Count " << des[s] << endl;
	
	des[s] = count;

	return des[s];
}

void printGraph (vector<vector<pair<int,long long>>> &v)
{
	cout << endl ; 
	int indx = 0;
	for (auto a:v)
	{
		cout << indx << " : ";
		for (auto b:a)
		{
			cout << b.first << " ";
		}
		cout << endl;
		indx++;
	}
}



int main()
{
	debug=0;
	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	int t;
	cin >> t;
	int index = 1;
	while(t--)
	{

		int n,e;
		cin >> n;
		e = n-1;

		gd.clear();
		vs.clear();
		des.clear();

		gd.resize(n+1);
		vs.resize(n+1);
		des.resize(n+1);

		vector<pair<pair<int,int>,long long>> alledges;

		for(int k=0;k<e;k++)
		{
			int st,ed;
			long long wt;
			cin >> st >> ed;
			cin >> wt;

			gd[st].push_back({ed,wt});
			gd[ed].push_back({st,wt});
			
			alledges.push_back({{st,ed},wt});
		}

		if(debug)
			printGraph(gd);

		fill(vs.begin(),vs.end(),0);
		fill(des.begin(),des.end(),0);

		long long maxDistance = 0;

		for(int i=1;i<=n;i++)
		{
			if(vs[i]==0)
			{
				dfs(i,gd,vs,des,maxDistance,n);
				if(debug)
					cout << endl;
			}
		}

		if(debug)
		{
			cout << " Desc " << endl;
			for(auto a:des)
				cout << a << " ";
			cout << endl;
		}

		
		cout << "Case #"<< index++ << ": " << maxDistance <<endl;
	}
}