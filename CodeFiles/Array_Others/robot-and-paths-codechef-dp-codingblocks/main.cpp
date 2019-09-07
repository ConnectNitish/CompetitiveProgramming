/******************************************************************************
https://www.codechef.com/problems/CD1IT4
*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
#define ll long long

ll r;
ll c;
ll o;

int mod = 1000000007;

// vector<vector<ll>> data(1010,vector<ll>(1010,0));
// vector<vector<ll>> paths(1010,vector<ll>(1010,0));

int data[1010][1010]={0};
int paths[1010][1010]={0};

int main()
{
    scanf("%lld",&r);
    scanf("%lld",&c);
    scanf("%lld",&o);
    
    memset(data,0,sizeof(data));
    memset(paths,0,sizeof(paths));
    
    for(int i=0;i<o;i++)
    {
        ll x;ll y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        data[x-1][y-1] = 2;
    }
    
    // vector<vector<ll>> paths(r,vector<ll>(c,0));
    
    bool unreachable = false;
    for(int i=0;i<c;i++)
    {
        if(unreachable==false && data[0][i]==2)
            unreachable = true;
            
        if(unreachable==true)
        {
            paths[0][i]=0;
            data[0][i]=2;
        }
        else
            paths[0][i]=1;
    }    
    
    unreachable = false;
    for(int i=0;i<r;i++)
    {
        if(unreachable==false && data[i][0]==2)
            unreachable = true;
        if(unreachable==true)
        {
            paths[i][0]=0;
            data[i][0]=2;
        }
        else
            paths[i][0]=1;
    }
    
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(data[i-1][j]==2 && data[i][j-1]==2)
            {
                // setting obstacles for 
                // next corodinates coming 
                data[i][j]=2;
                paths[i][j]=0;
                continue;
            }
            
            if(data[i-1][j]!=2 && data[i][j-1]!=2)
            {
                // summing up the path
                paths[i][j] = (paths[i-1][j] + paths[i][j-1])%mod;
                continue;
            }
            
            if(data[i-1][j]!=2)
                paths[i][j] = (paths[i-1][j])%mod;
            
            if(data[i][j-1]!=2)
                paths[i][j] = (paths[i][j-1])%mod;
            
        }
    }
    
    /*
    
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%lld ",data[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%lld ",paths[i][j]);
        }
        printf("\n");
    }
    
    
    */
    
    // base Case 
    // because may be the scenario that
    // last coridinate is blocked 
    if(data[r-1][c-1]==2)
    {
        printf("0");
        return 0;
    }
    printf("%lld",paths[r-1][c-1]%mod);
}


