#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> allSubsequence;


vector<int> subsequence;
int minValue=INT_MAX; 
int minValueCount=0;

int max_size;
int k;
vector<int> input;

int debug=0;

void get_all_subsequence_ofLength_k(int offset)
{
	if(subsequence.size()==k)
	{
		int sum = 0 ;
		for(auto a:subsequence)
		{
			if(debug)
				cout << a << " ";

			sum += a;
		}

		if(debug)
			cout << endl;

		if(minValue>sum)
		{
			minValue = sum;
			minValueCount=1;
		}
		else if(minValue == sum)
		{
			minValueCount++;
		}
		return;
	}

	int size_left = (k - subsequence.size());

	for(int i=offset;i<max_size && size_left <= (max_size - i +1) ;i++)
	{
		subsequence.push_back(input[i]);
		get_all_subsequence_ofLength_k(i+1);
		subsequence.pop_back();
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> max_size >> k;

		input.clear();
		subsequence.clear();
		minValue=INT_MAX; 

		for(int i=0;i<max_size;i++)
		{
			int V;
			cin >> V;
			input.push_back(V);
		}

		get_all_subsequence_ofLength_k(0);

		cout << minValueCount << endl;

	}
}
