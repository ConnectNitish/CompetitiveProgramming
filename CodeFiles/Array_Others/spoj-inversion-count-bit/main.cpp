/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

int Input[10000009]={0};
int BIT[10000009]={0};
int NewInput[10000009]={0};
int debug=0;
class Solution
{
    public : 
    int solve(int Input[],int size,bool applycompression);
    //vector<int> solve(vector<int> &A);
    
};

void update(int BIT[],int index,int maxN)
{
    if(debug)
    cout << " Entered index " << endl; 
    while(index<=maxN)
    {
        if(debug)
        cout << index << " : ";
        BIT[index]++;
        index += (index&(-index));
    }
    if(debug)
    cout << endl;
    
}

long long query(int BIT[],int index)
{
    long long res = 0;
    while(index>0)
    {
        res += BIT[index];
        index -= (index&(-index));
    }
    return res;
}

int Solution::solve(int Input[],int size,bool applycompression)
{
    memset(BIT,0,sizeof(BIT));
    long long cnt=0;
    for(int i=size-1;i>=0;i--)
    {
        int value = Input[i];
        cnt += query(BIT,value-1);
        if(applycompression)
            update(BIT,value,size+1);
        else
            update(BIT,value,10000009);
    }
    return (int)cnt;
}



template<typename T>
void print(T value)
{
    cout << value << " ";
}

int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    debug=0;
    bool applycompression = true;
    int t;
    scanf("%d\n",&t);
    
    if(debug)
    cout << "  Test Case " << t << endl;
    
    Solution s;    
    while(t-->0)
    {
        string line;
        getline(cin, line);
        int n;
        scanf("%d\n",&n);
        if(debug)
        cout << n << endl;
        // vector<int> data;
        memset(Input,0,sizeof(Input));
        
        memset(NewInput,0,sizeof(NewInput));
        map<int,int> metadata;
        
        for(int i=0;i<n;i++)
        {
            int V;
            // cin >> V;
            scanf("%d\n",&V);
            // data.push_back(V);
            Input[i]=V;
            
            if(applycompression)
                metadata[V] = i+1;
        }
        if(debug)
        {
            for(int i=0;i<n;i++)
                cout << Input[i] << " : ";
            cout << endl;
        }
        
        // convert into range based
       int result ;
       
       if(applycompression)
       {
            int index=0;
            for(int i=n-1;i>=0;i--)
            {
                map<int,int>::iterator itrmap = metadata.begin();
                int _distance = 0;//distance(metadata.find(Input[i]),itrmap);
                if(metadata.find(Input[i])!=metadata.end())
                {
                    _distance = distance(metadata.begin(),metadata.find(Input[i]));
                    // cout << " Found " << _distance <<  endl;
                }
                // cout << " _distance " << _distance << " Input " << Input[i] ;
                NewInput[i]=(_distance+1);
                // if(debug)
                //     cout << " Test " << endl;
            }
            
            if(debug)
            {
                cout << " New Input " << endl;
            
                for(int i=0;i<n;i++)
                {
                    cout << NewInput[i] << ":";
                }
                cout<< endl;
            }
       }
        
        if(applycompression)
            result = s.solve(NewInput,n,applycompression);
        else
            result = s.solve(Input,n,applycompression);
        
        cout << result << endl;        
    }
}

/*
Input 1:
2

3
3
1
2

5
2
3
8
6
1
Output 1 : 


*/




