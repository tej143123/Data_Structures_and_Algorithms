#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int n, int m, int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == target){
                return true;
            }
        }
    }
    return false;
}


int main(){
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int n = 3;
    int m = 4;
    int target = 8;
    if(searchMatrix(mat, n, m, target)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

// TC---> O(N * M)
// SC---> O(1)