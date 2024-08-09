#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr, int n){
    set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int k=st.size();
    int j=0;
    for(auto it: st){
        arr[j]=it;
        j++;
    }
    return k;
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

// TC--> O(n log n)+o(n) --> for using Hash set data structure and inserting elements into it and linear travesal
// SC--> O(n) --> for storing the elements in set data structure
