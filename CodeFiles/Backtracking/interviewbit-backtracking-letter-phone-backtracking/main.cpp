/******************************************************************************

https://www.interviewbit.com/problems/letter-phone/

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

int debug=0;

class Solution {
public:
    
    // method 1 
    void genAll(vector<string> &res,int index,
                    string &digits,map<char,vector<char>> &metadata,
                   vector<char> tempres)
    {
        if(tempres.size()==digits.length())
        {
            string s="";
            
            for(auto a:tempres)
                s += a;
            
            
            res.push_back(s);
            return;
        }
        
        for(int i=index;i<digits.length();i++)
        {
            vector<char> data = metadata[digits[i]];
            if(data.size()>0)
            {
                for(auto a:data)
                {
                    tempres.push_back(a);
                    genAll(res,i+1,digits,metadata,tempres);
                    tempres.pop_back();
                }
            }
        }
    }
    
    // method 2 
    void genAllM2(char Input[],char Output[],int i,int j,vector<string> &result,
    int size,map<char,vector<char>> &metadata)
    {
        // Base Case 
        // length is achieved 
        // ie NULL is encountered 
        if(Input[i]=='\0')
        {
            Output[j]='\0';
            string s="";
            for(int k=0;k<j;k++)
            {
                s += Output[k];
            }
            result.push_back(s);
            return;
        }
        
        // iterate through all the charcters 
        // one by one 
        for(auto a:metadata[Input[i]])
        {
            Output[j] = a;
            genAllM2(Input,Output,i+1,j+1,result,size,metadata);
        }
    }
    
    vector<string> letterCombinationsM2(string digits)
    {
        vector<string> res;
        int index=0;
        map<char,vector<char>> metadata;
        vector<char> tempres;
        
        tempres.clear();
        tempres = {'1'};
        metadata[1+'0']=tempres;
        
        tempres.clear();
        tempres = {'0'};
        metadata[0+'0']=tempres;
        
        tempres.clear();
        tempres.push_back('a');tempres.push_back('b');tempres.push_back('c');
        metadata[2+'0']=tempres;
        
        tempres.clear();
        tempres.push_back('d');tempres.push_back('e');tempres.push_back('f');
        metadata[3+'0']=tempres;
        
        tempres.clear();
        tempres = {'g','h','i'};
        metadata[4+'0']=tempres;
        
        tempres.clear();
        tempres = {'j','k','l'};
        metadata[5+'0']=tempres;
        
        tempres.clear();
        tempres = {'m','n','o'};
        metadata[6+'0']=tempres;
    
        tempres.clear();
        tempres = {'p','q','r','s'};
        metadata[7+'0']=tempres;
        
        tempres.clear();
        tempres = {'t','u','v'};
        metadata[8+'0']=tempres;
        
        tempres.clear();
        tempres = {'w','x','y','z'};
        metadata[9+'0']=tempres;
        
        // if(debug)
        //     for(auto a:metadata)
        //         cout << a.first << " " << a.second.size() << endl;
        
        int size = digits.size();
        
        char Input[size];
        char Output[size];
        int i=0;
        
        while(digits[i]!='\0')
        {
            Input[i] = digits[i];
            i++;
        }
        
        
        i=0;
        
        if(debug)
            while(Input[i]!='\0')
                cout << Input[i++] << ":";
        
        i=0;
        
        int j=0;
        tempres.clear();
        genAllM2(Input,Output,i,j,res,size,metadata);
        
        return res;        
    }
    
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        int index=0;
        map<char,vector<char>> metadata;
        vector<char> tempres;
        
        tempres.clear();
        tempres = {'1'};
        metadata[1+'0']=tempres;
        
        tempres.clear();
        tempres = {'0'};
        metadata[0+'0']=tempres;
        
        tempres.clear();
        tempres.push_back('a');tempres.push_back('b');tempres.push_back('c');
        metadata[2+'0']=tempres;
        
        tempres.clear();
        tempres.push_back('d');tempres.push_back('e');tempres.push_back('f');
        metadata[3+'0']=tempres;
        
        tempres.clear();
        tempres = {'g','h','i'};
        metadata[4+'0']=tempres;
        
        tempres.clear();
        tempres = {'j','k','l'};
        metadata[5+'0']=tempres;
        
        tempres.clear();
        tempres = {'m','n','o'};
        metadata[6+'0']=tempres;
    
        tempres.clear();
        tempres = {'p','q','r','s'};
        metadata[7+'0']=tempres;
        
        tempres.clear();
        tempres = {'t','u','v'};
        metadata[8+'0']=tempres;
        
        tempres.clear();
        tempres = {'w','x','y','z'};
        metadata[9+'0']=tempres;
        
        // if(debug)
        //     for(auto a:metadata)
        //         cout << a.first << " " << a.second.size() << endl;
        
        tempres.clear();
        genAll(res,index,digits,metadata,tempres);
        
        return res;        
    }
};



template<typename T>
void print(T value)
{
    cout << value << " ";
}


int main()
{
    debug = 1;
    string st;
    cin >> st;
    Solution s;
    vector<string> ID;
    // ID = s.letterCombinations(st);
    
    cout << "M1 Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<string>);
    cout << endl;

    
    ID = s.letterCombinationsM2(st);
    
    cout << "M2 Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<string>);
}




