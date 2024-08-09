#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int>& arr, int target, int n){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;

        // Check for sorted half
        // check for left half
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        // Check for right half
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}


int main(){
    vector<int>arr={4,5,6,7,0,1,2};
    int n = 7;
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


// TC---> O(log N)
// SC---> O(1) 