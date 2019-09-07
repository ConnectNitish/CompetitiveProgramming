/******************************************************************************

https://www.interviewbit.com/problems/allocate-books/

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
    public : 
    int books(vector<int> &A,int B);
    //vector<int> solve(vector<int> &A);
};

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int debug=0;

bool checkAllocation(int maxPages,int students,vector<int> &A
,int &maxPagesByStudent_result
,int &noofstudents)
{
    // int noofstudents=0;
    int index=0;
    int maxPagesByStudent = A[index];
    
    vector<vector<int>> studentsadata;
    vector<int> r;
    studentsadata.push_back(r);
    r.push_back(maxPagesByStudent);
    studentsadata.push_back(r);
    
    noofstudents++;
    index++;
    
    while(index<A.size())
    {
        
        
        if(debug)
        {
            // cout << " maxPagesByStudent+A[index]>maxPages "
            // << maxPagesByStudent+A[index] << " sss " << maxPages << endl;
            
            // cout << " index " << index << " A[index] " << A[index] << endl;
                
        }
        
        if((maxPagesByStudent+A[index])>maxPages)
        {
            // if(debug)
            // cout << " New Students " << endl;
            
            
            vector<int> rr;
            rr.push_back(A[index]);
            studentsadata.push_back(rr);
            
            noofstudents++;
            maxPagesByStudent_result = max(maxPagesByStudent_result,maxPagesByStudent);
            maxPagesByStudent = 0;
            
            maxPagesByStudent=A[index];
        }
        else 
        {
            studentsadata[noofstudents].push_back(A[index]);
            
            maxPagesByStudent += A[index];
        }
        
        // if(debug)
        //     cout << " Next Loop " << endl;
        
        index++;
    }
    
    // if(maxPagesByStudent>=maxPages)
    // {
    //     students++;
    // }

    if(debug && abs(noofstudents-students)<=1)
    {
        int i=1;
        for(auto a:studentsadata)
        {
            cout << " MaxPages " << maxPages << " Student : "<< i << " : " ;
            for(auto ab:a)
            {
                cout << ab << " ";
            }
            cout << endl;
            i++;
        }
    }
    
    maxPagesByStudent_result = max(maxPagesByStudent_result,maxPagesByStudent);
    
    if(debug)
    {
        // cout << "  Max Value " << maxPagesByStudent_result << endl;
        // cout << " MaxPages " << maxPages << endl;
        // cout << " NOofStudents " << noofstudents << endl;
    }
    
    return (noofstudents==students);
}

int Solution::books(vector<int> &A, int B) 
{
    if(A.size()<=0)
        return 0;
        
    // sort(A.begin(),A.end());
    long long avg=0;
    int maxNumber = INT_MIN;
    int minNUmber = INT_MAX;
    
    for(int i=0;i<A.size();i++)
    {
        avg += A[i];
        maxNumber = max(maxNumber,A[i]);
        minNUmber = min(minNUmber,A[i]);
    }
    
    // no of Students equal to no of books 
    if(B==A.size())
    {
        // max Page number book is returned 
        return maxNumber;
    }
    
    if(B==1)
    {
        return avg;
    }
    
    int maxPageNumber=INT_MAX;
    int start = minNUmber;
    int end = avg;
    
    while(start<=end)
    {
        int mid = start + ((end-start)>>1);
        
        if(debug)
            cout << " start " << start << " mid " << mid << " end " << end << endl;
        
        int maxPagesByStudent_result=0;
        int noofstudents=0;
        bool isallowed = checkAllocation(mid,B,A,maxPagesByStudent_result,
        noofstudents);
        
        if(debug)
        {
            cout << " noofstudents " << noofstudents << endl;
            cout << " maxPagesByStudent_result " << maxPagesByStudent_result << endl;
        }
        
        if(noofstudents==B)
            maxPageNumber = min(maxPageNumber,maxPagesByStudent_result);
            
        
         if(start==end)
            break;
        
        // few studnts are able to read all pages 
        // it shows my no of pages need to reduced 
        if(noofstudents<=B)
        {
            // if(debug)
            //     cout << "  Max Value T:" << maxPagesByStudent_result << endl;
    
            end = mid-1; 
        }
        // more studnts are considerd for taking 
        // up all pages of the book 
        // it means each students is reading less number 
        // of pages so increase the no of pages 
        else if(noofstudents>B)
        {
            // if(debug)
            //     cout << "  Max Value F:" << maxPagesByStudent_result << endl;
    
            start = mid+1;
        }
        if(debug)
            cout << " POST start " << start << "  end " << end << endl;
       
    }
    
    if(maxPageNumber==INT_MAX)
        return -1;
    
    return maxPageNumber;
    
}




int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    
    vector<int> ID;
    
    for(int i=0;i<N;i++)
    {
        int V;
        cin >> V;
        ID.push_back(V);
    }
    int B;
    cin >> B;
    Solution s;
    cout << " Min Pages "  << s.books(ID,B) << endl;
    
    // cout << "Print using For Each Iterator " << endl;
    // for_each(ID.begin(),ID.end(),print<int>);
}

/*
Input 1:
7 3 32 32 41 54 77 17
4
Output 1:

*/



