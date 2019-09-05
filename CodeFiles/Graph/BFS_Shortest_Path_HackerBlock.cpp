#include<iostream>
#define forin(i,s,e) for(int i=s;i<=e;i++) 
#include<vector>
#include<queue>
#include<map>
using namespace std;

/*

https://online.codingblocks.com/player/33819/content/13653/5090

BFS - SHORTEST PATH
Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 . We define node 's' to be the starting position for a BFS.

Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by calculating the shortest distance from starting node 's' to all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if 's' is disconnected from a node, print -1 as the distance to that node.

Input Format:
The first line contains an integer,q , denoting the number of queries. The subsequent lines describe each query in the following format:

Each line contains N and M, the number of nodes and edges respectively.

The next m lines contains u and v means that there is edge between u and v .

The last line contains 's', the starting node.

Constraints:
1 <= q <= 10 2 <= n <= 1000 1 <= m <= (n*(n-1))/2 1 <= u,s,v <= n

Output Format
You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s itself.

Sample Input
2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output
6 6 -1
-1 6


*/



int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {

        map<int,int> distance;
        map<int,vector<int>> edges;
        map<int,bool> visited;

        // edges.clear();
        // distance.clear();
        // visited.clear();

        int _nodes;
        int _edges;
        scanf("%d",&_nodes);

        forin(i,1,_nodes)
        {
            vector<int> empty;
            edges[i] = empty;
            distance[i] = -1;
        }


        scanf("%d",&_edges);
        forin(i,0,_edges-1)
        {
            int u,v;
            scanf("%d",&u);
            scanf("%d",&v);
            edges[u].push_back(v);
            edges[v].push_back(u);

            visited[u]=false;
            visited[v]=false;   
        }

        int startingnode;
        scanf("%d",&startingnode);

        queue<int> _q;
        _q.push(startingnode);
        visited[startingnode]=true;
        distance[startingnode] = 0;

        while(_q.empty()==false)
        {
            int cur_node = _q.front();
            _q.pop();
            for(int neighbour:edges[cur_node])
            {
                if(visited[neighbour]==false)
                {
                    _q.push(neighbour);
                    visited[neighbour]=true;
                    distance[neighbour] = distance[cur_node] + 6;
                }
            }
        }

        for(auto nodes:distance)
            if(nodes.first!=startingnode)
                printf("%d ",nodes.second);

            printf("\n");

        }

        return 0;
    }