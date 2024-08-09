#include<bits/stdc++.h>
using namespace std;


// if array contains only "+ve" & "-ve" ---> Optimal Solution
long long findLongestSubArray(vector<int>& arr, int n, long long k){
    int maxLen = 0;
    map<long long, int>mpp;
    long long preSum = 0;
    for(int i=0;i<n;i++){
        preSum += arr[i];

        if(preSum == k){
            maxLen = max(maxLen, i + 1);
        }

        long long rem = preSum - k ;
        if(mpp.find(rem) != mpp.end()){
            int len = i -  mpp[rem];
            maxLen = max(maxLen, len);
        }

        if(mpp.find(preSum) == mpp.end()){
            mpp[preSum] = i;
        }
    }
    return maxLen;
}

int main(){
    vector<int>arr={1, 2, 3 , 1, 1 ,1 ,1, 4, 2 , 3};
    int n=10;
    long long k=3;
    cout<<" The longest subarray is : "<<findLongestSubArray(arr, n, k);
    return 0;
}

// TC ---> O(N log N)
// SC ---> O(N)