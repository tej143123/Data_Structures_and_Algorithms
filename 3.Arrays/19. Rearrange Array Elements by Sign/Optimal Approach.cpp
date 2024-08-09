#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& arr, int n){
    vector<int>ans(n, 0);
    int posIndex=0;
    int negIndex=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
        else{
            ans[negIndex]=arr[i];
            negIndex+=2;
        }
    }
    return ans;
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


// TC---> O(N)
// SC---> O(N)