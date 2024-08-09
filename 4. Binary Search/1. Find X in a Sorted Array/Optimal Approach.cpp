#include<bits/stdc++.h>
using namespace std;

int findTarget(vector<int>& arr, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int>arr={1,2,3,4,5};
    int n=5;
    int target=5;
    int ind = findTarget(arr, n, target);
    if(ind == -1){
        cout<<" The target is not found "<<endl;
    }
    else{
        cout<<"The target is found at index : "<<ind<<endl;
    }
    return 0;
}


// TC---> O(Log N)
// SC---> O(1)