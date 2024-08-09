#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i])  return false;
        }
    }
    return true;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int n=5;
    bool ans= isSorted(arr,n);
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}


// TC--> O(n^2)
// SC--> O(1)