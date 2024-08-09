#include<bits/stdc++.h>
using namespace std;


int searchInsertPosition(vector<int>& arr, int target){
    int ind = lower_bound(arr.begin(), arr.end(), target) - arr.begin(); 
    return ind;
}


int main(){
    vector<int>arr={1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    int target = 9;
    int ind = searchInsertPosition(arr, target);
    cout<<" The Insert Position is at index : "<<ind<<endl;
    return 0;
}


// TC---> O(Log N)
// SC---> O(1)