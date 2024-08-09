#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int>& arr, int n){
    int repeating = -1;
    int missing = -1;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == i){
                cnt++;
            }
        }
        if(cnt == 2){
           repeating = i;
        }
        else if(cnt == 0){
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

// TC---> O(N^2)
// SC---> O(1)