#include<bits/stdc++.h>
using namespace std;
int debug=0;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int s1,s2;
		cin >> s1 >> s2;
		cout << (s1*s2) - s1 - s2 << endl;
	}
}