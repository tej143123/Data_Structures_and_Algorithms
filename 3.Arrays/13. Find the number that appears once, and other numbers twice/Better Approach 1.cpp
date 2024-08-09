#include<bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>& arr, int n){
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        maxi=max(maxi, arr[i]);
    }

    vector<int>hash(maxi+1, 0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    for(int i=0;i<hash.size();i++){
        if(hash[i]==1) return i;
    }

    return -1;
}

int main(){
    vector<int>arr={1,1,2,3,3,4,4};
    int n=7;
    cout<<"The Single Element present in an array is : "<<findSingleElement(arr, n);
    return 0;
}


// TC --> O(n)
// SC --> O(maxi+1)