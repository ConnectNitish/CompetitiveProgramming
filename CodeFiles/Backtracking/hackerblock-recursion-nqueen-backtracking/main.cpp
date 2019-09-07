/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution
{
    public : 
    //int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
    vector<vector<string> > solveNQueens(int A);
    vector<vector<string> > solveNQueensOptimised(int A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}


// we need not to check 
// from all the directions 
// we just need to check the 
// diagonally above , left and right 
bool checkSafe(vector<vector<bool>> &board,int i,int j,int maxRows)
{
    int curri = i;
    int currj = j;
    
    curri--;
    currj--;
    while(curri>=0 && currj>=0)
    {
        if(board[curri][currj]==true)
            return false;
        curri--;
        currj--;
    }
    
    curri = i;
    currj = j;

    curri--;
    currj++;
    while(curri>=0 && currj<maxRows)
    {
        if(board[curri][currj]==true)
            return false;
        curri--;
        currj++;
    }
    
    curri = i;
    currj = j;
    curri--;
    while(curri>=0 && currj<maxRows)
    {
        if(board[curri][currj]==true)
            return false;
        curri--;
    }
    
    return true;
}

vector<vector<string>> r;
bool createQ
(vector<vector<bool>> &board,int currentrow,int maxRows)
{
    if(currentrow==maxRows)
    {
        // my board is filled with current 
        // correct configuration hence 
        // we are printing the current arrangment 
        vector<string> currentConfig;
        for(int i=0;i<maxRows;i++)
        {
            string strCUrrentConfig="";
            for(int j=0;j<maxRows;j++)
            {
                if(board[i][j])
                    strCUrrentConfig+='Q';
                else
                    strCUrrentConfig+='.';
            }
            currentConfig.push_back(strCUrrentConfig);
        }
        r.push_back(currentConfig);
        // Big Magic here 
        // for getting all configuration 
        // of NQueen 
        return false;
        
        // if above we are returing true 
        // then control stops by gviing 
        // only one correct arrangment 
        // if we need to get correct arranmnet for all the 
        // arranmnent 
        // return false 
        // because resturn false will erase all 
        // the previous configuration placed on board 
        // and then retry to get next configuration from next 
        // index - place 
    }
    
    // traverse all current row cell 
    for(int j=0;j<maxRows;j++)
    {
        if(checkSafe(board,currentrow,j,maxRows))
        {
            // becuase its safe we are visiting and marking its as true 
            board[currentrow][j] = true;
            bool nextCallStatus = createQ(board,currentrow+1,maxRows);
            if(nextCallStatus)
                return true;
            // as we have placed in current row 
            // but above - false is stating 
            // that the next configuration which system is 
            // trying is incorrect 
            // hence resetting the original configuration 
            // and trying to go for next iteration
            // to place the queen 
            board[currentrow][j] = false;
        }
    }
    // all configuration for the current row is consumed 
    // and configuration does not seems to be correct 
    // hence removing the current placed Queen of the previous 
    // iteration  
    return false;
}


vector<vector<string> > Solution::solveNQueens(int A) 
{
    r.clear();
    vector<vector<bool>> board(A,vector<bool>(A,false));
    createQ(board,0,A);
    return r;
}


bool createQOptimised
(vector<vector<bool>> &board,int currentrow,int maxRows,
vector<bool> &leftDiagonal,
vector<bool> &rightDiagonal,
vector<bool> &upperColumn,
vector<vector<string>> &result)
{
    if(currentrow==maxRows)
    {
        // my board is filled with current 
        // correct configuration hence 
        // we are printing the current arrangment 
        vector<string> currentConfig;
        for(int i=0;i<maxRows;i++)
        {
            string strCUrrentConfig="";
            for(int j=0;j<maxRows;j++)
            {
                if(board[i][j])
                    strCUrrentConfig+='Q';
                else
                    strCUrrentConfig+='.';
            }
            currentConfig.push_back(strCUrrentConfig);
        }
        result.push_back(currentConfig);
        // Big Magic here 
        // for getting all configuration 
        // of NQueen 
        return false;
        
        // if above we are returing true 
        // then control stops by gviing 
        // only one correct arrangment 
        // if we need to get correct arranmnet for all the 
        // arranmnent 
        // return false 
        // because resturn false will erase all 
        // the previous configuration placed on board 
        // and then retry to get next configuration from next 
        // index - place 
    }
    
    // traverse all current row cell 
    for(int j=0;j<maxRows;j++)
    {
        //if(checkSafe(board,currentrow,j,maxRows))
        
        //for diagonal left - (i-j) is constant 
        // so if 5*5 matrix is there 
        // you are 1 4 so (i-j) will be negative 
        // hence making this to (i-j)+(N-1)
        // it will handle all the negative indexes also 
        //for diagonal right - (i+j) is constant 
        //for current column - i is constant  

        // initally check whether any current 
        // left , right diagonal 
        // upper column is visited 

        
        bool _checkSafe = ((leftDiagonal[j-currentrow+maxRows-1] == false)
                          && 
                          (rightDiagonal[j+currentrow] == false)
                          &&
                          (upperColumn[j] == false));
                          
        if(_checkSafe==true)
        {
            // becuase its safe we are visiting and marking its as true 
            board[currentrow][j] = true;
            
            // mark respective index 
            
            // place the queen and it will tell 
            // forthcoming leftdiagonals  
            leftDiagonal[j-currentrow+maxRows-1] = true;
            
            
            rightDiagonal[j+currentrow]=true;
            upperColumn[j] = true;
            
            bool nextCallStatus = 
            createQOptimised(board,currentrow+1,maxRows,
            leftDiagonal,rightDiagonal,upperColumn,result);
            if(nextCallStatus)
                return true;
            // as we have placed in current row 
            // but above - false is stating 
            // that the next configuration which system is 
            // trying is incorrect 
            // hence resetting the original configuration 
            // and trying to go for next iteration
            // to place the queen 
            board[currentrow][j] = false;
            
            leftDiagonal[j-currentrow+maxRows-1] = false;
            rightDiagonal[j+currentrow]=false;
            upperColumn[j] = false;
            
        }
    }
    // all configuration for the current row is consumed 
    // and configuration does not seems to be correct 
    // hence removing the current placed Queen of the previous 
    // iteration  
    return false;
}

vector<vector<string> > Solution::solveNQueensOptimised(int A) 
{
    r.clear();
    vector<vector<bool>> board(A,vector<bool>(A,false));
    vector<bool> leftDiagonal(2*A,false);
    vector<bool> rightDiagonal(A,false);
    vector<bool> upperColumn(A,false);
    vector<vector<string>> result;
    createQOptimised(board,0,A,leftDiagonal,rightDiagonal,upperColumn,result);
    return result;
}


int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<string>> result = s.solveNQueensOptimised(n);
    
    for(auto a: result)
    {
        for(auto d:a)
            cout << d << endl;
        cout << endl;
    }
}




