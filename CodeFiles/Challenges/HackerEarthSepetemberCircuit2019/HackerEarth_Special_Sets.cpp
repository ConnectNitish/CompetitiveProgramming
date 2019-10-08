#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int fabon[2010];

int factorial[2010];

void process()
{
	fabon[0]=0;
	fabon[1]=1;

	for(int i=2;i<=2000;i++)
		fabon[i] = (fabon[i-1] + fabon[i-2]) % MOD;

	factorial[0]=1;
	factorial[1]=1;

	for(int i=2;i<=2000;i++)
		factorial[i] = (factorial[i-1] * i) % MOD;
}

int32_t main()
{
	int n;
	cin >> n;

	// process();
	// cout << fabon[n+2] << endl;
	if(n==1) 
	{
		cout << 1 << endl;
		return 0;
	}
	int Totalresult = 0;
	int debug=1;
	int result =1;

	int r=1;

	while(n>=r)
	{
		result=1;
		for(int k=n;k>=(n-r+1);k--)
			result = ( result * k ) % MOD;
		Totalresult = (Totalresult + result)%MOD;
		n--;
		r++;
	}


	cout << Totalresult <<  endl;

}