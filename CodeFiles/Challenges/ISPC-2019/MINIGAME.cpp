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

		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			data.push_back(v);
		}

		sort(data.begin(),data.end());

		long long dora = 0;
		long long boots = 0;

		bool doraTurn = true;
		for(int i=n-1;i>=0;i--)
		{	
			if(doraTurn == false)
				boots += data[i],doraTurn = true;
			else
				dora += data[i],doraTurn = false;
		}

		if(boots > dora)
			cout << "Boots" << endl;
		else if(boots < dora)
			cout << "Dora" << endl;
		else
			cout << "Draw" << endl;


	}
}