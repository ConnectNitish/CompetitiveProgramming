#include<bits/stdc++.h>
using namespace std;

bool comp(pair<char,int> &p1,pair<char,int> &p2)
{
	if(p1.first<p2.first) return true;
	if(p1.first==p2.first)
	{
		if(p1.second<=p2.second) return true;
	}
	return false;
}

int main()
{



	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;

	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;

	string s2Copy = s2;

	vector<pair<char,int>> s2data;
	for(int i=0;i<s2.length();i++)
		s2data.push_back({s2[i],i});

	// sort(s1.begin(),s1.end());
	// sort(s2.begin(),s2.end());
	sort(s2data.begin(),s2data.end(),comp);
	// sort(s3.begin(),s3.end());

	char lastchars1 = s1[s1.length()-1];
	char firstchars3 = s3[0];

	if(s2data[0].first>firstchars3)
	{
		cout << s1 << s3 << endl;
		return 0; 
	}
	else 
	{
		int i=0;
		
		vector<char> newDatas2;
		int pointerIndex = s2data[i].second;
		newDatas2.push_back(s2data[i].first);

		i++;

		for(;i<n2;i++)
		{
			if(s2data[i].first<=firstchars3 && s2data[i].second>pointerIndex)
			{
				newDatas2.push_back(s2data[i].first);
				pointerIndex = max(pointerIndex,s2data[i].second);
			}
		}

		int indexofs2=0;
		int indexofs3=0;

		string newString = "";

		while(indexofs2<newDatas2.size() && indexofs3<n3)
		{
			if(newDatas2[indexofs2]<s3[indexofs3])
			{
				newString += newDatas2[indexofs2];
				indexofs2++;
			}
			else if(newDatas2[indexofs2] == s3[indexofs3])
			{
				indexofs3++;
			}
			else if(newDatas2[indexofs2]>s3[indexofs3])
			{
				break;
			}
		}

		cout << s1 << newString << s3 << endl;
	}
	return 0;
}