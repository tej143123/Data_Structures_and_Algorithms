#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& arr, int n){
    vector<int>ls;
    map<int, int>mpp;
    int mini=(n/3)+1;
    for(int i=0;i<n;i++){
        // Storing the elements in the map
        mpp[arr[i]]++;

        // Checking if the element appears more than 2 times
        // then push it into the list
    }
    for(auto it: mpp){
        if(it.second >= mini){
            ls.push_back(it.first);
        }
        if(ls.size() == 2) break;
    }
    return ls;
}

int main(){
    vector<int>arr={11, 33, 33, 11, 33, 11};
    int n=6;
    vector<int>ans=majorityElement(arr, n);
    cout<<" The majority elements are : "<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N log N)
// SC---> O(N)---> (Worst Case)