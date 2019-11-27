#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> data;
		vector<int> data2;

		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			data.push_back(v);
		}

		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			data2.push_back(v);
		}


		sort(data.begin(),data.end());
		sort(data2.begin(),data2.end());


		long long value = 0;

		for(int i=n-1;i>=0;i--)
		{	
			value += min(data[i],data2[i]);
		}
		
		cout << value << endl;

	}
}