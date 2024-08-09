#include<bits/stdc++.h>
using namespace std;


int findLowerBound(vector<int>& arr, int target){
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    return lb;
}


int main(){
     vector<int>arr={1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    int target = 12;
    int ind = findLowerBound(arr, target);
    cout<<" The Lower Bound is the index : "<<ind<<endl;
    return 0;
}


// TC---> O(Log N)
// SC---> O(1)