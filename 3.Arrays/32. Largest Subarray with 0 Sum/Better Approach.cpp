#include<bits/stdc++.h>
using namespace std;

int longestSubarryLength(vector<int>& arr, int n){
    int maxLen=0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum +=arr[j];
            if(sum == 0){
                maxLen=max(maxLen, (j-i+1));
            }
        }
    }
    return maxLen;
}

int main(){
    vector<int>arr={9, -3, 3, -1, 6, -5};
    int n=6;
    cout<<" The longest subarray length is : "<<longestSubarryLength(arr, n);
    return 0;
}

// TC---> O(N^2)
// SC---> O(1)  