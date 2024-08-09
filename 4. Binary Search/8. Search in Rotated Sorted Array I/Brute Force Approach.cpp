#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int>& arr, int target, int n){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return  i;
            break;
        }
    }
    return -1;
}


int main(){
    vector<int>arr={4,5,6,7,0,1,2,3};
    int n = 8;
    int target = 0;
    int ind = findElement(arr, target, n);
    if(ind == -1){
        cout<<" The element is not found "<<endl;
    }
    else{
        cout<<" The element is found at index : "<<ind<<endl;
    }
    return 0;
}


// TC---> O(N)
// SC---> O(1) 