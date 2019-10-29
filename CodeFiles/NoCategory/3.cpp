#include <bits/stdc++.h> 
using namespace std; 
#define int long long int

bool recur(int n)
{
	if(n<10)
	{
		if(n==1) return true;
		else return false;
	} 

	bool check1 = (n%10 ==0 && recur(n/10));
	if(check1 == true)
		return check1;

	bool check2 = (n%20 ==0 && recur(n/20));
		return (check2);
}

int32_t main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		int v;
		cin >> v;

		if((v%10 ==0 && recur(v/10)) || (v%20 ==0 && recur(v/20)))
		{
			cout << "Yes" << endl; 
		}
		else
		{
			cout << "No" << endl;
		}
	}
}