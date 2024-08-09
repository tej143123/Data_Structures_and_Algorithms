#include<bits/stdc++.h>
using namespace std;

int findFirstOccurence(vector<int>& arr, int target, int n){
    int first = -1;
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int findLastOccurence(vector<int>& arr, int target, int n){
    int last = -1;
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}


pair<int, int> getFirstAndLastPosition(vector<int>& arr, int target, int n){
    int first = findFirstOccurence(arr, target, n);
    if(first == -1) return {-1, -1};
    int last = findLastOccurence(arr, target, n);
    return {first, last};
}


int main(){
    vector<int>arr={2, 4, 6, 8, 8, 8, 11, 13};
    int n=8;
    int target = 11;
    pair<int, int> ans = getFirstAndLastPosition(arr, target, n);
    cout<<" The first and last position is : "<<ans.first<<", "<<ans.second<<endl;
    return 0;
}


// TC---> O(2*log N)
// SC---> O(1)