#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int n){
    int revNum = 0;
    int dup = n;
    while( n > 0){
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
    }
    if(dup == revNum) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    cout<<checkPalindrome(n);
    return 0;
}

// TC---> O(log N) 
// SC---> O(1)