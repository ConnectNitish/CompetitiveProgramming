#include <bits/stdc++.h> 
using namespace std; 
// #define int unsigned long long int  
  
string decToBinary(long long int n,int startIndex) 
{ 
	string str= "";
    for (int i = startIndex; i >= 0; i--)
    { 
        int k = n >> i; 
        if (k & 1) 
        {
            // cout << "1";
            str += '1'; 
        }
        else
        {
            // cout << "0";
            str += '0'; 
        }
    } 
    return str;
} 

long long int  binaryToDecimal(string n) 
{ 
    string num = n; 
    long long int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    long long int base = 1; 
  
    long long int len = num.length(); 
    for (long long int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 

int debug = 0;

int32_t main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		long long int l,r;
		cin >> l >> r;

		string str = decToBinary(l,(log(l)/log(2)));
		string str2 = decToBinary(r,(log(r)/log(2)));

		long long int l1 = str.length();
		long long int l2 = str2.length();

		string padding = "";
		for(int k=0;k<(l2-l1);k++)
		{
			padding += '0';
		}

		// str.append(padding);

		padding.append(str);

		str = padding;

		if(debug)
		{
			cout << " paddinbg " << padding << endl;
			cout << " str 	" << str << endl;
			cout << " str2	" << str2 << endl;
		}

		long long int k=0;
		for(;k<l2;k++)
		{
			if(str[k]!=str2[k])
				break;
		}

		for(int j=k;j<l2;j++)
		{
			str[j] = '1';
		}

		if(debug)
		{
			cout << " final ";
			for(int j=0;j<l2;j++)
				cout << str[j];
			cout << endl;
		}

		cout << binaryToDecimal(str) << endl;
		
	}
}