#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr, int n){
    int mini = arr[0];
    for(int i=0;i<n;i++){
        mini = min(mini, arr[i]);
    }
    return mini;
}

int findMax(vector<int>& arr, int n){
    int maxi = arr[0];
    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

bool possible(vector<int>& arr, int day, int m, int k){
    int n = arr.size();
    int cnt = 0, noOfB = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            noOfB += cnt / k;
            cnt = 0;
        }
    }
    noOfB += cnt / k;
    if(noOfB >= m) return true;
    return false;
}
int minimumNoOfDaysRequired(vector<int>& arr, int n, int m, int k){
    int val = m * k;
    if(val > n) return -1;
    int mini = findMin(arr, n);
    int maxi = findMax(arr, n);
    int low = mini, high = maxi;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(possible(arr, mid, m, k)){
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
    vector<int>arr= {7, 7, 7, 7, 13, 11, 12, 7};
    int n = 8;
    int m = 2;
    int k = 3;
    int days = minimumNoOfDaysRequired(arr, n, m, k);
    cout<<" The minimum number of days required to make m bouquets are : "<<days<<endl;
    return 0;
}

// TC---> O(N * log(max(arr) - min(arr) + 1))
// SC---> O(1)