#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    
    stack<pair<char,int>> st;
    
    int debug=0;

    string removeDuplicates(string s, int k) 
    {
        st = stack<pair<char,int>>();
        
        int l = s.length();

        for(int i=0;i<l;i++)
        {
        	if(debug)
        	{
        		cout << " Index " << i << endl;
        	}
            char ch = s[i];

            if(st.empty()==true)
            {
                st.push({ch,1});
            }
            else
            {
                pair<char,int> stcktop = st.top();

                if(stcktop.first==ch)
                {
                    // sum reached to k-1 
                    // an seen 1 more current Character 
                    if(stcktop.second == k-1)
                    {
                        // removing till that charcter is seen 
                        while(stcktop.first==ch)
                        {
                            st.pop();    
                            if(st.empty()==true)
                            	break;
                            stcktop = st.top();
                        }
                    }
                    // existing Chacretre Increamenting by 1
                    else
                    {
                        st.push({ch,stcktop.second+1});
                    }
                }
                // new Character Comes In 
                else
                {
                    st.push({ch,1});
                }
            }
        }
        
        string final_data = "";
        
        while(st.empty()==false)
        {
            final_data += (st.top().first);
            st.pop();
        }
        
        
        
        reverse(final_data.begin(),final_data.end());
        
        // final_data += '\0';
        
        return final_data;
        
    }
};

int main()
{
	string s1;
	cin >> s1;
	int k;
	cin >> k;

	Solution s;
	cout << s.removeDuplicates(s1,k) << endl;

	return 0;
}

/*

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

*/

