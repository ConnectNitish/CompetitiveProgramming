#include<bits/stdc++.h>
using namespace std;
#define int long long

int debug=1;

int32_t main()
{
	if(debug)
	{
		freopen("input.txt","rb",stdin);
		freopen("output.txt","wb",stdout);	
	}

	int t;
	cin >> t;
	map<int,vector<int>> data;
	while(t--)
	{
		int n,k;

		cin >> n >> k;

		data.clear();

		vector<int> A0;
		vector<int> A1;
		vector<int> A2;
		vector<int> A;

		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			A.push_back(v);
		}

		A0 = A; 

		if((n&1)==1)
		{
			A0[n/2] = 0;
		}

		vector<int> data_temp;

		data_temp = A0;

		for(int i=0;i<n;i++)
		{
			int start = i;
			int end = (n-i+n-1)%n;
			if(start==end)
			{
				A1.push_back(0);
				data_temp[i] = 0;
			}	
			else
			{
				A1.push_back(data_temp[start]^data_temp[end]);
				data_temp[i] = data_temp[start]^data_temp[end]; 
			}
		}

		data_temp = A1;

		for(int i=0;i<n;i++)
		{
			
			if( (n&1) == 1 && (i == (n/2)) ) 
			{
				A2.push_back(0);
				data_temp[i] = 0;
			}
			else
			{
				A2.push_back(data_temp[i]^A0[i]);
				data_temp[i] = data_temp[i]^A0[i]; 
			}
		}


		data[0] = A0;
		data[1] = A1;
		data[2] = A2;

		// if(debug)
		// {
		// 	cout << " A1 " << endl;
		// 	for(auto a:A1)
		// 		cout << a << " ";
		// 	cout << endl;

		// 	cout << " A2 " << endl;
		// 	for(auto a:A2)
		// 		cout << a << " ";
		// 	cout << endl;
		// }

		int d = (k/n);

		int r = (k%n);

		d = d % 3;
		vector<int> finalAnswer;


		if(r>0)
		{
			int nextBucket = (d+1) % 3;

			data_temp = data[nextBucket];

			for(int i=0;i<r;i++)
			{
				finalAnswer.push_back(data_temp[i]);
			} 
		} 

		data_temp = data[d];

		for(int i=r;i<n;i++)
			finalAnswer.push_back(data_temp[i]);

		if((n&1)==1 && k<=(n/2))
		{
			finalAnswer[(n/2)] = A[(n/2)];
		}

		for(auto a:finalAnswer)
			cout << a << " ";
		cout << endl;
	}

	return 0;

}