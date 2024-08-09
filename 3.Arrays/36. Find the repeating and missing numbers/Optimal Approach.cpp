#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int>& arr, int n){
    // S - SN --> X-Y
    // S2 - S2N
    long long S = 0, S2 = 0;
    long long SN = (n * (n+1))/2;
    long long S2N= (n * (n+1)* (2*n+1))/6;
    for(int i=0;i<n;i++){
        S+=arr[i];
        S2+=(long long)(arr[i]) * (long long)(arr[i]);
    }
    
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2/val1;
    long long x = (val1 + val2)/2;
    long long y = (x - val1);
    return {(int) x, (int) y};
}

int main(){
    vector<int>arr={4, 3, 6, 2, 1, 1};
    int n=6;
    vector<int>ans = findMissingRepeatingNumbers(arr, n);
    cout<<" The repeating and missing elements are : "<<ans[0]<<" , "<<ans[1]<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(1)