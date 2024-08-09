#include<bits/stdc++.h>
using namespace std;

int findSmallestDivisor(vector<int>& arr, int n, int limit){
    int maxi = INT_MIN;
    // finding the maximum element 
    // so that we can check upto maximum number as divisor
    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i]);
    }

    // finding the smallest divisor
    for(int d=1;d<=maxi;d++){
        int sum = 0;
        // finding the summation of result
        for(int i=0;i<n;i++){
            sum += ceil((double) arr[i] / (double) d);
        }
        // check
        if(sum <= limit){
            return d;
        }
    }
    // if divisor is not exist
    return -1;
}

// TC---> O(max(arr) * N)
// SC---> O(1)