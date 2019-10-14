#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int BIT[MAX];
int Data[MAX];
int temp[MAX];

int q=0;
int n=0;
int debug = 0;

void update(int i,int val)
{
	while(i<=n)
	{
		BIT[i] += val;
		if(debug)
			cout << " Update " << i << endl;
		i += (i & (-i));
	}
}

int query(int i)
{
	int res = 0;
	while(i>0)
	{
		res += BIT[i];
		i -= (i&(-i));
	}
	return res;
}

int bsearch(int element,int length)
{
	int start = 1;
	int end = length;

	while(start <= end)
	{
		if(debug)
		cout << " INput " << endl;

		// int mid = (end - ((end- start) / 2));
		int mid = (start + end) / 2;
		
		if(temp[mid] == element)
			return mid;
		if(temp[mid] > element)
			end = mid - 1;
		else
			start = mid + 1; 
	
	}

	return -1;

}



int main()
{

	if(debug)
	{
		freopen("input.txt","rb",stdin);
		freopen("output.txt","wb",stdout);
	}

	cin >> n >> q;

	if(debug)
	cout << " N " << n << " Q " << q << endl;
	

	memset(Data,0,sizeof Data);
	memset(temp,0,sizeof temp);

	for(int i=1;i<=n;i++)
	{
		cin >> Data[i];
		temp[i] = Data[i];
	}

	sort(temp+1,temp+n+1);

	int inversion_Count = 0;

	for(int i=1;i<=n;i++)
	{
		long long actual_index = bsearch(Data[i],n);
		update(actual_index,1);
	}

	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin >> l >> r;
		int actual_index_l = bsearch(Data[l],n);
		int actual_index_r = bsearch(Data[r],n);
		inversion_Count += query(actual_index_r) - query(actual_index_l-1);
		cout << inversion_Count << endl;
		inversion_Count=0;
	}

	// cout << inversion_Count << endl;
	
	return 0;
}