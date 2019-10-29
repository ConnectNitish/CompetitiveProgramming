// https://www.codechef.com/LTIME77B/problems/INVYCNT

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int tc,n,k;
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        vector<long long int> vec(n);

        map<long long,long long> m;
        for(int i=0;i<n;i++)
           cin>>vec[i];
            
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vec[i]<vec[j])
                    m[vec[i]] += 1;
            }
        }
        long long ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(vec[j]>vec[i]) ans++;
            }
        }
        ans = ans*k;
        long long temp  = (k * (k-1) )/2;
        for(int i=0;i<n;i++){
            ans += m[vec[i]] * temp;
        }
        cout<<ans<<endl;
    }
}