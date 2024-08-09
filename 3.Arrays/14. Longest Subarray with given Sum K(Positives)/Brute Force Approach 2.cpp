#include<bits/stdc++.h>
using namespace std;

int findLongestSubArray(vector<int>& arr, int n, long long k){
    int len=0;
    for(int i=0;i<n;i++){
        long long sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k) len=max(len, j-i+1);
        }
    }
    return len;
}

int main(){
    vector<int>arr={1,2,3,1,1,1,1,4,2,3};
    int n=10;
    int k=3;
    cout<<" The longest subarray is : "<<findLongestSubArray(arr, n, k);
    return 0;
}

// TC ---> O(N^2)
// SC ---> O(1)