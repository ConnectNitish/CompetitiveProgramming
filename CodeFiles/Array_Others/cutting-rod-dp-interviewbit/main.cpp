/******************************************************************************
https://www.interviewbit.com/problems/rod-cutting/
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

*******************************************************************************/
#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int debug = 0;
int noofrecusriveCalls = 0;
int noofrecusriveCallsTopDown = 0;
int cutting_Rod_Recursion(vector<int> &rodsData,int start,int end)
{
    ++noofrecusriveCalls;
    // -1 to check whether any updates 
    // has been done or not 
    int currentCost=-1;
    int minCostForIndex = INT_MAX;
    
    for(int i=0;i<rodsData.size();i++)
    {
        if(start<rodsData[i] && rodsData[i]<end)
        {
            int costbyleft = cutting_Rod_Recursion(rodsData,start,rodsData[i]);
            int costbyright = cutting_Rod_Recursion(rodsData,rodsData[i],end);
            currentCost = costbyleft + costbyright + (end-start); 
        }
        
        if(currentCost!=-1 && currentCost<minCostForIndex)
        {
            minCostForIndex = currentCost;
        }
    }
    
    
    
    if(minCostForIndex==INT_MAX)
        return 0;
    
    return minCostForIndex;
}


map<pair<int,int>,vector<int>> leftrightpair;



map<pair<int,int>,int> indexpointer;
unordered_map<int,int> indexpointertemp;
vector<int> ordered;
int cutting_Rod_Recursion_top_down(vector<int> &rodsData,int start,int end,
vector < vector < int >> &dpTopDown,int level
,vector<int> &minAll)
{
    if(debug)
    cout<<start<<" "<<end<<" \n";
    
    ++noofrecusriveCallsTopDown;
    int temprevcrsivecall = noofrecusriveCallsTopDown;
    int currentCost=-1;
    int minCostForThisIndex = INT_MAX;
    int minCostpointofSplit=-1;
    int valueofSplit = -1;
    vector<int> minLeft;
    vector<int> minRight;
    
    if(dpTopDown[start][end]!=-1) 
    {
        minAll = leftrightpair[{start,end}]; 
        return dpTopDown[start][end];
    }
    
    for(int i=0;i<rodsData.size();i++)
    {
        currentCost=-1;
        
        minLeft.clear();
        minRight.clear();
        
        if(start<rodsData[i] && rodsData[i]<end)
        {
            int leftdata; 
            if(dpTopDown[start][rodsData[i]]!=-1)
            {
                if(debug)
                cout<<start<<" "<<rodsData[i]<<" \n";
                
                minLeft = leftrightpair[{start,rodsData[i]}];
                leftdata = dpTopDown[start][rodsData[i]];   
            }
            else
            {
               leftdata = cutting_Rod_Recursion_top_down(rodsData,start,rodsData[i],dpTopDown,level+1,minLeft);
              leftrightpair[{start,rodsData[i]}] = minLeft;
            }
            
            int rightData; 
            if(dpTopDown[rodsData[i]][end]!=-1) 
            {
                if(debug)
                cout<<" "<<rodsData[i]<<end<<" \n";
                
                minRight = leftrightpair[{rodsData[i],end}];
                rightData = dpTopDown[rodsData[i]][end];
            }
            else
            {
                rightData = cutting_Rod_Recursion_top_down(rodsData,rodsData[i],end,dpTopDown,level+1,minRight);
                leftrightpair[{rodsData[i],end}] = minRight;
            }
            currentCost = (end-start) + rightData + leftdata;
        }
        
        if(currentCost!=-1 && currentCost<minCostForThisIndex)
        {
            minCostpointofSplit = i;
            indexpointer[{start,end}] = minCostpointofSplit;
            valueofSplit = rodsData[i];
            indexpointertemp[level] = valueofSplit;
            minCostForThisIndex = currentCost;
            
            if(debug)
            cout<<"valueofSplit: "<<valueofSplit<<"\n";
            
            minAll.clear();
            // cout<<start<<" "<<end<<" \n";
            
            if(debug)
            cout << " Indexes Right\n";
            for(int iitemp=0;iitemp<minRight.size();iitemp++)
            {
                if(debug)
                cout << minRight[iitemp]<<" ";
                minAll.push_back(minRight[iitemp]);
            }
            
            if(debug)
            cout << endl;
            
            if(debug)
            cout << " Indexes left \n" ;
            for(int iitemp=0;iitemp<minLeft.size();iitemp++)
            {
                if(debug)
                cout << minLeft[iitemp]<<" ";
                minAll.push_back(minLeft[iitemp]);
            }
            if(debug)
            cout << endl;
            
            minAll.push_back(rodsData[i]);
            
            if(debug)
            {
                cout << " MIN ALL \n" ;
                for(int iitemp=0;iitemp<minAll.size();iitemp++)
                {
                    cout << minAll[iitemp]<<" ";
                    // minAll.push_back(minLeft[iitemp]);
                }
            }
            
            if(debug)
            cout << endl;
            
        }
    }
    
    if(minCostpointofSplit!=-1)
    {
        // indexpointertemp[level] = valueofSplit;
        ordered.push_back(valueofSplit);
    }
    
    leftrightpair[{start,end}] = minAll;
    
    if(minCostForThisIndex==INT_MAX)
    {
        
        return (dpTopDown[start][end]=0);
    }
    
    

    return (dpTopDown[start][end]=minCostForThisIndex);
}

