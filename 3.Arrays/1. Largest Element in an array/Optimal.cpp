#include<bits/stdc++.h>
using namespace std;

int findLargestElement(vector<int>&arr){
    int max=arr[0];
    for(int i=0; i <arr.size();i++){
        if(arr[i] > max){
            max=arr[i];
        }
        else continue;
    }
    return max;
}

int main(){
    vector<int>arr={2,5,1,3,0};
    cout<<"The Largest Element in an array is: "<<findLargestElement(arr);
    return 0;
}

// TC--> O(N);
// SC--> O(1);