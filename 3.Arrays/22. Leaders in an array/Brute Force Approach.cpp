#include<bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>& arr, int n){
    vector<int>ans;
    for(int i=0;i<n;i++){
         bool leader=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
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

// TC---> O(N^2)
// SC---> O(N)(Worst Case)(in order to store and return the ans)
// Extra Space---> O(1)