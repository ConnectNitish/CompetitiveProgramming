#include<iostream>
#include<vector>
using namespace std;

long long count = 0;
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
        // vector<string> currentConfig;
        // for(int i=0;i<maxRows;i++)
        // {
        //     string strCUrrentConfig="";
        //     for(int j=0;j<maxRows;j++)
        //     {
        //         if(board[i][j])
        //             strCUrrentConfig+='Q';
        //         else
        //             strCUrrentConfig+='.';
        //     }
        //     currentConfig.push_back(strCUrrentConfig);
        // }
        // result.push_back(currentConfig);
        // Big Magic here 
        // for getting all configuration 
        // of NQueen 
        count++;
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
        
        bool _checkSafe = ((leftDiagonal[j-currentrow+maxRows-1] == false)
                          && 
                          (rightDiagonal[j+currentrow] == false)
                          &&
                          (upperColumn[j] == false));
                          
        if(_checkSafe==true)
        {
            // becuase its safe we are visiting and marking its as true 
            board[currentrow][j] = true;
            
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

int solveNQueensOptimised(int A) 
{
    count =0;
    vector<vector<bool>> board(A,vector<bool>(A,false));
    vector<bool> leftDiagonal(2*A,false);
    vector<bool> rightDiagonal(A,false);
    vector<bool> upperColumn(A,false);
    vector<vector<string>> result;
    createQOptimised(board,0,A,leftDiagonal,rightDiagonal,upperColumn,result);
    return count;
}



int main() {
    int n;
    cin >> n;
    int _count = solveNQueensOptimised(n);
    cout << _count << endl;
    return 0;
}