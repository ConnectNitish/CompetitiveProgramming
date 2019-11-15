// https://www.geeksforgeeks.org/find-number-of-islands/ 
// can go up down left right not diagonal 

#include<bits/stdc++.h>
using namespace std;
int debug=0;
class Solution 
{
public:
    vector<vector<bool>> visited;

    // int rowN[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    // int colN[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

    int rowN[4] = { -1, 0, +1, +0 }; 
    int colN[4] = { +0, +1,+0, -1 }; 


    int ROW,COL;

    bool isSafe(vector<vector<char>>& grid,int r,int c,
    int Mr,int Mc)
    {
        return 
        (r >= 0) && (r < Mr) && (c >= 0) && (c < Mc) 
        && ((grid[r][c]=='1') && !visited[r][c]); 
    }

    void DFS(int r,int c,vector<vector<char>>& data)
    {
        visited[r][c] = true;
        for(int i=0;i<4;i++)
        {
            int newX = r + rowN[i];
            int newY = c + colN[i];

            // if(newX<0 || newX>=ROW) continue;
            // if(newY<0 || newY>=COL) continue;
            // if(visited[newX][newY]) continue;
            if(isSafe(data,newX,newY,ROW,COL))
                DFS(newX,newY,data);
        }
    }

    int numOffices(vector<vector<char>>& grid,int R,int C)
    {
        ROW = R;
        COL = C;
        
        visited.clear();
        visited.resize(ROW,vector<bool>(COL,false));

        int count=0;
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(visited[i][j]==false && grid[i][j]=='1')
                {
                    DFS(i,j,grid);
                    ++count;
                }                
            }
        } 

        return count;
    }

// Parse the raw input here
};

int main()
{
    int r,c;
    cin >> r >> c;
    vector<vector<char>> data;
    data.resize(r);

    for(int i=0;i<r;i++)
    {
        vector<char> tt(c,'0');
        for(int j=0;j<c;j++)
        {
            char ch;
            cin >> ch;
            tt[j]=ch;
        }
        data[i] = tt;
    }

    if(debug)
    {
        cout << " OK " << endl;
    }

    Solution s;
    cout << s.numOffices(data,r,c) << endl;
}