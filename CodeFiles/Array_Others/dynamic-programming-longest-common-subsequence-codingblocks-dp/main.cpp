/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int debug=1;

int noofRecusriveCalls=0;
int getLCSRecursion(string s1,string s2,int starts1,int starts2)
{
    ++noofRecusriveCalls;
    
    // this section will not work because 
    // invocation was from 0,0 to n+1 , m+1 
    
    // if(starts1>s1.length() || starts2>s2.length())
    //     return 0;

    // return ((s1[starts1]!=s2[starts2]) ? 
    //     max(
    //         getLCSRecursion(s1,s2,starts1+1,starts2),
    //         getLCSRecursion(s1,s2,starts1,starts2+1)
    //         )
    //     : 1 + getLCSRecursion(s1,s2,starts1+1,starts2+1));        
    
    // calling from n+1,m+1 to 0,0 will work 
    // because string comaprison should be from 
    // backwards not forward  
    
    if(starts1<0 || starts2<0)
        return 0;
    
        return ((s1[starts1]!=s2[starts2]) ? 
        max(
            getLCSRecursion(s1,s2,starts1-1,starts2),
            getLCSRecursion(s1,s2,starts1,starts2-1)
            )
        : 1 + getLCSRecursion(s1,s2,starts1-1,starts2-1));
}

int noofRecusriveCallTopDown=0;
int memoDataTopDown[1000][1000];
int getLCSTopDown(string s1,string s2,int starts1,int starts2)
{
    ++noofRecusriveCallTopDown;
    if(starts1<0 || starts2<0)
        return 0;
    
    int ans;
    
    if(s1[starts1]!=s2[starts2])
    {
        int removedfroms2;
        int removedfroms1;
        
        removedfroms2 = (memoDataTopDown[starts1][starts2-1]!=-1 ? memoDataTopDown[starts1][starts2-1] : 
        (memoDataTopDown[starts1][starts2-1] = getLCSTopDown(s1,s2,starts1,starts2-1)));
        
        removedfroms1 = (memoDataTopDown[starts1-1][starts2]!=-1 ? memoDataTopDown[starts1-1][starts2] : 
        (memoDataTopDown[starts1-1][starts2] = getLCSTopDown(s1,s2,starts1-1,starts2)));
        
        ans = max(removedfroms2,removedfroms1);
    }
    else
    {
        ans = 1 + 
        (memoDataTopDown[starts1-1][starts2-1]!=-1 ? memoDataTopDown[starts1-1][starts2-1] : 
        (memoDataTopDown[starts1-1][starts2-1] = getLCSTopDown(s1,s2,starts1-1,starts2-1)));
    }
    
    memoDataTopDown[starts1][starts2] = ans;
    
    return ans;
}

int noofCallsBottomUp=0;
int getLCSBttomUp(string s1,string s2)
{
    ++noofCallsBottomUp;
    int n1= s1.length();
    int n2= s2.length();
    
    int dp[n1+1][n2+1];
    
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else
                dp[i][j] = (s1[i-1]!=s2[j-1]) ? max(dp[i-1][j],dp[i][j-1]) : 1 + dp[i-1][j-1];
        }
    }
    
    return dp[n1][n2];
}

int main()
{
    debug = 1;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    
    // wrong invocation for recursion 
    // cout << " LCS - Recusrion " << getLCSRecursion(s1,s2,0,0) << endl;
    
    // cout << " LCS - Recusrion " << getLCSRecursion(s1,s2,s1.length()-1,s2.length()-1) << endl;
    // cout << " LCS - Recusrion Calls " << noofRecusriveCalls << endl;
    debug = 0;
    
    if(debug)
    {
        cout << endl;
        for(int i=0;i<=s1.length();i++)
        {
            for(int j=0;j<=s2.length();j++)
            {
                // cout << memoDataTopDown[i][j] << " ";
                memoDataTopDown[i][j] = -1;
                cout << memoDataTopDown[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    memset(&memoDataTopDown[0][0],-1,sizeof(memoDataTopDown));
    
    
    cout << " LCS - Top Down " << getLCSTopDown(s1,s2,s1.length()-1,s2.length()-1) << endl;
    cout << " LCS - Recusrion in Top Down Calls " << noofRecusriveCallTopDown << endl;
    
    
    
    
    // cout << " LCS - Bottom Up " << getLCSBttomUp(s1,s2) << endl;
    // cout << " LCS - Bottom Up Calls " << noofCallsBottomUp << endl;
}

/*
Input : 
aggtab
gxtxtab
Output:
4
Input2:
ab
cd
Output2:
0
*/


