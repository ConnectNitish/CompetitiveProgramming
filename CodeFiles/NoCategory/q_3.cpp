#include <bits/stdc++.h> 
using namespace std; 
int tornPages[100010];
int totalTornPages[100010];
#define int long long
int debug=0;

int m;
int n;

vector<int> input_data;

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;   
    int tt=0;

    while(t--)
    {
        tt++;

        cin >> n;
        cin >> m;

        // memset(tornPages,0,sizeof tornPages);
        input_data.clear();
        input_data.resize(n);
        
        int max_value = 0;

        int a,b,v = m;
        b =0 ;
        a=0;
        while(v)
        {
            if(v&1)
                a = b;
            b++;
            v = v >> 1;
        }
        max_value = max(max_value,a+1);

        for(int i=0;i<n;i++)
        {
            cin >> input_data[i];

            int a,b,v = input_data[i];
            b =0 ;
            a=0;
            while(v)
            {
                if(v&1)
                    a = b;
                b++;
                v = v >> 1;
            }

            max_value = max(max_value,a+1);
        }



        int answer = -1;

        int max_v_2 = 1 << (max_value+1);

        for(int k=max_v_2;k>=0;k--)
        {
            int temp = 0;
            for(int i=0;i<n;i++)
            {
                temp += (input_data[i] ^ k);       
                if(temp >m)
                    break;
            }

            if(temp<=m)
            {
                answer = k;
                break;
            }


        }

        cout << "Case #" << tt << ": " << answer << endl;

    }




}