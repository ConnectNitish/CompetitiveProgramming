#include<cstring>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long 
#define prime_no 43
#define mod 1000000007

int debug=1;

//method 1 
void createLPSArray(string pattern,vector<int> &lpsArray)
{
	// shows that starting point of the pattern 
	lpsArray[0]=-1;
	
	int i=0;
	int j=i-1;

	// iterate over length of pattern 
	while(i<pattern.length())
	{
		// check if the current index string from starting 
		// to this index have any suffix same as prefix 
		// and if it is then store the index till where 
		// it can be
		// e.g. A  B X A B  
		//		-1 0 0 0 1 
		// 0 indicates length of prefix same as suffix is only character 
		// 1 indicate at B that in (ABXAB)
		// prefix = suffix is found till index 1 i.e. AB    
		while(j>=0 && pattern[j]!=pattern[i])
			j = lpsArray[j];

		i++;
		j++;

		// store the index indicating that 
		// till this index prefix = suffix is found  
		lpsArray[i] = j;
	}
}

// method 1 
void get_KMP_Check_M1(string s1,string p1,vector<int> &lpsArray)
{
	int i=0;
	int j=0;
	while(i<s1.length())
	{
		while(j>=0 && s1[i]!=p1[j])
			j = lpsArray[j];
		i++;
		j++;
		if(j==p1.length())
		{
			cout << " Pattern Found at " << (i-j) << endl;
			j = lpsArray[j];
		}
	}
}

// method 2 
void createLPSArray_M2(string pattern,vector<int> &lpsArray)
{
	// shows that starting point of the pattern 
	// because only proper prefix and suffix is taken 
	// so for one character lps will be zero 

	lpsArray[0]=0;
	int i=1;
	int j=i-1;

	// iterate over length of pattern 
	// for 	A B X A B 
	//		0 0 0 1 2
	// 0 under shows that apart from A 
	// there is no other suffix == prefix matching 
	// 1 under A shows that there is one length 
	// prefix == suffix matched 
	// 2 under B shows that there is two length 
	// prefix == suffix matched 
	while(i<pattern.length())
	{
		if(pattern[i]==pattern[j])
		{
			// j is indiacting till that index prefix == suffix satisfies 
			// j is telling till this index prefix == suffix
			// and the current character matches
			// hence lps length is increased  
			lpsArray[i] = j + 1;
			i++;j++;
		}
		else
		{
			if(j==0)
				// not needed 
				// because all the LPS array is intialised with zero 
				// lps[i]=0;
				i++;
			else
				// because the chacrter does not match 
				// so shifting j to last chacrater till 
				// where match has been performed 
				j = lpsArray[j-1];
		}
	}
}

void get_KMP_Check_M2(string input,string pattern,vector<int> lpsArrayM2,vector<int> &indexes)
{
	int i=0;
	int j=0;
	while(i<input.length())
	{
		if(input[i]==pattern[j])
		{
			i++;j++;
			
			if(j==pattern.length())
			{
				indexes.push_back(i-j);
				cout << " Pattern Found at " << (i-j) << endl;
				j = lpsArrayM2[j-1];
			}
		}
		else
		{
			if(j==0)
				i++;
			else	
				j = lpsArrayM2[j-1];
		}
	}
}

// O(m+n) 
void invoke_KMP_M1()
{
	string s1;
	string p1;
	cin >> s1;
	cin >> p1;
	
	vector<int> lpsArray(p1.length());
	createLPSArray(p1,lpsArray);

	if(debug)
	{
		for(auto a:lpsArray)
			cout << a << " ";
		cout << endl;
	}

	get_KMP_Check_M1(s1,p1,lpsArray);
}

void invoke_KMP_M2()
{
	string s1;
	string p1;
	cin >> s1;
	cin >> p1;
	
	vector<int> lpsArrayM2(p1.length());
	createLPSArray_M2(p1,lpsArrayM2);

	if(debug)
	{
		for(auto a:lpsArrayM2)
			cout << a << " ";
		cout << endl;
	}

	vector<int> indexes;
	get_KMP_Check_M2(s1,p1,lpsArrayM2,indexes);

	for(auto a:indexes)
		cout << a << " ";
}

int main()
{

	cout << " Using KMP Implementation M1 " << endl;
	invoke_KMP_M1();
	cout << endl;

	cout << " Using KMP Implementation M2" << endl;
	invoke_KMP_M2();
	cout << endl;

	return 0;

}