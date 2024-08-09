#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& arr, int n){
    // Applying Moore's Voting Algorithm
    int cnt1=0, cnt2=0;
    int ele1=INT_MIN, ele2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1 == 0 && arr[i]!=ele2){
            cnt1++;
            ele1=arr[i];
        }
        else if(cnt2 == 0 && arr[i]!=ele1){
            cnt2++;
            ele2=arr[i];
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0, cnt2=0;
    vector<int>ls;
    for(int i=0;i<n;i++){
        if(ele1 == arr[i]) cnt1++;
        if(ele2 == arr[i]) cnt2++;
    }
    int mini=(n/3)+1;
    if(cnt1 >= mini) ls.push_back(ele1);
    if(cnt2 >= mini) ls.push_back(ele2);
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

// TC---> O(N) + O(N)
// SC---> O(1)