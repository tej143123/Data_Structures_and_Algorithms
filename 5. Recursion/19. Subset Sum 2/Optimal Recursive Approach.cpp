#include<bits/stdc++.h>
using namespace std;

void findSubsets(vector<int>& arr, int ind, vector<int>& ds, vector<vector<int>>& ans, int n){
    ans.push_back(ds);

    for(int i=ind;i<n;i++){
        if(i != ind && arr[i] == arr[i - 1]) continue;
        ds.push_back(arr[i]);
        findSubsets(arr, i + 1, ds, ans, n);
        ds.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>>ans;
    vector<int>ds;
    sort(arr.begin(), arr.end());
    findSubsets(arr, 0, ds, ans, n);
    return ans;
}

int main(){
    vector<int>arr = {1, 2, 2};
    vector<vector<int>>ans = subsets(arr);
    cout<<" The unique subsets are : ";
    for(auto it:ans){
        cout<<"[ ";
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}

// TC---> O(2^N * K)
// SC---> O(2^N * K)