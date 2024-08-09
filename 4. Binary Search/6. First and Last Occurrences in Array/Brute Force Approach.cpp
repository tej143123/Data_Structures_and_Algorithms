#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFirstAndLastPosition(vector<int>& arr, int target, int n){
    int first = -1;
    int last = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
}


int main(){
    vector<int>arr={2, 4, 6, 8, 8, 8, 11, 13};
    int n=8;
    int target = 8;
    pair<int, int> ans = getFirstAndLastPosition(arr, target, n);
    cout<<" The first and last position is : "<<ans.first<<", "<<ans.second<<endl;
    return 0;
}


// TC---> O(N)
// SC---> O(1)