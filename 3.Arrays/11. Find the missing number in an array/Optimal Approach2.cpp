#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& arr, int n){
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i=0;i<n-1;i++){
        XOR2 = XOR2 ^ arr[i];
        XOR1 = XOR1 ^ (i+1);
    }
    XOR1 = XOR1 ^ n;
    return XOR1 ^ XOR2;
}

int main(){
    vector<int>arr={1,2,3,5};
    int n=5;
    cout<<" The Missing element in an array is : "<<findMissing(arr, n);
    return 0;
}

// TC ---> O(N)
// SC ---> O(1)
