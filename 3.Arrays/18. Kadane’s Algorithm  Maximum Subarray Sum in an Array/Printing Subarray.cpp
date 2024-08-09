#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi=INT_MIN;
    int start=-1;
    int ansStart=-1, ansEnd=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maxi){
            ansStart=start;
            ansEnd=i;
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

// TC---> O(N)
// SC---> O(1)