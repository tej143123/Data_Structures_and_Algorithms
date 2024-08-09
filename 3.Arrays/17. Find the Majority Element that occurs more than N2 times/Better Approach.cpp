#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr, int n){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second>(n/2)) return it.first;
    }
    return -1;
}

int main(){
    vector<int>arr={2,2,3,3,1,2,2};
    int n=7;
    cout<<"The Majority Element in an array is : "<<majorityElement(arr, n);
    return 0;
}

// TC---> O(N log N)+ O(N)
// SC---> O(N)