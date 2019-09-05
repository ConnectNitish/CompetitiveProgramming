// https://www.interviewbit.com/problems/strongly-connected-components/

/*

Implemnted using both method : 

Method 1: Tarjan Implemntation O(V+E)
Method 2: KosaRaju Implemntation  2*O(V+E)

*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#define fr freopen("source.txt","r",stdin),freopen("output.txt","w",stdout)
#define boost ios::sync_with_stdio(false);cin.tie(0)
#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;

map<int,int> parent;
map<int,bool> visited;
map<int,int> low_time;
map<int,int> visited_time;
map<int,int> on_stack;
stack<int> data;
vector<vector<int>> all;
map<int,set<int>> graph;
map<int,set<int>> reverse_graph;

class Solution
{
    public : 
    //int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
    vector<vector<int>> solve(int A, vector<vector<int> > &B); 
};



int debug=0;

int _time = 0;

void dfs(int src)
{
    // bookepping 
    // setting visited and onStack 
    // also adding the current element to Stack 
    // setting low_link_value of the particular source  
    visited[src]=1;
    on_stack[src]=1;
    data.push(src);
    
    low_time[src] = _time;
    visited_time[src] = _time;
    
    _time++;
    
    for(auto ng:graph[src])
    {
        if(visited[ng]==false)
        {
            dfs(ng);
            low_time[src] = min(low_time[ng],low_time[src]);
        }
        // if the neighbour is in the stack 
        // and an SCC is found 
        // check wther the node is in SCC 
        // with the current source trace or not 
        // if its in current source trace 
        // then its onstack will be true
        // and will update the link value of the src 
        // with that of the neighbour   
        else if(on_stack[ng]==true)
        {
            low_time[src] = min(low_time[ng],low_time[src]);
        }
    }

    // All the Nodes are explored 
    // Strongly Conncted component 
    // is completetd till
    // the Link of the element 
    // is equal to Link of Source 
    if(visited_time[src] == low_time[src])
    {
        // storing the element to just print 
        std::vector<int> _v_data;

        // iterating till stack empty
        // and we will iterate till 
        // src node is not achieved  
        // src node is also popped 
        // it is giving SCC found in vector _v_data
        while(data.empty()==false)
        {
            int top_node = data.top();
            on_stack[top_node]=false;
            data.pop();
            _v_data.push_back(top_node);
            if(top_node == src)
                break;
        }

        // storing the result 
        if(_v_data.size()>0)
        {
            sort(_v_data.begin(),_v_data.end());
            all.push_back(_v_data);
        }
    }
}

vector<int> cur_ssc;
void dfs_stack(int src,int type,map<int,set<int>> &_graph)
{
    visited[src]=true;
    if(type==1)
        cur_ssc.push_back(src);
        
    for(auto ng:_graph[src])
    {
        if(visited[ng]==false)
            dfs_stack(ng,type,_graph);
    }
    
    if(type==0)
        data.push(src);
}

vector<vector<int>> Solution::solve(int A, vector<vector<int> > &B) 
{
    all.clear();
    graph.clear();
    low_time.clear();
    visited.clear();
    data = stack<int>();
    on_stack.clear();
    visited_time.clear();
    _time=0;
    
    for(int i=1;i<=A;i++)
    {
        graph[i]={};
        reverse_graph[i]={};
        low_time[i]=INT_MAX;
        visited[i]=false;
        on_stack[i] = 0;
    }   
    for(auto a:B)
    {
        graph[a[0]].insert(a[1]);
        reverse_graph[a[1]].insert(a[0]);
    }
    
    // Method 1: 
    for(auto a:visited)
        if(a.second==false)
            dfs(a.first);
            
    // Method 2:
    
    // for(auto a:visited)
    //     if(a.second==false)
    //         dfs_stack(a.first,0,graph);
    
    // for(int i=1;i<=A;i++)
    //     visited[i]=false;
        
    // while(data.empty()==false)
    // {
    //     int node = data.top();
    //     data.pop();
    //     if(visited[node]==false)
    //     {
    //         cur_ssc.clear();
    //         dfs_stack(node,1,reverse_graph);
    //         if(cur_ssc.size()>0)
    //         {
    //             sort(cur_ssc.begin(),cur_ssc.end());
    //             all.push_back(cur_ssc);
    //         }
    //     }
    // }
    
    return all;
}

int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V;
    cin >> V;
    int R,C; 
    cin >> R >> C;
    vector<vector<int>> __allData;
    for(int i=0;i<R;i++)
    {
        vector<int> dd(2,0);
        int V1;
        for(int k=0;k<C;k++)
        {
            cin >> V1;
            dd[k] = V1;
        }
        __allData.push_back(dd);
    }
    Solution s;
    vector<vector<int>> temp_all = s.solve(V,__allData);
    
    for(auto a:temp_all)
    {
        if(a.size()>0)
            cout << "[";
        for(auto b:a)
        {
            cout << " " << b;
        }
        if(a.size()>0)
            cout << "] ";
    }
    
}









