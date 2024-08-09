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
bool searchElement(vector<vector<int>>& mat, int target){
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
        if(binarySearch(mat[i], m, target)){
            return true;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    searchElement(mat, 14) == true ? cout<<" True " : cout<<" False ";
}


// TC---> O(N * log M)
// SC---> O(1)