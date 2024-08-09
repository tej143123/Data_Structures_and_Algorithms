#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& arr, int n, int target){
    map<int, int>mpp;
    for(int i=0;i<n;i++){
        int num = arr[i];
        int moreNeeded = target - num;
        if(mpp.find(moreNeeded)!=mpp.end()){
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

int main(){
    vector<int>arr={2,6,5,8,11};
    int n=5;
    int target=14;
    vector<int>ans=twoSum(arr, n, target);
    cout<<"["<< ans[0] <<","<<ans[1]<<"]";
    return 0;
}

// TC---> O(N log M)
// SC---> O(N)

