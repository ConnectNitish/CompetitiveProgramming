#include<stdio.h>

int data[2000000];

void swap(int *a,int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

int prt(int l,int h)
{
	int pv = data[h];
	int i = l-1;
	for(int j=l;j<=h-1;j++)
	{
		if(data[j]<pv)
		{
			i++;
			swap(&data[i],&data[j]);
		}
	}
	swap(&data[i+1],&data[h]);
	return (i+1);
}

void _qs(int l,int h)
{
	if(l<h)
	{
		int idx = prt(l,h);
		_qs(l,idx-1);
		_qs(idx+1,h);
	}
}

int main()
{
	int n;
	int count = 0;
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)>0)
	{
		data[count] = n;

		printf("%d ",data[count]);

		count++;
	}
	
	// _qs(0,count-1);

	// for(int i=0;i<count;i++)
	// 	printf("%d ",data[i]);

	return 0;
}

/*

#include <stdio.h>      
#include <stdlib.h>     

int values[] = { 40, 10, 100, 90, 10, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a > *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}

*/