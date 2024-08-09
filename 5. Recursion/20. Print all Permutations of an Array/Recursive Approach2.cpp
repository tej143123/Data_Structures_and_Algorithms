#include<bits/stdc++.h>
using namespace std;

void recurPermutation(vector<int>& arr, int ind, vector<vector<int>>& ans, int n){
    // Base Case
    if(ind == n){
        ans.push_back(arr);
        return;
    }

    for(int i=ind;i<n;i++){
        swap(arr[ind], arr[i]);
        recurPermutation(arr, ind + 1, ans, n);
        swap(arr[ind], arr[i]);
    }
}

vector<vector<int>> permutations(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>>ans;
    recurPermutation(arr, 0, ans, n);
    return ans;
}

int main(){
    vector<int>arr = {1, 2, 3};
    vector<vector<int>>ans = permutations(arr);
    cout<<" The permutations are : ";
    for(auto it : ans){
        cout<<"[ ";
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}

// TC---> O(N! * N)
// SC---> O(N! * N) 