#include<bits/stdc++.h>
using namespace std;

void findCombination(vector<int>& arr, int ind, int target, vector<int>& ds, vector<vector<int>>& ans, int n){
    // Base Case
    if(ind == n){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }

    // pick the element
    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombination(arr, ind, target - arr[ind], ds, ans, n);
        ds.pop_back();
    }
    // not pick the element
    findCombination(arr, ind + 1, target, ds, ans, n);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target){
    int n = arr.size();
    vector<int>ds;
    vector<vector<int>>ans;
    findCombination(arr, 0, target, ds, ans, n);
    return ans;
}

int main(){
    vector<int>arr = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>>ans = combinationSum(arr, target);
    cout<<" The combinations are : ";
    for(auto it: ans){
        cout<<"[ ";
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}

// TC---> O(2^t * K)
// SC---> O(K * X)---> Where K is the length of every combination & X is the no.of combinations