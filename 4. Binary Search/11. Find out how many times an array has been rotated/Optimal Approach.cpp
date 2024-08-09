#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int>& arr, int n){
    int ans = INT_MAX, index = -1;
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
            break;  
        }

        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            index = low;
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
            index = mid;
        }
    }
    return index;
}


int main(){
    vector<int>arr={4, 5, 6, 7, 0, 1, 2, 3};
    int n = 8;
    int ans = findKRotation(arr, n);
    cout<<" The array is rotated for "<<ans<<" times"<<endl;
    return 0;
}


// TC---> O(log N)
// SC---> O(1)