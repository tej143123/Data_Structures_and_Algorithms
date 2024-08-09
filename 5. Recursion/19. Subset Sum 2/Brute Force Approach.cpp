#include<bits/stdc++.h>
using namespace std;

void findsubset(vector<int>& arr, int ind, vector<int>& ds, set<vector<int>>& res, int n){
    // Base Case
    if(ind == n){
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
    }

    // if picks the element
    ds.push_back(arr[ind]);
    findsubset(arr, ind + 1, ds, res, n);
    ds.pop_back();
    
    // if not picks the element
    findsubset(arr, ind + 1, ds, res, n);
}

vector<vector<int>> subsets(vector<int>& arr){
    int n = arr.size();
    vector<int>ds;
    set<vector<int>>res;
    vector<vector<int>>ans;
    findsubset(arr, 0, ds, res, n);
    for(auto &it : res){
        ans.push_back(it);
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans = subsets(arr);
    cout<<" The unique subsets are : ";
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

// TC---> O(2^N * K log X)
// SC---> O(2^N * K)