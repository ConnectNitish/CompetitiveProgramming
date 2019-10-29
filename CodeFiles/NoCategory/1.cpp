#include<bits/stdc++.h>
using namespace std;
int debug=1;
#define int long long 

bool _sort(pair<int,int> &p1,pair<int,int> &p2)
{
	if(p1.first<p2.first)
		return true;
	if(p1.first == p2.first)
		if(p1.second <= p2.second)
			return true;
	return false;
}

int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<pair<int,int>> data(3);
		int v;
		cin >> v;
		int counter = 0;
		data[0] = {v,0};

		cin >> v;
		data[1] = {v,1};

		cin >> v;
		data[2] = {v,2};

		sort(data.begin(),data.end(),_sort);
		data.erase(data.begin()+1);



		n -= 3;
		counter += 2;

		while(n>0)
		{
			cin >> v;
			data.push_back({v,counter}); 
			sort(data.begin(),data.end(),_sort);
			data.erase(data.begin()+1);
			counter++;
			n--;
		}

		vector<int> answer(2,0);
		pair<int,int> firstValue = data[0];
		pair<int,int> secondValue = data[1];

		int f,s;

		if(firstValue.second < secondValue.second)
		{
			f = firstValue.first;
			s = secondValue.first;
		}
		else
		{
			f = secondValue.first;
			s = firstValue.first;
		}

		cout << f << " " << s << " ";
		cout << endl;

	}
}