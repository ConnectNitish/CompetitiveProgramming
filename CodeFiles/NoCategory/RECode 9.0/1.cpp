#include<bits/stdc++.h>
using namespace std;
int debug=0;
int input[1000];

int main()
{
	int t;
	// cin >> t;
	t = 1;
	while(t--)
	{
		int s1,s2;
		cin >> s1 >> s2;
		memset(input,0,sizeof input);
		int min_value=INT_MAX,max_value=INT_MIN;
		int total_sum = 0;

		for(int i=0;i<s1;i++)
		{
			int v; cin >> v;
			input[v] = 1;
			min_value = min(min_value,v);
			max_value = max(max_value,v);
			total_sum += v;
		}

		if(total_sum==s2)
		{
			cout << "YES" << endl;
			continue;
		}

		bool found = false;

		for(int k=min_value;k<=max_value;k++)
		{
			if(input[k]==0)
			{	
				if(total_sum + k == s2)
					found = true;
			}

			if(found==true)
				break;
		}

		if(found == true)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}
}