#include<bits/stdc++.h>
using namespace std;

int countSubarrayWithXor(vector<int>& arr, int n, int K){
    int cnt=0;
    int XR = 0;
    map<int, int>mpp;
    for(int i=0;i<n;i++){
        XR = XR ^ arr[i];
        if(XR == K){
            cnt++;
        }
        else{
            int x = XR ^ K;
            if(mpp.find(x) != mpp.end()){
                cnt+=mpp[x];
            }
            else{
                mpp[XR]++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int>arr={4, 2, 2, 6, 4};
    int n=5;
    int K=6;
    cout<<" The number of subarrays with xor k are : "<<countSubarrayWithXor(arr, n, K);
    return 0;
}

// TC---> O(N log N)
// SC---> O(N)