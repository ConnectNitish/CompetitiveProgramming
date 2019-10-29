// https://www.codechef.com/LTIME77B/problems/BOXGAM97

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t,n,k,p;
    cin>>t;
    while(t--){
        cin>>n>>k>>p;
        vector<long long int> vec(n);
        
        for(int i=0;i<n;i++)
            cin>>vec[i];

        long long int max_elem = *max_element(vec.begin(),vec.end());
        long long int min_elem = *min_element(vec.begin(),vec.end());
        long long int max_ind = distance(vec.begin(),max_element(vec.begin(),vec.end()));
        long long int min_ind = distance(vec.begin(),min_element(vec.begin(),vec.end()));
        vector<long long> dist_arr;
        dist_arr.push_back(vec[1]);
        dist_arr.push_back(vec[n-2]);
        if(n==2){
            if(p==0) cout<<max_elem<<endl;
            else cout<<min_elem<<endl;

        }
        else{
            if(p==0){
                if(k%2==1) cout<<max_elem<<endl;
                else{
                    for(int i=0;i<=n-3;i++)
                        dist_arr.push_back(min(vec[i],vec[i+2])) ;
                    cout<<*max_element(dist_arr.begin(),dist_arr.end())<<endl;
                }
            }
            else{
                if(k%2==1) cout<<min_elem<<endl;
                else{
                    for(int i=0;i<=n-3;i++)
                        dist_arr.push_back(max(vec[i],vec[i+2])) ;
                    cout<<*min_element(dist_arr.begin(),dist_arr.end())<<endl;
                }
            }
        }
        
    }
}