#include<bits/stdc++.h>
using namespace std;

bool palindrome(string &s, int start, int end){
    while(start <= end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(string &s, int ind, vector<string> &path, vector<vector<string>> &ans, int n){
    // Base Case
    if(ind == n){
        ans.push_back(path);
        return;
    }

    for(int i=ind;i<n;i++){
        if(palindrome(s, ind, i)){
            path.push_back(s.substr(ind, i - ind + 1));
            solve(s, i + 1, path, ans, n);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s){
    int n = s.size();
    vector<vector<string>>ans;
    vector<string>path;
    solve(s, 0, path, ans, n);
    return ans;
}

int main(){
    string s = "aabb";
    vector<vector<string>>ans = partition(s);
    cout<<" The palindromic partitions are : ";
    for(auto it: ans){
        cout<<"[ ";
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}

// TC---> O(2^N * (N/2) * K)
// SC---> O(N) + O(K * X)