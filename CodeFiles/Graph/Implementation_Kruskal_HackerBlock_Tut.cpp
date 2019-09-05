#include<bits/stdc++.h>
using namespace std;
// https://www.hackerrank.com/challenges/kruskalmstrsub/problem

class Edge
{
public:
	int st;
	int ed;
	int wt;
};

class Set
{
public:
	int rank;
	int parent;	
};

int debug=0;

int findParent(Set* set_data,int node)
{
	// check whather I am its parent or not 
	// if not it shows I am belonging 
	// to some other group , so i need to get 
	// the group id or parent id 
	if(set_data[node].parent!=node)
	{
		set_data[node].parent = findParent(set_data,set_data[node].parent);
	}
	// ensures node and parent id of the node is same 
	return set_data[node].parent;
}

// join u to v becuase both are belonging 
// to different group currently 
void UnionFind(Set* set_data,int src,int dest)
{
	// get the parent of src
	int parentofsrc = findParent(set_data,src);

	// get the parent of other end of edge dest
	int parentofdest = findParent(set_data,dest);

	if(set_data[parentofsrc].rank < set_data[parentofdest].rank)
	{
		set_data[parentofsrc].parent = parentofdest;
	}
	else if(set_data[parentofsrc].rank > set_data[parentofdest].rank)
	{
		set_data[parentofdest].parent = parentofsrc;
	}
	else
	{
		set_data[parentofsrc].parent = parentofdest;
		set_data[parentofsrc].rank++;
	}
}

bool comp(const Edge &e1,const Edge &e2)
{
	return e1.wt < e2.wt;
}

void perform_Kruskal(Set* set_data,Edge *edge_data,int no_of_vertices,Edge* output_edges,int no_of_edges)
{
	if(debug)
	{
		cout << " No of Edges " << no_of_edges << endl;
	}

	// sorth the edges 
	sort(edge_data,edge_data+no_of_edges,comp);

	if(debug)
	{
		cout << " Sorted Edges " << endl;
		for(int i=0;i<no_of_edges;i++)
		{
			Edge current_edge = edge_data[i];
			cout << current_edge.wt << " :: ";
		}
		cout << endl;
	}

	int no_of_edge_in_mst=0;

	int counter=0;

	// till mST is not built 
	while(no_of_edge_in_mst<no_of_vertices-1)
	{
		// pick the current edge 
		// and check wther we can add to MST or not 
		Edge current_edge = edge_data[counter];
		int left_end_parent = findParent(set_data,current_edge.st);
		int right_end_parent = findParent(set_data,current_edge.ed);

		// if both parent are same it shows 
		// that both node corresponds to same group 
		// hence cycle is present 
		// but if not equal then both does not belong to the same 
		// group 
		if(left_end_parent!=right_end_parent)
		{
			// both nodes of the edge belongs to diff group
			// hence we need to club both under the same tree 
			// by calling union 
			// by sending parent of the nodes 
			// not the current edge nodes ( main point ) 
			UnionFind(set_data,left_end_parent,right_end_parent);

			// Also adding edge to MST 
			output_edges[no_of_edge_in_mst] = current_edge;

			// increase edges in MST 
			no_of_edge_in_mst++;
		}

		counter++;
	}
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

if(debug)
	{
		cout << " Inputs " << endl;
		cout << " edges " << e ;
		cout << endl;
	}

	Edge* input_edge = new Edge[e];
	for(int i=0;i<e;i++)
	{
		int st,ed;
		long long wt;
		cin >> st >> ed;
		cin >> wt;
		Edge instance;
		instance.st=st;
		instance.ed=ed;
		instance.wt=wt;

		// edge[i].st = st;
		// edge[i].ed = ed;
		// edge[i].wt = wt;

		input_edge[i] = instance;
	}

	if(debug)
	{
		cout << " UNSorted Edges " << endl;
		for(int i=0;i<e;i++)
		{
			Edge current_edge = input_edge[i];
			cout << current_edge.wt << " :: ";
		}
		cout << endl;
	}

	Set* set_data = new Set[v+1];
	for(int i=0;i<=v;i++)
	{
		// set_data[i].rank=0;
		// set_data[i].parent=i;	

		Set instance;
		instance.rank=0;
		instance.parent=i;
		set_data[i] = instance;
	}

	// because its MST 
	Edge* output_edges = new Edge[v-1];
	perform_Kruskal(set_data,input_edge,v,output_edges,e);

	int net_weight_sum=0;

	for(int i=0;i<(v-1);i++)
	{
		Edge mst_edge = output_edges[i];

		if(debug)
		{
			cout << mst_edge.st << " &&& " << mst_edge.ed << endl;
		}

		net_weight_sum += mst_edge.wt;
	}

	cout << net_weight_sum << endl;

	return 0;
}