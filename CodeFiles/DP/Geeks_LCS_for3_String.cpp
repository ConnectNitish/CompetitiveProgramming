#include <iostream>
#include <string.h>
using namespace std;

int dp[110][110][110]={0};
int debug=0;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int a,b,c;
	    cin >> a >> b >> c;
	    string str1,str2,str3;
	    cin >> str1 >> str2 >> str3;
	    
        if(debug)
	    cout << str1 << endl << str2<< endl <<  str3 << endl;
	    
	    memset(dp,0,sizeof(dp));
	    
	    for(int i=1;i<=a;i++)
	    {
	        for(int j=1;j<=b;j++)
	        {
	            for(int k=1;k<=c;k++)
	            {
	                if(str1[i-1]==str2[j-1] && 
	                str2[j-1]==str3[k-1])
	                {
	                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
	                }
	                else
	                {
	                    dp[i][j][k] = 
	                    max(dp[i][j][k-1],
	                    max(dp[i-1][j][k],dp[i][j-1][k]));
	                }
	            }
	        }
	    }

        if(debug)
        {
            for(int i=0;i<=a;i++)
            {
                for(int j=0;j<=b;j++)
                {
                    for(int k=0;k<=c;k++)
                    {
                        cout << dp[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
	    cout << dp[a][b][c] << endl;
	    
	}
	return 0;
}