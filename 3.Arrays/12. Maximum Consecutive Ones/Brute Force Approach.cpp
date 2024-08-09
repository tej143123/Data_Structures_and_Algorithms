#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& arr, int n){
    int maxi=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi, cnt);
        }
        else{
            cnt=0;
        }
    }
    return maxi;
}

int main(){
    vector<int>arr={1,1,0,1,1,1,0,1,1};
    int n=9;
    cout<<" The Maximum number of consecutive ones are : "<<findMissing(arr, n);
    return 0;
}

// TC ---> O(N)
// SC ---> O(1)