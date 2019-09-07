/******************************************************************************

https://hack.codingblocks.com/practice/p/390/391

*******************************************************************************/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int debug=0;
bool checkisSafe(char number,vector<vector<char>> &board,
int currentrow,int currentCol,int boardsize,int fullSize)
{
    int boxnumberbyrows = currentrow % boardsize;
    int boxnumberbycols = currentCol % boardsize;
    
    int newCurrentRow = currentrow - boxnumberbyrows;
    int newCurrentCol = currentCol - boxnumberbycols;
    
    
    
    for(int i=0;i<boardsize;i++)
    {
        for(int j=0;j<boardsize;j++)
        {
            int newIndexX = newCurrentRow + i;
            int newIndexY = j + newCurrentCol;
            if(debug)
            {
                 cout << " suze " << boardsize << endl;
                cout << newIndexX << "^^" << newIndexY << endl;
            }
            if(number == board[newIndexX][newIndexY])
                return false;
        }
    }
    
    for(int i=0;i<fullSize;i++)
    {
        if(number == board[currentrow][i] || number == board[i][currentCol])
            return false;
    }
    return true;
}

bool sudoku(vector<vector<char>> &board,
int currentrow,int currentColumn,int maxRows,int fullSize)
{
    
    if(currentrow>fullSize && currentColumn>fullSize)
        return false;
    if(debug)
        cout << currentrow << ":"<< currentColumn << endl;
    
    if(currentColumn==fullSize && currentrow==fullSize-1)
    {
        // if(debug)
        {
            for(auto data:board)
            {
                for(auto data1:data)
                    cout << data1 << " ";
                cout<<endl;
            }  
        }
        return true;     
    }


    
    // pointer is at last but next column 
    // and rows is not completed till this point 
    // so need to iterate to bext row for processing 
    if(currentColumn==fullSize && currentrow<fullSize)
    {
        // starting from 0th column 
        bool canProceed = sudoku(board,currentrow+1,0,maxRows,fullSize);
        // if(canProceed==true)
            return canProceed;
        // return false;   
    }
    

        
    if(currentColumn < fullSize && board[currentrow][currentColumn]!=' ')
    {
        bool canProceed = sudoku(board,currentrow,currentColumn+1,maxRows,fullSize);
        // if(canProceed==true)
            return canProceed;
        // return false;
    }
    
    if(board[currentrow][currentColumn]==' ')
    {
        for(int numbers=1;numbers<=9;numbers++)
        {
            if(checkisSafe(numbers+'0',board,currentrow,currentColumn,maxRows,fullSize)
            && currentColumn < fullSize
            )
            {
                board[currentrow][currentColumn] = numbers+'0';
                
                bool canProceed = sudoku(board,currentrow,currentColumn+1,maxRows,fullSize);
                if(canProceed==true)
                    return canProceed;
                
                board[currentrow][currentColumn] = ' ';
            }
        }
    }
    
    return false;
}

int main()
{
   int size;
   cin >> size;
   int fullSize = size;
   size = sqrt(size);
   debug=0;
   vector<vector<char>> dataInput;
    for(int i=0;i<fullSize;i++)
    {
        vector<char> eachrow;
        for(int j=0;j<fullSize;j++)
        {
            char ch;
            char ch1;
            cin >> ch;
            // scanf("%c%c",&ch1,&ch);
            // cout << ch1 << ":" << ch << endl;
            if(ch == '0')
                ch = ' ';
            eachrow.push_back(ch);
        }
        dataInput.push_back(eachrow);
    }
    
    if(debug)
    {
        for(auto data:dataInput)
        {
            for(auto data1:data)
                cout << data1 << "|";
            cout<<endl;
        }   
    }
   
    sudoku(dataInput,0,0,size,fullSize);
    
    return 0;
}

/*
Input :
9
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9 
Output : 
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 
*/


