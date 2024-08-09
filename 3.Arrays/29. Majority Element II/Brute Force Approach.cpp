#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& arr, int n){
    vector<int>ls;
    for(int i=0;i<n;i++){
        if(ls.size()==0 || ls[0]!=arr[i]){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(arr[j]==arr[i]){
                    cnt++;
                }
            }
            if(cnt > n/3){
                ls.push_back(arr[i]);
            }
        }
        if(ls.size() == 2) break;
    }
    return ls;
}

int main(){
    vector<int>arr={11, 33, 33, 11, 33, 11};
    int n=6;
    vector<int>ans=majorityElement(arr, n);
    cout<<" The majority elements are : "<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N^2)
// SC---> O(1)