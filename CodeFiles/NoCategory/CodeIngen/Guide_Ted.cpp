#include<bits/stdc++.h>
using namespace std;
int debug=0;

int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		int x,y;
		cin >> x >> y;
		int dp[a+1][b+1];

		for(int i=0;i<=a;i++)
			for(int j=0;j<=b;j++)
				dp[i][j] = 0;

		for(int i=0;i<=a;i++)
			if(0==x && y==i)
				break;
			else
				dp[0][i] = 1;

		for(int i=0;i<=b;i++)
			if(0==y && x==i)
				break;
			else
				dp[i][0] = 1;

			if(debug)
			{
				cout << " -------- " << endl;
				for(int i=0;i<=a;i++)
				{
					for(int j=0;j<=b;j++)
					{
						cout << dp[i][j] << " ";
					}
					cout << endl;
				}
				cout << " -------- " << endl;
			}

		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(debug)
				{
					cout << " Co-ordinates " << endl;
					cout << i << " && " << j << endl;
					cout << "x y " << x << " && " << y << endl;
					cout << dp[i-1][j] << " --- " <<  dp[i][j-1] << endl;
				}

				
				if(i==x && j==y)
				{

				}
				else
				{
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
			}
		}

		cout << dp[a][b] << endl;
	}
}