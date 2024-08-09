#include<bits/stdc++.h>
using namespace std;

vector<int> reverseArray(vector<int>& arr){
    reverse(arr.begin(), arr.end());
    return arr;
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = 5;
    vector<int>ans = reverseArray(arr);
    cout<<" The reverse array is : ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(1)