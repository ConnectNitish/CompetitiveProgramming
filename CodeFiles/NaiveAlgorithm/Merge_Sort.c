#include<stdio.h>

int data[2000000];

int min(int x,int y)
{
	if(x>y) return y;
	return x;
}

void _merge(int l,int m,int h)
{
	int nA[h-l+1];

	int p = l,q=m+1,k=0;

	while(p<=m && q<=h)
	{
		if(data[p]>data[q])
		{
			nA[k++] = data[q++];

			// for inversion count
			// ct += (m-p+1);
		}
		else
			nA[k++] = data[p++];
	}

	while(p<=m)
		nA[k++] = data[p++];
	
	while(q<=h)
		nA[k++] = data[q++];

	for(int j=0;j<k;j++)
		data[l+j] = nA[j];
}

void _itertivems(int start,int end)
{
	for(int curr=1;curr<=end;curr = 2*curr)
	{
		for(int left = 0;left<end-1;left+=(2*curr))
		{
			int md = min(left+curr-1,end-1);
			int rg_end = min(left+2*curr-1,end-1);
			_merge(left,md,rg_end);
		}
	}
}

void _ms(int l,int h)
{
	if(l<h)
	{
		int md = l + ((h-l)/2);
		_ms(l,md);
		_ms(md+1,h);
		_merge(l,md,h);
	}
}

int main()
{
	int n;
	int count = 0;
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)>0)
		data[count++] = n;
	
	// _ms(0,count-1);

	_itertivems(0,count);

	for(int i=0;i<count;i++)
		printf("%d ",data[i]);

	return 0;
}