#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& arr, int n){
    int hash[n+1]={0};
    for(int i=0;i<n-1;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0) return i;
    }

    return -1;
}

int main(){
    vector<int>arr={1,2,4,5};
    int n=5;
    cout<<" The Missing element in an array is : "<<findMissing(arr, n);
    return 0;
}


// TC ---> O(N)+O(N)
// SC ---> O(N)