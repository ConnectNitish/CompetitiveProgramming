/******************************************************************************

*******************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int noofrecusrivecalls=0;
int recusriveeditdistance(string s1,string s2,int starts1,int starts2)
{
    ++noofrecusrivecalls;
    if(starts1>s1.length() || starts2>s2.length())
        return 0;
        
    int costrepalce;
    int costinsert;
    int costdelete;
    
    // if both charcters are equal then 
    // no operations will be taken 
    if(s1[starts1]==s2[starts2])
        return recusriveeditdistance(s1,s2,starts1+1,starts2+1);
    else
    {
        costrepalce = recusriveeditdistance(s1,s2,starts1+1,starts2+1);
        costdelete = recusriveeditdistance(s1,s2,starts1,starts2+1);
        costinsert = recusriveeditdistance(s1,s2,starts1+1,starts2);
        
        return 1 + min(costinsert,min(costdelete,costrepalce));
    }
}

int noofRecusriveCallTopDown=0;
int memoTables1s2TopDown[1000][1000];
int editdistanceTopDown(string s1,string s2,int starts1,int starts2)
{
    ++noofRecusriveCallTopDown;
    if(starts1>s1.length() || starts2>s2.length())
        return 0;
        
    if(memoTables1s2TopDown[starts1][starts2]!=-1) return memoTables1s2TopDown[starts1][starts2];
        
    if(s1[starts1]==s2[starts2])
    {
        memoTables1s2TopDown[starts1][starts2] = editdistanceTopDown(s1,s2,starts1+1,starts2+1);
    }
    else
    {
        int costdelete,costinsert,costrepalce;
        costdelete = editdistanceTopDown(s1,s2,starts1+1,starts2);
        costinsert = editdistanceTopDown(s1,s2,starts1,starts2+1);
        costrepalce = editdistanceTopDown(s1,s2,starts1+1,starts2+1);
        memoTables1s2TopDown[starts1][starts2] = 1 + min(costinsert,min(costrepalce,costdelete));
    }
    return memoTables1s2TopDown[starts1][starts2];
}

int noofRecusriveCallBottomUp=0;
int memoTables1s2BottomUp[1000][1000] = {0};
int editDistanceBottomUp(string s1,string s2)
{
    ++noofRecusriveCallBottomUp;
    int n1=s1.length();
    int n2=s2.length();
    
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 && j>0)
                memoTables1s2BottomUp[i][j] = 1 + memoTables1s2BottomUp[i][j-1];
            else if(j==0 && i>0)
                memoTables1s2BottomUp[i][j] = 1 + memoTables1s2BottomUp[i-1][j];
            else if(j>0 && i>0)
            {
                
                // replace : memoTables1s2BottomUp[i-1][j-1]
                // insert : memoTables1s2BottomUp[i][j-1]
                // delete : memoTables1s2BottomUp[i-1][j]
                
                // if(s1[i-1]==s2[j-1])
                //     memoTables1s2BottomUp[i][j] = min(memoTables1s2BottomUp[i-1][j-1],
                //     min(memoTables1s2BottomUp[i-1][j],memoTables1s2BottomUp[i][j-1]));
                // else
                //     memoTables1s2BottomUp[i][j] = 1 + min(memoTables1s2BottomUp[i-1][j-1],
                //     min(memoTables1s2BottomUp[i-1][j],memoTables1s2BottomUp[i][j-1]));
                    
                // above can also be written as
                // if both crahcraters are same then 
                // formulae will be 0+
                // else will be 1+
                memoTables1s2BottomUp[i][j] = min(memoTables1s2BottomUp[i-1][j-1],
                min(memoTables1s2BottomUp[i-1][j],memoTables1s2BottomUp[i][j-1]))
                + (s1[i-1]!=s2[j-1]);
            
            }
                
        }
    }
    
    return memoTables1s2BottomUp[n1-1][n2-1];
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    
    cout << " Edit Distance recusrion " << recusriveeditdistance(s1,s2,0,0) << endl;
    cout << " No of Recursive Calls " << noofrecusrivecalls << endl;
    
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            memoTables1s2TopDown[i][j]=-1;
        }
    }

    cout << " Edit Distance Top Down " << editdistanceTopDown(s1,s2,0,0) << endl;
    cout << " No of Recursive Calls " << noofRecusriveCallTopDown << endl;
    
    cout << " Edit Distance Bottom Up " << editDistanceBottomUp(s1,s2) << endl;
    cout << " No of Recursive Calls " << noofRecusriveCallBottomUp << endl;
    
    return 0;
}


