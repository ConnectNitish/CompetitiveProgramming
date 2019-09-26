#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353 

vector<vector<int>> allSubsequence;

// http://codeforces.com/contest/1188/submission/60583904

set<int> subsequence;
vector<int> v_subsequence;
int minValue=INT_MAX; 
long long minValueCount=0;

int max_size;
int k;
vector<int> input;

int debug=0;

void get_all_subsequence_ofLength_k(int offset)
{
	if(v_subsequence.size()==k)
	{	
		if(debug)
		{
			cout << " Data " << endl;
			for(auto a:v_subsequence)
				cout << a << " ";
			cout << endl;
		}

		sort(v_subsequence.begin(),v_subsequence.end());
		
		int diff=INT_MAX;

		for(int k=1;k<v_subsequence.size();k++)
		{
			if(abs(v_subsequence[k]-v_subsequence[k-1]) < diff)
				diff = abs(v_subsequence[k]-v_subsequence[k-1]);
		}
		minValueCount += (long long)abs(diff);
		
		if(debug)
			cout << endl;

		return;
	}

	int size_left = (k - v_subsequence.size());

	for(int i=offset;i<max_size && size_left <= (max_size - i+1) ;i++)
	{
		v_subsequence.push_back(input[i]);
		get_all_subsequence_ofLength_k(i+1);
		v_subsequence.pop_back();
	}
}

int main()
{
		cin >> max_size >> k;

		input.clear();
		v_subsequence.clear();
		minValue=0; 
		minValueCount=0;

		for(int i=0;i<max_size;i++)
		{
			int V;
			cin >> V;
			input.push_back(V);
		}

		get_all_subsequence_ofLength_k(0);

		cout << minValueCount%998244353 << endl;
}