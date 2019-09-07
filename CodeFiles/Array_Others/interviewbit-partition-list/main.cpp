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

struct ListNode 
{
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public : 
    //int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
    ListNode* partition(ListNode* A, int B);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

ListNode* Solution::partition(ListNode* A, int B) 
{
    ListNode* ptrgreater = NULL;
    ListNode* ptrSmall = NULL;
    
    ListNode* headptrgreater = NULL;
    ListNode* headptrSmall = NULL;
    
    ListNode* curr=A;
    ListNode* result=NULL;
    
    ListNode* tempGreater=NULL;
    ListNode* tempSamller=NULL;
    
    while(curr!=NULL)
    {
        if(curr->val>=B)
            tempGreater = curr;
        else
            tempSamller = curr;
        
        curr = curr->next;
        
        if(tempSamller!=NULL)
        {
            if(ptrSmall==NULL)
            {
                ptrSmall = tempSamller;
            }
            else
            {
                ptrSmall->next = tempSamller;
                ptrSmall=ptrSmall->next;
            }
        }
        
        if(tempGreater!=NULL)
        {
            if(ptrgreater==NULL)
            {
                ptrgreater = tempGreater;
            }
            else
            {
                ptrgreater->next = tempGreater;
                ptrgreater = ptrgreater->next;
            }
        }
        
        if(headptrgreater==NULL)
            headptrgreater = ptrgreater;
        else if(headptrSmall==NULL)
            headptrSmall = ptrSmall;
                
        tempGreater=NULL;
        tempSamller=NULL;
        
        
    }
    
        
    if(ptrSmall!=NULL && ptrSmall->next==NULL)
        ptrSmall->next = headptrgreater;
    
    return headptrSmall;
}

int main()
{
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    s.solve(ID);
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}




