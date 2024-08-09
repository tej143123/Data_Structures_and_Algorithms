#include<bits/stdc++.h>
using namespace std;

int findKthMissingNumber(vector<int>& arr, int k, int n){
    for(int i=0;i<n;i++){
        if(arr[i] <= k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}


int main(){
    vector<int>arr = {5, 7, 10, 12};
    int k = 4;
    int n = 4;
    int missingNumber = findKthMissingNumber(arr, k, n);
    cout<<" The kth missing number is : "<<missingNumber<<endl;
    return 0;
}


// TC---> O(N)
// SC---> O(1)
