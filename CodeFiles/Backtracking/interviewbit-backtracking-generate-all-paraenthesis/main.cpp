/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution
{
    public : 
    //int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
    int generateParenthesis(int A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int debug=0;

bool checkValid(string patternCopy,bool perfect)
{
    stack<char> data;
    int i=0;
    
    if(debug)
        cout << " pattern Came " << patternCopy << endl; 
    
    
    
    string pattern(patternCopy);
    
    int length=pattern.length();
    
    if(debug)
        cout << length << endl;
    
    while(i<length)
    {
        if(debug)
            cout << i << " index " << endl;
        
        if(data.empty()==true)
        {
            if(pattern[i]==')')
                return false;
            else 
                data.push(pattern[i]);
        }
        else
        {
            if(debug)
            {
                cout << " Stack Size " << data.size() << endl;
                cout << " Stack Data " << data.top() << endl;
                cout << " Stack Size " << data.size() << endl;    
            }
            if(pattern[i]==')' && data.top()=='(')
                data.pop();
            else
                data.push(pattern[i]);
        }
        i++;
    }
    
    if(perfect)
    {
        if(data.empty()==true)
            return true;
        return false;
    }
    return true;
}

string generateShortString(string str)
{
    if(debug)
    cout << " ---- " << str << endl;
    
    int length = str.length();
    for(int i=length-1;i>=0;i--)
    {
        if(i-1>=0 && str[i-1] == '(' && str[i]==')')
        {
            str[i-1]='$';
            str[i]='$';
        }
    }
    string strData="";
    for(int i=0;i<length;i++)
    {
        if(str[i]!='$')
            strData += str[i];
    }
    
    return strData;
}

bool allSamegreaterthanLength(string str,int length)
{
    int mid = length/2;
    int i=0;
    int count=0;
    while(str[i]!='\0')
    {
        if(str[i]=='(')
            count++;
        if(count>mid)
            return false;
        i++;
    }
    return true;
}

// Giving TLE 
// because we are genrating all possible 2^2n combinations
void genParen(vector<string> &res,string data,int maxLength,int index
,string shortString)
{
    if(data.length()>maxLength)
        return;
    
    if(shortString.length()>0 && shortString[0]==')')
        return;
        
    // if(shortString.length()>0 
    // && allSamegreaterthanLength(shortString,maxLength)==false)
    //     return;
    
    if(data.length()==maxLength)
    {
        // if(checkValid(data,true))
        // cout << data << ":" << checkValid(data,true) << endl;
        res.push_back(data);
        
        // res.push_back(data);
        
        return;
    }
    
    // if(data.length()>0 && checkValid(data,false)==false)
    //     return;
    
    for(int i=index;i<(maxLength)-1;i++)
    {
        if(allSamegreaterthanLength(data+'(',maxLength)==true)
            genParen(res,data+'(',maxLength,i+1,generateShortString(shortString+'('));
    }
        
    for(int i=index;i<(maxLength);i++)
    {
        if(data.length()>0 && allSamegreaterthanLength(data+')',maxLength)==true)
            genParen(res,data+')',maxLength,i+1,generateShortString(shortString+')'));
    }
    
}

// we will only generate 2n combinations 
void genParenM2(set<string> &res,int open,int close,int maxLength,string output)
{
    if(open>(maxLength) || close>(maxLength))
        return;
        
    if(open ==(maxLength) && close==(maxLength))
    {
        // open.append(close);
        // if(checkValid(open,true))
        res.insert(output);
        return;
    }
    
        // genParenM2(res,open+'(',close,maxLength);
        // genParenM2(res,open+')',close,maxLength);
        // genParenM2(res,open,close+')',maxLength);
        // genParenM2(res,open,close+'(',maxLength);
        
        // because in 2n length #of max open will be 
        // not more than n 
        if(open<maxLength)
            genParenM2(res,open+1,close,maxLength,output+'(');        
        
        // at any point of time 
        // no of close will be less than less than or equal to open 
        // not greater than open 
        if(close<open)
            genParenM2(res,open,close+1,maxLength,output+')');

}


vector<string> Solution::generateParenthesis(int A) 
{
    vector<string> res;
    string data="";
    string tempdata="";
    // genParen(res,data,2*A,0,tempdata);
    
    set<string> setres;
    int open=0;
    int close=0;
    genParenM2(setres,open,close,A,data);
    
    res.clear();
    
    for(auto a:setres)
        res.push_back(a);
    
    return res;
}


int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    
   int N;
   cin >> N;
   Solution s;
   vector<string> data = s.generateParenthesis(N);
   
   for_each(data.begin(),data.end(),print<string>);
}




