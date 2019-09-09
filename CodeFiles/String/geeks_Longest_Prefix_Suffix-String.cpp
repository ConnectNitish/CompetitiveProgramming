#include<iostream>
#include<cstring>
#include<vector>
using namespace std; 
#define MAX 10000

// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0

vector<int> lps;

int debug=0;

int main()
{
	int t;
	scanf("%d",&t);

	if(debug)
	{
		printf(" Test cases : %d\n",t);
	}


	while(t--)
	{
		// char s1[MAX];
		// scanf("%s",s1);
		// int len = strlen(s1);

		string s1;
		cin >> s1;
		int len = s1.length();

		// int lps[len];

		lps.clear();
		lps.resize(len,0);

		int i=0;
		int j=-1;
		lps[0]=-1;

		if(debug)
		{
			// printf("String : %s\n",s1);
			cout << s1 << endl;
			cout << " Length " << s1.length() << endl;
		}

		i = 1;
		j=0;

		// because only proper prefix and suffix is taken 
		// so for one character lps will be zero 
		lps[0]=0;
		while(i<len)
		{
			if(s1[i]==s1[j])
			{
				// j is telling till this index prefix == suffix
				// and the current character matches
				// hence lps length is increased   
				j++;
				lps[i] = j;
				i++;				
			}
			else
			{
				if(j==0)
				{
					// not needed 
					// because all the LPS array is intialised with zero 
					// lps[i]=0;
					i++;
				}
				else
					// because the chacrter does not match 
					// so shifting j to last chacrater till 
					// where match has been performed 
					j = lps[j-1];
			}
		}

		if(debug)
		{
			for(auto a:lps)
				cout << a << " ";
			cout << endl;
		}

		printf("%d\n",lps[len-1]);
	}
	return 0;
}