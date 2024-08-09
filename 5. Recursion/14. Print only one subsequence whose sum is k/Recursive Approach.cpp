#include<bits/stdc++.h>
using namespace std;

bool printSubsequences(vector<int>& arr, int ind, vector<int>& ds, int sum, int K, int n){
    // Base Case
    if(ind == n){
        // condition satisfied
        if(sum == K){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        // condition not satisfied
        return false;
    }
    ds.push_back(arr[ind]);
    sum += arr[ind];
    
    if(printSubsequences(arr, ind + 1, ds, sum, K, n) == true){
        return true; 
    }

    sum -= arr[ind];
    ds.pop_back();
    // not pick
    
    if(printSubsequences(arr, ind + 1, ds, sum, K, n) == true) return true;
    return false;
}

int main(){
    vector<int>arr = {1, 2, 1};
    int n = 3;
    int K = 2;
    vector<int>ds;
    cout<<" The subsequences are : ";
    printSubsequences(arr, 0, ds, 0, K, n);
    return 0;
}
