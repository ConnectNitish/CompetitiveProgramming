#include<iostream>
#include<vector>
#include<map>
using namespace std;

int debug=1;

class Set 
{
public:
	int rank;
	int parent;
};

// Recusrive Way O(n)
int findParent(vector<Set> &setdata,int node)
{
	if(setdata[node].parent==node)
		return node;
	return findParent(setdata,setdata[node].parent);
}

// Recusrive Way O(log n)
int findParentWithPathCompression(vector<Set> &setdata,int node)
{
	if(setdata[node].parent==node)
		return node;
	return (setdata[node].parent = findParentWithPathCompression(setdata,setdata[node].parent));
}


// iterative Way O(n)
int findParentIterative(vector<Set> &setdata,int node)
{
	while(setdata[node].parent!=node)
	{
		node = setdata[node].parent;
	}
	return setdata[node].parent;
}

// pass by reference between here setdata
// will be updated while perfoming union 
// O(n)
bool _union(vector<Set> &setdata,int u,int v)
{
	
	// int parentofu = findParent(setdata,u);
	// int parentofv = findParent(setdata,v);

	// int parentofu = findParentIterative(setdata,u);
	// int parentofv = findParentIterative(setdata,v);

	

	int parentofu = findParentWithPathCompression(setdata,u);
	int parentofv = findParentWithPathCompression(setdata,v);


	if(parentofu!=parentofv)
	{
		// here parent we are setting id 
		// of the bigger number among the two 
		// this logic can be replaced by rank also 
		if(parentofu<=parentofv)
		{
			setdata[parentofu].parent = parentofv;
		}
		else
		{
			setdata[parentofv].parent = parentofu;
		}

		return false;
	}

	return true;
}

// pass by reference between here setdata
// will be updated while perfoming union 
bool _unionbyRank(vector<Set> &setdata,int u,int v)
{
	
	// int parentofu = findParent(setdata,u);
	// int parentofv = findParent(setdata,v);

	// int parentofu = findParentIterative(setdata,u);
	// int parentofv = findParentIterative(setdata,v);

	int parentofu = findParentWithPathCompression(setdata,u);
	int parentofv = findParentWithPathCompression(setdata,v);


	if(parentofu!=parentofv)
	{
		// here parent we are setting id 
		// of the bigger number among the two 
		// this logic can be replaced by rank also 
		if(setdata[parentofu].rank<setdata[parentofu].rank)
		{
			setdata[parentofu].parent = parentofv;
		}
		else if(setdata[parentofu].rank>setdata[parentofu].rank)
		{
			setdata[parentofv].parent = parentofu;
		}
		// if two ranks are same then I am increamenting the size of 
		// left with 1 ( i.e. u is coming as child of v)
		else if(setdata[parentofu].rank == setdata[parentofu].rank)
		{
			setdata[parentofu].parent = parentofv;		
			setdata[parentofu].rank++;
		}


		return false;
	}

	return true;
}



int main()
{
	if(debug)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}

	int v,e;
	cin >> v >> e;

	map<int,vector<int>> gr;
	vector<Set> setdata(v);
	vector<bool> visited(v,false);
	vector<pair<int,int>> alledges;

	for(int i=0;i<v;i++)
	{
		gr[i] = {};
		Set ins;
		ins.rank=0;
		ins.parent=i;
		setdata[i] = ins;
	}

	for(int i=0;i<e;i++)
	{
		int st,ed;
		cin >> st >> ed;
		gr[st].push_back(ed);
		gr[ed].push_back(st);
		alledges.push_back({st,ed});
	}

	// traverse for each node of the graph 
	for(int i=0;i<e;i++)
	{
		pair<int,int> curr_edge = alledges[i];
		// bool result = _union(setdata,curr_edge.first,curr_edge.second);
		bool result = _unionbyRank(setdata,curr_edge.first,curr_edge.second);

		if(debug)
		{
			cout << " Current Edge " << endl;
			cout << curr_edge.first << " $$ " << curr_edge.second << endl;
			cout << " Current Set " << endl;
			for(auto a: setdata)
			{
				Set instance = a;
				cout << instance.parent << " ";
			}
			cout << endl;

			cout << " Current Rank " << endl;
			for(auto a: setdata)
			{
				Set instance = a;
				cout << instance.rank << " ";
			}
			cout << endl;

			cout << " Has Cycle " << result << endl;
		}
	}





	return 0;
}

/*
Input:

5 5
0 1
1 2
2 3
2 4
0 4

Output:

 Current Edge 
0 $$ 1
 Current Set 
1 1 2 3 4 
 Current Rank 
1 0 0 0 0 
 Has Cycle 0
 Current Edge 
1 $$ 2
 Current Set 
1 2 2 3 4 
 Current Rank 
1 1 0 0 0 
 Has Cycle 0
 Current Edge 
2 $$ 3
 Current Set 
1 2 3 3 4 
 Current Rank 
1 1 1 0 0 
 Has Cycle 0
 Current Edge 
2 $$ 4
 Current Set 
1 2 3 4 4 
 Current Rank 
1 1 1 1 0 
 Has Cycle 0
 Current Edge 
0 $$ 4
 Current Set 
4 4 4 4 4 
 Current Rank 
1 1 1 1 0 
 Has Cycle 1




*/
