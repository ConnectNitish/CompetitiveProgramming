#include<bits/stdc++.h>
using namespace std;
#define int long long 

int test;
int N;

int arr[10];

int32_t main()
{
    cin>>test;
    while(test--)
    {
        cin>>N;
        
        memset(arr,0,sizeof(arr));

        string data;
        for(int i=0;i<N;i++)
        {
            cin>>data;
            for(int j=0;j<=9;j++)
            {
                if(data[j]=='1') 
                    arr[j] = (arr[j] ^ 1);
            }
        }
        int ans = 0;
        for(int i=0;i<=9;i++)
        {
            if(arr[i]==1)
                ans++;
        }
        cout<<ans<<endl;
    }
}