#include<bits/stdc++.h>
using namespace std;

void printSubsequences(vector<int>& arr, int ind, vector<int>& ds, int sum, int K, int n){
    // Base Case
    if(ind == n){
        if(sum == K){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printSubsequences(arr, ind + 1, ds, sum, K, n);
    sum -= arr[ind];
    ds.pop_back();
    printSubsequences(arr, ind + 1, ds, sum, K, n);
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
