/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<string> _ID)
{
    for(auto i=_ID.begin();i!=_ID.end();++i)
        cout << *i << " ";
    cout << endl;
}

//Input : qqq12 wer1 qwe345 qs a1111cv u77777777ia a bbbfff

int main()
{
    vector<string> _ID;
    copy(istream_iterator<string>(cin),istream_iterator<string>(),back_inserter(_ID));
    
    cout << "Analysising The Copy Command" << endl;
    
    vector<string> _tempID(_ID.size());
    copy(_ID.begin(),_ID.end(),_tempID.begin());
    print(_ID);
    print(_tempID);
    
    cout << "Analysising The Sort Command" << endl;
    
    //equivalent to copy 
    vector<string> _tempID1 = _ID;
    sort(_tempID1.begin(),_tempID1.end());
    print(_ID);
    print(_tempID1);
    
    cout << "Analysising The Reverse Sort Command" << endl;
    
    vector<string> _tempID2 = _ID;
    sort(_tempID2.begin(),_tempID2.end(),greater<string>());
    print(_ID);
    print(_tempID2);
    
    cout << "Analysising The Sort Using Lambda Function ( Sorting on Basis of length ) " << endl;
    
    //sort using lambda function 
    vector<string> _tempID3 = _ID;
    sort(_tempID3.begin(),_tempID3.end(),
    [](const string& left,const string& right)
    {
        return left.length() < right.length();
    }
    );
    print(_ID);
    print(_tempID3);
    
    cout << "Analysising The Stable Sort Using Lambda Function ( Sorting on Basis of length ) " << endl;
    
    //sort using lambda function 
    vector<string> _tempID4 = _ID;
    stable_sort(_tempID4.begin(),_tempID4.end()
    ,[](const string& left,const string& right)
    {
        return left.length() < right.length();
    }
    );
    print(_ID);
    print(_tempID4);
    
    
    

    return 0;
}

