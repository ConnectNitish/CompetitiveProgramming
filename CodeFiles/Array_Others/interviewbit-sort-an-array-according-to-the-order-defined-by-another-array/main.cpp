/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
    public : 
    vector<int> solve(vector<int> &A, vector<int> &B);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    map<int,int> ump;
    ump.clear();
    
    int counter=0;
    for(int i=0;i<B.size();i++)
    {
        ump[B[i]]=counter;    
        counter++;
    }
    
    vector<int> ACopy(A.size(),0);
    
    int countElementInArray = 0;
    set<int> notinB;
    unordered_map<int,int> dddd;
    
    map<int,pair<int,int>> elementinB;
    
    for(int i=0;i<A.size();i++)
    {
        if(ump.find(A[i])==ump.end())
        {
            notinB.insert(A[i]); 
        }
        else
        {
            countElementInArray++;
            dddd[A[i]]=i;
            if(elementinB.find(ump[A[i]])!=elementinB.end())
            {
                pair<int,int> dataTraverse = elementinB[ump[A[i]]];
                dataTraverse.second++;
                elementinB[ump[A[i]]] = dataTraverse;
            }
            else
                elementinB[ump[A[i]]] = {A[i],1};
        }
    }
    
    int indextoappend = ACopy.size() - notinB.size();
    
    if(notinB.size()>0 && indextoappend>=0 && indextoappend<ACopy.size())
    {
        for(auto a:notinB)
        {
            ACopy[indextoappend++] = a;
        }
    }
    
    int index = 0;
    for(auto a:elementinB)
    {
        int ttt = a.second.second;
        while(ttt>0)
        {
            ACopy[index++] = a.second.first;
            ttt--;
        }
    }
    
    return ACopy;
}


int main()
{
    debug=1;
    
    vector<int> ID;
    int D;
    cin >> D;

    for(int i=0;i<D;i++)
    {
        int V;
        cin >> V;
        ID.push_back(V);
    }

    int D2;
    cin >> D2;
    vector<int> ID2;
    for(int i=0;i<D2;i++)
    {
        int V;
        cin >> V;
        ID2.push_back(V);
    }

    cout << " Input A " << endl;
    for_each(ID.begin(),ID.end(),print<int>);    

    cout << " Input B " << endl;
    for_each(ID2.begin(),ID2.end(),print<int>);    


    Solution s;
    ID = s.solve(ID,ID2);
    
    if(debug)
        cout << " Checkpoint " << endl;
    
    cout << " Output " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}



