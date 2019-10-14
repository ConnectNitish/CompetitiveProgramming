#include<bits/stdc++.h>
using namespace std;
#define LIMIT 1000000000000
#define int long long 

int t,n;
map<int,int> powers;

// int pw(int a,int b)
// {
// 	if(b == 0) return 1;
// 	if(b == 1) return a;
// 	if(a == 1) return a;
// 	int small = pw(a,b/2);
// 	if((b&2) == 1)
// 		return small * small * a;
// 	return small * small; 
// }

int pw(int a,int b)
{
	int res = 1;
	while(b)
	{
		if((b&1))
			res = res * a;
		
		if(res>LIMIT)
			return -2;

		a = a * a;
		b = b >> 1;
	}
	return res;
}

int debug=0;

int32_t main()
{
	cin >> t;

	while(t--)
	{
		cin >> n;

		vector<string> data;
		vector<int> maxBase;
		vector<pair<int,string>> given_base;

		map<char,int> char_map;

		int frst;
		string str;

		int count=0;
		for(int i=0;i<=9;i++)
		{
			char_map[i+'0'] = i;
		}

		count = 10;
		for(char ch='A';ch<='Z';ch++)
		{
			char_map[ch] = count;
			count = count + 1;
		}

		// debug = 1;
		if(debug)
		{
			for(auto a:char_map)
				cout << a.first << " " << a.second << endl;
		}

		for(int i=0;i<n;i++)
		{
			cin >> frst >> str;
			
			if(frst!=-1)
			{
				given_base.push_back({frst,str});
			}
			else
			{
				int _len = str.length();
				char max_char = '0';
				for(int l=0;l<_len;l++)
					max_char = max(max_char,str[l]);

				data.push_back(str); 
				// storing for max_base_of_String
				if(max_char=='0')
					maxBase.push_back(1);
				else
					maxBase.push_back(char_map[max_char]);
			}


		} 

		int error = 0;

		int target = -999;

		for(int i=0;i<given_base.size();i++)
		{
			int current_base = given_base[i].first;

			string str_data = given_base[i].second;

			int length_str = str_data.length();

			int base_counter_from_right=0;

			int sum_value = 0;

			for(int k=length_str-1;k>=0;k--)
			{
				int current_value = char_map[str_data[k]];

				if(current_value>0)
				{
					int power_value = pw(current_base,base_counter_from_right);

					if(power_value == -2)
					{
						error = 1;
						break;
					}

					sum_value += current_value * power_value;

					if(sum_value > LIMIT)
					{
						error = 1;
						break;
					}
				}

				base_counter_from_right++;
			}

			if(error == 1)
				break;

			if(target == -999 && error==0)
			{
				target = sum_value;
			}

			if(target != sum_value)
			{
				error =1 ;
				break;
			}

		}

		if(error == 1)
		{
			cout << "-1" << endl;
			continue;
		}

		error = 0;

		unordered_map<int,int> value_freq;

		int target_found = 1;

		// No Target Found Shows all are -1 
		if(target == -999)
		{
			target_found = 0;
		}

		int count_of_minus_one = data.size();

		if(debug)
		{
			cout << endl;
			cout << " Check Point 1" << endl;
			cout << " -1 size " << data.size() << endl;
			cout << " target_found " << target_found << endl;
		}

		for(int i=0;i<data.size();i++)
		{	
			int max_base_in_String = maxBase[i];
			
			string str_data = data[i];
			int length_of_string = str_data.length();


			int base_of_String_Starting = max_base_in_String + 1;

			if(debug)
			{
				cout << " Starting and Max Base " << endl;
				cout << " Starting Base " << base_of_String_Starting << endl;
				cout << " String " << str_data << endl; 
			}



			for(int k=base_of_String_Starting;k<=36;k++)
			{

				int sum_value_by_base = 0;
				
				int traversed_all = 1;

				int counter_for_length=0;

				// if(str_data == "1011010" && k==2)
				// 	debug = 1;
				// else
				// 	debug = 0;

				int temp_k = k;

				for(int j1 = length_of_string-1;j1>=0;j1--)
				{

					// int value_by_pow = pow(temp_k,counter_for_length);

					int current_value = char_map[str_data[j1]];

					if(current_value>0)
					{
						int value_by_pow = pw(temp_k,counter_for_length);
						
						if(debug)
						{
							cout << " pow " << value_by_pow << " ";
							cout << " k " << temp_k << " ";
							cout << " counter_for_length " << counter_for_length << " " ;
							cout << " current_value " << current_value << " ";
							cout << " till point Sum :" << sum_value_by_base << endl;
						}
						
						if(value_by_pow == -2)
						{
							traversed_all = -1;
							break;
						}

						sum_value_by_base += current_value * value_by_pow;

						if(sum_value_by_base > LIMIT)
						{
							traversed_all = -1;
							break;
						}					
					}

					counter_for_length++;
				}

				counter_for_length = 0;

				if(traversed_all == 1)
				{
					value_freq[sum_value_by_base]++;
				}

				if(debug)
				{
					cout << " String " << str_data << endl; 
					cout << " base " << k << endl;
					cout << " (String)base " << sum_value_by_base << endl;
					cout << "Finished " << traversed_all << endl; 
				}
			}

		}

		if(debug)
		{
			cout << " values found in map " << endl;
			for(auto a:value_freq)
			{
				cout << a.first << " & " << a.second << endl;
			}
		}


		if(target_found == 0)
		{
			int min_value = -1;

			for(auto a:value_freq)
			{
				if(a.second == count_of_minus_one)
				{
					if(min_value == -1)
						min_value = a.first;
					else if(min_value > a.first)
						min_value = a.first; 
				}
			}

			cout << min_value << endl;
		}
		else
		{
			if(value_freq[target] == count_of_minus_one)
			{
				cout << target << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
	}
}