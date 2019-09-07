/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

//input 
//a111 b1234 111c111 123d321

template<typename T>
void print(T value)
{
    cout << value << " ";
}

template<typename T>
bool checkPalindrome(T value)
{
    int _len = value.length()-1;
    int _start = 0;
    if(_len<=0) return true;
    while(_start<_len)
    {
        if(value[_start]!=value[_len])
            return false;
        _start++;
        _len--;
    }
    return true;
}

template<typename T>
bool checkIfStringIsPalindrome(T value)
{
    return checkPalindrome(value);
}

int main()
{

    //taking input from cin 
    vector<string> _ID;

    //istream_iterator present in iterator
    copy(istream_iterator<string>(cin),istream_iterator<string>(),back_inserter(_ID));
    
    //present in <algorithm> 
    cout << "Print using For Each Iterator " << endl;
    for_each(_ID.begin(),_ID.end(),print<string>);

    cout << endl;

    //Constant Iterator : Its Read Only Iterator 
    cout << "Print using Constant For Each Iterator (Read Only and Fast ) " << endl;
    for_each(_ID.cbegin(),_ID.cend(),print<string>);

    cout << endl;

    // if find_if return iterator where first match is performed 
    // if no match is found for the iterator then iterator will be at the end 
    cout << "Use of find_if iterator and check whther input is containng any plaindrome string or not " << endl;
    vector<string>::iterator itrSearch = find_if(_ID.begin(),_ID.end(),checkIfStringIsPalindrome<string>);
    
    if(itrSearch!=_ID.end())
        cout << *itrSearch << endl;
    
    cout << "In case none of the condition is satisfied then iterator willbe at end()" << endl;
    cout << "Location of iterator " << itrSearch - _ID.begin() << endl;
    
    cout << "Post sort function " << endl;
    sort(_ID.begin(),_ID.end());
    for_each(_ID.cbegin(),_ID.cend(),print<string>);

    cout << "Post Reverse function " << endl;
    reverse(_ID.begin(),_ID.end());
    for_each(_ID.cbegin(),_ID.cend(),print<string>);
    
    return 0;
}



