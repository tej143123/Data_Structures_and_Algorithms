#include<bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2){
    int n=arr1.size();
    int m=arr2.size();
    int i=0, j=0;
    vector<int>ans;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int>arr1={1,1,2,3,4,5};
    vector<int>arr2={2,3,4,4,5,6};
    cout<<"The intersection of two sorted arrays is : ";
    vector<int>ans=findIntersection(arr1, arr2);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}

// TC---> O(n+m)
// SC---> O(n)(worst case)