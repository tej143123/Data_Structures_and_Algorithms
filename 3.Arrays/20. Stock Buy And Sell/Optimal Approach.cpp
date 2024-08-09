#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr, int n){
    int maxPro=0;
    int minPrice=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<minPrice){
            minPrice=arr[i];
        }
        maxPro=max(maxPro, (arr[i] - minPrice));
    }
    return maxPro;
}

int main(){
    vector<int>arr={7,1,5,3,6,4};
    int n=6;
    cout<<" The maximum profit is : "<<maxProfit(arr, n);
    return 0;
}


// TC---> O(N)
// SC---> O(1)