#include<bits/stdc++.h>
using namespace std;

int countSubarrayWithXor(vector<int>& arr, int n, int K){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int XOR=0;
            for(int k=i;k<=j;k++){
                XOR = XOR^arr[k];
            }
            if(XOR == K){
                cnt++;
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

// TC---> O(N^3)
// SC---> O(1)