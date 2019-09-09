#include<cstring>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long 
#define prime_no 43
#define mod 1000000007

// naive Pattern Search Algorithm 
void searchString(string s1,string p1,vector<int> &All_Indexes)
{
	int ls1 = s1.length();
	int lp1 = p1.length();

	for(int i=0;i<ls1;i++)
	{
		int j=-1;
		for(j=0;j<lp1;j++)
		{
			if(s1[i+j]!=p1[j])
				break;
		}
		if(j==lp1)
		{
			All_Indexes.push_back(i);
			i = i+j-1;
		}
	}
}

// O(m*n) 
void naive_implemntation()
{
	string s1;
	string p1;
	cin >> s1;
	cin >> p1;
	vector<int> all_indexes;
	searchString(s1,p1,all_indexes);

	for(auto a:all_indexes)
		cout << a << " ";
}

int main()
{

	cout << " Using Naive Implementation " << endl;
	naive_implemntation();
	cout << endl;

	return 0;

}