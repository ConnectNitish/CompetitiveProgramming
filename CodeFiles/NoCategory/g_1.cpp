#include <bits/stdc++.h> 
using namespace std; 
int tornPages[100010];
int totalTornPages[100010];
#define int long long
int debug=0;
vector<int> n_torn;

void SieveOfEratosthenes(int n) 
{ 
    int count=0;
    for (int p=1; p<=n; p++) 
    {
        // if(tornPages[p]==1)
        //     count++;

        for (int i=p; i<=n; i += p) 
            if(tornPages[i]==1)
                count++;
        
        totalTornPages[p] = count;
        
        count=0; 
    } 

    if(debug)
    {
        for(auto a:n_torn)
        {
            cout << " Page No : " << a << " : " << totalTornPages[a] << endl;
            cout << " Page No : " << a << " : " << tornPages[a] << endl;
        }
    } 
} 

int32_t main()
{
    int t,n,m,q;
    cin >> t;
    int max_pages = INT_MIN;
    vector<vector<int>> v_torn_pages;
    vector<vector<int>> v_queries_pages;    
    int tt=0;

    while(t--)
    {
        tt++;

        cin >> n;
        cin >> m;
        cin >> q;

        memset(tornPages,0,sizeof tornPages);

        max_pages = max(max_pages,n);

        n_torn.clear();
        n_torn.resize(m,0);
        
        for(int i=0;i<m;i++)
        {
            cin >> n_torn[i];
            if(debug)
                cout << " Torn Page NO " << n_torn[i] << endl;
            tornPages[n_torn[i]]=1;
        }

        vector<int> n_queries(q,0);
        
        for(int i=0;i<q;i++)
            cin >> n_queries[i];

        // if(n==m)
        // {
        //     cout << "Case #" << tt << ": 0" << endl;
        //     continue;
        // }

        memset(totalTornPages,0,sizeof totalTornPages);
        SieveOfEratosthenes(n);

        // v_torn_pages.push_back(n_torn);



        int total_value = 0;

        for(int i=0;i<q;i++)
        {
            int n_value = n_queries[i];

            int multiple = n / n_value;

            int torn_pages =  totalTornPages[n_value];

            if(n_value==1)
                torn_pages = m;

            total_value += (multiple - torn_pages);
        }

        cout << "Case #" << tt << ": " << total_value << endl;

    }




}