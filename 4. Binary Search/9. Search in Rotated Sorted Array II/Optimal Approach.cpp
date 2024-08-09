#include<bits/stdc++.h>
using namespace std;

bool findElement(vector<int>& arr, int target, int n){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;

        // if mid points to target
        if(arr[mid] == target) return true;

        // edge case
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }

        // check for sorted half
        // if left half is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        // if right half is sorted
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
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


// TC---> O(log N) (for Best and Average Case) . O(N/2)(for the Worst Case)
// SC---> O(1) 