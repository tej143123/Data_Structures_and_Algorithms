#include<bits/stdc++.h>
using namespace std;

void getElements(vector<int>& arr, int n){
    int smallest=INT_MAX, second_smallest=INT_MAX;
    int largest=INT_MIN, second_largest=INT_MIN;
    
    //edge case if there are no elements & only one element present in an array 
    if(n==0 || n==1){
        cout<<-1<<" "<<-1<<endl;
    }
    for(int i=0;i<n;i++){
        smallest=min(smallest, arr[i]);
        largest=max(largest, arr[i]);
    }

    for(int i=0;i<n;i++){
        if(arr[i]<second_smallest && arr[i]!=smallest){
            second_smallest=arr[i];
        }
        if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }

    cout<<"Second Smallest is: "<<second_smallest<<endl;
    cout<<"Second Largest is:  "<<second_largest<<endl;
}

int main(){
    vector<int>arr={1,2,4,6,7,5};
    int n=6;
    getElements(arr, n);
    return 0;
}

// TC--> O(n)
// SC--> O(1)