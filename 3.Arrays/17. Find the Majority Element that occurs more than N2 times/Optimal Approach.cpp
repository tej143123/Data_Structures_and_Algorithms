#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr, int n){
    // Applying Moore's Voting Algorithm
    int ele;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            ele=arr[i];
            cnt=1;
        }
        else if(arr[i]==ele){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            cnt1++;
        }
        if(cnt1>(n/2)) return ele;
    }
    return -1;
}

int main(){
    vector<int>arr={2,2,3,3,1,2,2};
    int n=7;
    cout<<"The Majority Element in an array is : "<<majorityElement(arr, n);
    return 0;
}

// TC---> O(N)
// SC---> O(1)