// https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

#include<bits/stdc++.h> 
using namespace std; 

int debug=0;

int maxHist(vector<int> &row,int R,int C) 
{ 
	stack<int> result; 
	int top_val,max_area = 0,area = 0,i = 0; 
	while (i < C) 
	{ 
		if (result.empty() || row[result.top()] <= row[i]) 
			result.push(i++); 
		else
		{ 
			top_val = row[result.top()]; 
			result.pop(); 
			area = top_val * i; 
			if (!result.empty()) 
				area = top_val * (i - result.top() - 1 ); 
			max_area = max(area, max_area); 
		} 
	} 
	while (!result.empty()) 
	{ 
		top_val = row[result.top()]; 
		result.pop(); 
		area = top_val * i; 
		if (!result.empty()) 
			area = top_val * (i - result.top() - 1 ); 
		max_area = max(area, max_area); 
	} 
	return max_area; 
} 

int maxRectangle(vector<vector<int>> &A,int R,int C) 
{ 
	int result = maxHist(A[0],R,C); 

	for (int i = 1; i < R; i++) 
	{ 
		for (int j = 0; j < C; j++) 
			if (A[i][j])
				A[i][j] += A[i - 1][j]; 
		result = max(result, maxHist(A[i],R,C)); 
	} 

	return result; 
} 

int main() 
{ 
	int r,c;
    cin >> r >> c;
    vector<vector<char>> data;
    data.clear();
    data.resize(r);

    if(debug)
    {
    	cout << " r " << r << endl;
    	cout << " c " << c << endl;
    }

    for(int i=0;i<r;i++)
    {
        vector<char> tt;
        for(int j=0;j<c;j++)
        {
            // int ch;
            // cin >> ch;
            // tt[j]=ch;
            // cin >> &data[i][j];
            char v;
            cin >> v;
            tt.push_back(v);
        }
        data[i] = tt;
    }

    if(debug)
    {
    	cout << " TEST " << endl;

    	cout << " r " << r << endl;
    	cout << " c " << c << endl;
    }

    vector<vector<int>> intdata;


    for(int i=0;i<r;i++)
    {
        vector<int> tt;
        for(int j=0;j<c;j++)
        {
        	tt.push_back(data[i][j]-'0');
        }
        intdata.push_back(tt);
    }

    cout << maxRectangle(intdata,r,c) << endl;
} 
