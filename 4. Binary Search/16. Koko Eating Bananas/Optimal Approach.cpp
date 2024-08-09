#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr){
    int maxi = arr[0];
    for(int i=1;i<arr.size();i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int calculateTotalTime(vector<int>& arr, int hourly){
    int toatlHrs = 0;
    for(int i=0;i<arr.size();i++){
        toatlHrs += ceil((double) arr[i] / (double) hourly);
    }
    return toatlHrs;
}

int minimumRateToEatBananas(vector<int>& arr, int h){
    int maxi = findMax(arr);
    int low = 1, high = maxi;
    int ans = 1;
    while(low <= high){
        int mid = (low + high)/2;
        int reqTime = calculateTotalTime(arr, mid);
        if(reqTime <= h){
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
    vector<int>arr= {7, 15, 6, 3};
    int h = 8;
    cout<<" The minimum number of bananas koko should eat "<<minimumRateToEatBananas(arr, h)<<" atleast /hr";
    cout<<endl;
    return 0;
}


// TC---> O(N * log(max(arr)))
// SC---> O(1)