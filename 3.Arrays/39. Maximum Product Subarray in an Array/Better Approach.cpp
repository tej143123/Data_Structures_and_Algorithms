#include<bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int product = arr[i];
        for(int j=i+1;j<n;j++){
            product *= arr[j];
            maxi = max(maxi, product);
        }
    }
    return maxi;
}


int main(){
    vector<int>arr={2, 3, -2, 4};
    int n=4;
    cout<<" The maximum product subarray is : "<<maxProductSubarray(arr, n)<<endl;
    return 0;
}

// TC---> O(N^2)
// SC---> O(1)