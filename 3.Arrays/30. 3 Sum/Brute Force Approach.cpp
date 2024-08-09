#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int>& arr, int n){
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                   vector<int>temp={arr[i], arr[j], arr[k]};
                   sort(temp.begin(), temp.end());
                   st.insert(temp);
                }
            }
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

// TC---> O(N^3) *log(No. of unique triplets)
// SC---> 2* O(No. of unique triplets)