/******************************************************************************
https://www.spoj.com/problems/MIXTURES/

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#define ll long long 
using namespace std;

int debug=0;

ll colors[10000];
ll prefixSumcolors[10000];

ll noofRecusriveCalls=0;
int calculateminSmogRecursion(int start,int end)
{
    ++noofRecusriveCalls;
    if(start>end) return 0;
    if(start==end) return 0;
    
    ll minCost = LONG_MAX;
    
    for(ll i=start;i<end;i++)
    {
        ll currentcost=0;
        
        if(debug)
        cout << " Indexes i -" << i << " - start - " << start << " end " << end << endl;
        
        ll leftCol = calculateminSmogRecursion(start,i);
        ll rightCol = calculateminSmogRecursion(i+1,end);
        ll colorofLeftSmog;
        if(i>0)
            colorofLeftSmog = (prefixSumcolors[i+1] - prefixSumcolors[start]+100)%100;
        else
            colorofLeftSmog = prefixSumcolors[i+1];
        
        ll colorofRightSmog;
        colorofRightSmog = (prefixSumcolors[end+1] - prefixSumcolors[i+1]+100)%100;
        
        currentcost = leftCol + rightCol + colorofLeftSmog * colorofRightSmog;
        
        if(minCost>currentcost)
            minCost = currentcost;
    }
    
    return minCost;
}

ll noofRecusriveCallsTopDown=0;
ll colorMixture[110][110];

int calculateminSmogRecursionTopDown(int start,int end)
{
    ++noofRecusriveCallsTopDown;
    if(start>end) return 0;
    if(start==end) return (colorMixture[start][end]=0);
    
    if(colorMixture[start][end]!=-1) return colorMixture[start][end];
    
    ll minCost = LONG_MAX;
    
    for(ll i=start;i<end;i++)
    {
        ll currentcost=0;
        
        if(debug)
        cout << " Indexes i -" << i << " - start - " << start << " end " << end << endl;
        
        ll leftCol = calculateminSmogRecursionTopDown(start,i);
        ll rightCol = calculateminSmogRecursionTopDown(i+1,end);
        ll colorofLeftSmog;
        if(i>0)
            colorofLeftSmog = (prefixSumcolors[i+1] - prefixSumcolors[start]+100)%100;
        else
            colorofLeftSmog = prefixSumcolors[i+1];
        
        ll colorofRightSmog;
        colorofRightSmog = (prefixSumcolors[end+1] - prefixSumcolors[i+1]+100)%100;
        
        currentcost = leftCol + rightCol + colorofLeftSmog * colorofRightSmog;
        
        if(minCost>currentcost)
            minCost = currentcost;
    }
    
    if(minCost==INT_MAX)
        return (colorMixture[start][end]=0);
    
    return (colorMixture[start][end]=minCost);
}

// accepted in SPOj 
ll noofRecusriveCallsBottomUp=0;
int calculateminSmogRecursionBottomUp(int size)
{
    ++noofRecusriveCallsBottomUp;
    ll colorMixtureBottomUp[110][110];
    ll minSmogProduced[110][110];
    
    memset(colorMixtureBottomUp,0,sizeof(colorMixtureBottomUp));
    memset(minSmogProduced,0,sizeof(minSmogProduced));
    
    /*
    for(ll j=0;j<=size-1;j++)
    {
        for(ll k=0;k<size-j;k++)
        {
            ll xCoordinate = k;
            ll yCorodinate = k+j;
            
            if(xCoordinate==yCorodinate)
            {
                minSmogProduced[xCoordinate][yCorodinate]=0;
                colorMixtureBottomUp[xCoordinate][yCorodinate] = colorMixture[xCoordinate];
            }
            else
            {
                ll colorfromLeft = colorMixtureBottomUp[xCoordinate][yCorodinate-1];
                ll colorfromDown = colorMixtureBottomUp[xCoordinate+1][yCorodinate];
                
                ll minSmogFromLeft = minSmogProduced[xCoordinate][yCorodinate-1];
                ll minSmogFromDown = minSmogProduced[xCoordinate+1][yCorodinate];
                
                ll currentColor = colorMixture[yCoordinate];
                
                ll finalSmogFromleft = minSmogFromLeft + (colorfromLeft * colorfromDown);
                ll finalSmogFromDown = minSmogFromDown + (colorfromLeft * colorfromDown);
                
                ll newColor;
                // Calculate minSmogProduced
                // down is minimum 
                if(finalSmogFromleft>finalSmogFromDown)
                {
                    newColor = (currentColor + colorfromDown)%100;
                    minSmogProduced[xCoordinate][yCorodinate]=finalSmogFromDown;
                }
                else if(finalSmogFromleft==finalSmogFromDown)
                {
                    if(minSmogFromLeft<=minSmogFromDown)
                    {
                        newColor = (currentColor + colorfromLeft)%100;
                        minSmogProduced[xCoordinate][yCorodinate]=finalSmogFromleft;
                    }
                    else
                    {
                        newColor = (currentColor + colorfromDown)%100;
                        minSmogProduced[xCoordinate][yCorodinate]=finalSmogFromDown;
                    }
                }
                // left is minimum 
                else
                {
                    newColor = (currentColor + colorfromLeft)%100;
                    minSmogProduced[xCoordinate][yCorodinate]=finalSmogFromleft;
                }
                
                // Set New Color 
                colorMixtureBottomUp[xCoordinate][yCorodinate] = newColor;
            }
        }
    }
    */
    
    for(ll j=0;j<=size-1;j++)
    {
        for(ll k=0;k<size-j;k++)
        {
            ll xCoordinate = k;
            ll yCorodinate = k+j;
            
            if(debug)
            cout << " xCoordinate " << xCoordinate << " yCorodinate " << yCorodinate << endl;
            
            if(xCoordinate == yCorodinate)
            {
                colorMixtureBottomUp[xCoordinate][yCorodinate]=colors[xCoordinate];
                minSmogProduced[xCoordinate][yCorodinate]=0;
            }
            else
            {
                ll minsmogCost = LONG_MAX;
                ll smogCost=0;
                ll colorgivingminCost=0;
                
                for(ll k1=xCoordinate;k1<yCorodinate;k1++)
                {
                    if(debug)
                    {
                        cout << " k1 " << k1 << endl;
                        
                        cout << " (prefixSumcolors[k1+1]-prefixSumcolors[xCoordinate]+100)%100 " 
                        << (prefixSumcolors[k1+1]-prefixSumcolors[xCoordinate]+100)%100 << endl;
                        
                        cout << " (prefixSumcolors[yCorodinate+1] - prefixSumcolors[k1+1]+100)%100 "
                        << (prefixSumcolors[yCorodinate+1] - prefixSumcolors[k1+1]+100)%100 << endl;
                        
                        cout << " minSmogProduced[xCoordinate][k1] "
                        << minSmogProduced[xCoordinate][k1] << endl;
                        
                        cout << " minSmogProduced[k1+1][yCorodinate] "
                        << minSmogProduced[k1+1][yCorodinate] << endl;
                    }
                    
                    ll testleft = (prefixSumcolors[k1+1]-prefixSumcolors[xCoordinate]+100)%100;
                    ll testright = (prefixSumcolors[yCorodinate+1] - prefixSumcolors[k1+1]+100)%100;
                    
                    smogCost = 
                    minSmogProduced[xCoordinate][k1] + minSmogProduced[k1+1][yCorodinate] + (testleft * testright);
                    
                    if(debug)
                    cout << " Prev smogCost " << smogCost << endl;
                    
                    if(minsmogCost>smogCost)
                    {
                        minsmogCost = smogCost;
                        colorgivingminCost = k1;
                    }
                    
                    if(debug)
                    cout << " minsmogCost " << minsmogCost << endl;
                }
                
                if(minsmogCost==LONG_MAX)
                    minsmogCost = 0;
                    
                minSmogProduced[xCoordinate][yCorodinate] = minsmogCost;
            }
        }
    }
    
    if(debug)
    {
        cout << endl;
        
        for(ll i=0;i<=size-1;i++)
        {
            for(ll k=0;k<size;k++)
            {
                cout << minSmogProduced[i][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return (minSmogProduced[0][size-1]);
}


// SPOJ SOlution


ll dpSPOJ[1000][1000];

ll sum(int s,int e)
{
    ll sumValue=0;
    for(int i=s;i<=e;i++)
        sumValue = (sumValue + colors[i])%100;
    return sumValue;
}

int calculteMinSPOJ(int start,int end)
{
    if(start>=end) return 0;
    if(dpSPOJ[start][end]!=-1) return dpSPOJ[start][end];
    dpSPOJ[start][end]=LONG_MAX;
    for(int k=start;k<=end;k++)
    {
        dpSPOJ[start][end] = 
        min(dpSPOJ[start][end],
        calculteMinSPOJ(start,k)+calculteMinSPOJ(k+1,end)+(sum(start,k)*sum(k+1,end)));
    }
    return dpSPOJ[start][end];
}

int main()
{
    ll n;
    ll first=0;
    while(scanf("%lld",&n)!=EOF)
    {
    
    // if(first>0)
    //     printf("\n");
    
    memset(colors,-1,sizeof(colors));
    memset(prefixSumcolors,0,sizeof(prefixSumcolors));
    memset(dpSPOJ,-1,sizeof(dpSPOJ));
    
     if(debug)
        cout << " execution " << endl;
        
    
    ll i=0;
    for(;i<n;i++)
    {
        scanf("%lld",&colors[i]);
        prefixSumcolors[i+1] = (colors[i] + prefixSumcolors[i]);
    }

    // for(int kk=0;kk<n;kk++)
    //     cout << colors[kk] << " ";
    // cout << endl;

        
    if(debug)
    {
        cout << " execution " << endl;
    
        cout << " Prefix Array " << endl;    
        for(int kk=0;kk<=n;kk++)
            cout << prefixSumcolors[kk] << " ";
        cout << endl;
    }
        
    // printf(" Minimum Smoke %lld \n",calculateminSmogRecursion(0,n-1));
    // printf(" No of Recusrive Calls %lld \n",noofRecusriveCalls);
    
    memset(colorMixture,-1,sizeof(colorMixture));
    
    // printf("%lld\n",calculateminSmogRecursionTopDown(0,n-1));
    printf("%lld\n",calculateminSmogRecursionBottomUp(n));
    
    // printf("%lld\n",calculteMinSPOJ(0,n-1));
    
    // printf("TD %lld\n",calculateminSmogRecursionTopDown(0,n-1));
    // printf("BU %lld\n",calculateminSmogRecursionBottomUp(n));
    
    
    
    // printf(" Minimum Smoke Top Down : %lld \n",calculateminSmogRecursionTopDown(0,n-1));
    // printf(" No of Recusrive Calls Top Down : %lld \n",noofRecusriveCallsTopDown);
    
    // return 0;
    
    ++first;
    
    }
    // printf("\n");
    
}

