#include<iostream>
#include<map>
#include<limits.h>
using namespace std;
#define MAX 200000
#define Jump(i) (i&(-i)) 
#define int long long int



// Actaul Input Data 


// map<int,int> fwd;
// map<int,int> rmap;

int debug=1;

//min
int operation_type=1;
//xor
// int operation_type=3;
// //max
// int operation_type=2;


void buildTree(int start,int end,int index,int *Input,int* InputData)
{
	if(start>end) return;

	if(start == end)
	{
		Input[index] = InputData[start];
		return;
	}
	int mid = (start+end)/2;

	buildTree(start,mid,(index * 2),Input,InputData);
	buildTree(mid+1,end,(index * 2)+1,Input,InputData);
	
	if(operation_type==1)
		Input[index] = min(Input[(index * 2)],Input[(index * 2)+1]);
	else if(operation_type==2)
		Input[index] = max(Input[(index * 2)],Input[(index * 2)+1]);
	else if(operation_type==3)
		Input[index] = (Input[(index * 2)]^Input[(index * 2)+1]);
}

void updateTree(int start,int end,int value,int tree_index,int index_to_update,int *Input,int* InputData)
{

	// if(debug)
	// {
	// 	cout << " Start " << start << " End " << end << " index_to_update " << index_to_update << endl;
	// 	cout << " tree_index " << tree_index << endl;
	// }


	if(index_to_update < start || end < index_to_update)
		return;

	// if(debug)
	// 	cout << " Stage 2" << endl;

	if(start==end)
	{
		Input[tree_index] += value;
		return;
	}

	int mid = (start+end)/2;
	updateTree(start,mid,value,tree_index* 2,index_to_update,Input,InputData);
	updateTree(mid+1,end,value,(tree_index* 2)+1,index_to_update,Input,InputData);

	if(operation_type==1)
		Input[tree_index] = min(Input[(tree_index * 2)],Input[(tree_index * 2)+1]);
	else if(operation_type==2)
		Input[tree_index] = max(Input[(tree_index * 2)],Input[(tree_index * 2)+1]);
	else if(operation_type==3)
		Input[tree_index] = (Input[(tree_index * 2)]^Input[(tree_index * 2)+1]);
}

// start_index for Query  
// end_index for Query 
// start for Tree  
// end for Tree
// current_index -> where at Tree I am Standing  
int query(int start,int end,int start_index,int end_index,int current_index,int *Input,int* InputData)
{
	// Complete Over lapp 
	if(start >= start_index  && end <= end_index )
		return Input[current_index];

	// No Over lapp 
	if(end<start_index || end_index<start)
		return INT_MAX;

	// Partial Over Lapp 
	// Call left and Right 
	int mid = (start+end)/2;
	int min_by_left = query(start,mid,start_index,end_index,(current_index * 2),Input,InputData);
	int min_by_right = query(mid+1,end,start_index,end_index,(current_index * 2)+1,Input,InputData);

	int result;

	if(operation_type==1)
		result = min(min_by_left,min_by_right);
	else if(operation_type==2)
		result = max(min_by_left,min_by_right);
	else if(operation_type==3)
		result = (min_by_left^min_by_right);

	return result;
}


void initialise(int n,int q)
{

	// Represent Tree (4*n+1)
	int* Input = new int[4*n+1];
	int* InputData=new int[n];

	for(int i=1;i<=n;i++)
	{
		int v;
		cin >> v;
		// fwd[v]=i;
		// rmap[i]=v;
		InputData[i-1] = v;
		// Input[i] = INT_MAX;
	}

	/**/
	// for(auto a:rmap)
	buildTree(0,n-1,1,Input,InputData);
	
	for(int i=1;i<=q;i++)
	{
		int optype,val1,val2;
		cin >> optype >> val1 >> val2;

		/**/

		if(optype==1)
		{
			int min_value = query(0,n-1,val1-1,val2-1,1,Input,InputData);
			cout << min_value << endl;
		}
		else if(optype==2)
		{
			// int delta = val2;
			// InputData[val1] = val2;
			// rmap[val1] = val2;
			// update(delta,val1,n);

			// if(debug)
			// {
			// 	for(int k=0;k<=4*n+1;k++)
			// 	{
			// 		cout << Input[k] << " ";
			// 	}
			// 	cout << endl;
			// }

			int delta = val2 - InputData[val1-1];

			// if(debug)
			// {
			// 	cout << " delta " << delta << endl;
			// }
			// InputData[val1-1] += delta;
			updateTree(0,n-1,delta,1,val1-1,Input,InputData);
			
			// if(debug)
			// {
			// 	cout << " Post Update "<< endl;
			// 	for(int k=0;k<=4*n+1;k++)
			// 	{
			// 		cout << Input[k] << " ";
			// 	}
			// 	cout << endl;
			// }
		}

		

	}

	

}

int32_t main()
{
	if(debug)
	{
		// freopen("input.txt","rb",stdin);
		freopen("ae5e3153-432e-4c93-b30e-7d27bad0db75","rb",stdin);
		freopen("output.txt","wb",stdout);
	}
	int n,q;
	cin >> n >> q;
	initialise(n,q);
	return 0;
}
