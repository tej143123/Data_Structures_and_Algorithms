#include<bits/stdc++.h>
using namespace std;

void getElements(vector<int>& arr, int n){

    //edge case if there are no elements & only one element present in an array  
    if(n==0 || n==1){
        cout<<-1<<" "<<-1<<endl;
    }
    sort(arr.begin(), arr.end());
    int second_smallest=arr[1];
    int second_largest=arr[n-2];
    cout<<"The Second Smallest Element is: "<<second_smallest<<endl;
    cout<<"The Second Largest Element is: "<<second_largest<<endl;
}

int main(){
    vector<int>arr={1,2,4,6,7,5};
    int n=6;
    getElements(arr, n);
    return 0;
}

// TC--> O(n log n)
// SC--> O(1)