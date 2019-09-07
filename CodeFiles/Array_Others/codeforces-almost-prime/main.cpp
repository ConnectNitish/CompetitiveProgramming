/******************************************************************************


http://codeforces.com/problemset/problem/26/A#

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int Pr[100001];
int debug = 0;
void performSieve()
{
    memset(Pr,1,sizeof(Pr));
    
    Pr[0]=0;
    Pr[1]=1;
    Pr[2]=1;
    
    for(int i=2;i*i<=100000;i++)
    {
        if(Pr[i]==0)
            continue;
            
        for(int j=i*i;j<=100000;j+=i)
        {
            Pr[j]=0;
        }
    }
    
    if(debug)
    {
        for(int i=1;i<=1000;i++)
        {
            if(Pr[i])
                cout << i <<  " ";
        }
        cout << endl;
    }
        
}

int main()
{
    debug = 0;
    
    int N;
    // cin >> N;
    scanf("%d",&N);
    // cout << N << endl;
    
    performSieve();
    
    int countall=0;
    for(int k=1;k<=N;k++)
    {
        // cout << k << " &&&: ";
        int count=0;
        for(int i=2;i<=(k);i++)
        {
            // cout << k << " " << i << " : ";
            if(Pr[i] && (k % i)==0)
            {
                // cout << i << " AAAA " << endl;
                count++;
            }
            if(count>2)
                break;
        }
        if(count==2)
            countall++;
    }
    printf("%d",countall);
    return 0;
}


