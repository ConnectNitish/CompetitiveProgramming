#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> allSubsequence;

// CHEFINSQ

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


/*

Chef has a sequence A1,A2,…,AN. This sequence has exactly 2N subsequences. Chef considers a subsequence of A interesting if its size is exactly K and the sum of all its elements is minimum possible, i.e. there is no subsequence with size K which has a smaller sum.

Help Chef find the number of interesting subsequences of the sequence A.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer ― the number of interesting subsequences.

Constraints
1≤T≤10
1≤K≤N≤50
1≤Ai≤100 for each valid i
Subtasks
Subtask #1 (30 points): 1≤N≤20
Subtask #2 (70 points): original constraints

Example Input
1
4 2
1 2 3 4
Example Output
1
Explanation
Example case 1: There are six subsequences with length 2: (1,2), (1,3), (1,4), (2,3), (2,4) and (3,4).
 The minimum sum is 3 and the only subsequence with this sum is (1,2).

*/