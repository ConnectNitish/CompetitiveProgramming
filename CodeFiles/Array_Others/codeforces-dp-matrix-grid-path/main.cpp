/******************************************************************************

http://codeforces.com/contest/429/problem/B

*******************************************************************************/
#include <iostream>
using namespace std; 

int toplefttobottomright[1001][1001];
int bottomlefttotopright[1001][1001];
int bottomrighttotopleft[1001][1001];
int toprighttobottomleft[1001][1001];
int data[1001][1001];

int main()
{
    int r;int c;
    scanf("%d",&r);
    scanf("%d",&c);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
            scanf("%d",&data[i][j]);
    }
    
    for(int i=0;i<=r;i++)
    {
        for(int j=0;j<=c;j++)
        {
            toplefttobottomright[i][j]=0;
            bottomlefttotopright[i][j]=0;
            bottomrighttotopleft[i][j]=0;
            toprighttobottomleft[i][j]=0;
        }
    }
    
    // Boy 1
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            // if(i==0 && j==0)
            //     toplefttobottomright[i][j]=data[i][j];
            // else if(i==0 && j>0)
            //     toplefttobottomright[i][j]=data[i][j]+toplefttobottomright[i][j-1];
            // else if(i>0 && j==0)
            //     toplefttobottomright[i][j]=data[i][j]+toplefttobottomright[i-1][j];
            // else
                toplefttobottomright[i][j]=data[i][j]+
                max(toplefttobottomright[i-1][j],toplefttobottomright[i][j-1]);
        }
    }

    // Boy 2
    for(int i=r;i>0;i--)
    {
        for(int j=c;j>0;j--)
        {
            // if(i==r-1 && j==c-1)
            //     bottomrighttotopleft[i][j]=data[i][j];
            // else if(i==r-1 && j<c-1)
            //     bottomrighttotopleft[i][j]=data[i][j]+bottomrighttotopleft[i][j+1];
            // else if(i<r-1 && j==c-1)
            //     bottomrighttotopleft[i][j]=data[i][j]+bottomrighttotopleft[i+1][j];
            // else
                bottomrighttotopleft[i][j]=data[i][j]+
                max(bottomrighttotopleft[i+1][j],bottomrighttotopleft[i][j+1]);
        }
    }

    // Girl 2
    for(int i=1;i<=r;i++)
    {
        for(int j=c;j>0;j--)
        {
            // if(i==0 && j==c-1)
            //     toprighttobottomleft[i][j]=data[i][j];
            // else if(i==0 && j<c-1)
            //     toprighttobottomleft[i][j]=data[i][j]+toprighttobottomleft[i][j+1];
            // else if(i>0 && j==c-1)
            //     toprighttobottomleft[i][j]=data[i][j]+toprighttobottomleft[i-1][j];
            // else
                toprighttobottomleft[i][j]=data[i][j]+
                max(toprighttobottomleft[i-1][j],toprighttobottomleft[i][j+1]);
        }
    }

    // Girl 1
    for(int i=r;i>0;i--)
    {
        for(int j=1;j<=c;j++)
        {
            // if(i==r-1 && j==0)
            //     bottomlefttotopright[i][j]=data[i][j];
            // else if(i==r-1 && j>0)
            //     bottomlefttotopright[i][j]=data[i][j]+bottomlefttotopright[i][j-1];
            // else if(i<r-1 && j==0)
            //     bottomlefttotopright[i][j]=data[i][j]+bottomlefttotopright[i+1][j];
            // else
                bottomlefttotopright[i][j]=data[i][j]+
                max(bottomlefttotopright[i][j-1],bottomlefttotopright[i+1][j]);
        }
    }

    int maxCal = 0;
    
    for(int i=2;i<r;i++)
    {
        for(int j=2;j<c;j++)
        {
            // maxCal = max(maxCal,
            //     max(toplefttobottomright[i][j],
            //     max(toprighttobottomleft[i][j],
            //     max(bottomlefttotopright[i][j],bottomrighttotopleft[i][j])
            //     )));
                
            // considering all the paths 
            // having simultaneous directions 
            // maxCal = max(maxCal,
            // (toplefttobottomright[i][j] + bottomrighttotopleft[i][j]-2*data[i][j] + 
            //     bottomrighttotopleft[i][j] + toprighttobottomleft[i][j]-2*data[i][j]));
                
            //case 1 
            // boy i,j-1 to i,j+1
            // girl i+1,j to i-1,j
            int maxCal1 = toplefttobottomright[i][j-1]
            + bottomrighttotopleft[i][j+1] + 
            + toprighttobottomleft[i-1][j] +
            bottomlefttotopright[i+1][j];
            
            //case 2 
            // boy i-1,j to i+1,j
            // girl i,j-1 to i,j+1 
            int maxCal2 = toplefttobottomright[i-1][j]
            + bottomrighttotopleft[i+1][j] + 
            + toprighttobottomleft[i][j+1] +
            bottomlefttotopright[i][j-1];
            
            // if(maxCal>0)
            // maxCal -= data[i][j]; 
            
            maxCal = max(maxCal,max(maxCal1,maxCal2));
        }
    }
    
    printf("%d",maxCal);

    return 0;
}

/*
Input 2:
3 3
3 1 2
3 2 0
2 3 2
Output 2:
16
Input 1:
3 3 
100 100 100 
100 1 100 
100 100 100
Output 1:
800
*/
