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
    for(int i=1;i<=maxi;i++){
        int reqTime = calculateTotalTime(arr, i);
        if(reqTime <= h){
            return i;
        }
    }
    return maxi;
}


int main(){
    vector<int>arr= {7, 15, 6, 3};
    int h = 8;
    cout<<" The minimum number of bananas koko should eat "<<minimumRateToEatBananas(arr, h)<<" atleast /hr";
    cout<<endl;
    return 0;
}


// TC---> O(MAX(arr) * N)
// SC---> O(1)