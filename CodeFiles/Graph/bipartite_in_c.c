#include <iostream>
using namespace std;

struct node{
    int data;
    node *nxt;
};

struct queue{
    node *front;
    node *rear;
};

node *newnode(int x){
    node *tmp = new node();
    tmp->data = x;
    tmp->nxt = NULL;
    return tmp;
}

queue *newqueue()
{
    queue *q = new queue();
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue *q, int x){
    node *tmp = newnode(x);
    if(q->rear)
        q->rear->nxt = tmp;
    q->rear = tmp;
    if(!q->front)
        q->front = q->rear;
}

int dequeue(queue *q){
    node *tmp = q->front;
    if(q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->nxt;
    return tmp->data;
}

bool isempty(queue *q){
    return q->front == NULL;
}

int n;
int graph[110][110];

bool isbipartite()
{
    //0 -> 1st color;
	//1 -> 2nd color; 
	//-1 -> no color; 
    int color[n];
    for(int i=0;i<n;i++)
        color[i] = -1;
    color[0] = 1;
    queue *q = newqueue();
    enqueue(q, 0);
    while(!isempty(q)){
        int u = dequeue(q);
        for(int i=0;i<n;i++){
            if(graph[u][i] == 1 && color[i]==-1){
                color[i] = 1 - color[u];
                enqueue(q, i);
            }
            else if(graph[u][i] == 1 && color[i]==color[u]){
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                graph[i][j]=0;

        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>graph[i][j];
        cout<<isbipartite<<"\n";
    }
    return 0;
}