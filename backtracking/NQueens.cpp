/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<int>> &board) {
    for(vector<int> row : board) {
        cout<<"\n";
        for(int value : row) {
            cout<<value<<" ";
        }
    }
}

bool bounding(vector<vector<int>> &board, int row, int col) {
    for(int i=0; i<row; i++) {
        if(board[i][col] == 1) {
            return false;
        }
    }
    
    for(int i=0; i<col; i++) {
        if(board[row][i] == 1) {
            return false;
        }
    }
    
    for(int i=row,j=col; i>=0 && j>=0; i--,j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    for(int i=row,j=col; i>=0 && j>=0; i--,j++) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

bool solveNQueen(vector<vector<int>> &board, int col, int N) {
    if(col >= N) {
        return true;
    }
    
    for(int i=0; i<N; i++) {
        if(bounding(board, i, col)) {
            board[i][col] = 1;
            if(solveNQueen(board, col+1, N)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int N = 4;
    vector<int> row(N,0);
    vector<vector<int>> board(N,row);
    
    for(vector<int> row : board) {
        for(int value : row) {
            value = 0;
        }
    }
    
    solveNQueen(board, 0, N);
    
    printBoard(board);
    
    return 0;
    
}

