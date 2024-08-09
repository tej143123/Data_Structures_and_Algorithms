#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr, int n){
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        if(ans.empty()){
            ans.push_back(arr[i]);
        }
        else{
            if(arr[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
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

// TC---> O(N log N) + O(N)
// SC---> O(N)