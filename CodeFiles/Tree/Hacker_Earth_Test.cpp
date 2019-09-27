#include <bits/stdc++.h>
using namespace std;
//N is the total nodes of the tree.
//Q is total number of queries.
//Array U and V denotes there is an edge between U[i] and V[i].
//Val denotes special number related to nodes.Val[i] is the special number related to node i.
/* Type denotes the type of the queries.If Type[i]=1,then i(th) query is of type 1.If Type[i]=2,
   then i(th) query is of type 2.
   If i(th) query is of type 1,then X[i] denotes the node whose special number is to be 
   updated to Y[k](0-based indexing),where k is the total number of queries of type 1 that came before i(th) 
   query.
   If i(th) query is of type 2,then X[i] denotes the node whose power you have to find.
   Y_length is the total number of type 1 queries.
*/

/*
Question Statement Mentioned Below 
// https://stackoverflow.com/questions/58121090/tried-binary-tree-examples-got-the-output-as-an-object-how-can-i-get-this-obje
*/


map<int,set<int>> graph;

map<int,int> parent;
map<int,int> countofNumber;
map<int,bool> visited;
map<int,int> node_spe_Number;
vector<int> primes;

#define MAX 1000000


int debug=1;

void getSieve()
{
    primes.resize(MAX+1,true);
    for(int p=2;p*p<=MAX;p++)
    {
        if(primes[p]==true)
        {
            for(int i=p*p;i<=MAX;i = i+p)
            {
                primes[i] = false;
            }
        }
    }
}

vector<int> sp;
void getSievesmallestPrime()
{
    sp.clear();
    
    sp.resize(MAX+1,0);
    sp[0]=0;
    sp[1]=1;
    
    for(int i=2;i<=MAX;i++)
    {
        sp[i] = i;
    }
    
    for(int p=4;p<=MAX;p=p+2)
    {
        sp[p] = 2;
    }
    
    
    for(int i=3;i*i<=MAX;i++)
    {
        if(sp[i]==i)
        {
            for(int j=i*i;j<=MAX;j = j+i)
            {
                if(sp[j]==j)
                    sp[j] = i;
            }
        }
    }
}

int getFactors(int n)
{
    set<int> res;
    int sum=0;
    while(n!=1)
    {
        sum += sp[n];
        res.insert(sp[n]);
        // if(sp[n] == 0)
        //     break;
        n = n / sp[n];
    }

    sum=0;
    for(auto a:res)
        sum+=a;

    return sum;
}

void Traverse(int src,int p_val)
{
    parent[src] = p_val;
    visited[src] = true;
    long long count=0;
    
    for(auto a:graph[src])
    {
        if(visited[a]==false)
        {
            int factors = getFactors(node_spe_Number[a]); 
            if(debug)
            {
                cout << " aaa" << factors << endl;
            }
            count += (factors%3);
            Traverse(a,src);
        }
    }
    count += (getFactors(node_spe_Number[src])%3);

    countofNumber[src] = (count >> 1);
}


vector<int> solve (vector<int> SpecialNumber, int N, int Q, vector<int> srcU, vector<int> destV, 
    vector<int> Y, int Y_length, vector<int> X, vector<int> Type) {
 vector <int> ans;
   //write your code here

 graph.clear();

 if(debug)
 {
    cout << " Graph " << endl;
}

for(int i=1;i<=N;i++)
{
 graph[i] = {};
 visited[i] = false;
 node_spe_Number[i] = SpecialNumber[i-1];
}

for(int i=0;i<srcU.size();i++)
{
 int src = srcU[i];
 int dest = destV[i];
 graph[src].insert(dest);
}

if(debug)
{
    cout << " Graph 2 " << endl;
}

Traverse(1,-1);

int counter=0;
for(int i=0;i<Type.size();i++)
{
    int type = Type[i];
    if(type==2)
    {
        int Xno = X[i];
        cout << "Query" << Xno << " Result " << countofNumber[Xno] << endl; 
        ans.push_back(countofNumber[Xno]);
    }
    else if(type==1)
    {
        int Xno = X[i];
        int YNo = Y[counter];
        if(getFactors(YNo)%3==0)
        {
            node_spe_Number[X[i]] = YNo;
        }
        else
        {
            int current_node = Xno;
            countofNumber[current_node] = 0;

            for(auto ng:graph[current_node])
                countofNumber[current_node] += countofNumber[ng];

            current_node = parent[current_node];
            node_spe_Number[X[i]] = YNo;

            while(current_node!=-1)
            {
                countofNumber[current_node]--;
                current_node = parent[current_node];
            }    
        }
        counter++;
    }

    if(debug)
    {
        cout << " Parent " << endl;

        for(auto a:parent)
        {
            cout << a.first << " : " << a.second << endl;
        }

        cout << " Cost " << endl;

        for(auto a:countofNumber)
        {
            cout << a.first << " : " << a.second << endl;
        }

    }
}

return ans;
}

int main() {

    if(debug)
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    
    getSievesmallestPrime();

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    int Num_U = N - 1;
    vector<int> U(Num_U), V(Num_U);
    for(int i_U=0; i_U<Num_U; i_U++)
    {
    	cin >> U[i_U] >> V[i_U];
    }
    vector<int> Val(N);
    for(int i_Val=0; i_Val<N; i_Val++)
    {
    	cin >> Val[i_Val];
    }
    vector<int> Type(Q), X(Q);
    vector<int> Y;
    for(int i_Type=0; i_Type<Q; i_Type++)
    {
    	cin >> Type[i_Type] >> X[i_Type];
    	if(Type[i_Type] == 1){
    		int x;
    		cin >> x;
    		Y.push_back(x);
    	}
    }

    vector<int> out_;
    out_ = solve(Val, N, Q, U, V, Y, Y.size(), X, Type);
    for(int i_out_=0; i_out_<out_.size(); i_out_++)
    {
    	cout << out_[i_out_] << endl;
    }
}

/*

Problem Statement You are given a tree with N nodes rooted at 1. Each of the N nodes have some special number Se related to it. Each Node also has certain Power. Power of each node of the tree is defined as the number of heavy nodes in the subtree of the node (including that node). A heavy node is a node whose sum of divisors of its special number is a multiple of 3. You are given Q queries
There are two types of queries : Type 1: Update special number of node. Type 2: Tell the power of a certain node.

Input Format

First line: Two space separated integers N and Q denoting number of nodes in the tree and number of queries respectively.Each of the next N-1 lines: Two space separated integers U and V denoting there is an edge between them. Next line: N space separated integers, i of which denotes the special number related to node i.First integer in next Q lines is T (the type of query). if T is 1, it is followed by 2 integers X and Y denoting special number S of node X is to be updated to Y if T is 2, it is followed by single integer X

Output Format

For each query of type 2, output the power of the given node X. Answer for each query should come in a new line

given sample input and outputs like

sample input

5 5
1 2
1 3
3 4
3 5
16 8 17 3 18
2 1
2 3
1 3 7
2 1
2 3

sample output
3
2
2
1

*/
