#include<bits/stdc++.h>
using namespace std;

bool findElement(vector<int>& arr, int target, int n){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}


int main(){
    vector<int>arr={3,5,6,7,0,0,1,2,3};
    int n = 8;
    int target = 0;
    bool ans = findElement(arr, target, n);
    if(ans == true){
        cout<<" The target is present "<<endl;
    }
    else{
        cout<<" The target is not found "<<endl;
    }
    return 0;
}


// TC---> O(N)
// SC---> O(1) 