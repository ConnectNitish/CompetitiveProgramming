#include<bits/stdc++.h> 
using namespace std; 

int splitArray(vector<int> &arr, int n) 
{ 
	int leftSum = 0; 
	for (int i = 0 ; i < n ; i++) 
		leftSum += arr[i]; 

	int rightSum = 0; 
	for (int i=n-1; i >= 0; i--) 
	{ 
		rightSum += arr[i];
		leftSum -= arr[i]; 

		if (rightSum == leftSum) 
			return i; 
	} 
	return -1; 
} 

bool divideArray(vector<int>& nums,int n_next)
{
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) { return false; }
        int half = sum / 2;
        if (*max_element(nums.begin(), nums.end()) > half) { return false; }
        vector<bool> reach(half+1, false);
        reach[0]=1;
        for (auto num : nums){
            for (int i=half; i >= num; i--){
                if (reach[i-num]) {
                    reach[i]=true;
                    if (reach[half]) { return true; }
                }
            }
        }
        return false;
}


int debug=0;
void answer(vector<int> &arr, int n) 
{ 
	int splitPoint = splitArray(arr, n); 

	if(debug)
	{
		cout << " Split Point " << splitPoint << endl;
	}

	if (splitPoint == -1 || splitPoint == n ) 
	{ 
		cout << "NO" <<endl; 
		return; 
	} 
	cout << "YES" << endl;
} 

int main() 
{ 
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> values;
		for(int i=0;i<n;i++)
		{
			int vv;
			cin >> vv;
			if(debug)
			{
				cout << "input " << vv << endl;
			}
			values.push_back(vv);
		}
		// sort(values.begin(),values.end());
		// answer(values, n); 

		if(divideArray(values,n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0; 
} 
