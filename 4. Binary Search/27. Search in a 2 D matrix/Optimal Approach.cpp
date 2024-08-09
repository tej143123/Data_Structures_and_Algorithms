#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int n, int m, int target){
    int low = 0;
    int high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;
        if(mat[row][col] == target){
            return true;
        }
        else if(mat[row][col] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
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

// TC---> O(log(N * M))
// SC---> O(1)