#include<bits/stdc++.h>
using namespace std;

int printSubsequences(vector<int>& arr, int ind, int sum, int K, int n){
    // Base Case
    // condition not satisfied
    // strictly done if array contains positives only
    if(sum > K) return 0;
    
    if(ind == n){
        if(sum == K){
            return 1;
        }
        return 0;
    }
    sum += arr[ind];
    int l = printSubsequences(arr, ind + 1, sum, K, n);
    sum -= arr[ind];
    
    // not pick
    int r = printSubsequences(arr, ind + 1, sum, K, n);
    
    return l + r;
}

int main(){
    vector<int>arr = {1, 2, 1};
    int n = 3;
    int K = 2;
    cout<<" The subsequences are : "<<printSubsequences(arr, 0, 0, K, n)<<endl;
    return 0;
}


// TC---> O(2^N)
// SC---> O(1)