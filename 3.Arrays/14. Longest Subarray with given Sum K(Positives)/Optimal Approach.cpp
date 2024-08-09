#include<bits/stdc++.h>
using namespace std;


// if array contains only "+ve" & "0" ---> Optimal Solution
int findLongestSubArray(vector<int>& arr, int n, long long k){
    int left=0;
    int right=0;
    int maxLen=0;
    long long sum=arr[0];
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen, right-left+1);
        }
        right++;
        sum+=arr[right];
    }
    return maxLen;
}


int main(){
    vector<int>arr={-1,1,1};
    int n=3;
    long long k=1;
    cout<<" The longest subarray is : "<<findLongestSubArray(arr, n, k);
    return 0;
}


// TC ---> O(2N)
// SC ---> O(1)