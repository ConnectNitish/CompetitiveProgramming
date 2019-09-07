/******************************************************************************

https://www.youtube.com/watch?time_continue=1734&v=eSDa4iauLbo

*******************************************************************************/
#include <stdio.h>

int debug = 0;

int noofInvocationRecursion=0;
// basic Recursion 
// gives max profit if each year bottle is sold 
int getMaxProfit(int bottle_weight[],int year,int start,int end)
{
    ++noofInvocationRecursion;
    if(start>end)
        return 0; // no profit since all bottle are consumed
    
    // picking bottle from left hand side     
    int firstBottleProfit = bottle_weight[start] * year 
    + getMaxProfit(bottle_weight,year+1,start+1,end);
    
    //picking bottle from right hand side 
    int lastbottleProfit = bottle_weight[end] * year 
    + getMaxProfit(bottle_weight,year+1,start,end-1);
    
    int ans; 
    if(firstBottleProfit>=lastbottleProfit)
        ans = firstBottleProfit;
    else
        ans =  lastbottleProfit;

    if(debug)
    printf("Start %d,End %d,Ans %d\n",start,end,ans);
    
    return ans;
}

int noofInvocationTopDown=0;
// top Down 
// whenever we get the result we will store 
// refer notes for more deeper explanation 
int statedatadp[1000][1000];
int getMaxProfitTopDown(int bottle_weight[],int year,int start,int end)
{
    ++noofInvocationTopDown;
    
    if(start>end) return 0; // all bottle are consumed 
    
    if(statedatadp[start][end]!=-1) 
        return statedatadp[start][end];
    
    int pickfromleft = bottle_weight[start]*year + 
    getMaxProfitTopDown(bottle_weight,year+1,start+1,end);
    
    int pickfromright = bottle_weight[end]*year +  
    getMaxProfitTopDown(bottle_weight,year+1,start,end-1);
    
    int ans;
    
    if(pickfromright>=pickfromleft)
        ans = pickfromright;
    else
        ans = pickfromleft;
    
    // Recusrion Call boils down to 
    // base recusrive calls 
    statedatadp[start][end] = ans;
    
    return ans;
}

int noofInvocationBottomUp=0;
// top Down 
// whenever we get the result we will store 
// refer notes for more deeper explanation 
int statedatadpBottomUp[1000][1000];
int getMaxProfitBottomUp(int bottle_weight[],int noofbottles)
{
    ++noofInvocationBottomUp;
    
    // no recursion call will be involved 
    // start from filling dp table 
    // start from diagonal which is base case 
    // and reaches to bigger subproblems 
    
    // here year is decreamanted from 
    // 5 -> 4 -> 3 -> 2 -> 1 
    // because of bottm up nature 
    // 5 year denotes single bottle 
    // 4 year denotes two consecutive bottle 
    
    int year = noofbottles;
    
    // getting max profit for 
    // single bottles ( length =1 )
    // filling up the diagonal element 
    for(int i=0;i<noofbottles;i++)
        statedatadpBottomUp[i][i] = year * bottle_weight[i];

    // decreamting the 
    // price based on time 
    --year;    

    // growing up the sales 
    // while traversing from length 2 to n 
    // i.e. consuming length 2 bottle to n length ( all bottle ) 
    
    for(int len = 2;len <= noofbottles ; len++)
    {
        int startPoint = 0;
        int endPointinMatrix = noofbottles - len;
        
        for(int k=startPoint;k<=endPointinMatrix;k++)
        {
            int xStartPoint = k;
            int yEndPoint = k + len -1;
            
            int pickfromleftSide = bottle_weight[xStartPoint] * year
            + statedatadpBottomUp[xStartPoint+1][yEndPoint];
            
            int pickfromRightSide = bottle_weight[yEndPoint] * year
            + statedatadpBottomUp[xStartPoint][yEndPoint-1];
            
            int ans;
            
            if(pickfromleftSide>=pickfromRightSide)
                ans = pickfromleftSide;
            else 
                ans = pickfromRightSide;
            
            statedatadpBottomUp[xStartPoint][yEndPoint]  = ans;
            
        }
        
        --year;
    }
    
    if(debug)
    {
        for(int k=0;k<noofbottles;k++)
        {
            for(int p=0;p<noofbottles;p++)
            {
                printf("%d ",statedatadpBottomUp[k][p]);
            }
            printf("\n");
        }
    }
    
    return statedatadpBottomUp[0][noofbottles-1];
}


int bottle_weight[1000];

int main()
{
    int noofBottle,ProfitByEachBottle;
    scanf("%d",&noofBottle);
    
    for(int i=0;i<noofBottle;i++)
    {
        scanf("%d",&ProfitByEachBottle);
        bottle_weight[i] = ProfitByEachBottle;
    }
    
    // memset(statedatadp,-1,sizeof(statedatadp));
    
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            statedatadp[i][j] = -1;
            

    
    // because every year one bottle needs to be sold 
    int maxYear = 1;
    
    printf("Maximum Profit ( Recursion ) is : %d\n",getMaxProfit(bottle_weight,maxYear,0,noofBottle-1));
    printf(" No of Invocations Recursion %d\n",noofInvocationRecursion);
    
    printf("Maximum Profit ( Top Down ) is : %d\n",getMaxProfitTopDown(bottle_weight,maxYear,0,noofBottle-1));
    printf(" No of Invocations Top Down  %d\n",noofInvocationTopDown);



    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            statedatadpBottomUp[i][j] = -1;
    
    printf("Maximum Profit ( Bottom Up ) is : %d\n",getMaxProfitBottomUp(bottle_weight,noofBottle));
    printf(" No of Invocations Bottom Up  %d\n",noofInvocationBottomUp);
    
        
    
    return 0;
}

