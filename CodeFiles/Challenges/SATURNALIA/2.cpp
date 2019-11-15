#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		for(int i=0;i<1000;i++)
		{
			for(int j=0;j<1000;j++)
			{
				dp[i][j] = 0;
			}
		}

		int r,c;

		cin >> r >> c;

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin >> dp[i][j];

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(i==0 && j>0)
				{
					dp[i][j] += dp[i][j-1];
				}
				else if(i>0 && j==0)
				{
					dp[i][j] += dp[i-1][j];
				}	
				else
				{
					dp[i][j] += max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
				}
			}
		}

		cout << dp[r-1][c-1] << endl;

	}
}