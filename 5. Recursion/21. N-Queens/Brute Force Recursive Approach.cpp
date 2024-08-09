#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n){
    // check for upper diagonal
    int dupRow = row;
    int dupCol = col;
    while(row >=0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    // check for left side
    row = dupRow;
    col = dupCol;
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    // check for lower diagonal
    row = dupRow;
    col = dupCol;
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(vector<string>& board, int col, vector<vector<string>>& ans, int n){
    // Base Case
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(board, col + 1, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }
    solve(board, 0, ans, n);
    return ans;
}


int main(){
    int n = 4;
    vector<vector<string>>ans = solveNQueens(n);
    cout<<" The arrangements are : ";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// TC---> O(N! * N)
// SC---> O(N^2)