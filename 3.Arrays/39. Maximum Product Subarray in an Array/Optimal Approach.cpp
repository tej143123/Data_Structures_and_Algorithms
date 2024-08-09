#include<bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& arr, int n){
    int maxi = INT_MIN;
    int prefix = 1, suffix = 1;
    for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}


int main(){
    vector<int>arr={2, 3, -2, 4};
    int n=4;
    cout<<" The maximum product subarray is : "<<maxProductSubarray(arr, n)<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(1)