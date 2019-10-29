#include <bits/stdc++.h> 
using namespace std; 
int tornPages[100010];
int totalTornPages[100010];
#define int long long
int debug=0;

int height;
int n;

map<long long,map<long long,map<long long,long long>>> coll;

vector<int> input_data;
vector<int> input_data2;


int invokeCount(int first,int second,int current)
{
    if(debug)
    {
        cout << " first " << first << " second " << second << " current " << current << endl;
    }

    if(current==n)
    {
        bool check=false;
        if(first>=height && second>=height)
        {
                return 1;
        }

        // if(check==true)
        {
            return 0;
        }
    }

    if(coll.find(current)!=coll.end())
    {
        if(coll[current].find(first)!=coll[current].end())
        {
            if(coll[current][first].find(second)!=coll[current][first].end())
            {
                return coll[current][first][second];
            }
        }
    }

    int all_answer = 0;
    int first_next = 
    invokeCount(first + input_data[current],
        second,current+1);

    int next_second = 
    invokeCount(first,
        second + input_data2[current],current+1);

    int third_next = 
    invokeCount
    (first + input_data[current],
        second+input_data2[current],current+1);

    coll[current][first][second] = 
    (first_next + next_second + third_next);

    return (first_next + next_second + third_next); 
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;   
    int tt=0;

    while(t--)
    {
        tt++;

        cin >> n;
        cin >> height;

        // memset(tornPages,0,sizeof tornPages);
        input_data.clear();
        input_data2.clear();
        coll.clear();

        input_data2.resize(n);
        input_data.resize(n);
        
        for(int i=0;i<n;i++)
            cin >> input_data[i];

        for(int i=0;i<n;i++)
            cin >> input_data2[i];
        
        int total_value = invokeCount(0,0,0);

        cout << "Case #" << tt << ": " << total_value << endl;

    }




}