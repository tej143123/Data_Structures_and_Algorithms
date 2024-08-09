#include<bits/stdc++.h>
using namespace std;

void leftRotate(vector<int>& arr, int n, int k){
    int temp[k];

    k=k%n;
    // storing 
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }

    // shifting
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }

    // put back to the array
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-(n-k)];
    }
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int n=7;
    int k=8;
    leftRotate(arr, n, k);
    cout<<"After Rotating the elements to left : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// TC--> O(K)+O(N-K)+O(K)---> O(N+K)
// SC--> O(K)