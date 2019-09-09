#include<cstring>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long 
#define prime_no 43
#define mod 1000000007

// Implmentation Using hash 
// Worst acse O(m*n)
// Average Case O(m+n)

ll gethash(string s1,int length)
{
	ll hashValue =0;
	for(int i=0;i<length;i++)
	{
		hashValue += (ll)((int)s1[i]*(ll)pow(prime_no,i));
	}
	return hashValue;
}

ll getnexthash(string s1,int old_index,int next_index,ll current_hash,int pattern_length)
{
	current_hash -= s1[old_index];
	current_hash /= prime_no;
	current_hash += (ll)(((int)s1[next_index])*(ll)pow(prime_no,pattern_length));
	return current_hash;
}

bool checkEntireString(string s1,string p1,
	int start_idx_of_s1,int end_idx_of_s2,int start_idx_of_p1,int end_idx_of_p2)
{
	if(end_idx_of_s2-start_idx_of_s1 != end_idx_of_p2 - start_idx_of_p1)
	{
		return false;
	}

	for(int k=start_idx_of_s1;k<=end_idx_of_p2;k++)
	{
		if(s1[k]!=p1[k])
		{
			return false;
		}
	}
	return true;
}

void Robin_karp_method_string_matching()
{
	string s1;
	string p1;
	cin >> s1;
	cin >> p1;

	ll hashofPattern = gethash(p1,p1.length());
	ll hashofInitialString = gethash(s1,p1.length());

	ll len_of_pattern =  p1.length();

	vector<int> all_indexes;

	for(int i=1;i<=s1.length()-p1.length()+1;i++)
	{
		if(hashofPattern == hashofInitialString)
		{
			if(checkEntireString(s1,p1,i,i+len_of_pattern-1,0,len_of_pattern-1))
			{
				all_indexes.push_back(i-1);
				// i = i + len_of_pattern-1;

				if(i<s1.length())
					hashofInitialString = getnexthash(s1,i-1,i+len_of_pattern-1,
						hashofInitialString,len_of_pattern-1);
				
			}
		}			
		else
		{
			if(i<s1.length())
				hashofInitialString = getnexthash(s1,i-1,i+len_of_pattern-1,
					hashofInitialString,len_of_pattern-1);
		}
	}

	for(auto a:all_indexes)
		cout << a << " ";

}

int main()
{
	cout << " Using Robin Karp : rolling Hash " << endl;
	Robin_karp_method_string_matching();
	cout << endl;
	
	return 0;

}