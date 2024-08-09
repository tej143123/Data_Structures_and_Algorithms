#include<bits/stdc++.h>
using namespace std;

int countOccurrences(vector<int>& arr, int target, int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            cnt++;
        }
    }
    return cnt;
}


int main(){
    vector<int>arr={2, 8, 8, 8, 8, 8, 11, 13};
    int n = 8;
    int target = 8;
    int cnt = countOccurrences(arr, target, n);
    cout<<" The number of occurrences of a target is : "<<cnt<<endl;
    return 0;
}


// TC---> O(N)
// SC---> O(1)