#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int tt=1;tt<=t;tt++)
	{
		long long count=0;

		int n,k;
		cin >> n >> k;

		vector<int> data;
		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			data.push_back(v);
		}

		int index = 1;
		
		int changes=0;

		vector<pair<int,int>> distinct;
		map<int,int> freq;
		map<int,int> freqIndex;

		int debug=0;
		int first=data[index];
		int second=-1;
		index++;

		while(index<data.size())
		{
			second = data[index];

			if(first==second)
			{
				index++;
				continue;
			}

			freq[first]++;
			freqIndex[first] = index;

			// index++;
			// if(index>=n)
			// 	break;
			if(first!=second)
				distinct.push_back({first,second});
			
			freq[second]++;
			freqIndex[second] = index;

			first = second;

			if(distinct.size()>=k)
			{
				if(debug)
				{
					cout << " Index " << endl;
					cout << index+1 << endl;
					cout << data[index+1] << endl;
				}
				count++;
				int max_value = INT_MIN;
				int min_value = INT_MAX;
				for(auto mm : freq)
				{
					max_value = max(max_value,mm.first);
					min_value = max(min_value,mm.first);
				}
				// index = freqIndex[max_value];
				//distinct.clear();

				// if(distinct.find({max_value,min_value})==distinct.end())
				// 	distinct.erase({max_value,min_value});
				// else if(distinct.find({min_value,max_value})==distinct.end())
				// 	distinct.erase({min_value,max_value});

				distinct.erase(distinct.begin());
				distinct.erase(distinct.begin());
				 
				// continue;
			}
			index++;
		}

		// if(distinct.size()>=k)
		// 	{
		// 		count++;
		// 		// continue;
		// 	}


		cout <<"Case #" << tt<<": "<< count << endl;
	}
}