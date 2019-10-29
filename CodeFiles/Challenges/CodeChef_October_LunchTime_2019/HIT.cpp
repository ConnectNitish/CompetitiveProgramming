// https://www.codechef.com/LTIME77B/problems/HIT

#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
int t; 
cin >> t;
while(t--)
{
int n;
cin >> n;
vector<int> d(n,0);
for(int i=0;i<n;i++)
cin >> d[i];

sort(d.begin(),d.end());

int chunk = n / 4; 

int fi  = chunk , si = 2 * chunk , ti = 3*chunk ; 

if( d[fi] == d[fi - 1 ] || d[si] == d[si - 1] || d[ti] == d[ti - 1]) 
{
cout << "-1" << endl;
}
else
{
cout  << d[fi] << " " << d[si] << " " << d[ti] << " " << endl;
}
}
return 0;
}