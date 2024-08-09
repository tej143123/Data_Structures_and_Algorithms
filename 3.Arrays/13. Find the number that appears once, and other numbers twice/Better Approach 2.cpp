#include<bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>& arr, int n){
    map<long long, int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second==1) return it.first;
    }

    return -1;
}

int main(){
    vector<int>arr={1,1,2,2,3,4,4,8,8};
    int n=9;
    cout<<" The single element present in an array is : "<<findSingleElement(arr, n);
    return 0;
}


// TC ---> O(N log M)+O(N/2+1)
// SC ---> O(N/2+1)