/******************************************************************************

https://www.hackerrank.com/challenges/the-quickest-way-up/problem

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int debug=0;

int bfs(int start,map<int,vector<int>> graph)
{
    map<int,bool> visited;
    map<int,int> parent;
    

    for(auto a:graph)
        visited[a.first]=false;

    visited[start]=true;
    
    //parent[start] = start;

    queue<int> bfsqueue;
    bfsqueue.push(start);
    
    // cout << " Start " << start << endl;

    vector<int> order;

    int lastNode = -1;

    while(bfsqueue.empty()==false)
    {
        int topNode = bfsqueue.front();
        bfsqueue.pop();
        order.push_back(topNode);
        
        lastNode = topNode;
        
        // cout << " Mid " << topNode << endl;

        vector<int> neighbours = graph[topNode];
        if(neighbours.size()>0)
        {
            for(auto a:neighbours)
            {
                if(visited[a]==false)
                {
                    parent[a] = topNode;
                    bfsqueue.push(a);
                    visited[a]=true;
                }
            }
        }
    }
    
    if(debug)
    {
        cout << " Parent Map " << endl;
        for(auto a:parent)
        {
            cout << a.first << " " << a.second << endl;
        }
    }

    int lastvisitedNode = 100;
    int count=0; 
    while(lastvisitedNode!=start)
    {
        if(debug)
            cout << " dddd " << lastvisitedNode << endl;
        
        if(visited[lastvisitedNode]==false)
            return -1;

        lastvisitedNode=parent[lastvisitedNode];
        count++;
    }

    if(count==0)
        return -1;

    return count;

}

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) 
{

    map<int,vector<int>> graph;

    for(int i=0;i<=100;i++)
    {
        vector<int> B;
        graph[i] = B;
    }

    vector<int> jumps(101,0);

    for(auto a:ladders)
    {
        vector<int> b = a;
        int start = b[0];
        int end = b[1];
        jumps[start] = (end-start);
    }

    for(auto a:snakes)
    {
        vector<int> b = a;
        int start = b[0];
        int end = b[1];
        jumps[start] = (end-start);
    }

    for(int i=0;i<=100;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int dest = i+dice+jumps[i+dice];
            int source = i;
            graph[source].push_back(dest);
        }
    }

    return bfs(1,graph);

}

int main()
{
    
    // ofstream fout(getenv("OUTPUT_PATH"));
    debug = 1;
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        cout << result << "\n";
    }

    // fout.close();

    return 0;
}


