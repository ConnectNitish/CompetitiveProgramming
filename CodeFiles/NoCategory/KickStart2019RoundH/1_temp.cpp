#include<bits/stdc++.h>
#define int long long
using namespace std;

void takeInput()
{
	int t;
	cin >> t;
	int tt=1;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> data(n);
		for(int i=0;i<n;i++)
			cin >> data[i];

		vector<int> answer;
		// answer.push_back(1);

		vector<int> details_dis(n+1,0);

		int m_value = INT_MIN;

		for(int i=1;i<=n;i++)
		{
			int value = data[i-1];
			m_value = INT_MIN;

			for(int j = 1;j<=n && j<=value;j++)
			{
				details_dis[j] = details_dis[j] + 1;
				if(details_dis[j]==j)
					m_value = j;
			}

			if(answer.size()==0)
			{
				answer.push_back(1);
				continue;
			}

			if(m_value == INT_MIN)
				m_value = answer[answer.size()-1];
			
			answer.push_back(m_value);
		}

		for(int i=0;i<n;i++)
		{
			if(i==0)
				cout << "Case #" << tt++ << ": ";
				
			cout << answer[i] << " ";

			if(i==n-1)
				cout << endl;
			
		}
	}
}

int32_t main()
{
	takeInput();
}