#include<iostream>
using namespace std;
#define int long long 

int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		if(n==2)
		{
			cout << "2" << endl;
			continue;
		}
		else if(n==3)
		{
			cout << "1" << endl;
			continue;
		}
		else
		{
			if((n&1)==1)
			{
				cout << "1" << endl;
			}
			else
				cout << "0" << endl;
		}

	}
}