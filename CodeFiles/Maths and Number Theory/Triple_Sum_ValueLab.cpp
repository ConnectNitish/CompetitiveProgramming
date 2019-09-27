#include<bits/stdc++.h>
using namespace std;
#define ll long long

// https://stackoverflow.com/questions/58074259/good-triplets-sum-and-divisor

long long good_triplets(vector<int> arr, int n) {
    
    unordered_map<ll,ll> freq;
    set<ll> values;

   for(auto a:arr)
   {
        freq[a]++;
        values.insert(a);
   }
   
    vector<ll> dis;
    
    for(auto a:values)
    {
        dis.push_back(a);    
    }
    
    ll net_count=0;
    
    n = dis.size();
    
    if(n<=2)
    {
       for(int i=0;i<n;i++)
        {
            if(freq[dis[i]]<2)
                continue;
                
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                ll sum = (dis[i] << 1) + dis[j];
                if(sum % dis[i]!=0 && sum % dis[j]==0)
                {
                    net_count += (((freq[dis[i]] * (freq[dis[i]]-1)) >> 1)
                                * freq[dis[j]]);
                }
            }
        }
        return net_count*6;
    }
    
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                ll sum = dis[i] + dis[j] + dis[k];
                  
                int count=0;
                
                if(sum % dis[i]==0) count++;
                if(sum % dis[j]==0) count++;
                if(sum % dis[k]==0) count++;
                
                if(count==1)
                    net_count += (freq[dis[i]] * freq[dis[j]] * freq[dis[k]]);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(freq[dis[i]]<2)
            continue;
            
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            ll sum = (dis[i] << 1) + dis[j];
            if(sum % dis[i]!=0 && sum % dis[j]==0)
            {
                net_count += (((freq[dis[i]] * (freq[dis[i]]-1)) >> 1)
                            * freq[dis[j]]);
            }
        }
    }
    
    return (net_count*6);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }
    long long out_;
    out_ = good_triplets(arr, n);
    cout << out_;
}
