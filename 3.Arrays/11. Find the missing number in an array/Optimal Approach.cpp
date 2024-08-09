#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& arr, int n){
    int sum=(n*(n+1))/2;
    for(int i=0;i<n-1;i++){
        sum-=arr[i];
    }

    return sum;
}

int main(){
    vector<int>arr={1,2,3,5};
    int n=5;
    cout<<" The Missing element in an array is : "<<findMissing(arr, n);
    return 0;
}

// TC ---> O(N)
// SC ---> O(1)
