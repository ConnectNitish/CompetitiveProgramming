#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		priority_queue<int,vector<int>,greater<int>> data;
		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			data.push(v);
		}

		ll result = 0;

		while(data.empty()==false && data.size()>=2)
		{
			ll top1 = data.top();
			data.pop();
			
			// if(data.empty()==true)
			// {
			// 	result+=top1;
			// 	break;
			// }

			ll top2 = data.top();
			data.pop();
			result += top1*top2;
			
			if(data.size()>0)
				data.push(top1+top2);
		}

		if(data.size()==1)
			result += data.top();

		cout << result << endl;
	}	
}