#include<bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int>ans;
    int vis[m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j] && vis[j]==0){
                ans.push_back(arr1[i]);
                vis[j]=1;
                break;
            }
            if(arr2[j]>arr1[i]) break;
        }
    }
    return ans;
}

int main(){
    vector<int>arr1={1,1,2,3,4,4};
    vector<int>arr2={2,3,4,4,5,6};
    cout<<"The intersection of two sorted arrays is : ";
    vector<int>ans=findIntersection(arr1, arr2);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}

// TC---> O(n*m)
// SC---> O(m)