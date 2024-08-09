#include<bits/stdc++.h>
using namespace std;

vector<string> printSubsequences(string &s, int n){
    vector<string>ans;
    for(int num=0;num<(1 << n);num++){
        string sub = " ";
        for(int i=0;i<n;i++){
            if((num &(1 << i)) != 0){
                sub += s[i];
            }
        }
        ans.push_back(sub);
    }
    return ans;
}


int main(){
    string s = "abc";
    int n = 3;
    vector<string>ans = printSubsequences(s, n);
    cout<<" The subsequences of giben string are : ";
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}


// TC---> O(2^N * N)
// SC---> O(1)