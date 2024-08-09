#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> arr, int n, int target){
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& mat, int n, int m, int target){
    for(int i=0;i<n;i++){
        int first = mat[i][0];
        int last = mat[i][m-1];
        if(first <= target && target <= last){
            return binarySearch(mat[i], m, target);
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

// TC---> O(N + log M)
// SC---> O(1)