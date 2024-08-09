#include<bits/stdc++.h>
using namespace std;

int findTarget(vector<int>&arr, int n, int target){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int n=5;
    int target=6;
    int ind = findTarget(arr, n, target);
    if(ind == -1){
        cout<<" The target is not found "<<endl;
    }
    else{
        cout<<"The target is found at index : "<<ind<<endl;
    }
    return 0;
}


// TC--> O(N)
// SC--> O(1)