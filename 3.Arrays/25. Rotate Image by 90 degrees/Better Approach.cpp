#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector < vector < int >> matrix;
    matrix =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(matrix);
    cout<<" The Rotated Image is : "<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// TC---> O(N/2 * N/2) + O(N*N/2)
// SC---> O(1)

