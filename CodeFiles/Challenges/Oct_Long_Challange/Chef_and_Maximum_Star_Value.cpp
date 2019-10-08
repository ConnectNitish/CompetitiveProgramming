#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

map<int,int> factor_freq;
int Data[MAX];

void getDivisors(int n)
{
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			factor_freq[i]++;
			if(n/i != i)
				factor_freq[n/i]++;
		}
	}
}

int32_t main()
{
	int t,n;
	cin >> t;
	while(t--)
	{
		factor_freq.clear();
		cin >> n;
		
		for(int i=0;i<n;i++)
			cin >> Data[i];

		int max_value = 0;
		for(int i=0;i<n;i++)
		{
			if(factor_freq.find(Data[i]) != factor_freq.end())
				max_value = max(factor_freq[Data[i]],max_value);
			
			getDivisors(Data[i]);
		}

		cout << max_value << endl;

	}
	return 0;
}