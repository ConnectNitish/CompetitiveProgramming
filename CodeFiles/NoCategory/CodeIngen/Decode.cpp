#include <bits/stdc++.h> 
using namespace std; 
#define int long long int 
map<int,int> dp;

#define MOD 1000000007
int debug=0;

string countWays(int n,string s) 
{ 
	string snew = "";

	for(auto a:s)
	{
		if(a!=' ')
			snew += a;
	}

	s = snew;
	snew = "";

	if(debug)
	{
		cout << " FINAL " << s << endl; 
	}

	for(auto a:s)
	{
		char ch;

		if(((a-'A') - n)>=0)
			ch = ((a-'A') - n) + 'A';
		else 
			ch = 'Z' + ((a-'A') - n) + 1 ; 

		// if(debug)
		// 	cout << a << " & " << ch << endl;

		if(ch > 'Z')
			ch = ('Z' - ch) + 'A';
		snew += ch;
	}

	if(debug)
	{
		cout << " FINAL " << snew << endl; 
	}

	string s_new="";

	int start_space_ptr = 0;
	string temp_string = "";
	bool seen_space = false;

	for(int i=0;i<snew.length();i++)
	{
		if(snew[i]=='Q' && i+1<snew.length() && snew[i+1]=='Q')
		{
			temp_string += ' ',seen_space = true,
			i=i+1;
		}
		else
			temp_string += snew[i];

		// if(temp_string.length()>0 && temp_string[temp_string.length()-1]!=' '
		// 	&& seen_space == false)
		// 	seen_space = true;

		if(seen_space==true)
		{
			// if(start_space_ptr!=-1)
			{
				// string s_temp_data = "";
				// for(auto a:temp_string)
				// {
				// 	if(a!=' ')
				// 		s_temp_data+=a;

				// }
				if(debug)
				{
					cout << " temp_string " << temp_string << endl;
				}
				// if(temp_string.length()>0 && temp_string[temp_string.length()-1]!='Q')
					s_new.append(temp_string),temp_string="",seen_space=false;
			}
		}
	}

	if(temp_string.length()>0)
		if(temp_string.length()>0 && temp_string[temp_string.length()-1]!='Q')
			s_new.append(temp_string);

	// string s_new_1 = "";
	// int counter = 0;
	// for(auto a:s_new)
	// {
	// 	s_new_1 += a;
	// 	counter++;
	// 	if(counter==4)
	// 	{
	// 		s_new_1 += ' ';
	// 		counter=0;
	// 	}
	// }

	// s_new = s_new_1; 
	if(s_new.length()>0 && s_new[0]==' ') s_new="";
	return s_new;

} 

// driver code 
int32_t main() 
{ 
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		n = n % 26;
		string s;
		cin.ignore();
		getline(cin,s); 
		if(debug)
		{
			cout << " Input " << s << endl; 
		}
		cout << countWays(n,s) << endl; 
	}
	return 0; 
} 
