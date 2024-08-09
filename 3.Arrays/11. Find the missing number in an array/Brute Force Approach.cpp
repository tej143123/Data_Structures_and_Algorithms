#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& arr, int n){
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
    return -1;
}

int main(){
    vector<int>arr={1,2,4,5};
    int n=5;
    cout<<" The Missing element in an array is : "<<findMissing(arr, n);
    return 0;
}

// TC---> O(n^2)
// SC---> O(1)