#include<bits/stdc++.h>
using namespace std;

int findMaxElement(vector<vector<int>>& mat, int n, int col){
    int maxValue = -1;
    int index = -1;
    for(int i=0;i<n;i++){
        if(mat[i][col] > maxValue){
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakElement(vector<vector<int>>& mat, int n, int m){
    int low = 0;
    int high = m - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        int row = findMaxElement(mat, n, mid);
        int left = mid - 1 >=0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if(left < mat[row][mid] && mat[row][mid] > right){
            return {row, mid};
        }
        else if(mat[row][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {-1, - 1};
}


int main(){
    vector<vector<int>> mat = {{4, 2, 5, 1, 4, 5}, {2, 9, 3, 2, 3, 2}, {1, 7, 6, 0, 1, 3}, {3, 6, 2, 3, 7, 2}};
    int n = 4, m = 6;
    vector<int> ans = findPeakElement(mat, n, m);
    cout<<" The peak element is at index : "<<"[" <<ans[0] <<", "<<ans[1]<<" ]"<<endl;
    return 0;
}

// TC---> O((log m) * n))
// SC---> O(1)