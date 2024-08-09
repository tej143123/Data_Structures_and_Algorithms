#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& mat, int i, int j, vector<string>& ans, vector<vector<int>>& vis, string s, int n){
    // Base Case
    if(i == n - 1 && j == n - 1){
        ans.push_back(s);
        return;
    }
    // Down
    if(mat[i + 1][j] == 1 && i + 1 < n && vis[i + 1][j] == 0){
        vis[i][j] = 1;
        solve(mat, i + 1, j, ans, vis, s + "D", n);
        vis[i][j] = 0;
    }
    // Left
    if(mat[i][j - 1] == 1 && j - 1 >= 0 && vis[i][j - 1] == 0){
        vis[i][j] = 1;
        solve(mat, i, j - 1, ans, vis, s + "L", n);
        vis[i][j] = 0;
    }
    // Right
    if(mat[i][j + 1] == 1 && j + 1 < n && vis[i][j + 1] == 0){
        vis[i][j] = 1;
        solve(mat, i, j + 1, ans, vis, s + "R", n);
        vis[i][j] = 0;
    }
    // Up
    if(mat[i - 1][j] == 1 && i - 1 >= 0 && vis[i - 1][j] == 0){
        vis[i][j] = 1;
        solve(mat, i - 1, j, ans, vis, s + "", n);
        vis[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &mat, int n){
    vector<string>ans;
    vector<vector<int>>vis(n, vector<int>(n, 0));
    if(mat[0][0] == 1) 
    solve(mat, 0, 0, ans, vis, "", n);
    return ans;
}

// TC---> O(4^(n*n))
// SC---> O(n*n)