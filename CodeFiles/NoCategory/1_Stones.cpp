#include<bits/stdc++.h>
using namespace std;
#define int long long 

int debug=0;

int32_t main()
{
	int testcase;
	cin >> testcase;

	while(testcase--)
	{
		int f,s,t;

		cin >> f >> s >> t;

		if(s==0)
		{
			cout << "0" << endl;
			continue;
		}

		if(t<2)
		{
			if(s<2)
			{
				cout << "0" << endl;
				continue;
			}
			else
			{
				if(f<1)
				{
					cout << "0" << endl;
					continue;
				}
				else
				{
					int pick = s/2;
					pick = min(pick,f);
					int value = pick + 2*pick;
					cout << value << endl;
					continue;
				}
			}
		}
		else
		{
			int pick_by_3 = t/2;
			int pick_by_2 = min(s,pick_by_3);
			if(debug)
			{
				cout << " Picked by 2-3 " << pick_by_2 << endl;
			}
			int final_picked = pick_by_2 + 2*pick_by_2;
			s = s - pick_by_2;
			pick_by_2 = s/2;
			
			

			int pick_by_1 = min(f,pick_by_2);

			if(debug)
			{
				cout << " Picked by 1-2 " << pick_by_1 << endl;
			}

			final_picked += pick_by_1 + 2 * pick_by_1;
			cout << final_picked << endl;
		}
	}
	return 0;
}