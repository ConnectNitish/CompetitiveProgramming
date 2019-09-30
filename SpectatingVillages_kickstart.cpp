#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    while(t--){
        int v;
        cin>>v;
        int B[v];
        for(int i=0; i<v; i++){
            cin>>B[i];
        }
        vector<vector<int>> g(v);
        int u, v;
        for(int i=1; i<=v-1; i++){
            cin>>u>>v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
    }
    return 0;
}
