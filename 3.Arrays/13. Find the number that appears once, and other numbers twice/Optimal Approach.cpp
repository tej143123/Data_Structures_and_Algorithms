#include<bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>& arr, int n){
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR=XOR^arr[i];
    }

    return XOR;
}

int main(){
    vector<int>arr={1,1,2,3,3,4,4};
    int n=7;
    cout<<"The Single Element present in an array is : "<<findSingleElement(arr, n);
    return 0;
}

// TC ---> O(N)
// SC ---> o(1)

