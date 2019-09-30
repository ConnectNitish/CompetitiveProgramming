#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>

map<pair<set<int>,set<int>>,int> visited;
unordered_map<int,set<int>> subjectsknown;
unordered_map<int,set<int>> notknown; 
unordered_map<int,int> all_subjects;

int debug=0;

int main()
{
	int t;
	cin >> t;

	for(int tt=1;tt<=t;tt++)
	{
		visited.clear();
		subjectsknown.clear();
		notknown.clear();
		all_subjects.clear();

		int n,s;
		cin >> n >> s;

		for(int i=1;i<=n;i++)
		{
			int noofsubject;
			cin >> noofsubject;
			for(int k=0;k<noofsubject;k++)
			{
				int x;
				cin >> x;
				subjectsknown[x].insert(i);
				all_subjects[x] = 1 ;
			}
		}

		for(auto a:all_subjects)
		{
			for(int i=1;i<=n;i++)
			{
				if(subjectsknown[a.first].find(i)==subjectsknown[a.first].end())
				{
					notknown[a.first].insert(i);
				}
			}
		}

		long long count =0;


		set<pair<int,int>> dclass;

		for(auto subject:all_subjects)
		{
			set<int> teacher = subjectsknown[subject.first];
			set<int> student = notknown[subject.first];

			if(visited.find({teacher,student})==visited.end())
			{
				// count += teacher.size() * student.size();

				

				if(debug)
				{	
					cout << " Subject " << subject.first << endl;
					cout << " Teacher " << endl;
					for(auto t:teacher)
						cout << t << " ";
					cout << endl;
					cout << " Student " << endl;
					for(auto t:student)
						cout << t << " ";
					cout << endl;
				}

				for(auto t:teacher)
				{
					for(auto s:student)
					{
						dclass.insert({t,s});
					}
				}

				// count += dclass.size();

				visited[{teacher,student}] = 1;
			}
		}

		cout <<"Case #" << tt<<": "<< dclass.size() << endl;

	}
	return 0;
}