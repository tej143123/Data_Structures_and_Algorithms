#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr, int n){
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]){
                cnt++;
            }
        }
        if(cnt>n/2) return arr[i];
    }
    return -1;
}

int main(){
    vector<int>arr={2,2,3,3,1,2,2};
    int n=7;
    cout<<"The Majority Element in an array is : "<<majorityElement(arr, n);
    return 0;
}

// TC---> O(N^2)
// SC---> O(1)