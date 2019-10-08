#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s1;
		string s2;
		cin >> s1 >> s2;
		map<char,int> s1c;
		
		for(auto a:s1)
		{
			s1c[a]++;
		}

		string ans="NO";

		for(auto l:s2)
		{
			if( s1c.find(l) != s1c.end())
				{
					ans = "YES";
					break;
				} 
		}

		cout << ans << endl;

	}
}