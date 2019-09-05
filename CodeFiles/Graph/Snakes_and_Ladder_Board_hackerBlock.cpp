#include<iostream>
#include<vector>
#include<map>
#include<queue>
#define forin(i,s,e) for(int i=s;i<=e;i++) 
using namespace std;

// map<int,int> ladder;
// map<int,int> snake; 
// map<int,int> attemptstoDestination;



int debug=0;

int noofrecrsiceCall=0;

int main()
{
	int t;
	scanf("%d",&t);

	if(debug)
	{
		cout << " Test Case " << t << endl;
	}

	while(t--)
	{
		// ladder.clear();
		// snake.clear();

		// jumps.clear();
		// _q = queue<int>();
		// visited.clear();
		// parent.clear();
		// graph.clear();


		map<int,vector<int>> graph ;
		map<int,bool> visited ;
		map<int,int> jumps;
		map<int,int> parent;
		queue<int> _q;	
		
		int target = 100;	
		int _ladder;
		scanf("%d",&_ladder);

		if(debug)
		{
			cout << " ladder " << _ladder << endl;
		}

		int start,end;
		int index;
		forin(index,0,_ladder-1)
		{
			scanf("%d",&start);
			scanf("%d",&end);
			// ladder[start] = (end-start+1);

			if(debug)
			{
				cout << " ladder start " << start << " end " << end << endl;
			}

			// ladder[start] = end;

			jumps[start] = (end-start);
		}

		int _snake;
		scanf("%d",&_snake);

		if(debug)
		{
			cout << " snake " << _snake << endl;
		}

		index=0;
		forin(index,0,_snake-1)
		{
			scanf("%d",&start);
			scanf("%d",&end);
			// snake[start] = (end-start+1);

			if(debug)
			{
				cout << " snake start " << start << " end " << end << endl;
			}

			// snake[start] = end;

			jumps[start] = (end-start);

		}

		for(int i=0;i<=target;i++)
		{
			for(int k=1;k<=6;k++)
			{
				int destination = i+k+jumps[i+k];
				int src = i;
				graph[src].push_back(destination);
				visited[src] = false;
			}
		}

		int source=1;

		visited[source]=true;
		_q.push(source);
		parent[source] = source;

		bool targetReached = false;

		while(_q.empty()==false)
		{
			int cur_node = _q.front();
			_q.pop();
			for(int neighbour:graph[cur_node])
			{
				if(visited[neighbour]==false)
				{
					visited[neighbour] = true;
					_q.push(neighbour);
					parent[neighbour] = cur_node;
					if(neighbour==100)
						targetReached=true;
				}
			}
		}

		int minAttempts=0;

		if(targetReached==false)
		{
			minAttempts=-1;
			printf("%d\n",minAttempts);
			continue;
		}

		while(source!=target)
		{
			minAttempts++;
			target = parent[target];
		}
		printf("%d\n",minAttempts);
		
	}
	return 0;
}

/*

1
1
2 3
1
4 1

*/