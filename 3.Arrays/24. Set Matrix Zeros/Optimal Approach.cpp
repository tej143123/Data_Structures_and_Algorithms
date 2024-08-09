#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> setMatrixZero(vector<vector<int>>& matrix, int n, int m){
    int col0=1;
    // int col[m]={0}-->matrix[0][...]
    // int row[n]={0}-->matrix[...][0]
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                // mark the i-th row
                matrix[0][j]=0;
                // mark the j-th col
                if(j!=0){
                    matrix[i][0]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }

    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }

    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
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
// SC---> O(1)