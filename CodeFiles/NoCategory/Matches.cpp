#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n1,n2;
		cin >> n1 >> n2;
		ll res = n1 + n2;
		string str = to_string(res);
		ll cnt =0;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='1') cnt += 2;
			else if(str[i]=='2') cnt += 5;
			else if(str[i]=='3') cnt += 5;
			else if(str[i]=='4') cnt += 4;
			else if(str[i]=='5') cnt += 5;
			else if(str[i]=='6') cnt += 6;
			else if(str[i]=='7') cnt += 3;
			else if(str[i]=='8') cnt += 7;
			else if(str[i]=='9') cnt += 6;
			else if(str[i]=='0') cnt += 6;
		}
		cout << cnt << endl;
	}
}