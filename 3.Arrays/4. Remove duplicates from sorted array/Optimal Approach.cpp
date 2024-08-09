#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr, int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    vector<int>arr={1,1,2,2,2,3,3};
    int n=7;
    int k=removeDuplicates(arr, n);
    cout<<"The array after removing duplicates is : ";
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// TC--> O(n)
// SC--> O(1)