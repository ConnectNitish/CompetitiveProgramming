#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;

		int count=0;
		int sum=0;

		for(auto a:s)
			if(a=='x')
				count++;
			else
				sum += (a-'0');

		string news = "";
		char to_append = (sum > 9 ? (9 - (sum % 9))+'0' : (9-sum)+'0'); 
		for(auto a:s)
		{
			if(a=='x' && count>1)
				news += '9',count--;
			else if(a=='x' && count==1)
				news += to_append,count--;				
			else
				news += a;
		}

		cout << news << endl;

	}
}