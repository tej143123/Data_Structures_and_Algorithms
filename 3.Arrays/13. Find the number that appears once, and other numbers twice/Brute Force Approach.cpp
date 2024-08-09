#include<bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>& arr, int n){
    for(int i=0;i<n;i++){
        int num=arr[i];
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==num){
                cnt++;
            }
        }
        if(cnt==1) return num;
    }
    return -1;
}

int main(){
    vector<int>arr={1,1,2,3,3,4,4};
    int n=7;
    cout<<"The Single Element present in an array is : "<<findSingleElement(arr, n);
    return 0;
}


// TC --> O(n^2)
// SC --> O(1)