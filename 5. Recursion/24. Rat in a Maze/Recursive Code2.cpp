#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& mat, int i, int j, vector<string>& ans, vector<vector<int>>& vis, string s, int n, int di[], int dj[]){
    // Base Case
    if(i == n - 1 && j == n - 1){
        ans.push_back(s);
        return;
    }
    string dir = "DLRU";
    for(int ind=0;ind<4;ind++){
        int nextRow = i + di[ind];
        int nextCol = j + dj[ind];
        if(nextRow >=0 && nextCol >= 0 && nextRow < n && nextCol < n && mat[nextRow][nextCol] == 1 && vis[nextRow][nextCol] == 0){
            vis[i][j] = 1;
            solve(mat, nextRow, nextCol, ans, vis, s + dir[ind], n, di, dj);
            vis[i][j] == 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat, int n){
    vector<string>ans;
    vector<vector<int>>vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, -1, 0};
    int dj[] = {0, -1, 0, +1};
    if(mat[0][0] == 1) 
    solve(mat, 0, 0, ans, vis, "", n, di, dj);
    return ans;
}

// TC---> O(4^(n*n))
// SC---> O(n*n)