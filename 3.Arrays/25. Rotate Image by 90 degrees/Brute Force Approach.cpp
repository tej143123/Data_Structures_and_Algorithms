#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>>& matrix){
    int n=matrix.size();
    vector<vector<int>>ans(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-i-1]=matrix[i][j];
        }
    }
    return ans;
}

int main(){
    vector < vector < int >> matrix;
    matrix =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>>ans=rotateMatrix(matrix);
    cout<<" The Rotated Image is : "<<endl;
    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// TC---> O(N^2)
// SC---> O(N^2)

