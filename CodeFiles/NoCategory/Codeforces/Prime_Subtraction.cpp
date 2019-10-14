#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll k,r;
		
		cin >> k >> r;

		string answer="YES";

		if(abs(k-r)==1)
			answer="NO";

		cout << answer << endl;
		
	}	
}