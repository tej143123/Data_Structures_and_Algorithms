#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr, int n){
    int ans = INT_MAX;
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;

        // if search space is already sorted
        // then arr[low] is always be smaller
        // in that search space 
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }
        // check for sorted half
        // if left half is sorted 
        // then take minimum from the left half 
        // and eleminate the entire left half
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // if right half is sorted 
        // then take minimum from the right half 
        // and eleminate the entire right half
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    vector<int>arr={4, 5, 6, 7, 0, 1, 2, 3};
    int n = 8;
    int ans = findMin(arr, n);
    cout<<" The minimum value is : "<<ans<<endl;
    return 0;
}


// TC---> O(log N)
// SC---> O(1)  