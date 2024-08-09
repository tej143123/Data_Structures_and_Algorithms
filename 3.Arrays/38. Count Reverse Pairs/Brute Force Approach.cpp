#include<bits/stdc++.h>
using namespace std;

int countReversePairs(vector<int>& arr, int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > 2*arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int>arr={40, 25, 19, 12, 9, 6, 2};
    int n=7;
    cout<<" The number of reverse pairs are : "<<countReversePairs(arr, n);
    return 0;
}


// TC---> O(N^2)
// SC---> O(1)