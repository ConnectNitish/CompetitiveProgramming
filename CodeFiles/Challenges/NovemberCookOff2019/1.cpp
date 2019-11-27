#include<bits/stdc++.h>
using namespace std;
#define int long long 

int test;
int N,K;

int arr[10];

int32_t main()
{
    cin>>test;
    while(test--)
    {
        cin>>N >> K;
        
        vector<int> data(N,0);
        for(int i=0;i<N;i++)
            cin >> data[i];

        int remaining  = 0 ;
        int day = 0;
        bool flag = false;
        for(auto a:data)
        {
            day++;
            if(a+remaining>=K)
                remaining = (a+remaining-K);
            else
            {
                flag = true;
                break;
            }
        }

        if(flag==false)
            cout << "YES" << endl;
        else 
            cout << "NO " << day << endl; 
    }
}