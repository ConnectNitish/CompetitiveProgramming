#include<bits/stdc++.h>
#define int long long
using namespace std;

bool runArithmetic(vector<int>& arr, int all_comsumed, char operation, int sum){
	if(all_comsumed==0)
	{
		if(sum%11==0) 
			return true;
		return false;
	}
	bool flag = false;
	for(int i = 0;i<9;i++)
	{
		if(arr[i]==0)
				continue;

		arr[i] = arr[i] - 1;
		if(operation=='-') 
		{
			flag = runArithmetic(arr,all_comsumed-1,'+',sum-i-1);
		}
		else if(operation=='+')
		{
			flag = runArithmetic(arr,all_comsumed-1,'-',sum+i+1);
		}
		arr[i] = arr[i] + 1;

		if(flag == true) 
			return true;

	}	
	return false;
}

int32_t main(){

	int t;cin>>t;
	for(int k = 1;k<=t;k++)
	{
		int num_digits = 0;
		bool result = false;
		vector<int> arr(9);
		for(int i = 0;i<9;i++)
		{
			int v;
			cin>>v;
			arr[i] = v;
			num_digits += v;
		}

		for(int i = 0;i<9;i++)
		{
			if(arr[i]==0)
				continue;

			arr[i]--;
			result = runArithmetic(arr,num_digits-1,'-',i+1);
			arr[i]++;
			if(result) 
				break;
		}

		if(result)
		{
			cout <<"Case #" << k <<": "<<"YES"<<"\n";
		}
		else 
		{
			cout <<"Case #" << k <<": "<<"NO"<<"\n";
		}
	}	
	return 0;
}