#include<bits/stdc++.h>
using namespace std;

int sortArr(vector<int>& arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size()-1];
}

int main(){
    vector<int>arr={2,5,1,3,0};
    cout<<"The Largest Element in an array is: "<<sortArr(arr)<<endl;
    return 0;
}

// TC--> O(n logn);
// SC--> O(n);