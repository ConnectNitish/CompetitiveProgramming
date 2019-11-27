#include<bits/stdc++.h>
using namespace std;
int debug=0;

int32_t main()
{
	int t;
	cin >> t;
	int tt=1;
	while(t--)
	{
		int n;
		cin >> n;
		int data[n];
		for(int i=0;i<n;i++)
			cin >> data[i];

		int ans[n];
		ans[0] = 1;

		multiset<int,greater<int>> svalue;
		// multiset<int> svalue;
		map<int,int> map_data;

		svalue.insert(data[0]);

		map_data.insert({data[0],0});
		int max_till_point=1;
		for(int i=1;i<n;i++)
		{
			int value = data[i];

			// auto it = svalue.lower_bound(value);
			// int index = distance(it,svalue.end());

			auto it = map_data.lower_bound(value);
			int index = distance(map_data.begin(),it);


			if(debug)
			{
				cout << endl;
				cout << " Value " << value << endl;
				cout << "Set data" << endl;
				for(auto a:map_data)
					cout << a.first << " ";
				cout << endl;
				cout << " index " << index << endl;
				cout << endl;
			}

			if(map_data.size()==index)
				ans[i]=map_data.size();
			else
				ans[i] = (index + 1);

			svalue.insert(value);

			map_data.insert({value,i});

			// max_till_point = max(max_till_point,ans[i]);

		}


		for(int i=0;i<n;i++)
		{
			if(i==0)
				cout << "Case #" << tt << ": ";
				
			cout << ans[i] << " ";

			if(i==n-1)
				cout << endl;
			
		}
		tt++;

	}
}