#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> arr1, vector<int> arr2){
    set<int>st;
    int n1=arr1.size();
    int n2=arr2.size();
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    vector<int> temp;
    for(auto it: st){
        temp.push_back(it);
    }
    return temp;
}

int main(){
    vector<int>arr1={1,1,2,3,4,5};
    vector<int>arr2={2,3,4,4,5,6};
    cout<<" The union of two sorted arrays is : ";
    vector<int>ans=findUnion(arr1, arr2);
    for(auto &it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(n1 log n)+O(n2 log n)+ O(n1+n2)(worst case)
// SC---> O(n1+n2) + O(n1+n2)