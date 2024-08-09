#include<bits/stdc++.h>
using namespace std;

void leftRotate(vector<int>& arr, int n){
    int temp[n];
    for(int i=1;i<n;i++){
        temp[i-1]=arr[i];
    }
    temp[n-1]=arr[0];
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int n=5;
    leftRotate(arr, n);
    return 0;
}


// TC---> O(n)
// SC---> O(n)