#include<bits/stdc++.h>
using namespace std;
int debug=0;
int input[1000];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{

		string s;

		cin >> s;

		int data[26][2];

		for(int i=0;i<26;i++)
		{
			data[i][0]=INT_MAX;
			data[i][1]=INT_MIN;
		}

		int i=0;
		int max_value_index=INT_MIN;
		char max_char_value;
		for(auto a:s)
		{
			int chi = a-'a';
			int min_value = data[chi][0];
			int max_value = data[chi][1];

			data[chi][0] = min(data[chi][0],i);
			data[chi][1] = max(data[chi][1],i);

			i++;

			// max_value_index = max(max_value_index,data[chi][1] - data[chi][0]);

			if(max_value_index<data[chi][1] - data[chi][0])
			{
				max_value_index = data[chi][1] - data[chi][0];
				max_char_value = a;
			}
			else if(max_value_index == data[chi][1] - data[chi][0] && max_char_value>a)
				max_char_value = a;
		}

		cout << max_char_value << " " << max_value_index << endl;
	}
}