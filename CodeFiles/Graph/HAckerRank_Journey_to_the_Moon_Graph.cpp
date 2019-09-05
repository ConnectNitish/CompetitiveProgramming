#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> gr(100001,vector<int>(0));
vector<int> vs(100001,0);

int debug=1;

void dfs(vector<vector<int>> &gr,vector<int> &vs,int source,int &count)
{
	count++;
	vs[source]=1;
	for(int n:gr[source])
	{
		if(vs[n]==0)
			dfs(gr,vs,n,count);
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

	vs.clear();
	vs.resize(100001);

	gr.clear();
	gr.resize(100001);

	long long v,e;
	cin >> v >> e;

	if(debug)
	{
		cout << " Input v" << v << endl;
		cout << " Input e" << e << endl;
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		gr[st].push_back(ed);
		gr[ed].push_back(st);
	}

	long long totalSum = 0;
	if((v&1)==1)
	{
		totalSum = (long long)(((v-1)/2) * v);
	}
	else
	{
		totalSum = (long long)((v/2) * (v-1));
	}	

	if(debug)
	{
		cout << " totalSum " << totalSum << endl;
	}

	for(int i=0;i<v;i++)
	{
		if(vs[i]==0)
		{
			int count=0;
			dfs(gr,vs,i,count);

			if(count>1)
			{
				if(debug)
				{
					cout << " count " << count << endl;
				}
				totalSum -= ((long long)(count * (count-1))/2);
			}
		}
	}

	cout << totalSum << endl;


}


/*


Input (stdin)
Download
100000 2
1 2
3 4
Expected Output
Download
4999949998


*/