#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int>& arr, int n){
    int repeating = -1;
    int missing = -1;
    int hash[n+1] = {0};
    
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(hash[i] == 2){
            repeating = i;
        }
        else if(hash[i] == 0){
            missing = i;
        }
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing};
}

int main(){
    vector<int>arr={4, 3, 6, 2, 1, 1};
    int n=6;
    vector<int>ans = findMissingRepeatingNumbers(arr, n);
    cout<<" The repeating and missing elements are : "<<ans[0]<<" , "<<ans[1]<<endl;
    return 0;
}

// TC---> O(2N)
// SC---> O(N)