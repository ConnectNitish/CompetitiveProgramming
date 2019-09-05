#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000000ll 
using namespace std;

long double _dis(pair<int,int> p1,pair<int,int> p2)
{
    int x = abs(p1.first - p2.first);
    int y = abs(p1.second - p2.second);
    return sqrt(x*x + y*y);
}

long double dp[1<<13][40];
long double distance1[40][40]={0};

int debug=0;
int n,m;
vector<pair<int,int>> coordinates;
vector<int> ingredients;

long double tsp(int mask,int shop)
{
    if((mask == (1<<m)-1) && shop==0)
    {
        return 0;
    }

    if(dp[mask][shop]!=-1) return dp[mask][shop];

    dp[mask][shop] = MAX;

    for(int i=0;i<=n;i++)
    {
        // get the ith shop ingredients 
        int ingre = ingredients[i];
        if((mask!=(mask|ingre)) || (i==0))
        {
            dp[mask][shop] = min (dp[mask][shop],
            distance1[shop][i] + tsp(mask|ingre,i)
            );     
        }
    }

    return dp[mask][shop];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        coordinates.clear();
        ingredients.clear();

        cin >> n >> m;
        coordinates.push_back(make_pair(0,0));
        ingredients.push_back(0);

        

        for(int i=0;i<n;i++)
        {   
            int a,b;
            cin >> a >> b;
            coordinates.push_back(make_pair(a,b));
        }

        int allreciepies  = 0;

        for(int i=0;i<n;i++)
        {
            int maskedINput=0;
            string sItem_from_Shop = "";
            cin >> sItem_from_Shop;

            if(debug)
            {
                cout << " INput String " << endl;
                cout << sItem_from_Shop << endl;
            }

            reverse(sItem_from_Shop.begin(),sItem_from_Shop.end()); 

            for(int k=0;k<sItem_from_Shop.length();k++)
            {
                maskedINput = maskedINput | ((1<<k)*(sItem_from_Shop[k]-'0'));
            }

            if(debug)
            {
                cout << " R INput String " << endl;
                cout << sItem_from_Shop << endl;
                cout << maskedINput << endl;
            }

            // get all details of the product 
            allreciepies = allreciepies | maskedINput;

            ingredients.push_back(maskedINput);
        }

        if(allreciepies!=((1<<m)-1))
        {
            cout << -1 << endl;
            continue;
        }

        if(debug)
        {
            cout << " Ingredient Size  " << ingredients.size() << endl;
            for(int i=0;i<=n;i++)
            {
                cout << " Ingre " << ingredients[i] << endl;
                pair<int,int> pr = coordinates[i];
                cout << pr.first << " " << pr.second << endl;
            }
            cout << " Pair " << endl;
        }

        memset(distance1,0,sizeof(distance1));
        // set the Distance  
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                distance1[i][j] = _dis(coordinates[i],coordinates[j]);
                if(debug)
                {
                    cout << distance1[i][j] << " ";
                }
            }
            if(debug)
            cout << endl;
        }


        // memset(dp,-1,sizeof(dp));

        for(int i=0;i<(1<<13);i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }

        long double value = tsp(0,0) ;

        cout << fixed << setprecision(9) << value << endl;

    }

    return 0;
}