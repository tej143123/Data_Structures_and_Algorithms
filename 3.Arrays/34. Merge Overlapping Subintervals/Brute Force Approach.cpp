#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr, int n){
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end   = arr[i][1];
        // Skip all the merged intervals
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        // checking the overlapping intervals
        // if exists, then merge those intervals
        for(int j=i+1;j<n;j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main(){
    vector<vector<int>> arr={{1, 3}, {8, 10}, {2, 6}, {15, 18}};;
    int n=4;
    vector<vector<int>>ans = mergeOverlappingIntervals(arr, n);
    for(auto it : ans){
        cout<<"["<<it[0]<<","<<it[1]<<"]";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N log N) + O(2*N)
// SC---> O(N)