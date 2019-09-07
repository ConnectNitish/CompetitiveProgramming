/*

https://www.hackerearth.com/problem/algorithm/problem-1-29/
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
https://www.codechef.com/problems/BPHC03
https://www.codechef.com/problems/MM1803
https://leetcode.com/problems/unique-paths/
https://leetcode.com/articles/the-maze-ii/
https://practice.geeksforgeeks.org/problems/final-destination/0

Videos : 


Refrences:
https://leetcode.com/articles/the-maze/
https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-using-stack/
https://www.geeksforgeeks.org/rat-in-a-maze-with-multiple-steps-jump-allowed/
https://www.geeksforgeeks.org/a-variation-of-rat-in-a-maze-multiple-steps-or-jumps-allowed/
https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
https://www.geeksforgeeks.org/find-paths-from-corner-cell-to-middle-cell-in-maze/

*/

#include<iostream>
#include<vector>
using namespace std;

int paths
(vector<vector<char>> data,
vector<vector<bool>> &visited,
int curri,int currj,int maxi,int maxj
,vector<string> &__paths,
string pathFormed)
{
   if(curri==maxi-1 && currj==maxj-1)
   {
       __paths.push_back(pathFormed);
       return 1;
   }
   visited[curri][currj] = true;
   int _paths = 0;
   if(curri+1<maxi && currj<maxj 
   && visited[curri+1][currj]==false
   && data[curri+1][currj]!='0')
   {
       string temp = pathFormed+"D";
       _paths += paths(data,visited,curri+1,currj,maxi,maxj,__paths,temp);
   }
   if(curri<maxi && currj+1<maxj 
   && visited[curri][currj+1]==false
   && data[curri][currj+1]!='0')
   {
       _paths += paths(data,visited,curri,currj+1,maxi,maxj,__paths,pathFormed+'R');
   }
   visited[curri][currj] = false;
   return _paths;
}

// vector<pair<int,int>> _coordinates;
// bool toprint = false;

// much simple code as to 
// check various conditions of indexes 
// __paths -> take all the paths for the destination 
int simple_code_paths
(vector<vector<char>> data,
vector<vector<bool>> &visited,
int curri,int currj,int maxi,int maxj
,vector<string> &__paths,
string pathFormed)
{

   if(curri>=maxi || currj>=maxj)
        return 0;    
    
    // if(__paths.size()>0)
    //     return 0;

   if(curri==maxi-1 && currj==maxj-1)
   {
        // cout << pathFormed << endl;
        __paths.push_back(pathFormed);
       return 1;
   }
   
    int _paths=0;
   
//   _coordinates.push_back({curri,currj});
   
   visited[curri][currj] = true;
       
   if(currj+1<maxj && visited[curri][currj+1]==false && data[curri][currj+1]!='X')
       _paths += simple_code_paths(data,visited,curri,currj+1,maxi,maxj,__paths,pathFormed+'R');
       
   if(curri+1<maxi && visited[curri+1][currj]==false && data[curri+1][currj]!='X')
       _paths += simple_code_paths(data,visited,curri+1,currj,maxi,maxj,__paths,pathFormed+'D');
       
   visited[curri][currj] = false;
   
//   _coordinates.pop_back();
    
   return _paths;
}

int main()
{
    int n;
    cin >> n;
    while(n-->0)
    {
        int r;
        cin >> r;
        int c;
        cin >> c;
        
        vector<vector<char>> input(r,vector<char>(c,0));
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                char temp;
                cin >> temp;
                input[i][j] = temp; 
            }
        }
        int _paths=0;
        string pathFormed="";
        vector<string> allpaths;
        int i=0;int j=0;
        allpaths.clear();
        if(input[i][j]!='X')
            _paths = simple_code_paths(input,visited,i,j,r,c,allpaths,pathFormed);
        
        /**/
        if(_paths>0)
        {
            for(auto a:allpaths)
                cout << a << ":" << endl;
        }
        
            
        cout << ((_paths>0) ? "POSSIBLE :::" : "NOT POSSIBLE ::::") << endl;
        
         cout << " No of Paths " << _paths << endl;
    }
    return 0;
}

/*
Input: 

2
4 4
OOOO
OOOO
OOOO
OOOO
3 3
XOO
OOO
OOX
5 4
OXOO
OOOX
OOXO
XOOO
XXOO

Input 2: 

1
5 4
OXOO
OOOX
OOXO
XOOO
XXOO

*/

