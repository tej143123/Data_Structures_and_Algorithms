#include<bits/stdc++.h>
using namespace std;

int findKthMissingNumber(vector<int>& arr, int k, int n){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low + k;
}


int main(){
    vector<int>arr = {5, 7, 10, 12};
    int k = 4;
    int n = 4;
    int missingNumber = findKthMissingNumber(arr, k, n);
    cout<<" The kth missing number is : "<<missingNumber<<endl;
    return 0;
}


// TC---> O(log N)
// SC---> O(1)
