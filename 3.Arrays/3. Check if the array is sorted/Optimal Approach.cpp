#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr, int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
          return false;
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


// TC--> O(n)
// SC--> O(1)