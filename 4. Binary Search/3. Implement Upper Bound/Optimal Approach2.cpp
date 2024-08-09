#include<bits/stdc++.h>
using namespace std;

int findUpperBound(vector<int>& arr, int target){
    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    return ub;
}


int main(){
    vector<int>arr={1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    int target = 9;
    int ind = findUpperBound(arr, target);
    cout<<" The Upper Bound is the index : "<<ind<<endl;
    return 0;
}

// TC---> O(log N)
// SC---> O(1)