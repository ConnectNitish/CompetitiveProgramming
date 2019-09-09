#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int data[60];

vector<ll> dataIndexes;
vector<ll> fabonacciValues;

int debug=0;

void preprocess()
{
	
	data[0]=0;
	data[1]=1;

	for(int i=2;i<60;i++)
		data[i] = ( data[i-1] + data[i-2] ) % 10; 

	if(debug)
	{	
		for(int i=0;i<60;i++)
			cout << data[i] << "  " ; 
		cout << endl;
	}

	ll fa_value,value;

	dataIndexes.push_back(0);
	fabonacciValues.push_back(0);

	for(int i=0;i<=61;i++)
	{
		value = pow(2,i);
		if(value==0 || value==1)
			fa_value = 0;
		else
			fa_value = data[(value%60)-1];
		dataIndexes.push_back(value);
		fabonacciValues.push_back(fa_value);
	}

	if(debug)
		for(int i=0;i<=61;i++)
			cout << dataIndexes[i] << " " << fabonacciValues[i] << endl;

	}

	int main()
	{
		int t;
		cin >> t;

		preprocess();

		while(t--)
		{
			unsigned long long int nu;
			cin >> nu;
			// int index = (lower_bound(dataIndexes.begin(),dataIndexes.end(),nu) - dataIndexes.begin());


			int index ;

			for(index=0;index<dataIndexes.size();index++)
				if(nu < dataIndexes[index])
					break;

			if(debug)
				cout << " Found Index " << index << endl;


			cout << fabonacciValues[index-1] << endl;
		}


	}