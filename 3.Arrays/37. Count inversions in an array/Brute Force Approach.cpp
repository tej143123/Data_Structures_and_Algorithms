#include<bits/stdc++.h>
using namespace std;

int countInversions(vector<int>& arr, int n){
    // condition ---> (i < j) && (arr[i] > arr[j])
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    vector<int>arr={5, 3, 2, 4, 1};
    int n=5;
    cout<<" The number of inversions are : "<<countInversions(arr, n)<<endl;
    return 0;
}


// TC---> O(N^2)
// SC---> O(1)