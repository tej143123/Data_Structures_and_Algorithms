#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    string s = to_string(n);
    return s.size();
}

int main(){
    int n;
    cin >> n;
    cout<<countDigits(n);
    return 0;
}

// TC---> O(1)
// SC---> O(1)