int cutting_Rod_Recursion_top_down_backUp(vector<int> &rodsData,int start,int end,
vector < vector < int >> &dpTopDown,int level
)
// ,vector<int> &minAll)
{
    ++noofrecusriveCallsTopDown;
    int temprevcrsivecall = noofrecusriveCallsTopDown;
    int currentCost=-1;
    int minCostForThisIndex = INT_MAX;
    int minCostpointofSplit=-1;
    int valueofSplit = -1;
    vector<int> minLeft;
    vector<int> minRight;
    
    if(dpTopDown[start][end]!=-1) return dpTopDown[start][end];
    
    for(int i=0;i<rodsData.size();i++)
    {
        currentCost=-1;
        
        
        if(start<rodsData[i] && rodsData[i]<end)
        {
            int leftdata = (dpTopDown[start][rodsData[i]]!=-1) ? dpTopDown[start][rodsData[i]] : 
            cutting_Rod_Recursion_top_down_backUp(rodsData,start,rodsData[i],dpTopDown,level+1);
            int rightData = (dpTopDown[rodsData[i]][end]!=-1) ? dpTopDown[rodsData[i]][end] :  
            cutting_Rod_Recursion_top_down_backUp(rodsData,rodsData[i],end,dpTopDown,level+1);
            currentCost = (end-start) + rightData + leftdata;
        }
        
        if(currentCost!=-1 && currentCost<minCostForThisIndex)
        {
            minCostpointofSplit = i;
            indexpointer[{start,end}] = minCostpointofSplit;
            valueofSplit = rodsData[i];
            indexpointertemp[level] = valueofSplit;
            minCostForThisIndex = currentCost;
        }
    }
    
    if(minCostpointofSplit!=-1)
    {
        // indexpointertemp[level] = valueofSplit;
        ordered.push_back(valueofSplit);
    }
    
    if(minCostForThisIndex==INT_MAX)
        return (dpTopDown[start][end]=0);
    
    

    return (dpTopDown[start][end]=minCostForThisIndex);
}

int
main ()
{
  int n, size;
  cin >> n;

  while (n != 0)
    {


      cin >> size;
      vector < int >ID;
      // ID.push_back(0);
      for (int i = 0; i < size; i++)
	{
	  int v;
	  cin >> v;
	  ID.push_back (v);
	}
      // ID.push_back(n);
      if (debug)
	{
	  cout << endl;
	  for (int i = 0; i < ID.size (); i++)
	    {
	      cout << ID[i] << "  ";
	    }
	  cout << endl;
	}



    //   cout << " Cutting Rod Recursive Solution : " << cutting_Rod_Recursion(ID,0,n) << endl;
    //   cout << " Cutting Rod Recursive Calls : " << noofrecusriveCalls << endl;


    //   int dpTopDown[1001][1001];
    //   memset(&dpTopDown[0][0],-1,sizeof(dpTopDown));
       
      vector < vector < int >>dpTopDown (n + 1, vector < int >(n + 1, -1));
       
        if(debug)
        {
    //   for(int i=0;i<=1000;i++)
    //   {
    //       for(int j=0;j<=1000;j++)
    //           if(dpTopDown[i][j]!=-1)
    //               cout << " NOt Allowed " << endl;
    //   }
        }

    vector<int> allIndexes;
      cout << "The minimum cutting is " << cutting_Rod_Recursion_top_down (ID, 0, n,dpTopDown,0,allIndexes) <<
	"." << endl;
    //   cout << "Recusrie Calls " << noofrecusriveCallsTopDown << "." << endl;

    // if(debug)
    {
         cout << " All Indexes " << endl;
         reverse(allIndexes.begin(),allIndexes.end());
        for(auto a:allIndexes)
        {
             cout << a << " && ";
        }
        cout << endl;
    }

      cin >> n;

    }

  return 0;
}



