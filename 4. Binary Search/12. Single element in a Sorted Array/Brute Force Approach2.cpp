#include<bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>& arr, int n){
    int XOR = 0;
    for(int i=0;i<n;i++){
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

int main(){
    vector<int>arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int n = 11;
    int ans = findSingleElement(arr, n);
    cout<<" The single element is : "<<ans<<endl;
    return 0;
}


// TC---> O(N)
// SC---> O(1)