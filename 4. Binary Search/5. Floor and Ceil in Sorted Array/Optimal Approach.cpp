#include<bits/stdc++.h>
using namespace std;

// Floor ---> Largest No. in an array <= target
int findFloor(vector<int>& arr, int target, int n){
    int low = 0, high = n - 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] <= target){
            ans = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


// Ceil ---> Smallest No. in an array >= target
int findCeil(vector<int>& arr, int target, int n){
    int low = 0, high = n - 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= target){
            ans = arr[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


pair<int, int> getFloorAndCeil(vector<int>& arr, int target, int n){
    int floor = findFloor(arr, target, n);
    int ceil = findCeil(arr, target, n);
    return make_pair(floor, ceil);
}


int main(){
    vector<int>arr={10, 20, 30, 40, 50};
    int n = 5;
    int target = 25;
    pair<int, int> ans=getFloorAndCeil(arr, target, n);
    cout<<" The floor and ceil are : "<< ans.first<<", " << ans.second <<endl;
    return 0;   
}


// TC ---> O(log N)
// SC ---> O(1)