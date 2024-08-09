#include<bits/stdc++.h>
using namespace std;

void findCombination(vector<int>& arr, int ind, int target, vector<int>& ds, vector<vector<int>>& ans, int n){
    // Base Case
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i=ind;i<n;i++){
        if(i > ind && arr[i] == arr[i - 1]) continue;
        if(arr[i] > target) break;

        ds.push_back(arr[i]);
        findCombination(arr, i + 1, target - arr[i], ds, ans, n);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& arr, int target){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int>ds;
    vector<vector<int>>ans;
    findCombination(arr, 0, target, ds, ans, n);
    return ans;
}

int main(){
    vector<int>arr = {10,1,2,7,6,1,5};
    int target = 8;
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

// TC---> O(2^n * K)
// SC---> O(K * X)---> Where K is the length of every combination & X is the no.of combinations