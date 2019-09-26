// https://cses.fi/problemset/task/1716

#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<ll> f_value(10000900);

void factorial()
{
	f_value[0] = 1;
	f_value[1] = 1;
	for(ll k=2;k<10000900;k++)
	{
		f_value[k] = (k * f_value[k-1])%MOD;
	}
}

ll p(ll a,ll b)
{
	if(a==1) return 1;
	if(b==0) return 1;
	if(b==1) return a%MOD;
	ll half = p(a,(b >> 1));
	if((b&1))
	{
		return (((half * a) % MOD ) * half )%MOD;
	}
	return (half%MOD * half%MOD) % MOD;
}

int main()
{
	ll n;
	ll r;
	cin >> n >> r;
	
	swap(n,r);

	factorial();

	ll nr = f_value[n+r-1]%MOD;
	ll nfac = p(f_value[n],MOD-2)%MOD;
	ll rmiunsone = p(f_value[r-1],MOD-2)%MOD;

	cout << ((nr * nfac)%MOD * rmiunsone)%MOD << endl;
	return 0;
}