//https://www.hackerearth.com/practice/notes/codemonk-dynamic-programming-ii-1/
//https://www.freecodecamp.org/news/unmasking-bitmasked-dynamic-programming-25669312b77b/
//https://discuss.codechef.com/t/dynamic-programming-with-bitmasking/4775/2
//http://codeforces.com/blog/entry/337?mobile=true

//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/micro-and-graphdpbitmask-tutorial/

#include<iostream>
#include<limits.h>
#include<string.h>
#define ll long long
using namespace std;

ll debug=1;

ll data2[25][25];
ll states[100000][25] = {-1};
ll n,m;
// 1 based index of city 
ll tsptopdown(ll mask,ll city)
{
    if(__builtin_popcount(mask) == n)
    {
        return 0;
    }

    if(states[mask][city]!=-1) return states[mask][city];

    ll ans = 1e18;

    for(ll i=1;i<=n;i++)
    {
        if(mask>>i&1)
            continue;
        if(data2[i][city]==0)
            continue;
        ans  = min(ans,data2[i][city]+tsptopdown(mask|(1<<i),i));
    }
    return states[mask][city]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    memset(states,-1,sizeof(states));

    // setting distance as max 
    for(ll i=0;i<25;i++)
    {
        for(ll j=0;j<25;j++)
            data2[i][j] = 1e18;
    }

    // get all the edges
    // 1 based index  
    for(ll i=0;i<m;i++)
    {
        ll src,dest,path;
        cin >> src  >> dest >> path;

        // cout << src << path << dest << endl;

        data2[src][dest] = min(data2[src][dest],path);
        data2[dest][src] = min(data2[src][dest],path);
    }   

    // observing the data debug 
    // for(ll i=1;i<=n;i++)
    // {
    //     for(ll j=1;j<=n;j++)
    //         cout << data2[i][j] << " ";
    //     cout << endl;
    // }


    // In case of Complete Graph you 
    // can Start from any of the vertex 
    

    // In case some nodes are not conected 
    // then you have to explore all the nodes 
    ll ans = 1e18;
    for(ll i=1;i<=n;i++)
    {
        ans = min(tsptopdown(1<<i,i),ans);
    }
    cout << ans << endl;
    return 0;
}