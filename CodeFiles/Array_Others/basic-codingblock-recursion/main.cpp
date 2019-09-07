/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

int debug=0;

bool checkSorted(int *a,int n)
{
    if(n==1)
        return true;
    if(debug)
    {
        for(int i=0;i<n;i++)
        {
            cout << a[i] << " $$ " ;
        }
    }
    
    cout << endl;
     if(a[0]<=a[1] && checkSorted(a+1,n-1)) 
        return true;
    return false;
}

void performCheckSortedInput()
{
    int N;
    cin >> N;
    
    vector<int> D;
    // get all the input in Vector
    while(N-->0)
    {
        int T;
        cin >> T;
        D.push_back(T);
    }
    // cout << D.size() << endl;
    
    int data[D.size()];// = new int[D.size()];
    // int i=0;
    for(int i=0;i<D.size();i++)
    {
        data[i] = D[i];
        // i++;
    }
    
    cout << " Is Array Sorted " << checkSorted(data,D.size()) << endl;
    
}

#define ll long long 

ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    return a*power(a,b-1);
}

ll fastpower(ll a,ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ll small = power(a,b/2);
    if(b%2==1)
        return (a * small * small);
    return small * small;
}

void performpowerInput()
{
    ll a;
    ll b;
    scanf("%lld",&a);
    scanf("%lld",&b);
    cout << a << " power " << b << " is " << power(a,b) << endl;
}

void performfastpower()
{
    ll a;
    ll b;
    scanf("%lld",&a);
    scanf("%lld",&b);
    cout << a << " power " << b << " is " << fastpower(a,b) << endl;
}

int multiplicationusingrecusrion(int a,int b)
{
    if(b==0)
    {
        return 0;
    }
    return a + multiplicationusingrecusrion(a,(b-1));
}

void performInputMul()
{
    int n1;
    int n2;
    cin >> n1 >> n2;
    
    cout << n1 << n2 << endl;
    
    bool isNegative = false;
    if(n1<0)
    {
        if(n2>0)
            isNegative = true;
    }
    else
    {
        if(n2<0)
            isNegative=true;
    }
            
    int res = multiplicationusingrecusrion(abs(n1),abs(n2));
    if(isNegative)
        res = (-1) * res;
    
    cout << " Multiplication " << res << endl;
    
}

void stringtoInt(string s,int index,int &value)
{
    if(s.length()-1==index)
    {
        value = value*10 + (s[index]-'0');
        return;
    }
    value = value*10 + (s[index]-'0');
    // cout << " TEMP " << value << endl;
    stringtoInt(s,index+1,value);
}

void performStringToInt()
{
    string s;
    cin >> s;
    
    cout << " Input " << s << endl;
    
    if(s.length()==0)
        return;
    
    int isNegative=1;
    if(s[0]=='-')
    {
        isNegative=-1;
        string stemp="";
        int length = s.length();
        int i=1;
        while(i<length)
        {
            stemp += s[i++];
        }
        s = stemp;
    }
    
    int res=s[0]-'0';
    
    
    if(s.length()==1)
    {
        cout << " Intger form is " << isNegative*res << endl;
        return;
    }
    
    stringtoInt(s,1,res);
    
    cout << " Intger form is " << isNegative*res << endl;
    
}

void performBubbleSortRecursive(int a[],int n)
{
    if(n==1)
        return;
    for(int j=0;j<=(n-2);j++)
        if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
            
    performBubbleSortRecursive(a,n-1);
}

void performInputforBubbleSort()
{
    int size;
    cin >> size;
    
    int D[size];
    
    for(int i=0;i<size;i++)
    {
        int V;
        cin >> V;
        D[i]=V;
    }
    
    performBubbleSortRecursive(D,size);
    
    for(int i=0;i<size;i++)
        cout << D[i] << " ";
    cout << endl;
}

void performBubbleSortFullRecursive(int a[],int n,int j)
{
    if(n==1)
        return;
    
    if(j==n-1)
    {
        // array length will be reduced by 1 
        // and j will go to 0 
        performBubbleSortFullRecursive(a,n-1,0); 
        return;
    }   
    
    if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    
    // only j will change 
    // array length will not be reduced 
    performBubbleSortFullRecursive(a,n,j+1);
}

void performInputforFullRecursiveBubbleSort()
{
    int size;
    cin >> size;
    
    int D[size];
    
    for(int i=0;i<size;i++)
    {
        int V;
        cin >> V;
        D[i]=V;
    }
    
    performBubbleSortFullRecursive(D,size,0);
    
    for(int i=0;i<size;i++)
        cout << D[i] << " ";
    cout << endl;
}

int main()
{
    debug = 0;
    int Option;
    cout << " Enter the Option " << endl;
     cout << " 1: Perform isSorted Array " << endl;
    cout << " 2: Perform Base Power  " << endl;
    cout << " 3: Perform Fast Power  " << endl;
    cout << " 4: Multiplication Using recursion  " << endl;
    cout << " 5: Multiplication Using recursion  " << endl;
    cout << " 6: Recursive Bubble Sort  " << endl;
    cout << " 7: Full Recursive Bubble Sort  " << endl;
    cin >> Option;
    
   
    
    if(Option==1)
    {
        cout << " Perform isSorted Array " << endl;
        performCheckSortedInput();
    }
    if(Option==2)
    {
        cout << " : Perform Base Power " << endl;
        performpowerInput();
    }
    if(Option==3)
    {
        cout << " : Perform Fast Power " << endl;
        performfastpower();
    }
    if(Option==4)
    {
        cout << " Multiplication " << endl;
        performInputMul();
    }
    if(Option==5)
    {
        cout << " String Into Integer " << endl;
        performStringToInt();
    }
    if(Option==6)
    {
        cout << " Recursive Bubble Sort Sorted Array " << endl;
        performInputforBubbleSort();
    }
    if(Option==7)
    {
        cout << " Full Recursive Bubble Sort Sorted Array " << endl;
        performInputforFullRecursiveBubbleSort();
    }
    
    
    return 0;
}

