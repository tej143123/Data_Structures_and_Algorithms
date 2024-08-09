#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n){
    cout<<" The reverse array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(vector<int>& arr, int start, int end, int n){
    while(start < end){
        swap(arr[start], arr[end]);
        return reverseArray(arr, start + 1, end - 1, n);
    }
}

int main(){
    vector<int>arr = {5, 4, 3, 2, 1};
    int n = 5;
    reverseArray(arr, 0, n - 1, n);
    printArray(arr, n);
    return 0;
}

// TC---> O(N)
// SC---> O(1)