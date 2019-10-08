#include<bits/stdc++.h>
using namespace std;

#define N 1000000
#define BLOCK_SIZE 555 // ~sqrt(N)

vector<pair<pair<int,int>,int>> q;
// map<int,int> freq_count;

int freq_count[N];
int data[N];

int debug = 0;

// int BLOCK_SIZE;

bool m_sort(pair<pair<int,int>,int> &pair1,pair<pair<int,int>,int> &pair2)
{
	pair<int,int> _p1 = pair1.first;
	
	pair<int,int> _p2 = pair2.first;

	int _lvalue = _p1.first / BLOCK_SIZE;
	int _rvalue = _p2.first / BLOCK_SIZE;

	if(_lvalue != _rvalue)
		return _lvalue < _rvalue;

	return _p1.second < _p2.second;
}

int32_t main()
{
	if(debug)
	{
		freopen("input.txt","rb",stdin);
		freopen("output.txt","wb",stdout);
	}

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int n,nq;
	
	// cin >> n;
	scanf("%d",&n);
	// int data[n];

	// BLOCK_SIZE = (int)sqrt(n);

	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	
	// cin >> nq;
	
	scanf("%d",&nq);


	for(int i=0;i<nq;i++)
	{
		int l,r;
		
		// cin >> l >> r;

		scanf("%d",&l);
		scanf("%d",&r);
		
		q.push_back({{l-1,r-1},i});
	}

	sort(q.begin(),q.end(),m_sort);

	if(debug)
	{
		cout<< " Input Array " << endl;
		for(int k=0;k<n;k++)
			cout << data[k] << " ";
		cout << endl;
		cout << " Queries Sorted " << endl;
		for(auto a:q)
		{
			cout << " Q NO " << a.second << " -- " << a.first.first << " " << a.first.second << endl;
		}
	}

	int count_distinct = 0;
	vector<int> answers(nq+1,0);
	
	// at the start both pointer will be at first element 
	int start_pointer = 0;
	int end_pointer = 0;

	for(auto a:q)
	{
		pair<int,int> query = a.first;

		// case 1 
		// first we will check whether we have to add element the element or not 
		// case 2 can't be here and case 1 can't be below because 
		// start pointer is getting decrementing below 

		// decreasing the start Pointer while moving it to the right 
		while(start_pointer < query.first )
		{
			freq_count[data[start_pointer]]--;
			if(freq_count[data[start_pointer]]==0)
				count_distinct--;
			start_pointer++;
		}

		// case 2 
		// this case shows that we need to expanding ( add ) elements 
		// this case can't be above Case 1 because start_pointer is modified
		// and it is incremented 

		// exapnding the start Pointer to its left 
		while(start_pointer > query.first)
		{
			start_pointer--;
			freq_count[data[start_pointer]]++;
			if(freq_count[data[start_pointer]]==1)
				count_distinct++;
		}

		// case 3 
		// adding elements while moving to the right 

		// exapnding the end Pointer 
		while(end_pointer <= query.second)
		{
			freq_count[data[end_pointer]]++;
			if(freq_count[data[end_pointer]]==1)
				count_distinct++;
			end_pointer++;
		}

		// case 4 
		// removing the elements 
		// because here end_pointer is decreamented 
		// case 3 can't be upwards and case 4 below 

		// decreasing the end Pointer to its left 
		while(end_pointer > query.second+1)
		{
			end_pointer--;
			freq_count[data[end_pointer]]--;
			if(freq_count[data[end_pointer]]==0)
				count_distinct--;
		}

		answers[a.second] = count_distinct;
	}

	for(int i=0;i<nq;i++)
		cout << answers[i] << endl;

	return 0;
}