// https://online.codingblocks.com/player/33819/content/13657/168

#include<iostream>
#include<vector>
#include<iomanip>
#define ll double
#define MAX 40 
using namespace std;

ll dp[MAX][MAX][MAX];

ll getRockProbability(int r,int s,int p)
{
    // no rock is left 
    if(r==0)
        return 0.0;

    // ensures some rocks are left
    // but no scissors are left 
    // because no scissors are left 
    // so no paper can be cut. 
    // hence probablity of getting rock win is zero 
    if(s==0)
        return 0.0;

    // ensures rock and scissors are 
    // available ; but no paper is present 
    // because no paper is available
    // hence probablity of rock win 
    // is always 1  
    if(p==0)
        return 1.0;
    
    if(dp[r][s][p]!=-1.0) return dp[r][s][p];

    ll total = r*s + s*p + r*p;
    ll result = 0.0;
    result += getRockProbability(r,s-1,p) * ((r*s)/total);
    result += getRockProbability(r-1,s,p) * ((p*r)/total);
    result += getRockProbability(r,s,p-1) * ((s*p)/total);
    return dp[r][s][p] = result;
}

ll getScissorWinProbability(int r,int s,int p)
{
    // scissors are present and rocks are also present  
    // but no papaer is present showing 
    // scissors can be cut by rocks hence probaility 
    // of win of scissors is zero 
    if(p==0)
        return 0.0;

    // if not scissors is present 
    if(s==0)
        return 0.0;
    
    // ensures Scissors are present but no rocks are present 
    // so scissors will not be attacked by any one else
    // hence its probability of winning is always 1 
    if(r==0)
        return 1.0;
    
    if(dp[r][s][p]!=-1.0) return dp[r][s][p];

    ll total = r*s + s*p + r*p;

    ll result = 0.0;
    result += getScissorWinProbability(r,s-1,p) * ((r*s)/total);
    result += getScissorWinProbability(r-1,s,p) * ((p*r)/total);
    result += getScissorWinProbability(r,s,p-1) * ((p*s)/total);

    return (dp[r][s][p] = result);
}

ll getPaperWinProbability(int r,int s,int p)
{
    // if not paper is present 
    if(p==0)
        return 0.0;

    // ensures paper are present but no Rock are present 
    // so Paper will not be attacked by any one else
    // hence its probability of winning is always 1 
    if(r==0)
        return 0.0;
    
    // paper are present and rocks are also present  
    // but no Scissor is present showing 
    // paper can be cut by Scissrs hence probaility 
    // of win of paper is zero 
    if(s==0)
        return 1.0;

    if(dp[r][s][p]!=-1.0) return dp[r][s][p];

    ll total = r*s + s*p + r*p;

    ll result = 0.0;
    result += getPaperWinProbability(r,s-1,p) * ((r*s)/total);
    result += getPaperWinProbability(r-1,s,p) * ((p*r)/total);
    result += getPaperWinProbability(r,s,p-1) * ((p*s)/total);

    return (dp[r][s][p] = result);
}

void initialise_dp()
{
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            for(int k=0;k<MAX;k++)
                dp[i][j][k] =-1.0;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
    int r,s,p;
    cin >> r >> s >> p;

    initialise_dp();
    ll rock_win_pro = getRockProbability(r,s,p);
    initialise_dp();
    ll scissor_win_pro = getScissorWinProbability(r,s,p);
    initialise_dp();
    ll paper_win_pro = getPaperWinProbability(r,s,p);
    
    cout << fixed << setprecision(9) << rock_win_pro << " " << scissor_win_pro << " " << paper_win_pro << endl;
    }
    return 0;
}