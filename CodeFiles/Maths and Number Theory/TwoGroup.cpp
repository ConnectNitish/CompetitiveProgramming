#include<iostream>
// https://discuss.codechef.com/t/twogrs-editorial/38845
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{

		int a,b,c;
		cin >> a >> b >> c;
		
		int sum = a*1 + b*2 + c*3;

		if(sum%2!=0)
		{
			cout << "NO" << endl;continue;
		}
		
		else
		{
			if(a==0 && c==0 && b%2!=0)
			{
				cout << "NO" << endl;continue;
			}
			else if(a==1 && b==0 && c%2!=0)
			{
				cout << "NO" << endl;continue;
			}
			else if(a==0 && b==1 && c%2==0)
			{
				cout << "NO" << endl;continue;
			}
			else
				cout << "YES" << endl;
		}
	}
}