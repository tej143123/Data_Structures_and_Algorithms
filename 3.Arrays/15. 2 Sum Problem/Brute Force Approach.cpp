#include<bits/stdc++.h>
using namespace std;

string twoSum(vector<int>& arr, int n, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target)
            return "Yes";
        }
    }
    return "No";
}

int main(){
    vector<int>arr={2,6,5,8,11};
    int n=5;
    int target=14;
    cout<<twoSum(arr, n, target);
    return 0;
}

// TC ---> O(N^2)
// SC ---> O(1)