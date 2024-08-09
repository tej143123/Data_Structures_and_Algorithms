#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int i, string &s){
    // Base Case
    if(i >= s.size() / 2) return true;
    if(s[i] != s[s.size() - i - 1]) return false;
    return checkPalindrome(i + 1, s);
}

int main(){
    string s = "MADAM";
    cout<<checkPalindrome(0, s)<<endl;
    return 0;
}

// TC---> O(N/2)
// SC---> O(N/2)---> Stack Space