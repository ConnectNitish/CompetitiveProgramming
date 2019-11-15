#include<bits/stdc++.h>
using namespace std;
int debug=0;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s1,s2;
		cin >> s1 >> s2;

		if(debug)
		{
			cout << s1 << endl;
			cout << s2 << endl;
		}

		int s1_len=0,s2_len=0;
		while(s1_len<s1.length() && s2_len<s2.length())
		{
			if(s1[s1_len] == s2[s2_len])
				s2_len++;
			s1_len++;
		}

		if(s2_len == s2.length())
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}