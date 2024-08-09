#include<bits/stdc++.h>
using namespace std;

void recurPermutation(vector<int>& arr, vector<int>& ds, vector<int>& vis, vector<vector<int>>& ans, int n){
    // Base Case
    int m = ds.size();
    if(m == n){
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            ds.push_back(arr[i]);
            vis[i] = 1;
            recurPermutation(arr, ds, vis, ans, n);
            ds.pop_back();
            vis[i] = 0;
        }
        else continue;
    }
}

vector<vector<int>> permutations(vector<int>& arr){
    int n = arr.size();
    vector<int>ds;
    vector<int>vis(n, 0);
    vector<vector<int>>ans;
    recurPermutation(arr, ds, vis, ans, n);
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
// SC---> O(N! * N) + O(N)