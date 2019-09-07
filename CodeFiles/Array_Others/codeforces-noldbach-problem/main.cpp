/******************************************************************************

http://codeforces.com/problemset/problem/17/A

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
int Pr[100001];

map<int,int> Preprocess;

void performSeive()
{
    memset(Pr,1,sizeof(Pr));
    
    Pr[0]=0;
    Pr[1]=1;
    Pr[2]=1;
    
    for(int i=2;i*i<100001;i++)
    {
        if(Pr[i]==0)
            continue;
            
        for(int j=i*2;j<100001;j+=i)
        {
            Pr[j]=0;
        }
    }
    
    int previousPrime = -1;
    for(int i=1;i<100001;i++)
    {
        if(Pr[i])
        {
            if(previousPrime==-1)
                Preprocess[i] = i;
            else
                Preprocess[i]=previousPrime;
            previousPrime = i;
        }
    }
}

int main()
{
    int N,K;
    cin >> N >> K;
    Preprocess.clear();
    performSeive();
    int count=0;
    for(int i=2;i<=N;i++)
    {
        if(Pr[i])
        {
            int valueofMap = i;
            do
            {
                int last = Preprocess[valueofMap];
                if(last==1)
                {
                    valueofMap=1;
                    break;
                }
                int secondLast = Preprocess[last];
                if(secondLast==1)
                {
                    valueofMap=1;
                    break;
                }
                if(last+secondLast+1 == i)
                {
                    count++;
                    valueofMap = 1;
                }
                else
                    valueofMap = Preprocess[valueofMap];
            }while(valueofMap!=1);
        }
    }
    
    if(count>=K)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

