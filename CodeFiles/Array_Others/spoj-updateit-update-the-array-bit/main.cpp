/******************************************************************************

https://www.spoj.com/problems/UPDATEIT/

*******************************************************************************/
#include <iostream>
using namespace std;
int debug=0;

int BIT[100010];

void printArray(int BIT[],int index)
{
    for(int i=0;i<=index;i++)
        printf("%d",BIT[i]);
    printf("\n");
}

void updateBIT(int BIT[],int index,int value,int maxN)
{
    while(index<=maxN)
    {
        BIT[index] += value;
        index += (index & (-index));
    }
}

void range_update(int BIT[],int start,int end,int maxN,int value)
{
    // both are 1 based index 
    // all the indexes which are out of range 
    // of end index is also updated with value 
    updateBIT(BIT,start,value,maxN);
    
    // because in above all greater than end indexes are updated
    // with value SO
    // we need to decreament value from those indexes 
    updateBIT(BIT,end+1,(-1)*value,maxN);
}

int queryBIT(int BIT[],int index)
{
    int res=0;
    while(index>0)
    {
        res += BIT[index];
        index -= (index & (-index));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
	
    int t;
    debug=0;
    // cin >> t;
    scanf("%d",&t);
    
    while(t-->0)
    {
        int n;
        int uq;
        
        // cin >> n;
        // cin >> uq;
    	scanf("%d",&n);
        scanf("%d",&uq);
        
        // int Input[n+1]={0};
        // int BIT[n+1]={0};
        
        for(int i=0;i<100010;i++)
        {
            BIT[i]=0;
        }
        
        for(int i=0;i<uq;i++)
        {
            int start;
            int end;
            int value;
            
            // cin >> start >> end >> value;
            scanf("%d",&start);
        	scanf("%d",&end);scanf("%d",&value);
            
            // before making the range update 
            // we need to make it 1 based index 
            range_update(BIT,start+1,end+1,n,value);
            
            if(debug)
                printArray(BIT,n);
            
        }
        
        int queriesforsum;
        // cin >> queriesforsum;
        scanf("%d",&queriesforsum);
        
        for(int i=0;i<queriesforsum;i++)
        {
            int index;
            // cin >> index;
            scanf("%d",&index);
            if(index==0)
                index = 1;
            else    
                index++;
            // std::cout << queryBIT(BIT,index) << std::endl;
            printf("%d\n",queryBIT(BIT,index));
        }
    }

    return 0;
}

/*
Input 1:
1
5 3
0 1 7
2 4 6
1 3 2
3
0
3
4
Output 1:
7
8
6
Input 2:
1
4 4
0 3 -6
0 3 -6
0 3 -6
0 3 -6
2
0
3
Output 2:
-14
2
*/


