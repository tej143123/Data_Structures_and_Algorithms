#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int>& arr, int n){
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hashSet;
        for(int j=i+1;j<n;j++){
            int third=-(arr[i] + arr[j]);
            if(hashSet.find(third)!=hashSet.end()){
                vector<int>temp={arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);            
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

int main(){
    vector<int>arr={-1, 0, 1, 2, -1, -4};
    int n=6;
    vector<vector<int>>ans=triplets(arr, n);
    for(auto it : ans){
        cout<<"[";
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}

// TC---> O(N^2) *log(Size of set)
// SC---> O(N) + 2* O(No. of unique triplets)