#include<bits/stdc++.h>
using namespace std;
#define int long long 

int test;
int N;

int debug=0;

int arr[130];
unordered_map<int,int> previous_index;
unordered_map<int,int> current_index; 
int occurences[130];

void precompute(int n)
{
    memset(occurences,0,sizeof occurences);
    memset(arr,0,sizeof arr);
    previous_index.clear();
    current_index.clear();

    arr[1]=0;
    previous_index[0]=current_index[0]=1;
    occurences[arr[0]]++;

    int max_bar=n;

    for(int i=2;i<=max_bar;i++)
    {
        int value = arr[i-1];
        int diff = current_index[value] - previous_index[value];
        arr[i] = diff;
        
        if(previous_index.find(diff)==previous_index.end())
            previous_index[diff] = current_index[diff] = i;
        else
        {
            previous_index[diff] = current_index[diff];
            current_index[diff] = i;
        }

        occurences[arr[i]]++;
    }

    if(debug)
    {
        cout << endl;
        for(int i=1;i<=max_bar;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        for(int i=1;i<=max_bar;i++)
        {
            cout << occurences[i] << " ";
        }
        cout << endl;
    }

}

int32_t main()
{
    cin>>test;

    

    while(test--)
    {
        cin>>N;
        precompute(N);
        cout << occurences[arr[N]] << endl;
    }

}