#include<bits/stdc++.h>
using namespace std;

vector<int> input;
int n,K;
int dp[1000][1000]={-1};

int debug=1;

int R(int i,int j)
{
	int len = j-i+1;
	int maxFreq = 0;

	unordered_map<int,int> count;
	
	for(int k=i;k<=j;k++)
	{
		count[input[k]]++;

		if(count[input[k]]>maxFreq)
		{
			maxFreq = count[input[k]]; 
		}
	}

	// if(debug)
	// {
	// 	cout << " i " << i << " j " << j << endl;
	// 	cout << (len - maxFreq) << endl;
	// }

	return (len - maxFreq);
}

int f(int x,int K1)
{
	// if(x==0) return 0;

	if(K1<0) return 0;

	if(debug)
	{
		cout << " Entering ";
		cout << " x " << x << " K " << K1 << endl;
	}

	if(dp[x][K1] != -1)
	{
		if (debug)
		{
			cout << dp[x][K1] << endl;
		}
		return dp[x][K1];
	}
	
	int value  = INT_MAX;

	for(int i=0;i<=x-1;i++)
	{
		// if(debug)
		// {
		// 	cout << " x " << x << endl;
		// 	for(int k=0;k<i;k++)
		// 		cout << "\t" ;
		// }

		int f_value = f(i,K1-1);
		int r_value = R(i+1,x);

		// value  = min(value,r_value + f_value);

		if(r_value+f_value>0)
		{
			if(value!=INT_MAX)
				value = min(value,f_value+r_value);
			else
				value = r_value + f_value;
		}

		// if(debug)
		// {
		// 	cout << " x " << x << endl;
		// 	cout << " i " << i << endl;
		// 	cout << " f_value " << f_value << endl;
		// 	cout << " r_value " << r_value << endl;	
		// 	cout << " Sum " << value << endl;
 	// 	}
	}

	if(debug)
	{
		cout << " Exit \t";
		cout << " x " << x << " K " << K1 << endl;
	}

	value = (value == INT_MAX ? 0 : value);

	dp[x][K1] = value;

	return value;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		input.clear();
		cin >> n >> K;
		for(int i=0;i<n;i++)
		{
			int v;
			cin >> v;
			input.push_back(v);
		}

		// memset(dp,INT_MAX,sizeof(dp));

		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=K;j++)
				dp[i][j] = -1;
		}

		// cout << dp[7][2] << endl;
		f(n-1,K);

		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=K;j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}


	}
	return 0;
}