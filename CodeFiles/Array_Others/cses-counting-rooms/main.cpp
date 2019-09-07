/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://cses.fi/problemset/task/1192

https://cses.fi/problemset/result/193666/

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

int dirx[4]={+0,-1,+0,+1};
int diry[4]={-1,+0,+1,+0};

int rooms(char map[][1001],int r,int c)
{
    
    int count = 0;
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            
            if(map[i][j]=='$' || map[i][j]=='#')
            {
                continue;
            }
            
            queue<pair<int,int>> d;
            
            if(map[i][j]=='.')
            {
                d.push({i,j});
                map[i][j]='$';
            }
            
            while(d.size()>0)
            {
                pair<int,int> pr = d.front();
                d.pop();
                for(int k=0;k<4;k++)
                {
                    int xnew = pr.first + dirx[k];
                    int ynew = pr.second + diry[k];
                    if(map[xnew][ynew]=='$')
                        continue;
                    else if(map[xnew][ynew]=='#')
                        continue;
                    else if(map[xnew][ynew]=='.')
                    {
                        d.push({xnew,ynew});
                        map[xnew][ynew]='$';
                    }
                }
            }
            
            count++;
        }
    }
    
    return count;
}

char d[1001][1001];

int main()
{
    int r,c;
    
    scanf("%d",&r);
    scanf("%d",&c);
    
    
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            char ch;
            cin >> ch;
            d[i][j] = ch;
        }
    }
    /*
    cout << r << " ---------------- " << c << endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%c",d[i][j]);
        }
        printf("\n");
    }
    */
    cout << rooms(d,r,c) << endl;

    return 0;
}

/*

Input 1 : 
5 8
########
#..#...#
####.#.#
#..#...#
########
Output 1 : 
3

*/

/*
Input 2 : 

Output 2 : 

*/

