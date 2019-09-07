/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int debug=0;

// computing via 2D matrix as per input given 
int getMinPathDistance(int data[][1000],int gridPathValue[][1000],int r,int c)
{
    int minDistance=0;
    
    for(int i=0;i<r;i++)
    {
        for(int k=0;k<c;k++)
        {
            if(i==0 && k==0)
            {
                gridPathValue[i][k] = data[i][k];
            }
            else if(i==0 && k>0)
            {
                gridPathValue[i][k] = 
                data[i][k] + gridPathValue[i][k-1];
            }
            else if(i>0 && k==0)
            {
                gridPathValue[i][k] = 
                gridPathValue[i-1][k] + data[i][k];
            }
            else if(i>0 && k>0)
            {
                gridPathValue[i][k] = 
                //min(up,left)
                (gridPathValue[i][k-1] <= gridPathValue[i-1][k] ? 
                gridPathValue[i][k-1] : gridPathValue[i-1][k]) + data[i][k];
            }
        }
    }
    
    return gridPathValue[r-1][c-1];
}

// an optimization over space 
// if observed only at a time 
// for a particular row 
// above row is only used 
int getMinPathDistancewith1DDP(int data[][1000],int gridPathValue[2][1000],int r,int c)
{
    // table has two rows top and bottom 
    // filling top row 
    for(int i=0;i<r;i++)
    {
        if(i==0)
            gridPathValue[0][i] = data[0][i];
        else
            gridPathValue[0][i] = data[0][i] + gridPathValue[0][i-1];
    }

    // iterating from second row   
    for(int i=1;i<r;i++)
    {
        // iterating for filling bottom row 
        for(int j=0;j<c;j++)
        {
            if(j==0)
                gridPathValue[1][j] = gridPathValue[0][j] + data[i][j];
            else
                gridPathValue[1][j] = data[i][j] + 
                (gridPathValue[0][j]<=gridPathValue[1][j-1] ? gridPathValue[0][j] : gridPathValue[1][j-1]);
        }
        
        // copying bottom row to top row 
        for(int j=0;j<c;j++)
        {
            gridPathValue[0][j] = gridPathValue[1][j];
        }
    }
     
    if(debug)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%d ",gridPathValue[i][j]);
            }
            printf("\n");
        }
    }
    
    return gridPathValue[1][c-1];
}

int main()
{
    int r;
    int c;
    scanf("%d",&r);
    scanf("%d",&c);

    int OptimalgridPathValue[r][1000];
    int data[r][1000];

    for(int i=0;i<r;i++)
    {
        for(int k=0;k<c;k++)
        {
            int V;
            scanf("%d",&V);
            data[i][k]=V;
        }
    }
    
    printf("Min Path Distance : %d\n",getMinPathDistance(data,OptimalgridPathValue,r,c));

    int OptimalgridPathValueLessSpace[2][1000];

    printf("Min Path Distance ( Less Space ) : %d\n",
    getMinPathDistancewith1DDP(data,OptimalgridPathValueLessSpace,r,c));

    return 0;
}

