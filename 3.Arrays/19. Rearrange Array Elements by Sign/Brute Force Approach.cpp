#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& arr, int n){
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0;i<n/2;i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    return arr;
}

int main(){
    vector<int>arr{3,1,-2,-5,2,-4};
    int n=6;
    vector<int>ans=rearrangeArray(arr, n);
    cout<<" The Rearrange array elements of an array is : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


// TC---> O(N)+O(N/2)
// SC---> O(N)