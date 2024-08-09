#include<bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int> arr, int n, int x){
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int findRowWithMax1s(vector<vector<int>>& mat, int n, int m){
    int maxCnt = 0;
    int index = -1;
    for(int i=0;i<n;i++){
        int cnt_ones = m - findLowerBound(mat[i], m, 1);
        if(cnt_ones > maxCnt){
            maxCnt = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> mat = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3;
    int m = 3;
    int ans = findRowWithMax1s(mat, n, m);
    cout<<" The row with max number of 1's is : "<<ans<<endl;
    return 0;
}

// TC---> O(N * log M)
// SC---> O(1)