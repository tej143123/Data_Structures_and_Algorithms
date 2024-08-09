#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int n, int target){
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target){
                        vector<int>temp={arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

int main(){
    vector<int>arr={4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int n=10;
    int target = 9;
    vector<vector<int>>ans = fourSum(arr, n, target);
    cout<<" The quadruplets are : \n";
    for(auto it : ans){
        cout<<"[";
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}

// TC ---> O(N^4)
// SC ---> O(2* No. of quadruplets)