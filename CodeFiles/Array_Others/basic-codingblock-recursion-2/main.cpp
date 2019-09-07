/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int debug=0;
template<typename T>
void print(T val)
{
    cout << val << " ";
}

void TOH(int disksleft,char src,char dest,char helper)
{
    if(disksleft==0) return;
    TOH(disksleft-1,src,helper,dest);
    cout << " Moving from " << src << " to " << dest << endl;
    TOH(disksleft-1,helper,dest,src);
}

void InputForTOH()
{
    int towers;
    cin >> towers;
    TOH(towers,'A','C','B');
}

void merge(int In[],int start,int mid,int end)
{
    if(start>end)
        return;
    if(debug)
    {
        cout << " Range going to get Sorted " << endl;
        cout << endl;        
        for(int i=start;i<=end;i++)
        {
            cout << In[i] << " *** ";
        }
        cout << endl;
    }
        
    int p1=start;
    int p2=mid+1;
    int index=0;
    int tempIn[end-start+1];
    while(p1<=mid && p2<=end)
    {
        if(In[p1]>In[p2])
            tempIn[index++] = In[p2++];
        else
            tempIn[index++] = In[p1++];
    }


    
    while(p1<=mid)
        tempIn[index++] = In[p1++];
        
    while(p2<=end)
        tempIn[index++] = In[p2++];
        
    for(int i=start;i<=end;i++)
    {
        In[start+i]=tempIn[i];
    }
    
}

void mergeSort(int In[],int start,int end)
{
    if(start>=end)
        return;
    int mid = (end+start)/2;
    
    if(debug)
        cout << "Indexes are :  start " << start << " mid " << mid << " end " << end << endl;
    
    mergeSort(In,start,mid);
    mergeSort(In,mid+1,end);
    merge(In,start,mid,end);
}

void InputForMergeSort()
{
    int size;
    cin >> size;
    int In[size];
    for(int i=0;i<size;i++)
    {
        int v;
        cin >> v;
        In[i] = v;
    }
    
    if(debug)
    {
        cout << " Input Array " << endl;
        for(int i=0;i<size;i++)
        {
            cout << In[i] << " : ";
        }
        cout << endl;
    }
    
    mergeSort(In,0,size-1);
    
    cout << " Output Array " << endl;
    for(int i=0;i<size;i++)
    {
        cout << In[i] << " : ";
    }
    cout << endl;
}

void getAllsubsequences(char Input[],char Output[],int i,int j)
{
    if(Input[i]=='\0')
    {
        Output[j]='\0';
        cout << Output << ",";
        return;
    }
    
    // Include the charcters in substring
    // we will incremament j  
    Output[j] = Input[i];
    getAllsubsequences(Input,Output,i+1,j+1);
    
    // Exclude elelment 
    // we will not increamnt j 
    getAllsubsequences(Input,Output,i+1,j);
}

void InputForSubsequencesofString()
{
    char Input[10000];
    char Output[10000];
    int i=0;
    string s;
    cin >> s;
    
    // will not be able to take input
    scanf("%s\n",&s);
    
    while(true)
    {
        char ch=s[i];
        if(s[i]=='\0')
            break;
        Input[i++] = ch;
    }
    for(int k=0;k<i;k++)
        cout << Input[k] << " ";
    cout << endl;
    getAllsubsequences(Input,Output,0,0);
}

// get all permutations 
// with repetitions 
void generateAllPermutationsWithrepetitions(vector<vector<int>> &res,
vector<int> &data,int index,int maxLength,
vector<int> &A)
{
    if(index>maxLength) return;
    if(data.size()==maxLength)
    {
        for(auto a:data)
            cout << a << " ";
        cout << endl;
        
        return;
    }
    for(int i=0;i<maxLength;i++)
    {
        data.push_back(A[i]);
        generateAllPermutationsWithrepetitions(res,data,i+1,maxLength,A);
        data.pop_back();
    }
}

void generateAllPermutations(vector<int> &A)
{
    vector<vector<int>> res;
    vector<int> data;
    int index=0;
    int indexy=0;
    int maxLength=A.size();
    generateAllPermutationsWithrepetitions(res,data,index,maxLength,A);
    for(auto a:res)
    {
        for(auto d:a)
            cout << d << " ";
        cout << endl;
    }
}

void InputForgenerateAllPermutations()
{
    int size;
    cin >> size;
    vector<int> In(size,0);
    for(int i=0;i<size;i++)
    {
        int v;
        cin >> v;
        In[i] = v;
    }
    
    cout << " Input " << endl;
    for_each(In.begin(),In.end(),print<int>);
    cout << endl << endl;
    
    cout << " Output " << endl;
    generateAllPermutations(In);
    
}

void getAllPermutationWithDFS(
    set<vector<int>> &setdata,
    vector<int> &data,
    int index,
    vector<bool> &visited,vector<int> &originalArray,
    int &count)
{
    data.push_back(originalArray[index]);
    visited[index]=true;
    
    bool alltrue=true;
    
    for(int i=0;i<originalArray.size();i++)
    {
        if(visited[i]==false)
        {
            alltrue=false;
            
            // cout << " Caling at " << i << endl;
            getAllPermutationWithDFS(setdata,data,i,visited,originalArray,count);
        }
    }
    
    
    if(alltrue==true)
    {
        // for(auto a:data)
        //     cout << a << " ";
        // cout << endl;
        
        if(true)
        {
            for(auto a:data)
                cout << a << " ";
            cout << endl;
            
            setdata.insert(data);
            count++;
        }
        // return;
    }
    
    data.pop_back();
    visited[index]=false;
}

int invokegetAllPermutationWithDFS(vector<int> &A)
{
    set<vector<int>> setdata;
    vector<int> D;
    vector<bool> visited(A.size(),false);
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        for(int i=0;i<A.size();i++) visited[i]=false;
        getAllPermutationWithDFS(setdata,D,i,visited,A,count);
    }
    return setdata.size();
}

void InputForDFSMethod()
{
    int size;
    cin >> size;
    vector<int> In(size,0);
    for(int i=0;i<size;i++)
    {
        int v;
        cin >> v;
        In[i] = v;
    }
    
    // https://www.interviewbit.com/problems/number-of-squareful-arrays/
    cout << " No of Permutations whose adjacent are perfect square " << invokegetAllPermutationWithDFS(In) << endl;
}

int main()
{
    debug=0;
    int option;
    cin >> option;
    cout << " 1 : Tower of Hanoi " << endl;
    cout << " 2 : Merge Sort " << endl;
    cout << " 3 : Subsequences of String " << endl;
    cout << " 4 : Invoke DFS Method for getting permutations " << endl;
    cout << " 5 : Generate Permutations with Repitions " << endl;
    
    if(option==1)
    {
        InputForTOH();
    }
    if(option==2)
    {
        InputForMergeSort();
    }
    if(option==3)
    {
        InputForSubsequencesofString();
    }
    if(option==5)
    {
        InputForgenerateAllPermutations();
    }
    if(option==4)
    {
        InputForDFSMethod();
    }
    
    return 0;
}

/*

5
5 3 2 1 3 5

4
5 3 2 1 3 5

*/

