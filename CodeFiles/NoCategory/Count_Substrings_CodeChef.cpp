#include<iostream>
using namespace std;

// https://www.codechef.com/problems/CSUB

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int l;
		string s;
		cin >> l;
		cin >> s;
		
		int count=0;

		for(int k=0;k<l;k++)
			if(s[k]=='1')
				count++;

		cout << ((((long long)count) * ((long long)count + 1)) >> 1) << endl;
	}
}