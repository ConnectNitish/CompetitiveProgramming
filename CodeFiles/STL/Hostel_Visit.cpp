#include <iostream>
#include<set>
#include<iterator>
using namespace std;

int debug=0;
int filedebug = 1;
int main() {

	if(filedebug){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	}

    int n,k;
    cin >> n >> k;
    multiset<long long int> data;

    while(n--)
    {
        long long int a,b,c;
        cin >> a;
        if(a==1)
        {
            cin >> b >> c;
            long long int distance = (b)*(b) + (c)*(c);
            data.insert(distance);
			if(data.size()>k){ data.erase(--data.end()); }
			if(debug)
			{
				cout << " Input " << " a" << a << "b " << b << "c " << c << endl;
				cout << endl;
				for(auto it1:data)
				cout << it1 << ":";
				cout << endl;
			}
        }
        else if(a==2)
        {
			if(debug)
			{
			cout << " Test " << " a " << a << endl;
			}
            long long int value = *data.rbegin();
            cout << value << endl;
        }
    }
    return 0;
}
