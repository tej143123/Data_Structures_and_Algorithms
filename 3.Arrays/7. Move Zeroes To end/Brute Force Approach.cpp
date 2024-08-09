#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeroesToEnd(vector<int>&arr, int n){
    vector<int>temp;

    // storing non zeroes in an extra memory
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }

    // moving the elements into original array
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }

    // filling rest of the cells with '0'
    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
    return arr;
}

int main(){
    vector<int>arr={1,0,2,3,2,0,0,4,5,1};
    int n=10;
    vector<int>ans=moveZeroesToEnd(arr, n);
    cout<<" The updated array after moving zeroes to end is : "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}

// TC--> O(2*n)
// SC--> O(n)