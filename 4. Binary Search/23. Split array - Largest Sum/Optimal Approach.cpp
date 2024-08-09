#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int findSum(vector<int>& arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}
int countPartitions(vector<int>& arr, int maxSum, int n){
    int subarraySum = 0;
    int partitions = 1;
    for(int i=0;i<n;i++){
        if(subarraySum + arr[i] <= maxSum){
            subarraySum += arr[i];
        }
        else{
            partitions++;
            subarraySum = arr[i];
        }
    }
    return partitions;
}
int splitArray(vector<int>& arr, int k, int n){
    int low = findMax(arr, n);
    int high = findSum(arr, n);
    int ans = low;
    while(low <= high){
        int mid = (low + high) / 2;
        int subarrays = countPartitions(arr, mid, n);
        if(subarrays == k){
            ans = mid;
            high = mid - 1;
        }
        else if(subarrays > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    vector<int>arr = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 3;
    int ans = splitArray(arr, k, n);
    cout<<" The answer is : "<<ans<<endl;
    return 0;
}


// TC---> O(N * (log ((Sum(arr[]) - Max(arr[]) + 1))))
// SC---> O(1)