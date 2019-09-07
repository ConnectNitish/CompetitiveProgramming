/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * Definition for an interval.
 *  */
struct Interval 
{
    int start;
    int end;
    
    Interval()
    {
        start = 0;
        end = 0;
    }
    
    Interval(int s, int e)
    {
        start =s;
        end = e;
    }
};

bool checkOverlapp(Interval a,Interval b)
{
    return (max(a.start,b.start) <= min(a.end,b.end));
}

// O(n) space and O(nlogn) time 
vector<Interval> copyMergeInterval(vector<Interval> e1,Interval newInterval)
{
    vector<Interval> newArray;
    
    if(e1.size()==0)
    {
        newArray.push_back(newInterval);
        return newArray;
    }
    
    int _l = e1.size();
    
    if(newInterval.end < e1[0].start)
    {
        newArray.push_back(newInterval);
        for(auto data:e1)
        {
            newArray.push_back(data);
        }
        return newArray;
    }
    
    if(e1[_l-1].end < newInterval.start)
    {
        newArray = e1;
        newArray.push_back(newInterval);
        return newArray;
    }

    bool _Overlapp = false;
    for(int i=0;i<_l;i++)
    {
        _Overlapp = checkOverlapp(e1[i],newInterval);
        
        // if it is overlapping then need to merge 
        // all subsequent intervals int the array 
        
        if(_Overlapp)
        {
            Interval toadd;
            toadd.start = min(e1[i].start,newInterval.start);
            
            while(i<_l && _Overlapp)
            {
                toadd.end = max(e1[i].end,newInterval.end);
                if(i==_l-1)
                    _Overlapp = false;
                else
                    _Overlapp = checkOverlapp(toadd,e1[++i]);
            }
            i--;
            newArray.push_back(toadd);
        }
        else
        {
            newArray.push_back(e1[i]);
            
            if(i<_l &&
            e1[i].end < newInterval.start &&
            newInterval.end < e1[i+1].start)
            {
                newArray.push_back(newInterval);
            }
            
        }
    }
    
    return newArray;
}

// O(1) space and O(logn) time 
vector<Interval> insert(vector<Interval> &e1,Interval newInterval)
{
    vector<Interval> newArray;
    
    if(e1.size()==0)
    {
        // newArray.push_back(newInterval);
        // return newArray;
        
        e1.push_back(newInterval);
        return e1;
    }
    
    int _l = e1.size();
    
    if(newInterval.end < e1[0].start)
    {
        // newArray.push_back(newInterval);
        // for(auto data:e1)
        // {
        //     newArray.push_back(data);
        // }
        // return newArray;
        
        e1.insert(e1.begin(),newInterval);
        return e1;
        
    }
    
    if(e1[_l-1].end < newInterval.start)
    {
        // newArray = e1;
        // newArray.push_back(newInterval);
        // return newArray;
        
        
        e1.push_back(newInterval);
        return e1;
    }

    bool _Overlapp = false;
    Interval toadd;
    int startIndex=-1;
    int endIndex=-2;
    int startIndextoInsert = -1;
    for(int i=0;i<_l;i++)
    {
        _Overlapp = checkOverlapp(newInterval,e1[i]);
        
        // if it is overlapping then need to merge 
        // all subsequent intervals int the array 
        
        if(_Overlapp)
        {
            
            toadd.start = min(e1[i].start,newInterval.start);
            toadd.end = max(e1[i].end,newInterval.end);
            startIndex = i;
            
            while(i<_l && _Overlapp)
            {
                toadd.end = max(e1[i].end,newInterval.end);
                if(i==_l-1)
                    _Overlapp = false;
                else
                    _Overlapp = checkOverlapp(toadd,e1[i+1]);
                i++;
            }
            i--;
            endIndex = i;
            //newArray.push_back(toadd);
        }
        else
        {
            newArray.push_back(e1[i]);
            
            if(i<_l &&
            e1[i].end < newInterval.start &&
            newInterval.end < e1[i+1].start)
            {
                //newArray.push_back(newInterval);
                startIndextoInsert = i;
            }
            
        }
    }
    
    if(endIndex - startIndex>0)
    {
        e1.erase(e1.begin()+startIndex+1,e1.begin()+endIndex+1);
        e1[startIndex] = toadd;
    }
    else if(endIndex - startIndex == 0)
    {
        e1[startIndex] = toadd;
    }
    else if(startIndextoInsert!=-1)
    {
        e1.insert(e1.begin()+startIndextoInsert+1,newInterval);    
    }
    
    return e1;
    //return newArray;
}

// Input need not be sorted at initials 
bool _sort(const Interval a,const Interval b)
{
     if(a.start == b.start)
        return a.end < b.end;
     return a.start < b.start;
}

int _min(int a,int b)
{
    return a<=b ? a : b;
}

int _max(int a,int b)
{
    return a>=b ? a : b;
}

vector<Interval> merge(vector<Interval> &A) 
{
    sort(A.begin(),A.end(),_sort);

/*
    for(int i=0;i<A.size();i++)
    {
        printf("%d",A[i].start);
        printf(" %d\n",A[i].end);
    }

*/

    int index=0;
    for(int i=0;i<A.size();i++)
    {
        //cout << i << ":::::" << endl;
        int current  = i;
        int overlap = 0;
        while(i>0 && (i)<A.size() && A[i].start <= A[current-1].end)
        {
            //cout << i << " ----- " <<  A[i].start << ":" << A[i].end << endl;
            
            A[current-1].start = _min(A[i].start,A[current-1].start);
            A[current-1].end = _max(A[i].end,A[current-1].end);
            i++;
            overlap = 1;
        }
        if(overlap == 1)
        {
            A[index-1] = A[current-1];
            i--;
        }
        else
        {
            //cout << i << " --ttt--- " <<  A[i].start << ":" << A[i].end << endl;
            
            A[index] = A[current];
            index++;
        }
    }
    
    vector<Interval> _r;
    for(int i=0;i<index;i++)
    {
        _r.push_back(A[i]);
    }
    
    return _r;
}

int main()
{
    int n;
    int sI,eI;
    scanf("%d",&n);
    int i=n;
    std::vector<Interval> _data;
    Interval toInsert;
    while(i>0)
    {
        
        scanf("%d",&sI);
        scanf("%d",&eI);
        //printf(" Input Number:%d",i);
        //printf(" start Value %d End Value %d \n",sI,eI);
        toInsert = Interval(sI,eI);
        _data.push_back(toInsert);
        i--;
    }

/*
    https://www.geeksforgeeks.org/insert-in-sorted-and-non-overlapping-interval-array/
    scanf("%d",&sI);
    scanf("%d",&eI);
    //printf(" Staruct start Value %d End Value %d \n",sI,eI);
    
    toInsert=Interval(sI,eI);


    _data = copyMergeInterval(_data,toInsert);
    
    for(i=0;i<_data.size();i++)
    {
        printf("%d",_data[i].start);
        printf(" %d\n",_data[i].end);
    }
*/
    
    /*
    https://www.interviewbit.com/problems/merge-overlapping-intervals/
    */
    _data = merge(_data);
    
    for(i=0;i<_data.size();i++)
    {
        printf("%d",_data[i].start);
        printf(" %d\n",_data[i].end);
    }
    
    return 0;
}

