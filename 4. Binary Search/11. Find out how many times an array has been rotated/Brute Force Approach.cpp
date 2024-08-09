#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int>& arr, int n){
    int ans = INT_MAX;
    int index = -1;
    for(int i=0;i<n;i++){
        if(arr[i] < ans){
            ans = arr[i];
            index = i;
        }
    }
    return index;
}


int main(){
    vector<int>arr={4, 5, 6, 7, 0, 1, 2, 3};
    int n = 8;
    int ans = findKRotation(arr, n);
    cout<<" The array is rotated for "<<ans<< " times"<<endl;
    return 0;
}


// TC---> O(N)
// SC---> O(1)