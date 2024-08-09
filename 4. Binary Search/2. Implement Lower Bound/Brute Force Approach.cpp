#include<bits/stdc++.h>
using namespace std;


// Lower Bound -----> Smallest Index such that arr[ind] >= target

int findLowerBound(vector<int>& arr, int target, int n){ 
    for(int i=0;i<n;i++){
        if(arr[i]>= target){
            return i;
        }
    }
    return n;
}


int main(){
    vector<int>arr={1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    int n = 10;
    int target = 9;
    int ind = findLowerBound(arr, target, n);
    cout<<" The Lower Bound is the index : "<<ind<<endl;
    return 0;
}


// TC---> O(N)
// SC---> O(1)