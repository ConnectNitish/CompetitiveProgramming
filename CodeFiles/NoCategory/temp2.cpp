// https://www.geeksforgeeks.org/given-two-strings-find-first-string-subsequence-second/

/*

Given two string xyz and xyxyz 
Find min steps to make xyxyz from 
xyz or its subsequences 

ex. xyxyz == "xy" + "xyz" ( Answer : 2)  

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	unordered_map<string,bool> patterns;


	string subsequence(string s, int binary) 
	{ 
	    string sub = ""; 
	    int pos; 
	      
	    while(binary>0) 
	    {  
	        pos=log2(binary&-binary)+1; 
	        sub=s[pos-1]+sub; 
	        binary= (binary & ~(1 << (pos-1))); 
	    } 
	    reverse(sub.begin(),sub.end()); 
	    return sub; 
	} 
	  
	void possibleSubsequences(string s){ 
	  
	    map<int, set<string> > sorted_subsequence; 
	  
	    int len = s.size(); 
	    int limit = pow(2, len); 
	    for (int i = 1; i <= limit - 1; i++) 
	    {  
	        string sub = subsequence(s, i);
	        sorted_subsequence[sub.length()].insert(sub); 
	        patterns[sub] = true;
	    } 
	  
	    // for (auto it : sorted_subsequence)
	    // {  
	    //     patterns[it.second] = true;
	    // } 
	} 

    int minimumConcat(string initial, string goal)
    {
    	patterns.clear();
        possibleSubsequences(initial); // 2^10 

        int ptr=0;
        int founds=0;

        int data[26];
		int data2[26];

		for(int i=0;i<26;i++)
			data2[i] = data[i] = 0;

		for(auto a:initial)
			data2[a-'a']=1;

		for(auto a:goal)
			data[a-'a']=1;

		for(int i=0;i<26;i++)
			if(data2[i]!=data[i])
				return -1;

        string temp="";

        while(ptr<goal.length())
        {
        	temp += goal[ptr];
        	if(patterns.find(temp) == patterns.end())
        	{
        		founds++;
        		temp = goal[ptr];
        	}
        	ptr++;
        }

        return founds>0?founds+1:founds;
    }
};

int main()
{
    string patt,target;
    cin >> patt >> target;
   
    Solution s;
    cout << s.minimumConcat(patt,target) << endl;
}