#include<bits/stdc++.h>
using namespace std;

string twoSum(vector<int>& arr, int n, int target){
    sort(arr.begin(),arr.end());
    int left=0;
    int right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            return "Yes";
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return "No";
}

int main(){
    vector<int>arr={2,6,5,8,11};
    int n=5;
    int target=14;
    cout<<twoSum(arr, n, target);
    return 0;
}


// TC---> O(N)
// SC---> O(1)