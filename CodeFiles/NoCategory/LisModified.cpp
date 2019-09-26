#include<bits/stdc++.h>
using namespace std;
vector<int> input;
vector<int> weight;
vector<int> LISArray;
vector<int> parent;
vector<int> __index;
int n;

void clear_v(vector<int> &v)
{
	v.clear();
}

void getLIS()
{
	for(int i=0;i<n;i++)
	{
		if(LISArray.size()==0)
		{
			parent[i] = -1;
			// __index[i] = i;
			LISArray.push_back(input[i]);
		}
		else
		{
			int current_element = input[i];
			if(current_element<LISArray[0])
			{
				parent[i] = -1;
				// __index[i] = i;
				LISArray[0] = current_element;
			}
			else if(current_element>LISArray[LISArray.size()-1])
			{
				parent[i] = LISArray.size()-1;
				LISArray.push_back(current_element);
			}
			else
			{
				int index = lower_bound(LISArray.begin(),LISArray.end(),current_element) 
				- LISArray.begin();
				if(index>0 && index<LISArray.size())
				{
					LISArray[index] = current_element;
					parent[i] = index;
				}
			}
		}
	}

	for(auto a:LISArray)
	{
		cout << a << " ";
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		clear_v(input);clear_v(weight);
		clear_v(parent);
		// clear_v(__index);
		clear_v(LISArray);
		cin >> n;

		input.resize(n);
		weight.resize(n);
		// LISArray.resize(n);
		parent.resize(n);
		// __index.resize(n);
		
		for(int i=0;i<n;i++)
		{
			int v; cin >> v;
			input[i]=v;
			// LISArray.push_back(1);
		}
		
		for(int i=0;i<n;i++)
		{
			int v; cin >> v;
			weight[i]=v;
		}

		getLIS();


	}
}