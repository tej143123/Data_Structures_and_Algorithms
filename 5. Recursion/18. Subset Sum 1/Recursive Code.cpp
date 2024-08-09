#include<bits/stdc++.h>
using namespace std;

void findsubsetSum(vector<int>& arr, int ind, int sum, vector<int>& ans, int n){
    // Base Case
    if(ind == n){
        ans.push_back(sum);
        return;
    }

    // if picks the element 
    findsubsetSum(arr, ind + 1, sum + arr[ind], ans, n);
    // if not picks the element
    findsubsetSum(arr, ind + 1, sum, ans, n);
}

vector<int> subsetSum(vector<int>& arr){
    int n = arr.size();
    vector<int>ans;
    findsubsetSum(arr, 0, 0, ans, n);
    sort(ans.begin(), ans.end());
    return ans;
}


int main(){
    vector<int>arr = {3, 1, 4};
    vector<int>ans= subsetSum(arr);
    cout<<" The sum of each subset is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(2^N) + O(2^N log(2^N))
// SC---> O(2^N)