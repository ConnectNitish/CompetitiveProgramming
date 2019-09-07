/******************************************************************************


*******************************************************************************/
#include <iostream>
using namespace std;

void testarray(int *arr)
{
    arr[0] = ( arr[0] + 10 );
}

void testvar(int &arr)
{
    arr = ( arr + 100 );
}




int main()
{
   int arr[3]={1,2,3};
   
   int n=99;
    int &c = n;

    cout << " c " << c << endl;
    
    c = 1000;
    
    cout << " c " << c << endl;
    cout << " n post c modification " << n << endl;
    
    cout << arr[0] << endl;
    cout << "n" << n << endl;
    
    // testarray(arr);
    testvar(n);

    cout << arr[0] << endl;
    
    cout << "n" << n << endl;

    return 0;
}
