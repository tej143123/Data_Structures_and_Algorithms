#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr, int n){
    int maxPro=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                maxPro=max(maxPro, (arr[j]-arr[i]));
            }
        }
    }
    return maxPro;
}

int main(){
    vector<int>arr={7,1,5,3,6,4};
    int n=6;
    cout<<" The maximum profit is : "<<maxProfit(arr, n);
    return 0;
}


// TC---> O(N^2)
// SC---> O(1)