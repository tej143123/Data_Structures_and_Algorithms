#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr, int n){
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    return mini;
}


int main(){
    vector<int>arr={4, 5, 6, 7, 0, 1, 2, 3};
    int n = 8;
    int ans = findMin(arr, n);
    cout<<" The minimum value is : "<<ans<<endl;
    return 0;
}


// TC---> O(N)
// SC---> O(1)