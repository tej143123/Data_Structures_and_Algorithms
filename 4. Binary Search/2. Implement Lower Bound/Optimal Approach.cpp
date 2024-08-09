#include<bits/stdc++.h>
using namespace std;


int findLowerBound(vector<int>& arr, int target, int n){
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


int main(){
     vector<int>arr={1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    int n = 10;
    int target = 9;
    int ind = findLowerBound(arr, target, n);
    cout<<" The Lower Bound is the index : "<<ind<<endl;
    return 0;
}


// TC---> O(Log N)
// SC---> O(1)