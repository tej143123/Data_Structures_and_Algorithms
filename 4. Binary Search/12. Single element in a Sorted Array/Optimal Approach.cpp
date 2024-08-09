#include<bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>& arr, int n){
    // edge case
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1, high = n - 2;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
        else if(((mid % 2) == 1 && arr[mid] == arr[mid - 1])  || ((mid % 2) == 0 && arr[mid] == arr[mid+1])){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int>arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int n = 11;
    int ans = findSingleElement(arr, n);
    cout<<" The single element is : "<<ans<<endl;
    return 0;
}


// TC---> O(log N)
// SC---> O(1)