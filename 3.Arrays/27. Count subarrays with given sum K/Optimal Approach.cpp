#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int>& arr, int n, int k){
    int cnt=0, prefixSum=0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        if(prefixSum==k) {
            cnt++;
        }
        if(mpp.find(prefixSum-k)!=mpp.end()){
            cnt+=mpp[prefixSum-k];
        }
        mpp[prefixSum]++;
    }
    return cnt;
}

int main(){
    vector<int>arr={1,2,3,-3,1,1,1,4,2,-3};
    int n=10;
    int k=3;
    cout<<" The number of subarray sum equals to k are : "<<countSubarray(arr, n, k);
    return 0;
}


// TC---> O(N log N)
// SC---> O(N)