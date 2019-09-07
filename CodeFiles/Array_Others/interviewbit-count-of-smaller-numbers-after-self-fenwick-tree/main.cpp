
#include <stdio.h>
#include<iostream>
#include<vector>
#include<iterator>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<string.h>
using namespace std;

// Time : O(nlogn)
// Space : O(n)
vector<int> solve_TLE(vector<int> &A) 
{
    vector<int> _r;
    multiset<int> s;
    for(int i=A.size()-1;i>=0;i--)
    {
        s.insert(A[i]);
        auto it = s.lower_bound(A[i]);
        A[i] = distance(s.begin(),it);
    }
    return A;
}

class Solution1 
{
    
public:
    int lowbit(int x)
    {
        return x&(-x);
    }
    
    void update(int s[],int i,int n)
    {
        while(i<=n)
        {
            cout << " To Inc " << i << endl;
            s[i]++;
            // getting 1 -> 2 -> 4 -> 8 ... 
            i=i+lowbit(i);
        }
    }
    
    int res(int s[],int t)
    {
        int ans=0;
        while(t>0)
        {
            cout << " RES " << t << endl;
            ans=ans+s[t];
            // getting ... 8 -> 4 -> 2 -> 1
            t=t-lowbit(t);
        }
        return ans;
    }
    
    void print1(int s[])
    {
        cout << "Printing BIT Array" << endl;
        int sizeofarray = sizeof(s)/sizeof(s[0]);
        for(int p=0;p<sizeofarray;p++)
            cout << s[p] << " ";
        cout << endl;
    }

    unordered_map<int,int> q;

    vector<int> countSmaller(vector<int>& nums) 
    {
        int k;
        k=nums.size();
        vector<int> p;
        if(k==0)
            return p;
            
        // taking up all the number into array  
        int i,j,d;
        int a[k];
        for(i=0;i<k;i++)
            a[i]=nums[i];
        
        // sorting the array 
        sort(a,a+k);
        
        j=0;
        
        // assigning index to the element 
        for(i=0;i<k;i++)
            if(q[a[i]]==0)
                q[a[i]]=++j;
        
        //creating BIT Array 
        
        cout << " J " << j << endl;
        
        int s[j+1];
        memset(s,0,sizeof(s));
        
        // performing for each 
        // in reverse of sorted order
        for(i=k-1;i>=0;i--)
        {
            // taking up all the values 
            // from last index elelemnt of array
            d=res(s,q[nums[i]]);
            
            cout << " NUms[i] " << nums[i] << ": map " << q[nums[i]] << endl;
            cout << "Printing BIT Array" << endl;
            int sizeofarray = sizeof(s)/sizeof(s[0]);
            for(int p=0;p<sizeofarray;p++)
                cout << s[p] << " ";
            cout << endl;
            
            // getting sum till this index 
            // adding it to the the result 
            p.push_back(d);
            //updating the current index by increamenting 
            //it by one in BIT Array 
            
            cout << " Going for Update " << q[nums[i]]+1 << endl;
            
            update(s,q[nums[i]]+1,j);
            
            cout << "Printing BIT Array" << endl;
            sizeofarray = sizeof(s)/sizeof(s[0]);
            for(int p=0;p<sizeofarray;p++)
                cout << s[p] << " ";
            cout << endl;
            
        }
        
        // performing the reverse of the array obtained as 
        // a result of getting up all the 
        // result till this index 
        reverse(p.begin(),p.end());
        
        // returning the result 
        return p;
    }

};

vector<int> solve(vector<int> &A) 
{
    Solution1 s;
    return s.countSmaller(A);
}

template<typename T>
void print(T va)
{
    cout << va << " ";
}

int main()
{
    vector<int> D;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(D));
    vector<int> r = solve(D);
    cout << "Printing the Result Array" << endl;
    for_each(r.begin(),r.end(),print<int>);
    return 0;
}
