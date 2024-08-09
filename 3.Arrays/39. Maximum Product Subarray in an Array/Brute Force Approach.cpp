#include<bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int product = 1;
            for(int k=i;k<=j;k++){
                product *= arr[k];
            }
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

// TC---> O(N^3)
// SC---> O(1)