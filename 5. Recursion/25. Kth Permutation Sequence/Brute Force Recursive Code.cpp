#include<bits/stdc++.h>
using namespace std;

void findpermutations(string &s, int ind, vector<string>& ans, int n){
    // Base Case
    if(ind == n){
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<n;i++){
        swap(s[ind], s[i]);
        findpermutations(s, ind + 1, ans, n);
        swap(s[ind], s[i]);
    }
}

string getKthPermutation(int n, int k){
    string s;
    vector<string>ans;
    for(int i=1;i<=n;i++){
        s.push_back(i + '0');
    }
    findpermutations(s, 0, ans, n);
    sort(ans.begin(), ans.end());
    auto it = ans.begin() + (k - 1);
    return *it;
}

int main(){
    int n = 3;
    int k = 3;
    string ans = getKthPermutation(n, k);
    cout<<" The kth permutation sequence is : "<<ans<<endl;
    return 0;
}

// TC---> O(N! * N) + O(N! log N!)
// SC---> O(N) + O(N! * N)