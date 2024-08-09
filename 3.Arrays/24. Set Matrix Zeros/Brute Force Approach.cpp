#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& matrix, int m, int i){
    for(int j=0;j<m;j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int n, int j){
    for(int i=0;i<n;i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> setMatrixZeros(vector<vector<int>>& matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                markRow(matrix, m, i);
                markCol(matrix, n, j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>ans=setMatrixZeros(matrix, n, m);
    cout<<" The Final matrix is : "<<endl;
    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// TC---> O(N*M) * O(N+M) + O(N*M)
// SC---> O(1)