/******************************************************************************



*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int debug = 0;

// not be able to genearte all the 
// permutations 
// genrate more possibilities  
void genAllPermutation(
    set<string> &res,char Input[],char Output[],int i,int j,
    map<char,vector<char>> &metadata)
    {
        if(Input[i]=='\0')
        {
            Output[j]='\0';
            string s="";
            for(int k=0;k<j;k++)
                s+=Output[k];
                
            if(debug)
                for(int k=0;k<j;k++)
                    cout << Output[k] << " : ";
                
            res.insert(s);
            return;
        }
        
        for(auto a:metadata[Input[i]])
        {
            Output[j]=a;
            genAllPermutation(res,Input,Output,
            i+1,j+1,metadata);
        }
    }
    
    
void getAllPerm(char Input[],int i)
{
    if(Input[i]=='\0')
    {
        cout << Input << ",";
        return;
    }
    
    for(int j=i;Input[j]!='\0';j++)
    {
        swap(Input[i],Input[j]);
        
        // now here array is modified 
        getAllPerm(Input,i+1);
        
        // restoreing the original state 
        // of array 
        // bactrack the array 
        swap(Input[i],Input[j]);
    }
}

int main()
{
    debug = 0;
    string s;
    cin >> s;
    
    int size=s.length();
    
    if(debug)
        cout << " Data " << s << " size " <<  size << endl;
    
    vector<char> data;
    char Input[size+1];
    char Output[size+1];
    int i=0;
    while(i<size)
    {
        data.push_back(s[i]);
        Input[i]=s[i];
        i++;
    }
    Input[i]='\0';
    
    map<char,vector<char>> metadata;
    
    int index=0;
    for(auto a:s)
    {
        vector<char> dataCopy = data;
        // vector<char>::iterator itr = find(dataCopy.begin(),dataCopy.end(),a);
        // dataCopy.erase(itr,itr+1);
        metadata[a]=dataCopy;
    }
    
    // set<string> &res,char Input[],char Output[],int i,int j,
    // map<char,vector<char>> &metadata;
    
    if(debug)
        for(auto a:metadata)
            cout << a.first << " : " << a.second.size() << endl;
    
    set<string> res;
    
    i=0;
    int j=0;
    cout << " Not All Perm " << endl;
    genAllPermutation(res,Input,Output,i,j,metadata);
    
    for(auto s:res)
        cout << s << ",";
    cout << endl;
    
    cout << " All Perm " << endl;
    getAllPerm(Input,i);

    return 0;
}
