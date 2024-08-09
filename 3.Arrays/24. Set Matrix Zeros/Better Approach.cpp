#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> setMatrixZero(vector<vector<int>>& matrix, int n, int m){
    vector<int>row(n, 0);
    vector<int>col(m, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>ans=setMatrixZero(matrix, n, m);
    cout<<" The Final matrix is : "<<endl;
    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// TC---> O(N*M) + O(N*M)
// SC---> O(N) + O(M)