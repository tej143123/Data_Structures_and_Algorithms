#include<bits/stdc++.h>
using namespace std;
/* int findMax(int ind, vector<int>& arr, int n){
    int maxi = INT_MIN;
    for(int i=ind;i<n;i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
vector<int> superiorElements(vector<int>& arr, int n){
    vector<int>ans;
    for(int i=0;i<n;i++){
        int maxi = findMax(i+1, arr, n);
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
*/
vector<int> superiorElements(vector<int>& arr, int n){
    vector<int>ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return ans;
}

int main(){
    vector<int>arr={10, 22, 12, 3, 0, 6};
    int n=6;
    vector<int>ans=superiorElements(arr, n);
    cout<<" The leaders in an array is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}

// TC---> O(N)
// SC---> O(N)(Worst Case)(in order to store and return the ans)
// Extra Space---> O(1)