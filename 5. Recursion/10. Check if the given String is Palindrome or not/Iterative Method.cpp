#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &s, int start, int end){
    // Base Case
    if(start >= s.size() / 2) return true;
    while(start < end){
        if(s[start] == s[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string s = "MADAM";
    cout<<checkPalindrome(s, 0, s.size() - 1);
    return 0;
}

// TC ---> O(N/2)
// SC ---> O(1)