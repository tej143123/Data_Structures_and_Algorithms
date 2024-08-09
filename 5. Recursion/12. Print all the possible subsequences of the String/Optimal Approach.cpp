#include<bits/stdc++.h>
using namespace std;

// code works only for strings

void printSubsequences(string s, int ind, string res, vector<string>&ans, int n)
{
    // Base Case
    if(ind==n)
    {
        ans.push_back(res);
        return;
    }
    // take
    res += s[ind];
    printSubsequences(s, ind + 1, res, ans, n);
    res.pop_back();
    // not take
    printSubsequences(s, ind + 1, res, ans, n);
}
vector<string> generateSubsequences(string s)
{
    int n=s.size();
    vector<string>ans;
    printSubsequences(s, 0, "", ans, n);
    return ans;
}

int main(){
    string s = "abcd";
    vector<string>ans = generateSubsequences(s);
    cout<<" The subsequences of given string are :";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(2^N)
// SC---> O(N) ---> Recursion Stack Space 