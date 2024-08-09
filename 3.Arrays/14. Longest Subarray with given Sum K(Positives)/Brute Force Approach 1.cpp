#include<bits/stdc++.h>
using namespace std;

int findLongestSubArray(vector<int>& arr, int n, long long k){
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long sum=0;
            for(int m=i;m<=j;m++){
                sum+=arr[m];
            }
            if(sum==k) 
            len=max(len, j-i+1);
        }
    }
    return len;
}

int main(){
    vector<int>arr={2,3,5,1,9};
    int n=5;
    int k=10;
    cout<<" The longest subarray is : "<<findLongestSubArray(arr, n, k);
    return 0;
}

// TC ---> O(N^3)
// SC ---> O(1)