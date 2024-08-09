#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr, int n){
    int maxi = arr[0];
    for(int i=1;i<n;i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int findSumByD(vector<int>& arr, int d){
    int sum = 0;
    int n = arr.size();
   for(int i=0;i<n;i++){
       sum += ceil((double) arr[i] / (double) d);
    }
    return sum;
}
int findSmallestDivisor(vector<int>& arr, int n, int limit){
    int maxi = findMax(arr, n);
    int low = 1;
    int high = maxi;
    int ans = -1;
    if(n > limit) return -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(findSumByD(arr, mid) <= limit){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


int main(){
    vector<int>arr = {1, 2, 5, 9};
    int n = 4;
    int limit = 6;
    cout<<" The smallest divisor is : "<<findSmallestDivisor(arr, n, limit)<<endl;
    return 0;
}

// TC---> O(N * log(max(arr)))
// SC---> O(1)