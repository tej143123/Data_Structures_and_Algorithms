#include<bits/stdc++.h>
using namespace std;

int longestSubarryLength(vector<int>& arr, int n){
    int maxLen = 0;
    int prefixSum = 0;
    unordered_map<int, int>mpp;
    for(int i=0;i<n;i++){
        prefixSum += arr[i];
        if(prefixSum == 0){
            maxLen = i+1;
        }
        else{
            if(mpp.find(prefixSum)!=mpp.end()){
                maxLen = max(maxLen, (i - mpp[prefixSum]));
            }
            else{
                mpp[prefixSum] = i;
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


// TC---> O(N log N)
// SC---> O(N)  