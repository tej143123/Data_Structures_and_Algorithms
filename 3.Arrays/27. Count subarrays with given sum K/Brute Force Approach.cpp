#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int>& arr, int n, int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==k){
                cnt++;
            }
        }
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


// TC---> O(N^3)
// SC---> O(1)