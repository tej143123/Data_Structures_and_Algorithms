#include<bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int>& arr, int target, int n){
    int ans = n;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int findUpperBound(vector<int>& arr, int target, int n){
    int ans = n;
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFirstAndLastPosition(vector<int>& arr, int target, int n){
    int lb = findLowerBound(arr, target, n);
    int ub = findUpperBound(arr, target, n);
    if(lb == n || arr[lb] != target) return {-1, -1};
    return {lb, ub - 1};
}


int main(){
    vector<int>arr={2, 4, 6, 8, 8, 8, 11, 13};
    int n=8;
    int target = 8;
    pair<int, int> ans = getFirstAndLastPosition(arr, target, n);
    cout<<" The first and last position is : "<<ans.first<<", "<<ans.second<<endl;
    return 0;
}


// TC---> O(2*log N)
// SC---> O(1)