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


int countOccurrences(vector<int>& arr, int target, int n){
    int first = findFirstOccurence(arr, target, n);
    if(first == -1) return 0;
    int last = findLastOccurence(arr, target, n);
    return (last - first + 1);
}


int main(){
    vector<int>arr={2, 8, 8, 8, 8, 8, 11, 13};
    int n = 8;
    int target = 8;
    int cnt = countOccurrences(arr, target, n);
    cout<<" The number of occurrences of a target is : "<<cnt<<endl;
    return 0;
}


// TC---> O(2*log N)
// SC---> O(1)